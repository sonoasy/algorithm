//다른 방법도 참고하기
#include<iostream>
#include <algorithm>
#include<queue>


#define MAX 1000000
using namespace std;

//int s[MAX];
//int e[MAX];
//동시에 생성
pair<int, int> p[MAX];

int main() {

	// 백준 110000번 최소 강의실 

	//n개의 수업
	int n;
	priority_queue<int,vector<int>,greater<int>> pq;


	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> p[i].first >> p[i].second;
	}
	//오름차순으로 정렬, 같은 값일경우는?
	sort(p,p+n); //pair는 기본적으로 첫번째 값을 기준으로 정렬
	//버블 정렬
	//for (int j = n - 1; j > 0; j--) {
	//	for (int i = 0; i <= j; i++) {
	//		if ((e[i] > e[i + 1])||((e[i]==e[i+1])&&(s[i]>s[i+1]))){
	//			swap(s[i], s[i + 1]);
	//			swap(e[i], e[i + 1]);
	//		}
    //	}
	//}
	//첫번째 시작, 큐에는 끝나는 시간만 저장 
	pq.push(p[0].second);

	for (int i = 1; i < n; i++) {
		if (pq.top() <= p[i].first) {
			pq.pop();
			pq.push(p[i].second);
		}
		else {
			//다른 강의실로 가기 
			pq.push(p[i].second);
		}



	}


	cout << pq.size();


}
