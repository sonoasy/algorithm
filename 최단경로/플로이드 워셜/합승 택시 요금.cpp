#include <string>
#include <vector>
//왜 다익스트라가 아닌지? - 시간초과
using namespace std;
//a에서 b 6번에서 2번으로 가려함
//지점번호 1-n

//지점갯수, 출발번호 s 도착 A-a B-b 
//fares [c,d,f] //c->d f
const int INF=1e7*3;

vector<vector<int>>makegraph(int n,vector<vector<int>>fares){
    vector<vector<int>>g;
    g.assign(n+1,vector<int>(n+1,INF));
    for(int i=1;i<=n;i++){
        g[i][i]=0; //빠트리지 말기 
    }
    for(int i=0;i<fares.size();i++){
        int u=fares[i][0];
        int v=fares[i][1];
        int w=fares[i][2];
        g[u][v]=w;
        g[v][u]=w; //양쪽 다 체크하기 
    }
    return g;
}
void floydwarshall(int n,vector<vector<int>> &graph){
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            for(int k=1;k<=n;k++){
                int dis=graph[j][i]+graph[i][k];
                graph[j][k]=min(dis,graph[j][k]);
            }
        }
    }
    
}
int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    
    vector<vector<int>>graph=makegraph(n,fares);
    
    floydwarshall(n,graph);
    //함께갈수 있는곳이 어디까지인지 탐색 - 이부분을 어떻게 할지 모르겠음
    //int answer=graph[s][a]+graph[s][b]; ->한개만 통과
    int answer=INF;
     for (int i = 1; i <= n; i++) { //i번째 지점까지 합승
        //지금까지의 최단거리와 합승한 최단거리 비교
        //이동 불가능한 경우(INF)은 min 조건에 의해 자동으로 고려되지 않음
        answer = min(answer, graph[s][i] + graph[i][a] + graph[i][b]); //최저 비용 계산
    }
    
    
    return answer;
}
