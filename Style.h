#pragma once
#include<iostream>
#include<Windows.h>
using namespace std;
namespace Style {

	//للحذف الشاشة
	void cls() {
		system("cls");
	}

	//لتأخير بالطباعة
	void sleep(int num) {
		sleep(num);
	}

	//enter لحذف إدخال 
	void clearLines(int i, int count) {
		for (i; i < count; i++) {
			cout << "\033[2K\r";  
			cout << "\033[A";     
		}
	}
}