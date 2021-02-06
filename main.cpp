#include <iostream>
//1. Написать программу, проверяющую что сумма двух чисел лежит в пределах от 10 до 20
//(включительно), если да – вывести true, в противном случае – false;

bool checkSumm(int a, int b){
	int sum = a + b; 
	if ((sum >= 10) && (sum <= 20))return true;
	
	return false;
}

//2. Написать программу, проверяющую, является ли некоторое число - натуральным простым.
//Простое число - это число, которое делится без остатка только на единицу и себя само
bool checkSimpleNumber(int number){
	if(number < 2)return false;
	for(int i = 2; i <= number/2; i++){
		if(number % i == 0) return false; 
	}
	return true;
}


//3. Написать программу, выводящую на экран “истину”, если две целочисленные константы,
//объявленные в её начале либо равны десяти сами по себе, либо их сумма равна десяти.
const int A = 10;
const int B = 0;
bool checkVar(void){
	if(A == 10 && B == 10)return true;
	if((A + B) == 10)return true;
	return false;
}

//4. * Написать программу, которая определяет является ли год високосным. Каждый 4-й год
//является високосным, кроме каждого 100-го, при этом каждый 400-й – високосный. Для
//проверки работы вывести результаты работы программы в консоль
/*
Если год високосный, то возвращаем true
*/
bool checkYear(int year){
	if(year % 4 != 0) return false;
	else
		if((year % 100 == 0) && (year % 400 != 0)) return false;
		else return true;
}

int main(){
	std::cout << (checkSumm(5,18) ? "True" : "False") << std::endl;
	
	std::cout << (checkSimpleNumber(18) ? "Number is simple" : "Number is't simple") << std::endl;
	
	std::cout << (checkVar() ? "True" : "False") << std::endl;
	
	std::cout << (checkYear(2005) ? "Leap year" : "Normal year") << std::endl;
	
	system("pause");
	return 0;
}