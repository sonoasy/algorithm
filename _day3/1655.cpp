#include<iostream>
#include<vector>
#include<queue>


using namespace std;



int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	//n 10만
	//1,2,3,...n -? 10만*10만 완전탐색 x

	//중간값 기준으로 앞,뒤숫자들 갯수가 <=1이어야함 
	//값 차이 1보다 크면 큰쪽 제일 작은거 빼고 작은쪽으로 지금 중간값 옮김

	//priority queue


	int n;
	int num;
	cin >> n;

	// 최대힙(큰것 순서로)   최소힙(작은것순서로)
	
	priority_queue<int, vector<int>, less<int>>a;
	priority_queue<int, vector<int>, greater<int>>b;
	int mid;

	//시간복잡도? n만큼 큐에 넣고/빼기 - 힙 log(n)  -> nlogn = 10만x17..=100만.0.1초
	//size() 쓰지말고 넣으면 ++, 뺴면 -- 하기 
	//n이 10만이면? "nlogn"으로 탐색/연산!!!!!


	int asize = 0;
	int bsize = 0;


	//첫값은 무조건 중간값
	cin >> num;
	mid = num;
	cout << mid << '\n';
	//한번 입력받았음!!!
	n = n - 1;
	while (n--) {

		cin >> num;

		if (num < mid) {
			a.push(num);
			asize++;
		}
		else {
			b.push(num);
			bsize++;
		}
		//a,b 사이즈 비교 
		//b가 1개초과로 클때 바꿔줘야함 
		//a가 1개이상으로 크면 바꿔줘야함 
		//
		
		if (asize > bsize) {
			//지금 중간값은 b에 넣고,a에서 제일 큰값 빼서 중간값 설정
			b.push(mid);
			mid = a.top();
			a.pop();
			//!!!뺼떄 사이즈 줄여야함!!!
			asize--; bsize++;
		}
		else if(bsize>asize+1){
			//지금 중간값은 a에 넣고,b에서 제일 작은값 빼서 중간값 설정
			a.push(mid);
			mid = b.top();
			b.pop();
			//!!!뺼떄 사이즈 줄여야함!!!
			bsize--; asize++;
		}


		cout << mid << '\n';

	}



}
