#include <iostream>
#include <vector>
using namespace std;


int dp[301]={0};
int solution(int n, vector<int>& score) {
	int answer=0;

	dp[1]=score[1];
	dp[2]=score[1]+score[2];
	
	for(int i=3;i<=n-3;i++){
		
		//dp에는 자기자신이 포함안될떄도 
		dp[i]=max(dp[i-2]+score[i],max(dp[i-3]+score[i-1]+score[i],dp[i-1]));
	}
	dp[n]=max(dp[n-2]+score[n],dp[n-3]+score[n-1]+score[n]);
	answer=dp[n];
	
	return answer; 
}

