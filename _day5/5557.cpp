#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;



int main() {

	int n;
	vector<int>arr;
	cin >> n;
	arr.assign(n, 0);

	//n-2개의 등식 (+ or -) , 중간값이 음수나 20보다 커지면 안됨, 결과가 같아야함
	//2^(n-1) =2^99 시간초과됨 
	//n<=100
	//백트래킹이 아니라 모든 경우의 수를 표로 표현할수 있으면 나타내기 
	//등식 갯수가 2^63-1 
	
	//표만들기
	long long  check[100][21];
	
	//n갯수 만큼만 0할당하기 
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= 20; j++) {
			check[i][j] = 0;
		}
	}
	int tmp;
	cin >> tmp;

	check[0][tmp] = 1;

	//값을 넣는게 아니라 카운트하는거임!!
	//첫값은 어차피 0~20 값임
	for (int i = 1; i < n-1; i++) {
		cin >> tmp;

		//이전값을 어떻게 알지..? 
	    //이전값 + 입력값 -> 위치에 저장이 아니라

		//이전 0-20 모든 가능성 
		for (int j = 0; j <= 20; j++) {
			//더하기 
			if (j + tmp <= 20)check[i][j + tmp] += check[i - 1][j];
			//빼기 	
			if (j - tmp >=0)check[i][j - tmp] += check[i - 1][j];

		     

		}


		
	}
	//맨마지막 등호 뒤에 값
	cin >> tmp; 
	cout << check[n - 2][tmp];



}
