#include<iostream>
#include<algorithm>
using namespace std;

int censer[10000];
int Distance[10000];
int result;

int main() {
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++)
		cin >> censer[i];
	sort(censer, censer + n);
	for (int i = 0; i < n - 1; i++)
		Distance[i] = censer[i + 1] - censer[i];
	sort(Distance, Distance + n - 1);
	for (int i = 0; i < n - k; i++)
		result += Distance[i];
	cout << result;
	return 0;
}