#include <iostream>
//1. Задать целочисленный массив, состоящий из элементов 0 и 1. Например: [ 1, 1, 0, 0, 1, 0, 1, 1,
//0, 0 ]. Написать функцию, заменяющую в принятом массиве 0 на 1, 1 на 0;

namespace myNamespase {
	void chengeData(int *mass, int len){
		for(int i = 0; i < len; i++){
			(*(mass + i) == 1) ? *(mass + i) = 0 : *(mass + i) = 1;
		}
	}
}