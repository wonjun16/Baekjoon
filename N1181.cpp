#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

bool compare(string a, string b) {
	if (a.length() == b.length()) {
		return a < b;
	}
	else
		return a.length() < b.length();
}

int main() {
	int N; cin >> N;
	vector<string> word(N);
	for (int i = 0; i < N; i++)
		cin >> word[i];
	sort(word.begin(), word.end(), compare);
	cout << word[0]<<endl;
	for (int i = 1; i < N; i++){
		if (word[i - 1] == word[i])
			continue;
		cout << word[i] << endl;
	}
	return 0;
}