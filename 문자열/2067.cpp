#include <iostream>
#include <vector>
#include <cstring>
#include <cstdlib> //abs 라이브러리 
using namespace std;
//본 시험에서는 solution 코드와 별도로 필요한 함수만 작성합니다.



int solution(int n, vector<string>words){    

    int answer=0;
    //알파벳 26개 첫번째 단어 빈도 저장  map 안써도 될듯
	  int alpha[26]={0};
	  //첫번째 단어
	  for(int i=0;i<words[0].size();i++){
			alpha[words[0][i]-'A']++;	
		}
	  //단어 길이 같은지
	  //map으로 목록 정하고 검사하려는건 정렬하고 갯수세기-> 정렬안하고 그냥 빈도 세기  
	  //계속 모든 단어가 카운트되는 문제-> count를 s가 해야함 
	
	  for(int j=1;j<n;j++){
			string s=words[j];
	    
			int count[26]={0};
			for(int k=0;k<s.size();k++){
				count[s[k]-'A']++;
			}
		
	    int tmp=0;
	    for(int i=0;i<26;i++){
			  tmp+=abs(alpha[i]-count[i]);
			
		  }
			//생각못한 부분:같은 알파벳 갯수 차이가 아니라 서로 겹치지 않는 단어 있을때도 2가지가 나옴
	    if(tmp<=1 || (tmp==2 && words[0].size()==s.size()))answer++;
			
		}
    return answer;
}

