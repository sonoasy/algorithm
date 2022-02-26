#include <iostream>
#include <vector>
#include <stack>
using namespace std;
//본 시험에서는 solution 코드와 별도로 필요한 함수만 작성합니다.
vector<string> solution(int T, vector<string> inputs){
    vector<string> answer;
    for(int j=0;j<T;j++){
			int cnt=0;
		  for(int i=0;i<inputs[j].size();i++){
				if(cnt<0)break;
				if(inputs[j][i]=='(')cnt++;
				if(inputs[j][i]==')')cnt--;
				
				
			}	
			if(cnt!=0){answer.push_back("NO");}
			else{
				answer.push_back("YES");
			}
		}
	  
	
	
	
	
    return answer;
}

