#include<iostream>
using namespace std;

int n;
int picture[65][65];

void input() {
	char c;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> c;
			picture[i][j] = c - '0';
		}
	}
}

void quad(int size, int x, int y) {
	if (size == 0) return;
	int flag = 0;

	for (int i = y; i < y + size;i++) {
		for (int j = x; j < x + size; j++) {
			if (picture[y][x] != picture[i][j]) flag = 1;
		}
	}

	if (flag) {
		cout << '(';
		quad(size / 2, x, y);
		quad(size / 2, x + size / 2, y);
		quad(size / 2, x, y + size / 2);
		quad(size / 2, x + size / 2, y + size / 2);
		cout << ')';
	}
	else cout << picture[y][x];
}

int main() {
	input();
	quad(n, 1, 1);
	return 0;
}