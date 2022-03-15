#include <string>
#include <vector>

using namespace std;

//초기화 0으로 하는 이유???? -> 길없음을 나타내려면 값 크게 
//f와 다른 res를 쓰는 이유??? -> ok 

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = 0;
    vector<vector<int>> f;
    f.assign(n+1,vector<int>(n+1,200002)); //초기화 0으로 하는 이유????
    //fares 초기화 -> 대칭으로 반대편도 해줘야함(플루이드 워샬 양방향이므로), 자기자신은 0으로 해야함
   for(int i=1;i<=n;i++){
       f[i][i]=0;
        
   }
        
    for(int i=0;i<fares.size();i++){
        int ss=fares[i][0];
        int e=fares[i][1];
        int costs=fares[i][2];
        
        f[ss][e]=costs;
        f[e][ss]=costs;
    }
    
    vector<vector<int>> res;
    res.assign(n+1,vector<int>(n+1,200002)); //100002-> 최대 100000인데 n-1 지날수 있으므로 2배정도로 하기
    //플루이드 워샬문제 3중 루프까진 기억나는데 범위..? -> 제일 바깥 루프가 중간임
    
    //f와 다른 res를 쓰는 이유??? 중간지점 있으면 원래 f와 비교해야 하는데 
    //res에 저장하고 이를 활용하려 했는데 f아니면 갱신이 안됨 
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            for(int k=1;k<=n;k++){
                
                f[j][k]=min(f[j][k],f[j][i]+f[i][k]);
            }
            
        }
    }
    
    //s->k->a , s->k->b 가 있으면 s->a + s->b보다 작은지 비교해서 값 갱신하기 
    
    //answer 초기화를 f[s][a]+f[s][b] 하는 이유?? -> ok
    answer=f[s][a]+f[s][b];
    for(int k=1;k<=n;k++){
        //없으면 min에서 걸러지지 않나
        answer=min(answer,f[s][k]+f[k][a]+f[k][b]);        
    }
    //illegal instruction (core dumped) 오류 뜸 -> res 초기화 안함 
    
    
    
    return answer;
}
