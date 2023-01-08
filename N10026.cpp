#include<iostream>
using namespace std;

int n, result1, result2;
int dir[4][2] = { {1,0}, {-1,0}, {0,1}, {0,-1} };
char picture[101][101];
int visited1[101][101];
int visited2[101][101];

void input() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++)
			cin >> picture[i][j];
	}
}

void dfs1(int x, int y) {
	visited1[y][x] = 1;
	for (int i = 0; i < 4; i++) {
		int xx = x + dir[i][0];
		int yy = y + dir[i][1];
		if (picture[y][x] == picture[yy][xx] && !visited1[yy][xx])
			dfs1(xx, yy);
	}
}

void dfs2(int x, int y) {
	visited2[y][x] = 1;
	for (int i = 0; i < 4; i++) {
		int xx = x + dir[i][0];
		int yy = y + dir[i][1];
		if (picture[y][x] == 'G' || picture[y][x] == 'R') {
			if ((picture[yy][xx] == 'R' || picture[yy][xx]=='G') && !visited2[yy][xx])
				dfs2(xx, yy);
		}
		else if (picture[y][x] == 'B') {
			if (picture[y][x] == picture[yy][xx] && !visited2[yy][xx])
				dfs2(xx, yy);
		}
	}
}

void findResult() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (!visited1[i][j]) {
				dfs1(j, i);
				result1++;
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (!visited2[i][j]) {
				dfs2(j, i);
				result2++;
			}
		}
	}

	cout << result1 << ' ' << result2;
}

int main() {
	input();
	findResult();
	return 0;
}