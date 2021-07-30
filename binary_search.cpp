#include<iostream>
#include<algorithm>
using namespace std;

//분할정복 -이진탐색

//재귀 호출로 구현
int binary(int a[], int left, int right, int x) {
	int mid;

	if (left <= right) {
		mid = (left + right) / 2;
		//탐색 성공
		if (x == a[mid])return mid;
		else if (x < a[mid])return binary(a, left, mid - 1, x);
		else return binary(a, mid + 1, right , x);
	}
	//탐색 실패
	return 0;
	
}
//반복문으로 구현
int binary2(int a[], int left, int right, int x) {
	int mid;
	while(left<=right){
	mid = (left + right) / 2;
	//탐색 성공
	if (x == a[mid])return mid;
	else if (x < a[mid])right = mid - 1;  //배열 왼쪽 탐색
	else left = mid + 1;                  //배열 오른쪽 탐색

    }
	//탐색 실패
	return 0;

}

int main() {

int a[6] = { 1,2,3,4,5,6 };
	cout << binary(a, 0, 4, 6);
	cout << binary(a, 0, 4, 2);
	cout << binary2(a, 0, 4, 2);




}

