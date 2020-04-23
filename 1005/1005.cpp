# include <iostream>

using namespace std;

class Building {
public:
	int		buildingNeed[10] = {};
	int		buildingTime=0;
	int		buildingTotalTime=0;
	Building() {
		fill_n(buildingNeed, 10, -1);
		
	}
};
int main() {
	int testCase, testcount = 0;
	cin >> testCase;
	int *result = new int[testCase];
	result[testCase] = {0};
	while (testCase > testcount) {
		int building_NO, condition, BuildingLast=0;
		cin >> building_NO >> condition;
		Building *building = new Building[building_NO];
		//insert build time
		for (int i = 0; i < building_NO; i++) {cin >> building[i].buildingTime;}
		// have to build first
		for (int i = 0; i < condition; i++) {
			int needNumber = 0; int buildingNumber = 0;
			cin >> needNumber >> buildingNumber;
			needNumber--, buildingNumber--;
			for (int j = 0; j < 10; j++) {
				if (building[buildingNumber].buildingNeed[j] == -1) {
					building[buildingNumber].buildingNeed[j] = needNumber;
					break;
				}
			}
		}
		// calculate the total_buildtime for each building
		for (int i = 0; i < building_NO; i++) {
			int tempMax=0;
			for (int j = 0; j < 10; j++) {
				if (building[i].buildingNeed[j] == -1) continue;
				int needBuildingIndex = building[i].buildingNeed[j];
				if (building[needBuildingIndex].buildingTotalTime >= tempMax) {
					tempMax = building[needBuildingIndex].buildingTotalTime;
				}
			}
			building[i].buildingTotalTime = tempMax + building[i].buildingTime;
		}
		cin >> BuildingLast;
		result[testcount] = building[BuildingLast-1].buildingTotalTime;
		testcount++;
		
		
	}
	for (int i = 0; i < testCase; i++) {
		cout << result[i] << endl;
	}
	delete[] result;
	
	return 0;
}