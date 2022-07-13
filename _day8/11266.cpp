#include<iostream>
#include<vector>

using namespace std;


int v, e, a, b;

vector<int>al[10001]; //연결관계 표시 

int order; //방문 순서 

int dfs(int, int); //minorder을 출력하는거 
int visitorder[10001];//몇번째 방문했는지 
int cutvertext[10001]; //단절점 체크 
int answer[10001],s_Ans; //출력할 단절점 정보와 갯수 

int main() {

	cin >> v >> e;
	for (int i = 0; i < e; i++) {
		cin >> a >> b;
		al[a].push_back(b);
		al[b].push_back(a);
	}

	//주어진 그래프가 연결된 그래프가아니므로 
	for (int i = 1; i <= v; i++) {
		if (visitorder[i] == 0)dfs(i,0);
	}

	//단절점 정보 출ㄺ 
	//int answer = 0;
	for (int i = 1; i <= v; i++) {
		if (cutvertext[i])answer[s_Ans++] = i;
	}
	cout << s_Ans<<'\n';
	for (int i = 0; i < s_Ans; i++)cout << answer[i]<<' ';

}

int dfs(int curr,int parent) {

	visitorder[curr] = ++order; //현재 위치 방문순서
	//다음 방문 예정인 정점 탐색해서 

	//부모에게 넘겨주어야 할 low(현재 나의 dfs return 값) 
	//나와 연결된 점을 방문했을때 그 연결점이 방문했던 
	//점들 중 order가 가장 빠른 것 

	int minorder = visitorder[curr]; //나말곤 아직 방문 안함
	
	int child = 0;//자식 트리 개수

	for (int next : al[curr]) {
		if (next == parent)continue; //부모노드이므로 패스  
		if (visitorder[next] > 0) { //방문을 이미 한경우
			// 내가 사용해야하는 low,
			//나보다 작을 거임 
			minorder = min(minorder, visitorder[next]);
			
		}
		else { //방문 아직 안함 
			child++; 

			int low = dfs(next, curr);
			
			//루트노드인 아닌 경우, 루트노드면 항상 참이어서 배제하기 
			if (parent!=0&&visitorder[curr] <= low) {
				cutvertext[curr] = 1;

			}
			minorder = min(low, minorder);
		}

	}
	//다 돌고나서 루트노드에 대한것 판단 
	if (parent == 0 && child >=2)cutvertext[curr] = 1;

	return minorder;

}
