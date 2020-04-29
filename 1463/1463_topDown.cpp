#include <iostream>

int main() {
		int x = 0, count = 0;
		std::cin >> x;
		for (;;) {
			if (x == 1) break;
			if (x % 3 == 0) { x /= 3; count++; }
			else if ((x % 2 == 0) && ((x / 2) % 2 == 0)) { x /= 2; count++; }
			else if ((x % 2 == 0) && ((x - 1) % 3 != 0)) { x /= 2; count++; }
			else { x--; count++; }
		}
		std::cout <<count;
}