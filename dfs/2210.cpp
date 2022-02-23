#include<iostream>
#include<vector>

using namespace std;

int board[5][5];
vector<bool>v;

int dr[4] = { 0,0,1,-1 };
int dc[4] = { 1,-1,0,0 };
void dfs(int r, int c, int cnt, int sum) {

	if (cnt == 5) {
		if (v[sum] == false)v[sum] = true;
		return;

	}
	for (int i = 0; i < 4; i++) {
		int nr = r + dr[i];
		int nc = c + dc[i];
		if (nr >= 0 && nr < 5 && nc >= 0 && nc < 5) {
			dfs(nr, nc, cnt + 1, sum * 10 + board[nr][nc]);
		}
	}
	



}


int main() {

	v.assign(1000000, false);
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			cin >> board[i][j];
		}
	}

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {

			dfs(i, j, 0, board[i][j]);


		}
	}
	int cnt = 0;
	for (int i = 0; i < v.size(); i++) {
		if (v[i] == true)cnt++;

	}
	cout << cnt;




	return 0;
}
