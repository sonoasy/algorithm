#include<iostream>
#include<vector>
#include<algorithm> //sort,unique
#include<cmath> //반올림
#include<set> //set
#define SIZE 500001

using namespace std;


int main() {
	
	int n,m;
	cin >> n;
    double sum = 0;  //float?
	vector<int>arr;
	vector<int> cnt;
	cnt.assign(SIZE, 0);
	
	for(int i=0;i<n;i++) {
		cin >> m;
		sum += m; //-0???
		arr.push_back(m);
		cnt[m+4000]++; //-1저장
	}
	//산술평균
	//cout.precision(0);
	//ceil하면 왜 틀리지
	//-0이면 안됨

	
	cout << int(round(double(sum) / n))<<'\n';

	//중앙값
	sort(arr.begin(), arr.end());
	
	cout << arr[n / 2 ]<<'\n';
	//최빈값
	int max = 0;
	int flag = 0;
	for (int i = 0; i < n; i++) {
		if (max < cnt[arr[i]+4000]) {
			max = cnt[arr[i]+4000];
			flag = arr[i];
		}

	}
	vector<int>v;
	for (int i = 0; i < n; i++) {
		if (cnt[arr[i] + 4000] == max) {
			v.push_back(arr[i]);
		}
	}
	unique(v.begin(), v.end());
	if (v.size() >= 2) {
		cout << v[1] << '\n';
	}
	else {
		cout << flag << '\n';
	}
	

	//범위 
	cout << arr[n - 1] - arr[0];


	return 0;

}
