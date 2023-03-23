#include<vector>
#include<iostream>
#include<queue>

using namespace std;

//재귀로 조합구하기 
vector<int>arr = { 1,2,3,4,5 };
vector<int>visited = { false,false,false,false,false };

void dfs(int idx, int cnt) {

	if (cnt == 3) {

		for (int i = 0; i < 5; i++) {
			if (visited[i])cout << arr[i] << ' ';
		}
		cout << '\n';
		return; 
	}

	for (int i = idx; i < 5; i++) {

		if (visited[i])continue;
		visited[i] = true;

		dfs(i, cnt + 1);
		visited[i] = false;

	}
}



int main() {
   
  	dfs(0, 0);



}
