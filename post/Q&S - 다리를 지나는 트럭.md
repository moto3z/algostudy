# Q&S - 다리를 지나는 트럭

생성일: 2020년 12월 2일 오후 9:21

# 문제

- 문제링크 : [https://programmers.co.kr/learn/courses/30/lessons/42583](https://programmers.co.kr/learn/courses/30/lessons/42583)

# 풀이

- 하나뿐인 다리를 트럭들이 차례로 지나는 모습은 전형적인 큐 형태로 모델링이 가능!
- 두개의 큐를 만들어서  wait큐와 Crossing큐 두개가 있어서, 두 큐 모두 빈 상태라면 모든 트럭이 다리를 건너고 종료되었으므로 끝.
- wait 큐 대신 입력값인 truck_weights에서 element 를 삭제해가며 진행할 수 있고, O(n)은 완전히 동일함.

# 코드

```cpp
#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;
struct MyStruct
{
    int weig;
    int tin;
}typedef trk;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    queue <trk> crossing;
    queue <int> wait;
    trk temp,cur;
    int cur_w = 0,tn=0,time=0;

    int len = truck_weights.size();
    for (int i = 0; i < len; i++) {
        wait.push(truck_weights[i]);
    }
    

    while (1) {
        
        if (wait.empty() == true && crossing.empty() == true) {
            break;
        }
        else {}

        // 
        if (crossing.empty()) {

        }
        else {
            cur = crossing.front();
            if (time - cur.tin >= bridge_length) {

                cur_w = cur_w - cur.weig;
                crossing.pop();
            }
            else {
                //pass;
            }
        }

        if( (wait.empty()!= true) && (weight >= (cur_w + wait.front())) ){
            temp.tin = time;
            temp.weig = wait.front();
            crossing.push(temp);

            cur_w = cur_w + wait.front();
            wait.pop();
            
        }
        else {}
        time++;

    }
    
    return time;
}

```

# 해설

```cpp
//앞에서 선언 queue <int> wait;
int len = truck_weights.size();
for (int i = 0; i < len; i++) {
    wait.push(truck_weights[i]);
}
```

- wait이라는 큐에다가 모든 트럭의 중량를 추가

```cpp

while (1) {
    @@@@
		@@@@

    if( (wait.empty()!= true) && (weight >= (cur_w + wait.front())) ){
        temp.tin = time;
        temp.weig = wait.front();
        crossing.push(temp);

        cur_w = cur_w + wait.front();
        wait.pop();
        
    }
    else {}
    time++;

}
    
```

- @@@@@에다가는 뒤에 설명함

```cpp
if (wait.empty() == true && crossing.empty() == true) {
        break;
    }
    else {}

    if (crossing.empty()) {

    }
    else {
        cur = crossing.front();
        if (time - cur.tin >= bridge_length) {

            cur_w = cur_w - cur.weig;
            crossing.pop();
        }
        else {
            //pass;
        }
    }
```

- wait 큐와 crossing 큐  둘다 건넜으면 break;
