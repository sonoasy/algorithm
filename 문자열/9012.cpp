#include<iostream>
#include<vector>
#include<stack>


using namespace std;


int main() {

	int n;
	cin >> n;
	string e;
	while (n--) {

		stack<char>s; //스택을 매번 초기화해서 사용해야함!!
		cin >> e;
		int tmp = 0;
		for (int i = 0; i < e.size(); i++) {

			if (e[i] == '(') {

				s.push(e[i]);

			}
			else if (e[i] == ')'){

				if (s.empty()) {
					cout << "NO" << "\n"; //solution 함수로 하면 cout 안함
					tmp = 1; //break해서 출력할때 표시를 해야함
					break; //return을 쓰면 안됨
				}
				else {
					s.pop();
					

				}
			}

		}
		if (!s.empty()) {
			cout << "NO" << '\n';
		}
		else {
		    if (tmp == 0)cout << "YES" << '\n';
		}
		


	}



	return 0;

}
