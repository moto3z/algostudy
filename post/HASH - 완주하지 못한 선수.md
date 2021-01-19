# HASH - 완주하지 못한 선수


# 문제

- 문제 : [https://programmers.co.kr/learn/courses/30/lessons/42576](https://programmers.co.kr/learn/courses/30/lessons/42576)
- 문제 설명
    - 문자열 배열이 2개 주어짐
        1. 하나는 참가한 모든 선수의 이름이 (participant)
        2. 다른건 완주한 모든 선수의 이름이(completion)
    - 위 두 배열을 비교해 완주하지 못한 선수의 이름을 구하는 문제입니다.
    ### 제한

    - N제한 : 마라톤 경기에 참여한 선수의 수는 1명 이상 100,000명 이하입니다.
    - 답은 1개 : completion의 길이는 participant의 길이보다 1 작습니다.
    - 중복가능성 : 참가자 중에는 동명이인이 있을 수 있습니다.
    - 참가자의 이름은 1개 이상 20개 이하의 알파벳 소문자로 이루어져 있습니다.

# 풀이

- 두가지 풀이법을 생각해볼수 있는데
    1. Hash 자료구조의 특성을 이용해서 participant에서 completion 을 하나하나 삭제하기
    2. participant , completion 둘다 정렬(사전순) 해서 양측에 존재하면  Pass, 한쪽에만 존재하는 문자열이 정답임

- 이 문제는 효율성도 점검하는데, 위 두가지 풀이중 
    - 1번 Hash 자료구조의 특성을 이용하면 전체 연산량은 N번이고,
    - 2번 정렬2번+순차탐색 방식으로 풀면 전체 연산량은 N+LogN*2  정도 된다.

# 코드

- cpp

```cpp
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    
    sort(participant.begin(),participant.end());
    sort(completion.begin(),completion.end());
    int len = participant.size();
    
    
    for(int i=0 ; i<len ; i++) {
        if(participant[i] !=completion[i]) {
            answer = participant[i];
            break;
        }
    }
    
    
    return answer;
}
```


- Python3 코드

```python
#test.py
from operator import *

def solution(participant, completion):
    
    answer = ''
    participant.sort()
    completion.sort()

    
       
    for i in range(len(completion)) :
        if participant[i] != completion[i]:
            answer = participant[i]
            break
    

    if answer == '' :
        answer = participant[-1]
    
    return answer
```

- Java8 코드
```java
import java.util.*;

public class first{
	public static void main(String[] args) 
	{
		Solution mysol = new Solution();
		String p1[] = {"leo", "kiki", "eden"};
		String c1[] = {"eden", "kiki"};
		String ret = mysol.solution(p1,c1);
		System.out.println(ret);

	}
}


class Solution {
    public String solution(String[] participant, String[] completion) {
        
    	String answer = "";
    	
    	
    	Arrays.sort(participant);
    	Arrays.sort(completion);
    	
    	for(int i=0 ; i<completion.length ; i++) { 
    		if(!participant[i].equals(completion[i])){
    			return participant[i];
    		}
    	}
    	
    	
        return participant[completion.length];
    }
}
```
