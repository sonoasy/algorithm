#include <iostream>
#include <vector>
#include<queue>
using namespace std;

int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};

int r,c=0;
void dfs(int s1,int s2,vector<vector<int>>& b){
	
	int curr=s1;
	int curc=s2;
	b[curr][curc]=-1;
	for(int i=0;i<4;i++){
		int nextr=curr+dx[i];
		int nextc=curc+dy[i]; 
		if(nextr>=0 && nextr<r && nextc>=0 && nextc<c && b[nextr][nextc]==0){//0조건!!
			dfs(nextr,nextc,b);
		}
	}
	
}
int canMelt(int r,int c,vector<vector<int>> b){
	//2변이상이 공기인지(-1)
	int cnts=0;
	for(int i=0;i<4;i++){
		int nr=r+dx[i];
		int nc=c+dy[i];
		if( nr>=0 && nr<r && nc>=0 && nc<c &&b[nr][nc]==-1)cnts++;
	}
	return cnts>=2;
}

int solution(int n, int m, vector<vector<int>> b) {
    int answer = 0; //시간
    queue<pair<int,int>> q; //큐에는 녹은 치즈가 들어감(2변 이상 공기와 접촉)
	  r=n; c=m;
	  vector<vector<int>> b1=b;
	  vector<pair<int,int>> v;
	  //외부공기, 내부공기 모두 0인데 구분하기 위해 바깥공기 -1로 
	  dfs(0,0,b);
	  for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				if(canMelt(i,j,b1)&&b[i][j]==1){ //치즈일 조건!!
          
					v.push_back({i,j}); //아무것도 안담김...
				}			
			}
		}
	  
	  while(!v.empty()){
			answer++;
			for(int i=0;i<v.size();i++){
				b1[v[i].first][v[i].second]=0; //한번에 녹이기 
			}
			dfs(0,0,b);
			for(int i=0;i<n;i++){
		  	for(int j=0;j<m;j++){
				  if(canMelt(i,j,b1)&&b[i][j]==1){
				   	v.push_back({i,j});
			  	}			
			  }
		  }
			answer++;
		}
	  
	
	
	
    return answer;
}

