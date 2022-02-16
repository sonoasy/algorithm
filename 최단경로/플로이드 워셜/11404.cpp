#include<iostream>
#include<vector>

using namespace std;

vector<vector<int>>graph;
const int INF = 1e7; //크기 정확하게 계산 안하면 틀림

void Floydwarshall(int n, vector<vector<int>>& graph) {

	for (int i = 1; i <=n; i++) {
		for (int j = 1; j <=n; j++) {
			for (int k = 1; k <= n; k++) {
				int dist = graph[j][i] + graph[i][k];
				graph[j][k] = min(graph[j][k], dist);

			}
		}
	}



}

int main() {


	int n, m, a, b, c;

	cin >> n >> m;

	graph.assign(n + 1, vector<int>(n + 1, INF));
	for (int i = 1; i <= n; i++) {
		graph[i][i] = 0;
	}

	while (m--) {

		cin >> a >> b >> c;

		if(c<graph[a][b])graph[a][b] = c;

	}
	Floydwarshall(n, graph);

	for (int i = 1; i <= n; i++) {
		for (int j =1; j <= n; j++) {
			cout<<(graph[i][j] == INF?0:graph[i][j])<<' ';

		}
		cout << '\n';
	}




	return 0;
}
