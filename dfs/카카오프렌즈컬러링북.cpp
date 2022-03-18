#include <vector>
#include<iostream>
using namespace std;

vector<vector<int>>visited;
int dr[4]={0,0,-1,1};
int dc[4]={-1,1,0,0};
int m1,n1;
int number_of_area = 0;
int max_size_of_one_area = 0;
int num=0;
int dfs(int r,int c,vector<vector<int>> picture,int num){
    
    int cur=picture[r][c];
    
    for(int i=0;i<4;i++){
        int nr=r+dr[i];
        int nc=c+dc[i];
        //왜 or로 하면 틀리지
        if(nr>=0 && nr<m1 && nc>=0 && nc<n1 && !visited[nr][nc] && picture[nr][nc]==cur){
          visited[nr][nc]=1;
          
          num=dfs(nr,nc,picture,num+1);   //재귀 리턴   
            
        } 
      
   }
   return num; 
    
}
//영역
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    
    m1=m;
    n1=n;
    vector<int>v;
    visited.assign(m,vector<int>(n,0));
    
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(picture[i][j]>=1 && !visited[i][j]){
                num=1;
                visited[i][j]=1;
                
                v.push_back(dfs(i,j,picture,num));
                
                number_of_area++;
                
            }
            
        }
    }
    for(int i=0;i<v.size();i++){
       if(max_size_of_one_area<=v[i])
           max_size_of_one_area=v[i];
    }
    
    
    
    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
    
}
