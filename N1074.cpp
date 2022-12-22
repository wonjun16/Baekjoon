#include<iostream>
#include<cmath>
using namespace std;

__int64 n, r, c, result;

void findResult(int n) {
	if (n == 0) return;
	int k = 2 * (n - 1);
	int p = pow(2, n - 1), h = pow(2, k);
	if (p > r && p > c) {
		result += h * 0;
		findResult(n - 1);
	}
	else if (p <= r && p > c) {
		result += h * 2;
		r -= p;
		findResult(n - 1);
	}
	else if (p > r && p <= c) {
		result += h * 1;
		c -= p;
		findResult(n - 1);
	}
	else if (p <= r && p <= c) {
		result += h * 3;
		r -= p;
		c -= p;
		findResult(n - 1);
	}
}

int main() {
	cin >> n >> r >> c;
	findResult(n);
	cout << result;
	return 0;
 }