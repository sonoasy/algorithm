#include<iostream>
#include<vector>

using namespace std;

vector<vector<int>>b;

int dr[4] = { 0,0,-1,1 };
int dc[4] = { 1,-1,0,0 };

typedef pair<int, int> ci;
//탐색하면서 치즈가 녹을수 있으면 바로녹이고 dfs vs 리스트에 담아서 나중에 처리하고 dfs 차이는 녹을수 있는지를 확인하는것!!! 녹이고 주위 공기 갱신하는건 상관없음

void dfs(int n, int m, int r, int c) { //dfs를 치즈가 녹을때마다 모든 격자를 탐색하는걸로 생각했는데 이미 갱신이 되었으므로 치즈가 녹은 주변만 새로 갱신하면 됨 

	
	if (r < 0 || r >= n || c < 0 || c >= m || b[r][c] != 0) return;

	b[r][c] = -1;
	for (int i = 0; i < 4; i++) {
		//if (r+dr[i] >= 0 && r+dr[i] < n && c+dc[i] >= 0 && c+dc[i] < m && b[r+dr[i]][c+dc[i]] == 0){ 이렇게 해도됨
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
