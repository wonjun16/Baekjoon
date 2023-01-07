#include<iostream>
#include<set>
using namespace std;

int t, n, num;
char c;
multiset <int> heap;

void multiHeap() {
	cin >> t;
	for (int i = 0; i < t; i++) {
		
		cin >> n;
		for (int j = 0; j < n; j++) {
			
			cin >> c;
			cin >> num;

			if (c == 'I')
				heap.emplace(num);
			else {
				if (num == 1 && !heap.empty())
					heap.erase(--heap.end());
				if (num == -1 && !heap.empty())
					heap.erase(heap.begin());
			}

		}

		if (!heap.size())
			cout << "EMPTY" << '\n';
		else
			cout << *(--heap.end())  << ' ' << *heap.begin() << '\n';

		heap.clear();

	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	multiHeap();
	return 0;
}