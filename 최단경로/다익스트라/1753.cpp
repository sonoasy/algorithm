#include<iostream>
#include<vector>
#include<queue>

#define INF 1e5*2

using namespace std;

typedef pair<int, int> ci;
//const int INF= 1e5 * 2;

vector<vector<ci>> graph;

vector<int> dijkstra(int start,int v) {
	vector<int>dist; //여기에 시작점으로부터 특정 정점까지 최단 거리 업데이트
	dist.assign(v + 1, INF);

	priority_queue<ci, vector<ci>, greater<>> q; //오름차순

	dist[start] = 0; //시작점은 거리 0
	
	q.push({ 0, start }); //거리, 정점
	//큐에는 의미있는 정보? 정점에 대한 거리 정보 갱신된거 

	while (!q.empty()) {

		int weight = q.top().first;
		int vertex = q.top().second;
		q.pop();

		if (weight > dist[vertex])continue;

		//dist[vertex] = weight;
		for (int i = 0; i < graph[vertex].size(); i++){

			
			int nextv = graph[vertex][i].first;
			int nextw = graph[vertex][i].second + dist[vertex];
			
			if (dist[nextv] > nextw) {

				dist[nextv] = nextw;
				q.push({ nextw, nextv });


			}



		}


	}
	return dist;

}


int main() {

	int v, e, k; //점점,간선, 시작
	int u, v2, w;
	cin >> v >> e >> k;
	graph.assign(v + 1, vector<ci>());
	
	while (e--) {

		//u->v, w
		cin >> u >> v2 >> w;
		graph[u].emplace_back(v2, w); //u에 연결된 정점 v, 가중치 w


	}

	
	vector<int> ans= dijkstra(k, v);

	for (int i = 1; i < ans.size(); i++) {

		if (ans[i] == INF)cout << "INF"<<'\n';
		else cout << ans[i] << '\n';
	}

}
