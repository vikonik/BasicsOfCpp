#include <iostream>
//3. * Написать метод, в который передается не пустой одномерный целочисленный массив,
//метод должен вернуть истину если в массиве есть место, в котором сумма левой и правой
//части массива равны. Примеры: checkBalance([1, 1, 1, || 2, 1]) → true, checkBalance ([2, 1, 1, 2,
//1]) → false, checkBalance ([10, || 1, 2, 3, 4]) → true. Абстрактная граница показана символами ||,
//эти символы в массив не входят.
namespace myNamespase {
	bool checkBalance(int *mass, int len){
		int summLeft = 0;
		int summRight = 0;
		int cnt = 0;//до этого элемента левая сумма
		for(cnt = 0;cnt < len-2 ;cnt++){
			for(int i = 0; i < len; i++){
				(i <= cnt ) ? summLeft += mass[i] : summRight += mass[i];
				std::cout << "summLeft = "<< summLeft << " summRight = " << summRight << " cnt = "<< cnt << " i =" <<i<<"\r\n";
			}
			if(summLeft == summRight)return true;
			summLeft = 0;
			summRight = 0;
		}
		return false;
	}
}