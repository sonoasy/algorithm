#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

vector<int>parent;

int find(int k) {

	if (parent[k] == k)return k;
	else return parent[k] = find(parent[k]);

}

void Union(int a, int b) {

	
	//union 연산
	int aroot = find(a);
	int broot = find(b);
	//시간초과문제
	/*if (aroot == broot)return;
	else*/ parent[aroot] = broot;
	
		

}





int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	parent.assign(n + 1, 0);
	for (int i = 0; i <= n; i++) {
		parent[i] = i;
	}

	int cmd, a, b;
	//0 합집합 //1 find 
	while (m--) {
		cin >> cmd >> a >> b;
		if (cmd == 0) {
			//union 연산
			Union(a, b);
		}
		if (cmd == 1) {
			//find 연산 
			if (find(a)==find(b)) {
				
				cout << "YES\n";
			}
			else {
				cout << "NO\n";
			}

		}



	}




}
