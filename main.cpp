#include <iostream>



//1
int a = 0;
long b = 0;
short c = 0;
unsigned d = 0;

char e = 'A';

float f = 0.0;
double g = 0.0;


//2
enum XO_symbolName{
	O,
	X
};

//3
char XO_symbol[2] = {'O', 'X'};

//4
typedef struct {
	int gameField[3][3];
	char HUMAN_DOT;
	char AI_DOT;
	
}Game;


//5
typedef union{
	int myInt;
	float myFloat;
	char myChar;
}MyUnion;


typedef struct{
	int isInt:		1;
	int isFloat:	1;
	int isChar:		1;
	
}BitFlag;

typedef struct{
	MyUnion myUnion;
	BitFlag bitFlag;
	
}MyStruct;

MyStruct myStruct;



int main(void){
myStruct.bitFlag.isInt = 1;
myStruct.myUnion.myInt = 123;
	if(myStruct.bitFlag.isInt)std::cout << myStruct.myUnion.myInt;
	else std::cout << "???";
	std::cout << "\r\n";
  system("pause");
  return 0;
}
