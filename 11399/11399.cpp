#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	vector<int> Line;
	int wait=0;
	int temp=0;
	int total = 0;
	cin >> wait;
	//Line.resize(wait);
	for (int i = 0; i < wait; i++) {
		cin >> temp;
		Line.push_back(temp);
	}
	sort(Line.begin(), Line.end());
	for (int i = 0; i < wait; i++) {
		total += (5 - i) * Line[i];
	}
	cout << total;
	cin >> wait;
}