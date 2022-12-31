#include<iostream>
using namespace std;

int n, top;
int tree[100001];

void swap(int a, int b) {
	int temp = tree[a];
	tree[a] = tree[b];
	tree[b] = temp;
}

void heap() {
	int num;
	for (int i = 0; i < n; i++) {
		cin >> num;
		if (num) {
			int temp;
			tree[++top] = num;
			temp = top;
			while (temp > 1) {
				if (tree[temp / 2] > tree[temp]) {
					swap(temp, temp / 2);
					temp /= 2;
				}
				else break;
			}
		}
		else {
			if (top) {
				int temp = 1;
				cout << tree[1] << '\n';
				tree[1] = tree[top];
				tree[top--] = 0;
				while (temp * 2 <= top) {
					int t;
					t = tree[temp * 2 + 1] != 0 ? (tree[temp * 2] > tree[temp * 2 + 1] ? temp * 2 + 1 : temp * 2) : temp * 2;
					if (tree[t] < tree[temp]) {
						swap(t, temp);
						temp = t;
					}
					else break;
				}
			}
			else 
				cout << 0 << '\n';
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	heap();
	return 0;
}