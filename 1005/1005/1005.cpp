# include <iostream>

using namespace std;

class Building {
public:
	bool	buildingAlready = false;
	bool	buildingFlag=false;
	int		buildingNeed[10] = {-1};
	int		buildingNext[10] = {-1};
	int		buildingTime;
	int		buildingTotalTime= 0;

	Building() {}

};

int main() {
	int testCase, testcount = 0;
	int building_NO, condition;
	cin >> building_NO >> condition;
	Building *building = new Building[building_NO];
	cin >> testCase;
	
	while (testCase > testcount) {

		for (int i = 0; i < building_NO; i++) {
			cin >> building[i].buildingTime;
		}

		for (int i = 0; i < condition; i++) {
			int tempnumber = 0;
			cin >> tempnumber;

			for (int i = 0; i < 10; i++) {
				if (building[tempnumber].buildingNext[i] == -1) {
					cin >> building[tempnumber].buildingNext[i];
					break;
				}
			}

		}
		testcount++;
	}
	
	for (int i = 0; i < building_NO; i++) {
		for (int j = 0; j < 9; j++) {
			cout << building[i].buildingNext[j];
		}
		
	}
	cin >> condition;

	

	return 0;
}