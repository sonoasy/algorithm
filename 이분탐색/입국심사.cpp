#include <string>
#include <vector>
#include<climits>
#include<algorithm>
using namespace std;


long long solution(int n, vector<int> times) {
    long long answer = LLONG_MAX;
    long long mid;
    long long tmp=0;
    
    sort(times.begin(),times.end());
    long long start=1;
    long long end=(long long)n*(long long)times[times.size()-1];
    
    while(start<=end){//멈추는 조건
        
        mid=(start+end)/2; //걸리는 시간
        tmp=0; //초기화 하기
        for(int i=0;i<times.size();i++){
            tmp+=(mid/(long long)times[i]);
        }
        if(tmp>=n){
            
            //마지막까지 줄어드는거 찾기 -저장하면서 비교
            answer=min(mid,answer);
            mid-=1;
            end=mid;
            
        }
        else{ 
            start=mid+1;
        }
        
    }
    
    
    
    return answer;
}
