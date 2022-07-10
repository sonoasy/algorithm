#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

//백트래킹에서 인수는 현재 상태, 종료나 조건은 if로 표현하기 
vector<int>arr;
int n, m;

int check[10001] = { 0};
int ans[8];

//첫번째 원소부터 차례로 탐색하려함 
//그 정렬에서 같으면 넘어가는거..?

//인수를 k로 설정하기?
//출력을 어떻게 해야할지 모르겠음 배열에 담아야하는지
//배열에 담으면 초기화는 어떻게하고 -> 그냥 인덱스에 담으면 덮어씌어짐 


//arr[i]!=arr[i-1]에서 중복검사를 하고, check에서 있는만큼 순회



void search(int num) {

	//현재 탐색하는 위치 
	if (num == m) { //출력하기 
		for (int j = 0; j < m; j++) {
			cout << ans[j] <<' ';
		}
		cout << '\n';
		
		return; 
	}

	for (int i = 0; i < n; i++) { 
		//모든 자리에서 시작하고,
		//여기는 탐색할 자리 

		//자기랑 같은 값 - 정렬했으니까 앞에거 확인하면 됨 있으면 거긴 탐색 안함
		// 자기와 같은 수를 제외하는게 잘안됨 
		
		if ((i==0 || arr[i]!=arr[i-1] )&& check[arr[i]] ) {
			ans[num] = arr[i];
			
			check[arr[i]]--; 
			search(num + 1);
			check[arr[i]]++;
		}



	}
	 


}



int main() {

	

	cin >> n >> m;
	arr.assign(n, 0);
	for (int i = 0; i < n; i++) {
		cin >> arr[i]; //숫자 배열 
		check[arr[i]]++; 
	}

	//m개씩 증가하는 순서로 출력해야됨 
	sort(arr.begin(), arr.end());


	//중복되게 출력하면 안됨- 지금 시작한 숫자에선 x 같은숫자-같은 숫자는 됨
	//일일이 하나 하나탐색..? 

	search(0);



}
