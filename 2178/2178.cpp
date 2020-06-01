#include <iostream>
#include <vector>
# define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)
using namespace std;

int maze[100][100] = { 0 };			// Maze
int visit[100][100] = { 0 };		// Y,N visit
int count_path[100][100] = { 0 };	// depth

int x_move[4] = { 0, -1, 0, 1};		//Move Combination
int y_move[4] = { 1, 0, -1, 0 };
int width, height;

void Escape(int x, int y) {
	visit[x][y] = 1;
	//if (x <= 0 || y <= 0 || x > width || y > height) return;
	//cout << "now" << x << ", " << y << endl;
	for (int i = 0; i < 4; i ++) {
		int t_x = x + x_move[i];
		int t_y = y + y_move[i];
		if (t_x <= 0 || t_y <= 0 || t_x > width || t_y > height) continue;
		if (maze[t_x][t_y] == 0) continue;
		
		if (visit[t_x][t_y] == 1)
		{
			if (count_path[t_x][t_y] <= count_path[x][y] + 1)  continue;
			else count_path[t_x][t_y] = count_path[x][y] + 1;
		}
		else count_path[t_x][t_y] = count_path[x][y] + 1;
		Escape(t_x, t_y);
	}
}

int main() {
	cin >> width >> height;
	for (int i = 1; i <= width; i++)
	{
		for (int j = 1; j <= height; j++) 
		{
			scanf("%1d", &maze[i][j]);
		}
	}
	count_path[1][1] = 1;
	Escape(1,1);
	cout << count_path[width][height];
	//return 0;
	cin >> width;
}
