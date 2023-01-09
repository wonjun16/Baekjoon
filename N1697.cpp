#include<iostream>
#include<queue>
#define SIZE 100001
using namespace std;

int n, k, result;
int visited[SIZE];
queue <int> q;

void search(int x) {
	visited[x] = 1;
	q.push(x);
}

void bfs(int x) {
	search(x);
	while (!visited[k]) {
		int sizeq = q.size();
		for (int i = 0; i < sizeq; i++) {
			int frontq = q.front();
			if (frontq + 1 < SIZE && !visited[frontq + 1] ) search(frontq + 1);
			if (frontq - 1 >= 0 && !visited[frontq - 1] ) search(frontq - 1);
			if (frontq * 2 < SIZE && !visited[frontq * 2] ) search(frontq * 2);
			q.pop();
		}
		result++;
	}
}

int main() {
	cin >> n >> k;
	bfs(n);
	cout << result;
	return 0;
}