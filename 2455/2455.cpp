#include <iostream>  
using namespace std;

int main() {
	int number = 4;
	int in, out;
	int total=0;
	int max=0;
	while (number--) {
		cin >> out >> in;
		total += in - out;
		if (max < total) {
			max = total;
		}
	}
	cout << max;
}


