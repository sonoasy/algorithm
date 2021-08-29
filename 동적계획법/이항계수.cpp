#include<iostream>
#define MAX 11
using namespace std;

//이항계수 백준 11050
//동적계획법으로 구현해보기 


int bin(int n1, int k1) {

	int s[MAX][MAX] = { 0 };
	int m;
	int n = n1;
	int k = k1;
	//top-down은 시간 오래 걸림

	//bottom-up 방식
	for (int i = 1; i <= n; i++) {
		// n= 1,2,3,4,5..n 까지 올라감, 
		// k는 0...n까지만 확인하면됨, i가 작으면 i까지, k가 작으면 k까지 
		m = (i < k) ? i : k;
		
		for (int j = 0; j <= m; j++) {
			if (j == 0 || i == j) {
				s[i][j] = 1;
			}
			else {
				s[i][j] = s[i - 1][j - 1] + s[i - 1][j];
			}

		}
	}
	
	return s[n][k];
}


int main() {

	int n, k;
	
	cin >> n >> k;
	
	cout << bin(n, k);
	
	

}



