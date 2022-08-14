#include<iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, data; cin >> n;
	int max[10001] = { 0 };
	for (int i = 0; i < n; i++) {
		cin >> data;
		max[data]++;
	}
	for (int i = 1; i <10001; i++) {
		for (int j = 0; j < max[i];j++)
			cout << i << '\n';
	}
	return 0;
}