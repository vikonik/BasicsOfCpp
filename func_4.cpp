#include <iostream>
//4. * Написать функцию, которой на вход подаётся одномерный массив и число n (может быть
//положительным, или отрицательным), при этом метод должен циклически сместить все
//элементы массива на n позиций.
namespace myNamespase {
	void scrolMass(int *mass, int len, int n){
		int tmp;
		if(n >= 0){
			while(n--){
				tmp = mass[len-1];
				for(int i = len; i > 0; i--){
					mass[i] = mass[i-1];
				}
				mass[0] = tmp;
			}
		}
		else{
			while(n++){
				tmp = mass[0];
				for(int i = 0; i < len-1; i++){
					mass[i] = mass[i+1];
				}
				mass[len -1] = tmp;
			}		
		}
	}
}