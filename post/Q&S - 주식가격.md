# Q&S - 주식가격

생성일: 2020년 12월 2일 오후 9:20

# 문제

- 딴거설명

# 풀이

# 코드

```cpp
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    int len = prices.size();
    
    bool is_find=false;
    for(int i=0 ; i<len ; i++) {
        is_find=false;
        for(int j=i ; j<len ; j++) {
            
            if(prices[i]>prices[j]){
                is_find=true;
                answer.push_back(j-i);
                break;
            }
        }
        if(is_find == false) {
            answer.push_back(len-i-1);
        }
    }
    return answer;
}
```

# 해설

```cpp
snipet
```