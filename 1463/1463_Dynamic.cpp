#include <iostream>
#include <algorithm>
#include <cstring>
class MakeOne {
private:
	int num;
	int count[10000];

	
public:
	void set() {
		std::cin >> num;
		std::memset(count, 0, sizeof(int)* (num + 1));
	}

	void resolve() {
		count[1] = 0;
		for (int i = 2; i <= num; i++) {
			count[i] = count[i - 1] + 1;
			if (i % 2 == 0) { count[i] = std::min(count[i], count[i / 2] + 1); }
			if (i % 3 == 0) { count[i] = std::min(count[i], count[i / 3] + 1); }
		}
		std::cout << count[num];
	}
};

int main() {
	MakeOne one;
	one.set();
	one.resolve();
	return 0;
}

