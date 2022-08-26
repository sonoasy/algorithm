#include<tuple>
#include<queue>
#include<iostream>

using namespace std;

typedef tuple<int, int, int> tp; 
vector<int>parent;

int find(int a) {

	if (parent[a] < 0)return a; 
	return parent[a] = find(parent[a]);
}

bool unions(int a, int b) {

	int xp = find(a);
	int yp = find(b);

	if (xp == yp)return false;
	if (parent[xp] < parent[yp]) {
		parent[xp] += parent[yp];
		parent[yp] = xp;
	}
	else {
		parent[yp] += parent[xp];
		parent[xp] = yp;
	}

	return true;
}

int kruscal(int v,priority_queue<tp, vector<tp>, greater<>> &q) {
	int cnt = 0;
	int sum = 0;

	while (cnt < v-1) { //v-1임!! 

		int cost =get<0>(q.top());
		int x = get<1>(q.top());
		int y = get<2>(q.top());
		q.pop();

		if (unions(x, y)) {
			cnt++;
			sum += cost;
		}

	}


	return sum; 

}



int main() {

	int v, e;
	int a, b, c;
	priority_queue<tp, vector<tp>, greater<>>q;

	cin >> v >> e; 
	parent.assign(v + 1, -1);

	while (e--) {
		cin >> a >> b >> c;
		q.push({ c,a,b });

	}

	cout << kruscal(v,q);





	
}
