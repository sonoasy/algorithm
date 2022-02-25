#include<iostream>
#include<vector>
#include<stack>


using namespace std;


int main() {

	int n;
	cin >> n;
	string e;
	while (n--) {

		stack<char>s;
		cin >> e;
		int tmp = 0;
		for (int i = 0; i < e.size(); i++) {

			if (e[i] == '(') {

				s.push(e[i]);

			}
			else if (e[i] == ')'){

				if (s.empty()) {
					cout << "NO" << "\n";
					tmp = 1;
					break;
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
