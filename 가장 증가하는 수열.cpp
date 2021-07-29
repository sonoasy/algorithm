#include<iostream>
#define MAX 1000
#include<algorithm>
using namespace std;

//가장 긴 증가하는 부분 수열 백준 11053
//동적계획법으로 구현해보기 




int main() {
	int dp[MAX+1] = { 0 }; //n번째 원소로 끝날때
	int n;
	int s[MAX+1];
	

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> s[i];
	}
	dp[1] = 1;
	for (int j = 2; j <= n; j++) {
		//기본적으로 이전부터 시작하거나 자기 자신부터 시작(1)
		dp[j] = 1;
		for (int k = 1; k < j; k++) {
						
			//전에 인덱스와 비교했을때 크면 +1, 기존 저장 값과 비교하기
			
			if (s[j] > s[k]) {
				dp[j] = max(dp[k] + 1,dp[j]);
			}


		}
	}
	//max_element(arr,arr+size) array 클래스형 객체 반환 값반환->*
    
	cout << *max_element(dp+1, dp + n+1);

}

