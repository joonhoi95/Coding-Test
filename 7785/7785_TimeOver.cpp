#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;


int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	vector<string> P;
	int NO_Record = 0;
	string name = "";
	string condition = "";
	cin >> NO_Record;
	for (int i = 0; i < NO_Record; i++) {
		cin >> name;
		cin >> condition;
		if (condition.front() == 'e') {
			P.push_back(name);
		}
		else if (condition.front() == 'l') 
		{
			P.erase(remove(P.begin(), P.end(), name), P.end());
		}
	}
	sort(P.begin(), P.end(), greater<string>());

	for (int i = 0; i < P.size(); i++) {
		cout << P[i] << "\n";
	}
}


