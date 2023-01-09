#include<iostream>
#include<algorithm>
using namespace std;

int n, result;
int dir[4][2] = { {1,0}, {-1,0}, {0,1}, {0,-1} };
int v[26][26], visited[26][26], num[440];
char c;

void input() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> c;
			v[i][j] = c - '0';
		}
	}
}

void search(int x, int y) {
	visited[y][x] = 1;
	num[result]++;
	for (int i = 0; i < 4; i++) {
		int xx = x + dir[i][0];
		int yy = y + dir[i][1];
		if (xx >= 1 && xx <= n && yy >= 1 && yy <= n && !visited[yy][xx] && v[yy][xx])
			search(xx, yy);
	}
}

void dfs() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (v[i][j] && !visited[i][j]) {
				result++;
				search(j, i);
			}
		}
	}
}

void output() {
	cout << result << '\n';
	for (int i = 1; i <= result; i++)
		cout << num[i] << '\n';
}

int main() {
	input();
	dfs();
	sort(num + 1, num + result+1);
	output();
	return 0;
}