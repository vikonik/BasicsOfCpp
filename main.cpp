#include <iostream>
#include <fstream>
#include <string>

using namespace std;

//1. Написать программу, которая создаст два текстовых файла, примерно по 50-100 символов в
//каждом (особого значения не имеет);

void createFile(string fileName, char simbol){
	ofstream fos(fileName + ".txt");
	for(int i = 0; i < 50; i++){
		fos << simbol;
	} 
	fos << "Hello";
	fos.close();
	
}

//2. Написать функцию, «склеивающую» эти файлы, предварительно буферизуя их содержимое в
//динамически выделенный сегмент памяти нужного размера.
char *text;
/**/
int getFileSize(string fileName){
	int size = 0;
	fstream file(fileName + ".txt");
	file.seekg (0, std::ios::end);
	size = file.tellg();
	cout << fileName << ".txt" << " size : " << size << " byte(s)" << endl;
	file.close();
	return size;
}
/**/
char *tmp;
void readFile(string fileName){
	ifstream fis(fileName+".txt");
	fis >> tmp;
	fis.close();
	
	//return tmp;
}
/**/
void glueFile(void){
	int dataSize = 0;
	int dataSizeFile_1 = 0;
	int dataSizeFile_2 = 0;
	dataSizeFile_1 = getFileSize("File_1");//получили размер файлов
	dataSizeFile_2 = getFileSize("File_2");
	dataSize = dataSizeFile_1 + dataSizeFile_2;
	text = (char*)calloc(dataSize,sizeof(char));//Выделили место в памти под этот размер
	tmp = (char*)calloc(dataSizeFile_1,sizeof(char));
	readFile("File_1");
	memcpy(text,tmp,dataSizeFile_1);
	readFile("File_2");
	tmp = (char*)realloc(tmp,dataSizeFile_2);
	memcpy(text+dataSizeFile_1,tmp,dataSizeFile_2);
	delete tmp;
}
//3. * Написать программу, которая проверяет присутствует ли указанное пользователем при
//запуске программы слово в указанном пользователем файле (для простоты работаем только
//с латиницей)
bool findWord(char *src, char *findWord){
	int sizeSrc = 0;
	int sizeFindWord = 0;
	//вот таким экзотическим способом получаем размер строки
	//перебираем все символы в строке пока не наткнемся на \0 - конец строки
	for(sizeSrc = 0;src[sizeSrc]; sizeSrc++);
	for(sizeFindWord = 0;findWord[sizeFindWord]; sizeFindWord++);
	//перебором проверяем на совпадеие
	int i = 0; 
	int j = 0;
	while(i <= sizeSrc - sizeFindWord){//пока искомая строка влезает в исходную
		while(src[i + j] == findWord[j] ){//перебираем посимвольно
			j++;
		}
		if(j == sizeFindWord) return true;
		j = 0;
		i++;
	}
	return false;
}


int main(int argc, char** argv){
	createFile("File_1",'a');
	createFile("File_2",'b');
	glueFile();

	cout << text;
	char findW[] = "Hello";
	cout << findWord(text,findW)<<endl;
	
}
