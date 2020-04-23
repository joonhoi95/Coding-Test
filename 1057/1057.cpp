#include <iostream>
//int main() {
//	int kim, lee, game = 0;
//	std::cin >> game >> kim >> lee;
//	while (1) {
//		if (game & 1) game++;
//		game = game >> 1;
//		if ((kim <= game && lee > game) || (kim > game && lee <= game)) { break; }
//	}
//	int number=1;
//	int index = 0;
//	while (game > number) {
//		number *= 2; index++;
//	}
//	std::cout << index+1;
//	//std::cin >> index;
//}
int main() {
	int a, b, game, count = 0;
	std::cin >> game >> a >> b;
	while (a != b) {
		a = a / 2 + a % 2;
		b = b / 2 + b % 2;
		count++;
	}
	std::cout << count; 
}