#include <iostream>
//1.Описать макрокоманду, проверяющую, входит ли переданное ей число в диапазон от нуля (включительно) 
//до переданного ей второго аргумента (исключительно)
#define IS_CHECK(a,b)	(((a) >= 0)&&((a) < (b))) ? true : false

//2.Описать макрокоманду, получающую доступ к элементу двумерного массива (организованного динамически) 
//посредством разыменования указателей
char **myMass;
#define CREATE_MASS(mass,m,n)	{mass = new char* [m];\
								for(int i = 0; i < m; i++)mass[i] = new char[n];}

#define GET_ELEMENT(mass,m,n)	*(*(mass + (m)) + (n))

//3.* Описать макрокоманду, возвращающую количество элементов локального массива, 
//принимающую на вход ссылку на массив и его тип
int mass[22];
#define QWEQWE(mass, mass_type) sizeof(mass)/sizeof(mass_type)/*/mass_type*/

int main(void){
  
  system("pause");
  return 0;
}