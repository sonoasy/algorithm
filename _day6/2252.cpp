#include<iostream>
#include<vector>
#include<queue>

using namespace std;

//인접리스트 
//차수 
//큐

int main() {
	//학생 수, 비교 횟수 
	int n, m;
	cin >> n >> m;

	vector<vector<int>>arr;
	vector<int>indegree;
	arr.assign(n + 1, vector<int>());
	indegree.assign(n + 1,0);
	//인접리스트를 어떻게 해야할지 약간 고민됨
	int a, b;
	while (m--) {
		cin >> a >> b;
		arr[a].push_back(b);
		indegree[b]++;
	}

	queue<int>q;
	for (int i = 1; i <= n; i++) {
		if (indegree[i] == 0) {
			q.push(i);
		}
	}
	while (!q.empty()) {

		//근데 큐를 넣고 뭘하는거지?
		//출력이먄
		int top = q.front();
		cout << top << ' ';
		q.pop();
		for (int i = 0; i < arr[top].size(); i++) {
			indegree[arr[top][i]]--;
			if (indegree[arr[top][i]] == 0) {
				q.push(arr[top][i]);
			}
		}


	}

	


}
