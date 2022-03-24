#include<iostream>
#include<vector>

using namespace std;
vector<int>parent;

int findParent(int node) {

	if (parent[node] < 0)return node; //루트 정점이면 node 리턴
	return parent[node] = findParent(parent[node]);//그래프 압축하며 루트 정점 찾기

}



void unionInput(int x, int y) {

	int xp = findParent(x);
	int yp = findParent(y);

	if (xp == yp)return;//같은 집합이므로 유니온 x

	if (parent[xp] < parent[yp]) { //새로운 루트 
		parent[xp] += parent[yp];
		parent[yp] = xp;
	}
	else {
		parent[yp] += parent[xp];
		parent[xp] = yp;
	}


}
/*
*사이클이 발생한 순간 = 같은 집합에 있는 원소 두 개를 유니온하려 할 때
* unionInput 함수의 반환형을 bool로 선언하여 cycle이 생성되는 순간 발견하기
*/


int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n, m;
	int cmd, a, b;
	cin >> n >> m;
	parent.assign(n + 1, -1);
	//합집합 0, 확인하는 연산 1
	while (m--) {

		cin >> cmd >> a >> b;

		if (cmd == 0) { //합치기-유니온
			unionInput(a, b);
		}
		if (cmd == 1) { //같은 집합인지 찾기-파인드
			if (findParent(a) == findParent(b))cout << "YES" << "\n";
			else cout << "NO" << "\n";
		}

	}


	return 0;

}
