#include <iostream>  
#include <string>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

// main 
int main() {

	int count;
	cin >> count;
	set<string> string_set;

	for (int count_idx = 0; count_idx < count; count_idx++) {
		string sub_name, sub_work;
		cin >> sub_name >> sub_work;

		if (sub_work == "enter")
			string_set.insert(sub_name);
		else
			string_set.erase(sub_name);
	}

	for (auto iter = string_set.rbegin(); iter != string_set.rend(); iter++)
		cout << *iter << "\n";

	return 0;
}


