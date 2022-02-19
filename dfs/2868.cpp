#include<iostream>
#include<vector>

using namespace std;

vector<vector<int>>b;

int dr[4] = { 0,0,-1,1 };
int dc[4] = { 1,-1,0,0 };

typedef pair<int, int> ci;

void dfs(int n, int m, int r, int c) {

	if (r < 0 || r >= n || c < 0 || c >= m || b[r][c] != 0) return;

	b[r][c] = -1;
	for (int i = 0; i < 4; i++) {
		dfs(n, m, r + dr[i], c + dc[i]);

	}

}

bool air(int i, int j) {

	int cnt = 0;
	for (int k = 0; k < 4; k++) {
		int nr = i + dr[k];
		int nc = j + dc[k];
		if (b[nr][nc] == -1)cnt++;

	}
	return cnt >= 2;

}



vector<ci> findchese(int n, int m) {
	vector<ci> p;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (b[i][j] == 1 && air(i, j))
				p.emplace_back(i, j);
		}
	}
	return p;
}



int main() {
	int ans = 0;

	int n, m;
	cin >> n >> m;
	b.assign(n, vector<int>(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> b[i][j];

		}
	}

	//외부 공기 처리 
	dfs(n, m, 0, 0);

	while (1) {

		vector<ci> list = findchese(n, m);
		if (list.empty())break;
		for (int i = 0; i < list.size(); i++) {
			int r = list[i].first;
			int c = list[i].second;
			b[r][c] = 0;
			//?
			dfs(n, m, r, c);


		}
		ans++;


	}
	cout << ans;
	return 0;
}
