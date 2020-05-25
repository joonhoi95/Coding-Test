#include <iostream>
#define MAX 51
int map[MAX][MAX] = { 0 };
bool check[MAX][MAX] = { 0 };
int total_insect = 0;

void init() {
	total_insect = 0;
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) {
			map[i][j] = 0;
			check[i][j] = 0;

		}
	}

}

void search(int x, int y) {
	check[x][y] = 1;
	if (x > 0) { if ((map[x - 1][y] == 1) && (check[x - 1][y] != 1))  search(x - 1, y);}
	if (x < 50) { if((map[x + 1][y] == 1) && (check[x + 1][y] != 1)) search(x + 1, y); }
	if (y > 0) { if ((map[x][y - 1] == 1) && (check[x][y - 1] != 1)) search(x, y - 1); }
	if (y < 50) { if((map[x][y + 1] == 1) && (check[x][y + 1] != 1)) search(x, y + 1); }
}

int main() {
	int testCase = 0;
	int hori = 0, verti = 0;
	int t_hori = 0, t_verti = 0;
	int cabbage = 0;
	std::cin >> testCase;

	while (testCase--) {
		init();
		std::cin >> hori >> verti >> cabbage;
		for (int i = 0; i < cabbage; i++) {
			std::cin >> t_hori >> t_verti;
			map[t_hori][t_verti] = 1;
		}
		for (int i = 0; i < MAX; i++) {
			for (int j = 0; j < MAX; j++) {
				if (map[i][j] == 0) { continue; }
				if (check[i][j] == 1) { continue; }
				search(i, j);
				total_insect++;
			}
		}
		std::cout << total_insect << std::endl;
	}
}

