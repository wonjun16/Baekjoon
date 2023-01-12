#include<iostream>
using namespace std;

int n;
int table[1001][3];
int rgb[1001][3];

void input() {
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> rgb[i][0] >> rgb[i][1] >> rgb[i][2];
}

void dp() {
	for (int i = 1; i <= n; i++) {
		int temp0 = table[i - 1][1] > table[i - 1][2] ? table[i - 1][2] : table[i - 1][1];
		int temp1 = table[i - 1][0] > table[i - 1][2] ? table[i - 1][2] : table[i - 1][0];
		int temp2 = table[i - 1][1] > table[i - 1][0] ? table[i - 1][0] : table[i - 1][1];
		table[i][0] = rgb[i][0] + temp0;
		table[i][1] = rgb[i][1] + temp1;
		table[i][2] = rgb[i][2] + temp2;
	}
}

int main() {
	input();
	dp();
	int result = (table[n][0] > table[n][1] ? table[n][1] : table[n][0]) > table[n][2] ? table[n][2] : (table[n][0] > table[n][1] ? table[n][1] : table[n][0]);
	cout << result;
	return 0;
}