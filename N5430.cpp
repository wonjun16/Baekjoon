#include<iostream>
#include<string>
#include<deque>
using namespace std;

int t, n;
string p;
deque <int> v;

void input() {
	char c;
	int num;
	cin >> p;
	p = p + '\0';
	cin >> n;
	if (n) {
		while (n != v.size()) {
			cin >> c;
			cin >> num;
			v.push_back(num);
		}
	}
	else
		cin >> c;
	cin >> c;
}

void ac() {
	for (int i = 0; i < t; i++) {
		v.clear();
		input();
		string result;
		int index = 0, flag = 1, front = 0, back = 0, size = v.size();
		
		while (p[index]) {
			if (p[index] == 'R')
				flag++;
			else if (p[index] == 'D') {
				if (size<=front+back) {
					result = "error";
					break;
				}
				else if (flag % 2)
					front++;
				else
					back++;
			}
			index++;
		}

		if (result != "error") {
			cout << '[';
			if (flag % 2) {
				int cersor = 0;
				for (int i : v) {
					if (cersor >= front) {
						if (cersor == n - back - 1) {
							cout << i;
							break;
						}
						else
							cout << i << ',';
					}
					cersor++;
				}
			}
			else {
				int cersor = n;
				for (auto i = v.rbegin(); i < v.rend(); i++) {
					if (cersor <= n - back) {
						if (cersor == front + 1) {
							cout << *i;
							break;
						}
						else
							cout << *i << ',';
					}
					cersor--;
				}
			}
			cout << ']' << '\n';
		}
		else
			cout << result << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> t;
	ac();
	return 0;
}