#include<iostream>


using namespace std;
int n, k;
int v[10];

int main() {
	//탐욕법
	//백준 11047번
	//n개의 동전가치 합이 k가 되는 최소갯수
	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	int count = 0;
	int idx = n - 1;
	//큰숫자부터
	while(k>0) {
		if (k >=v[idx]) {
			k -= v[idx];
			count++;
		}
		else {
			idx--;
		}

	}

	cout << count;
	

}
