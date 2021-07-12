#include<iostream>
#include<stack>
#include<vector>
#include<algorithm>
#include<stdio.h>
#include<queue>

using namespace std;
//DFS
//그래프 초기화,정점 갯수, 간선 삽입 연산, 깊이 우선 탐색(연결 정점 탐색&방문 여부 체크)

//깊이 우선 탐색- 스택
void dfs(int start, vector<int>graph[], vector<bool> check) {
	//graph는 정점 연결, check는 정점이 방문되었는지 체크 

	//1.스택형성
	stack<int>s; //정점 추가 스택

	//초기 정점 추가
	//방문하면 스택에 넣기
	s.push(start);
	check[start] = true;
	//방문한 정점 출력
	printf("%d", start);


	while (!s.empty()) {

		//현재 위치
		int current_node = s.top();
		s.pop();

		//연결된 정점들 하나씩 탐색
		for (int i = 0; i < graph[current_node].size(); i++) {

			int next_node = graph[current_node][i];

			//방문 안했으면 방문하고 스택에 넣기
			//한개라도 있으면 해결될때까지 기다려야함
			if (check[next_node] == false) {
				check[next_node] = true;
				printf("%d ", next_node);
				//이전에 pop한거 다시 다같이 넣기
				s.push(current_node);
				s.push(next_node);
				break;

			}

		}


	}


}

int main() {
	//n은 정점의 갯수, m은 간선 갯수, start는 시작 정점
	int n, m, start;
	cin >> n >> m >> start;


	vector<int> *graph=new vector<int>[n + 1];
	//방문 체크하는 배열 초기화는 false
	vector<bool> check(n+1,false);
	
	for (int i = 0; i < m; i++) {
		//연결되어 있는 정점
		int u, v;
		cin >> u >> v;

		//간선 연결 u-v , v-u 둘다 하기 
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	//순차 접근하기 위해 정렬
	for (int i = 1; i <= n; i++) {
		sort(graph[i].begin(), graph[i].end());
	}

	dfs(start, graph, check);
	printf("\n");

	return 0;



}
