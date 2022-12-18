#include<iostream>
#include<algorithm>
using namespace std;

int row, col;
int road[501][501];
int table[501][501];

int dx[] = { 0, 0, -1, 1 };
int dy[] = { 1, -1, 0, 0 };

void setup() {
	for (int i = 1; i <= row; i++)
		for (int j = 1; j <= col; j++) {
			cin >> road[i][j];
			table[i][j] = -1;
		}
}

int dp(int y, int x) {
	if (x == col && y == row) return 2;
	if (table[y][x] == -1) {
		table[y][x] = 0;
		for (int i = 0; i < 4; i++) {
			if (road[y][x] > road[y + dy[i]][x + dx[i]])
				table[y][x] += dp(y + dy[i], x + dx[i]);
		}
	}
	return table[y][x];
}

int main() {
	cin >> row >> col;
	setup();
	cout << dp(1, 1);
	return 0;
}