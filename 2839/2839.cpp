#include <iostream>
#define MAX 5001
int calculate[MAX] = { 0 };

int main() {
	int testLen = 0;
	std::cin >> testLen;
	calculate[0] = -1;
	calculate[1] = -1;
	calculate[2] = -1;
	calculate[3] = 1;
	calculate[4] = -1;
	calculate[5] = 1;
	if (testLen > 5) {
		for (int i = 6; i <= testLen; i++) {
			if ((calculate[i - 5] == -1) && (calculate[i - 3] == -1)) {
				calculate[i] = -1;
			}
			else {
				if (calculate[i - 5] < calculate[i - 3]) {
					if (calculate[i - 5] != -1) { calculate[i] = calculate[i - 5] + 1; }
					else { calculate[i] = calculate[i - 3] + 1; }
				}
				else {
					if (calculate[i - 3] != -1) { calculate[i] = calculate[i - 3] + 1; }
					else { calculate[i] = calculate[i - 5] + 1; }
				
				}
			
			}
		}
	}
	std::cout << calculate[testLen] << std::endl;
}

