#include<iostream>
#include<deque>
#include<cstring>
using namespace std;

int m, n, h, result, e1, e2, xx, yy, zz;
int box[102][102][102];
int dir[6][3] = { {1,0,0}, {-1,0,0}, {0,1,0}, {0,-1,0}, {0,0,1}, {0,0,-1} };
deque <pair<pair<int, int>,int>> v;

void input() {
	cin >> m >> n >> h;
	for (int i = 1; i <= h; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= m; k++) {
				cin >> box[i][j][k];
				if (box[i][j][k] == 1) {
					v.push_back({ {k,j},i });
					e2++;
				}
				if (box[i][j][k] == -1)
					e1++;
			}
		}
	}
}

void tomato() {
	while (!v.empty()) {
		int size = v.size();
		for(int s=0;s<size;s++){
			int x = v.back().first.first;
			int y = v.back().first.second;
			int z = v.back().second;
			v.pop_back();
			for (int i = 0; i < 6; i++) {
				xx = x + dir[i][0];
				yy = y + dir[i][1];
				zz = z + dir[i][2];
				if (box[zz][yy][xx] == 0) {
					box[zz][yy][xx] = 1;
					v.push_front({ {xx,yy},zz });
					e2++;
				}
			}
		}
		result++;
	}

	if (e1 + e2 != m * n * h)
		cout << -1;
	else
		cout << result - 1;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	memset(box, -1, sizeof(box));
	input();
	tomato();
	return 0;
}