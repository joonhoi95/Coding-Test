#include <iostream>
#include <vector>
using namespace std;



int main() {
	int test, start, end, count;
	cin >> test;
	count = test;
	vector<int> result;
	while (test--) {
		cin >> start >> end;
		vector<vector<int> > arr(start+1, vector<int>(end+1, 0));
		for (int j = 1; j <= end; j++) {
			arr[1][j] = j;
		}
		for (int i = 2; i <= start; i++) {
			for (int j = i; j <= end; j++) {
				for (int k = j; k >=i ; k--) {
					arr[i][j] += arr[i - 1][k-1];
				}
			}
		}
		result.push_back(arr[start][end]);
	}
	for (int i = 0; i < count; i++) {
		cout << result[i] << endl;
	}
}

