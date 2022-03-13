#include <iostream>
#include <vector>

using namespace std;

int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};

int r,c;
void dfs(int s1,int s2,vector<vector<int>> &b1){
	

	int curr=s1;
	int curc=s2;
	b1[curr][curc]=-1;
	for(int i=0;i<4;i++){
		int nextr=curr+dx[i];
		int nextc=curc+dy[i]; 
		
		if(nextr>=0 && nextr<r && nextc>=0 && nextc<c && b1[nextr][nextc]==0){//0조건!!
			dfs(nextr,nextc,b1);
		}
		
	}
	
}

bool canMelt(int x,int y,vector<vector<int>> &b1){
	//2변이상이 공기인지(-1)
	int cnt=0;
	for(int i=0;i<4;i++){
		int nr=x+dx[i];
		int nc=y+dy[i];
		if( nr>=0 && nr<r && nc>=0 && nc<c &&b1[nr][nc]==-1)cnt++;
	}
	
	return cnt>=2;
}

int solution(int n, int m, vector<vector<int>> b) {
    int answer = 0; //시간
   //큐에는 녹은 치즈가 들어감(2변 이상 공기와 접촉)
	  r=n; c=m;
	  vector<vector<int>> b1=b;
	  
	  //외부공기, 내부공기 모두 0인데 구분하기 위해 바깥공기 -1로 
	  dfs(0,0,b1);
	  //canmelt의 문제? 
	  //vector<pair<int,int>> v;// 벡터 초기화 안함!!!
	 /* for(int i=0;i<n;i++){  시간초과 문제...
			for(int j=0;j<m;j++){
				if(canMelt(i,j,b1)&&b1[i][j]==1){ //치즈일 조건!!
          
					v.push_back({i,j}); //아무것도 안담김...
				}			
			}
		}
	*/
	 
	  while(1){
			vector<pair<int,int>> v;// 벡터 초기화 안함!!!
			for(int i=0;i<n;i++){
		  	for(int j=0;j<m;j++){
				  if(canMelt(i,j,b1)&&b1[i][j]==1){
				   	v.push_back({i,j});
			  	}			
			  }
		  }
			if(v.empty())return answer;
			
			for(int i=0;i<v.size();i++){
				b1[v[i].first][v[i].second]=0; //한번에 녹이기 
			  //dfs(v[i].first,v[i].second,b1); //dfs를 여기에 위치시키고, 0,0,이 아니라 현재꺼를 !!! 여기는 외부 공기 표시만 하므로 치즈 녹는지 확인안해서 괜찮음 
			}
			//dfs(0,0,)을 하면 안되는 이유? 
		//	dfs(0,0,b1); -> -1이기때문에 안됨
			answer++;
		
			
			
			
			
			
		}
	  
	
	
	
    return answer;
}

