#include<iostream>
#include<algorithm>
using namespace std;

int a[1001], maxValue;
int table[1001];

void dp(int n) {
	for (int i = 1; i <= n; i++) {
		table[i] = 1;
		for (int j = 1; j <= i; j++) {
			if (a[i]<a[j] && table[j] + 1>table[i])
				table[i]++;
		}
	}
}

int findMax(int n) {
	int max = table[1];
	for (int i = 1; i <= n; i++)
		if (max < table[i])
			max = table[i];
	return max;
}

int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	dp(n);
	cout <<findMax(n);

	return 0;
}