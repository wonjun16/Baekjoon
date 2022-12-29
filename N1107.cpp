#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

int channel, n, button, result=0xf3f3f3;
vector <int> v = { 0,1,2,3,4,5,6,7,8,9 };

void input() {
	cin >> channel;
	cin >> n;
	if (n > 0) {
		for (int i = 0; i < n; i++) {
			cin >> button;
			v.erase(remove(v.begin(), v.end(), button), v.end());
		}
	}
}

void findResult(string num) {
	for (int i : v) {
		string temp = num + to_string(i);
		result = abs(stoi(temp)-channel)+temp.size() >result ? result : abs(stoi(temp) - channel)+temp.size();
		if (temp.size() < 6)
			findResult(temp);
	}
}

int main() {
	input();
	findResult("");
	result = result > abs(channel - 100) ? abs(channel - 100) : result;
	cout  << result;
	return 0;
}