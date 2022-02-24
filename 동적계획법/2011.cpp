#include<iostream>
#include<vector>


using namespace std;
const int ss = 1e6;
long long dp[5002] = { 0 };

int main() {


	string s;
	cin >> s;

	dp[0] = 1;
	dp[1] = 1;
	//dp는 가능한 경우의 수 인데 하나로 가능한걸 찾아야함
	//dp +1라고 생각했는데 경우의 수가 되는거니까 더해줘야함!!!

	if (s[0] == '0')return 0;

	for (int j = 2; j <= s.length(); j++) {

		int i = j - 1;
		//한자리,두자리도 안됨
		if (s[i] == '0' && (s[i - 1] <= '0' || s[i - 1] >= '3'))return 0;
		//한자리는 됨
		if (s[i] >= '1' && s[i] <= '9')dp[j] += dp[j - 1];

		//두자리됨
		if ((s[i - 1] == '2' && s[i] <= '6') || s[i - 1] == '1')dp[j] += dp[j - 2];

		//if (s[i] <= '0')dp[i] = dp[i - 1];
		//if (s[i] >= '1' && s[i] <= '9')dp[i]++;
		//char tmp = s[i - 1] + s[i];
		//if (tmp >= '10' && tmp  <= '26')dp[i]++;

		//dp[i] += dp[i - 1];

		dp[j] %= ss;
	}
	
	cout << int(dp[s.size()]);




	return 0;

}
