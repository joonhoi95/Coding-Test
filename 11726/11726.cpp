#include <iostream>
#define MAX 1001
int calculate[MAX] = { 0 };

int main() {
	int testLen = 0;
	std::cin >> testLen;
	calculate[0] = 0;
	calculate[1] = 1;
	calculate[2] = 2;
	for (int i = 3; i <= testLen; i++) {
		calculate[i] = calculate[i - 1] + calculate[i - 2];
	}
	std::cout << calculate[testLen] << std::endl;
	std::cin >> testLen;
}

