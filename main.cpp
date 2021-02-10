#include <iostream>
#include <stdarg.h>


/*
Выводим элементы массива

Почему endl вызывает ошибку? https://yadi.sk/i/GcAb7BlY-qvuJA
*/
void printMass(int *mass, int len){
	std::cout <<"\r\n";
	for(int i = 0; i < len; i++){
		std::cout << mass[i] << "\r\n";
	}
}

//1. Задать целочисленный массив, состоящий из элементов 0 и 1. Например: [ 1, 1, 0, 0, 1, 0, 1, 1,
//0, 0 ]. Написать функцию, заменяющую в принятом массиве 0 на 1, 1 на 0;
int myMass[10] = {1,1,0,0,1,0,1,1,0,0};



//2. Задать пустой целочисленный массив размером 8. Написать функцию, которая с помощью
//цикла заполнит его значениями 1 4 7 10 13 16 19 22;
int mass[8];


//3. * Написать метод, в который передается не пустой одномерный целочисленный массив,
//метод должен вернуть истину если в массиве есть место, в котором сумма левой и правой
//части массива равны. Примеры: checkBalance([1, 1, 1, || 2, 1]) → true, checkBalance ([2, 1, 1, 2,
//1]) → false, checkBalance ([10, || 1, 2, 3, 4]) → true. Абстрактная граница показана символами ||,
//эти символы в массив не входят.
int massCheckBalance[] = {10, 1, 2, 3, 4,3};//Массив для проверки функции


//4. * Написать функцию, которой на вход подаётся одномерный массив и число n (может быть
//положительным, или отрицательным), при этом метод должен циклически сместить все
//элементы массива на n позиций.


//5. ** Написать функцию из первого задания так, чтобы она работала с аргументом переменной
//длины.

//Переопределим функцию из первого задания
void chengeData(int count, ...) { 
	va_list lst; 
	va_start(lst, count); 
	//(*(mass + i) == 1) ? *(mass + i) = 0 : *(mass + i) = 1;
	for (int i = 0; i < count; i++) { 
		std::cout << ((va_arg(lst, int) == 1) ? 0 : 1) << "\r\n"; 
	}
	va_end(lst);
}



//6. ** Написать все функции в отдельных файлах в одном пространстве имён, вызвать их на
//исполнение в основном файле программы используя указатели на функции.

namespace myNamespase {
void chengeData(int *mass, int len);
void putData(int *mass, int len);
bool checkBalance(int *mass, int len);
void scrolMass(int *mass, int len, int n);

	}



int main(int argc, char** argv){
	void (*myFunction)(int*,int);
	myFunction = myNamespase::chengeData;
	myFunction(myMass, sizeof(myMass)/sizeof(int));
	printMass(myMass, sizeof(myMass)/sizeof(int));
	
	myFunction = myNamespase::putData;
	myFunction(mass, sizeof(mass)/sizeof(int));
	printMass(mass, sizeof(mass)/sizeof(int));
	
	
	chengeData(3, 1, 0, 1);

	system("pause");
}
