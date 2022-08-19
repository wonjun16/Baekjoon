#include<iostream>
using namespace std;

//dp[x]=3*dp[x-2] + 2*(dp[x-4]+dp[x-6]...+dp[0])
int dp(int memo[], int x) {
	if (x % 2) return 0;
	if (memo[x]) return memo[x];
	else {
		memo[x] = (3 * dp(memo, x - 2));
		for (int i = x - 4; i >= 0; i -= 2)
			memo[x] += 2 *memo[i];
	}
	return memo[x];
}

int main() {
	int memo[31] = { 1,0,3,0, }, n; cin >> n;
	dp(memo, n);
	cout << memo[n];
	return 0;
}