#include <iostream>
int M_123[11];
int main() {
	int testCase = 0;
	int testNo = 0;
	M_123[1] = 1;
	M_123[2] = 2;
	M_123[3] = 4;
	std::cin >> testCase;
	int *result = new int[testCase];

	for (int i = 0; i < testCase; i++) {
		std::cin >> testNo;
		for (int j = 4; j <= testNo; j++) {
			M_123[j] = M_123[j - 1] + M_123[j - 2] + M_123[j - 3];
		}
		result[i] = M_123[testNo];
	}
	for (int i = 0; i < testCase; i++) { std::cout << result[i] << std::endl; }
}

