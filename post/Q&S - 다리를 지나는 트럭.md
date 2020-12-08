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
    //@@@@
    //@@@@뒤에서 설명하는 부분이라 생략

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
- crossing큐에 Truck을 추가하는 부분이며, 매번 다리의 허용중량을 초과하지 않는지 검사하고 추가해야 한다.
- timeline을 따라가며 계산하는탓에, 이 코드의 종료시간은 다리 길이*트럭댓수이다. 결국 O(n*m) 이므로 N^2 에 버금가는 시간복잡도이지만, 문제의 nm 제한이 낮아서 성공할수 있다.
- @@@@@은 뒷부분에 설명하므로 여기서는 생략함
<br>
<br>
<br>
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
- if(time - cur.tin >= bridge_length) : 트럭의 이동거리는 다리의 길이인데, 여기서 모든 트럭은 동일한 속도로 이동하므로 거리는 시간에 정비례한다.
  - 따라서 원래 문제대로라면 다리의 길이만큼 트럭이 이동해야되지만, 트럭의 진입시간만 알아낸다면 트럭이 다리를 빠져나왔는지 아닌지를 알수 있다.
- wait 큐와 crossing 큐  둘다 건넜으면 break;
