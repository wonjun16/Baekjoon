#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

bool compare(string a, string b) {
	if (a.length() == b.length()) {
		int sumA = 0, sumB = 0;
		for (int i = 0; i < a.length() ; i++) {
			if (a[i]-'0'<=9 )//&& a[i]-'0'>=0)
				sumA += a[i]-'0';
		}
		for (int i = 0; i < b.length() ; i++) {
			if (b[i]-'0'<=9 )//&& b[i]-'0'>=0)
				sumB += b[i]-'0';
		}
		if (sumA != sumB)
			return sumA < sumB;
		else
			return a < b;
	}
	else
		return a.length() < b.length();
}

int main() {
	int n; cin >> n;
	vector<string> word(n);
	for (int i = 0; i < n; i++)
		cin >> word[i];
	sort(word.begin(), word.end(), compare);
	for (int i = 0; i < n; i++)
		cout << word[i] << endl;
	return 0;
}