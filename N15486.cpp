#include<iostream>
#include<algorithm>
using namespace std;

int n;
int work[1500001][2];
int table[1500001];

void dp(int n) {
	for (int i = 1; i <= n; i++) {
		int k = max(i - 50, 1);
		int maxValue = table[i - 1];
		maxValue = work[i][0] == 1 ? maxValue + work[i][1] : maxValue;
		for (int j = k; j <= i; j++) {
			if (work[j][0] + j - 1 == i && maxValue<work[j][1]+table[j - 1]) {
				maxValue = work[j][1] + table[j - 1];
			}
		}
		table[i] = maxValue;
	}
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> work[i][0] >> work[i][1];
	}
	dp(n);
	cout << table[n];
	return 0;
}