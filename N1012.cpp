#include<iostream>
#include<algorithm>
using namespace std;

int t, m, n, k,x, y, result;
int space[51][51];
int visited[51][51];

void resetSpace() {
	for (int i = 1; i < 51; i++) {
		for (int j = 1; j < 51; j++)
			space[i][j] = 0;
	}
}

void resetVisited() {
	for (int i = 1; i < 51; i++) {
		for (int j = 1; j < 51; j++)
			visited[i][j] = 0;
	}
}

void findVisited(int x, int y) {
	visited[y][x] = 1;
	if (space[y][x + 1] == 1 && visited[y][x + 1] == 0)
		findVisited(x + 1, y);
	if (space[y][x - 1] == 1 && visited[y][x - 1] == 0)
		findVisited(x - 1, y);
	if (space[y + 1][x] == 1 && visited[y + 1][x] == 0)
		findVisited(x, y + 1);
	if (space[y - 1][x] == 1 && visited[y - 1][x] == 0)
		findVisited(x, y - 1);
}

void findResult() {
	result = 0;
	for (int i = 1; i < n+1; i++) {
		for (int j = 1; j < m+1; j++) {
			if (space[i][j] == 1 && visited[i][j] == 0) {
				findVisited(j, i);
				cout << i << ' ' << j << endl;
				result++;
			}
		}
	}
}

void input_result() {
	cin >> t;

	for (int i = 0; i < t; i++) {
		cin >> m >> n >> k;
		resetSpace();
		resetVisited();
		for (int j = 0; j < k; j++) {
			cin >> x >> y;
			space[y+1][x+1] = 1;
		}

		findResult();
		cout << result << endl;
	}

}

int main() {
	input_result();
	return 0;
}