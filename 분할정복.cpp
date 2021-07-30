#include<iostream>
#include<algorithm>
using namespace std;

//분할정복으로 합을 구하기
//재귀보다는 단순 반복이 더 효율적일수 있음
int sum(int a[], int left, int right) {
	int mid, sum_left, sum_right;
	if (left == right)return a[left]; //배열의 원소 한개일경우
	else {
		mid = (left + right) / 2;
		sum_left = sum(a, left, mid);
		sum_right = sum(a, mid + 1, right);
		return sum_left + sum_right;
	}
}

//분할정복으로 곱셈 구하기 

int multi(int x, int y) {
	int z;
	if (y == 0)return 0;
	z = multi(x, int(y / 2));
	if (y % 2 == 0) return 2 * z;
	else return x + 2 * z;

}


int main() {
	int a[6] = { 1,2,3,4,5,6 };
	cout << sum(a, 0, 5);
	cout << multi(5, 6);







}

