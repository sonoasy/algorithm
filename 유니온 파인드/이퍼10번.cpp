#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

vector<int>parent;

int found(int a) {
	if (parent[a] == a)return a;
	else return parent[a] = found(parent[a]);

}

void unions(int a, int b) {

	int aroot = found(a);//parent[a]; 이건 왜 안됨? 
	int broot = found(b);//parent[b];
	
	if (aroot ==broot)return;

	if (aroot < broot) {
		parent[broot] = aroot;
		
	}
	else {
		parent[aroot] = broot;
		
	}
	//parent[a] = broot;

}

vector<int> solution(int n, vector<int>t1, vector<int>t2) {

	vector<int>answer;
	vector<vector<int>>tmp;
	tmp.assign(n + 1, vector<int>());

	parent.assign(n + 1, 0);
	for (int i = 1; i <= n; i++) {
		parent[i] = i;
		
	}

	for (int i = 0; i < t1.size(); i++) {
		unions(t1[i], t2[i]);
	}
	for (int i = 1; i <= n; i++) {
		found(i);
	}

	//대표 어떻게 뽑음 
	for (int i = 1; i <= n; i++) {
		tmp[parent[i]].push_back(i);
	}
	for (int i = 1; i <= n; i++) {
		cout << parent[i] << ' ';
	}
	cout << '\n';
	for (int i = 1; i <= 10; i++) {
		for (int j = 0; j < tmp[i].size(); j++) {
			cout << tmp[i][j]<<' ' ;
		}
		cout << '\n';
	}

	for (int i = 1; i <= n; i++) {
		if (tmp[i].size() == 0)continue;
		else {
			if (tmp[i].size() % 2 == 0) {
				answer.push_back(tmp[i][tmp[i].size() / 2 - 1]);
			}
			else {
				answer.push_back(tmp[i][tmp[i].size() / 2]);
			}
		}
	}


	return answer;
}



int main() {



	vector<int>a = { 6,3,4,9,2,7,5 };
	vector<int>b = { 4,2,8,2,1,10,3 };
	vector<int>ans=solution(10, a, b);
	sort(ans.begin(), ans.end());
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << ' ';
	}
}
