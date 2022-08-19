#include<iostream>
using namespace std;
int dp(int memo[], int x) {
	if (memo[x]) return memo[x];
	else return memo[x] = (dp(memo, x - 1) + 2*dp(memo, x - 2)) % 10007;
}
int main() {
	int memo[1001] = { 0, 1, 3, 5, 0, }, n; cin >> n;
	dp(memo, n);
	cout << memo[n];
	return 0;
}