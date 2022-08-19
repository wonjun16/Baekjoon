#include<iostream>
using namespace std;

int tiling(int x, int memo[]) {
	if (memo[x]) return memo[x];
	else 
		return memo[x] = (tiling(x-1, memo) + tiling(x-2, memo))%10007;
}

int main() {
	int memo[1001] = { 0, 1, 2, 0, }, n; cin >> n;
	tiling(n, memo);
	cout << memo[n];
	return 0;
}