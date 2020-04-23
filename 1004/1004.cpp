#include <iostream>
#include <math.h>
using namespace std;

class STEND_info {
	public:
	
		int startx,starty,endx,endy;
	
	STEND_info() {}

};

class Space_info {
	public:
		int x, y, r;
		Space_info() {}

};

int main() {
	int Test_No=0;
	int Test_Count=1;
	int Space_No;
	//cout << "Number of Test: ";
	cin >> Test_No;
	int *result = new int[Test_No];
	STEND_info Little_prince = STEND_info();

	while (Test_Count <= Test_No) {
		int route=0;
		cin >> Little_prince.startx >> Little_prince.starty >> Little_prince.endx >> Little_prince.endy;
		//cout << "space: ";
		cin >> Space_No;
		Space_info *space = new Space_info[Space_No];
		for (int i = 0; i < Space_No; i++) {
			cin >> space[i].x >> space[i].y >> space[i].r;
		}
		
		for (int i = 0; i < Space_No; i++) {
			double temp_dist1 = ((space[i].x-Little_prince.startx) * (space[i].x-Little_prince.startx))+
				((space[i].y - Little_prince.starty) * (space[i].y - Little_prince.starty));
			double temp_dist2 = ((space[i].x - Little_prince.endx) * (space[i].x - Little_prince.endx)) +
				((space[i].y - Little_prince.endy) * (space[i].y - Little_prince.endy));
			if (space[i].r > sqrt(temp_dist1)) {
				if (space[i].r < sqrt(temp_dist2)) {
					route++;
				}
			}
			else {
				if (space[i].r > sqrt(temp_dist2)) {
					route++;
				}
			}
		}
		result[Test_Count-1] = route;
		Test_Count++;
	}
	for (int i=0; i<Test_No;i++)
		cout << result[i] << "\n";
	delete[] result;
	return 0;
}