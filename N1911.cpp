#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

vector<pair<int, int>> v;
int result = 0;

void input(int n) {
	int start, end;
	for (int i = 0; i < n; i++) {
		cin >> start >> end;
		v.push_back(pair<int, int>(start, end));
	}

	sort(v.begin(), v.end());
}

void findResult(int n, int l) {
	int now = 0;
	for (int i = 0; i < n; i++) {
		if (v[i].second <= now) continue;
		if (now < v[i].first) now = v[i].first;
		if ((v[i].second - now) % l) {
			result += (v[i].second - now) / l + 1;
			now += ((v[i].second - now) / l + 1) * l;
		}
		else {
			result += (v[i].second - now) / l;
			now = v[i].second;
		}
	}
}

int main() {
	int n, l;
	cin >> n >> l;
	input(n);
	findResult(n, l);
	cout << result;
	return 0;
}