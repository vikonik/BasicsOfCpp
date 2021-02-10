#include <iostream>
//2. Задать пустой целочисленный массив размером 8. Написать функцию, которая с помощью
//цикла заполнит его значениями 1 4 7 10 13 16 19 22;
namespace myNamespase {
	void putData(int *mass, int len){
		*mass = 1;
		for(int i = 1; i < len; i++){
			*(mass + i) = *(mass + i - 1) + 3;
		}
	}
}