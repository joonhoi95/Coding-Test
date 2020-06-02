#include <iostream>
#include <algorithm>
//#include <vector>
using namespace std;
int main() {
	bool escape = false;
	int kid[9] = {};
	int result[7] = { };
	int total = 0;
	for (int i = 0; i < 9; i++) {
		cin >> kid[i];
		total += kid[i];
	}
	for (int j = 0; j < 8; j++) { // 9 C 2 -> MAX 36 times
		for (int k = j + 1; k < 9; k++) {
			if (total == kid[j] + kid[k] + 100) { 
				kid[j] = 0; kid[k] = 0;
				escape = true;
				break; 
			}
			if (escape == true) 
				break;
		}
	}
	sort(kid, kid + 9);
	for (int j = 0; j < 9; j++) {
		if (kid[j] != 0)
			cout << kid[j] << endl;
	}
	cin >> total;
}