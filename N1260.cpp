#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int n, m, v;
int table[1001][1001];
int visited[1001];
vector <int>dfsResult;
vector <int>bfsResult;
queue <int>bfsQ;

void clear() {
	for (int i = 1; i <= n; i++)
		visited[i] = 0;
}

void input() {
	int a, b;
	cin >> n >> m >> v;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		table[a][b] = 1;
		table[b][a] = 1;
	}
}

void dfs(int start) {
	dfsResult.push_back(start);
	visited[start] = 1;
	for (int i = 1; i <= n; i++) {
		if (!visited[i] && table[start][i])
			dfs(i);
	}
}

void bfs(int start) {
	bfsQ.push(start);
	visited[start] = 1;
	bfsResult.push_back(start);
	while (!bfsQ.empty()) {
		int temp = bfsQ.front();
		for (int i = 1; i <= n; i++) {
			if (!visited[i] && table[temp][i]) {
				bfsQ.push(i);
				bfsResult.push_back(i);
				visited[i] = 1;
			}
		}
		bfsQ.pop();
	}
}

void output() {
	for (int i : dfsResult)
		cout << i << ' ';
	cout << '\n';
	for (int i : bfsResult)
		cout << i << ' ';
}

int main() {
	input();
	dfs(v);
	clear();
	bfs(v);
	output();
	return 0;
}