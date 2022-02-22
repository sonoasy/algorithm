#include<iostream>
#include<vector>
#include<deque>
#include<map>
using namespace std;

vector<vector<int>> s;
vector<pair<int, char>>p;
deque<pair<int, int>>ss;
map<int, char> m;
//오른쪽,왼쪽의 의미는 단순히 오른쪽/왼쪽이 아니라 현재 기준 방향 전환!!
int dr[4] = { 1,0,-1,0 }; //하좌상우
int dc[4] = { 0,-1,0,1 }; 

//오른쪽 전환:하->좌->상->우   +1 %4 
//왼쪽 전환:하<-좌<-상<-우
int main() {

	//벽에 부딛히거나 자기자신에 붙으면 끝남, 몇초 후에 끝나는지  

	int a, b;
	int n; //보드의 길이
	int k; //사과 갯수
	cin >> n >> k;
	int x;
	char c;
	//각 좌표에서 방향 기록하기 
	vector<vector<int>>d;

	s.assign(n, vector<int>(n,0));
	d.assign(n, vector<int>(n));
	//k개의 줄 사과 위치 행,열
	while (k--) {

		cin >> a >> b;
		s[a - 1][b - 1] = 2; 


	}

	//뱀 방황 변환 횟수
	int l;
	cin >> l;
	//l개의 방향 정보 x,c   x초 후 c(D -오른쪽 ㅣ-왼쪽)로 방향 움직임 
	while(l--){
		cin >> x >> c;
		p.emplace_back(x, c);
		m[x] = c;
	}
	int times = 0;
	
	//뱀의 머리 위치
	int curr = 0;
	int curc = 0;

	int dir = 3;

	ss.push_front({ curr, curc });
	s[curr][curc] = 1;

	while (1) {

		times++; //움직이고 멈추는걸 고려해서 앞에 있어야함!!

		//뱀의 머리 방향으로 머리 한칸 움직이기
		
		curr = curr + dr[dir];
		curc = curc+ dc[dir];

		if (curr < 0 || curr >= n || curc < 0 || curc >= n || s[curr][curc]==1)break;  //+ 자기 자신과 부딪힐떄
		
		
		//사과 유무
		if (s[curr][curc] != 2) {
			//사과 없애기
			//s[curr][curc] = 0; 0아님!!!
		//사과 없으면 꼬리 위치 없애기 

			int lr = ss.back().first;
			int lc = ss.back().second;
			s[lr][lc] = 0;//
			ss.pop_back();

			//꼬리 위치 갱신하기
			//꼬리 앞 몸통 위치를 알려면 단순히 체크하는거로는 안됨 

		}
		s[curr][curc] = 1;
		d[curr][curc] = dir;
		ss.push_front({ curr,curc });

		//방향 바꾸기 
		for (int i = 0; i < p.size(); i++) {
			if (times == p[i].first) {
				if (p[i].second == 'D') {
					dir = (dir + 1) % 4;
			    }
				else if (p[i].second == 'L') {
					dir = (dir + 3) % 4;
				}
			}
		}
		
		/*if (m[times] == 'L') {
			dir = (dir + 3) % 4;
		}
		else if (m[times] == 'D') {
			dir = (dir + 1) % 4;
		}
		*/
		//times++;
	}
	cout << times;
	





	return 0;
}
