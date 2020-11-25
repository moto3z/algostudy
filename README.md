# pgs_algostudy

# 2주차 - 완전탐색, 이분탐색

생성일: 2020년 11월 21일 오후 7:55

# 목차

- 완전탐색
    - 모의고사 : [https://programmers.co.kr/learn/courses/30/lessons/42840](https://programmers.co.kr/learn/courses/30/lessons/42840)
    - 소수찾기 : [https://programmers.co.kr/learn/courses/30/lessons/42839](https://programmers.co.kr/learn/courses/30/lessons/42839)
    - 카펫 : [https://programmers.co.kr/learn/courses/30/lessons/42842](https://programmers.co.kr/learn/courses/30/lessons/42842)

- 이분탐색
    - 입국심사 : [https://programmers.co.kr/learn/courses/30/lessons/43238](https://programmers.co.kr/learn/courses/30/lessons/43238)
    - 징검다리 : [https://programmers.co.kr/learn/courses/30/lessons/43236](https://programmers.co.kr/learn/courses/30/lessons/43236)

- 모의고사

```cpp
#include <string>
#include <vector>
#define DEBUG 0
using namespace std;
int gnum1(int nums,vector<int> answers);
int gnum2(int nums,vector<int> answers);
int gnum3(int nums,vector<int> answers);
int num1[]={1, 2, 3, 4, 5};
int num2[]={2, 1, 2, 3, 2, 4, 2, 5};
int num3[]={3, 3, 1, 1, 2, 2, 4, 4, 5, 5};//get point
int sn1=sizeof(num1)/sizeof(sn1);
int sn2=sizeof(num2)/sizeof(sn1);
int sn3=sizeof(num3)/sizeof(sn1);
int pa=0,pb=0,pc=0;
//1->5, 2->8, 3->10

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    
    int point[4] = {0};    
    int temp=0;
    int nums = answers.size();
    
    point[1]=gnum1(nums,answers);
    point[2]=gnum2(nums,answers);
    point[3]=gnum3(nums,answers);
    
    
    //return answer;
    ///*
    //answer making
    for(int i=1 ; i<=3 ; i++) {
        if(temp<point[i]) {
            temp=point[i];
        }
    }
    
    for(int i=1 ; i<=3 ; i++) {
        if(temp==point[i]) {
            answer.push_back(i);
        }
    }
    
    
        
    
    
    return answer;
}


int gnum1(int nums,vector<int> answers) {
    for(int i=0; i<nums ; i++) {    
        if(answers[i]==num1[i%(sn1)]) {
            pa++;
            
        }
    }
    return pa;
    
}



int gnum2(int nums,vector<int> answers) {
    
    //get num2's point
    for(int i=0; i<nums ; i++) {
        if(answers[i]==num2[i%(sn2)]) {
            pb++;
        }
    }
    return pb;
}



int gnum3(int nums,vector<int> answers) {
    
    //get num3's point
    for(int i=0; i<nums ; i++) {
        if(answers[i]==num3[i%(sn3)]) {
            pc++;
        }
    }
    return pc;
}
```
```python
DEBUG = 1

ans_1 = [1,2,3,4,5]
ans_2 = [1,3,2,4,2]

pat1 = [1, 2, 3, 4, 5]#5
pat2 = [2, 1, 2, 3, 2, 4, 2, 5]#8
pat3 = [3, 3, 1, 1, 2, 2, 4, 4, 5, 5]#10

def get_1supo(answers):
    
    nl = len(answers)
    num = 0
    for i in range(nl):
        if answers[i] == pat1[i%5]:
            num = num+1

    return num

def get_2supo(answers):

    nl = len(answers)
    num = 0
    for i in range(nl):
        if answers[i] == pat2[i%8]:
            num = num+1

    return num

def get_3supo(answers):

    nl = len(answers)
    num = 0
    for i in range(nl):
        if answers[i] == pat3[i%10]:
            num = num+1

    return num

def solution(answers):
    answer = []
    supos = [0] * 4

    supos[1] = get_1supo(answers)
    supos[2] = get_2supo(answers)
    supos[3] = get_3supo(answers)

    max=-1
    for i in range(1,4,1):
        if DEBUG:
            print(i, supos[i], max)
        if max < supos[i]:
            max = supos[i]

    for i in range(1,4,1):
        if max == supos[i]:
            answer.append(i)

    return answer

#print(solution(ans_1))
```

- 소수찾기

```python

#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
//참고 https://kuklife.tistory.com/88
bool check[8];
bool prime[7654322]={true,};
int maxi_len, dep_len;

bool checkNumber(int i,string numbers) {
    bool flag = false;
    vector<bool> visit(numbers.length());
    while (i != 0) {
        flag = false;
        int temp = i % 10;
        for (int j = 0; j <= numbers.length(); j++) {
            if (temp == numbers[j]-'0'&&visit[j]==0) {
                flag = true;
                visit[j] = 1;
                break;
            }
        }
        if (flag == false)
            return false;
 
        i /= 10;
    }
 
    return true;
}

int is_prime(int num) {
    return prime[num];
}

void ari() {
    prime[0]=prime[1]=true;
    memset(prime,true,sizeof(prime));
    return;
    for(int i=2 ; i*i<=maxi_len ; i++) {
        if(prime[i]==true) {
            for(int j=i+i ; j*j<=maxi_len ; j=j+i) {
                prime[j]=false;
            }
        }
    }
    return;
}

bool comp(char a, char b) {
    return a>b ? a : b;
}

int solution(string numbers) {
    int answer = 0;//int temp;
    int len = numbers.size();
    
    string maxi=numbers;
    sort(maxi.begin(), maxi.end(),comp);
    for(int i=0 ; i<maxi.size() ; i++ ) {
        //printf("%c ",maxi[i]);
    }
    //temp = stoi(maxi);
    //printf("%d ",temp);
    
    //making prime arr
    //maxi_len=temp;
    ari();
    //int try = pow(2,len);
    
    
    //#############################################
    
    sort(numbers.begin(), numbers.end(), greater<int>());
    vector<bool> temp(stoi(numbers)+1);
    for (int i = 2; i <= stoi(numbers); i++) {
        if (temp[i]==false && checkNumber(i,numbers)) {
            answer++;
        }
        if (temp[i] == false) {
            for (int j = i; j <= stoi(numbers); j += i) {
                temp[j] = true;
            }
        }
    }
    
    return answer;
    return answer;
}

/*

    sort(numbers.begin(), numbers.end());
    
    for(int i=0 ; i<numbers.size() ; i++ ) {
        //printf("%c ",numbers[i]);
    }
    do{
        int temp = stoi(numbers);
        printf("%d ",temp);
    }while(next_permutation(numbers.begin(), numbers.end()));
    */
```

- 카펫

```python
#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    
    int total = brown + yellow;
    for(int i=3; i<total ; i++) {
        if(total%i==0) {
            //i, total/i
            if(((i*2 + (total/i*2))-4) == brown) {
                answer.push_back(total/i);
                answer.push_back(i);
                
                break;
            }
        }
            
    }
    //answer.
    
    return answer;
}
```

- 입국심사

```cpp
#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>

//#include <cstring>
//#include <cstdio>
//#include <cstdlib>

using namespace std;

const int DEBUG = 0;

#include <string>
#include <vector>

using namespace std;

long long solution(int n, vector<int> times) {
    long long answer = 0;
    long long minT = 1,maxT,avgT,nhuman=0;
    
    maxT = *max_element(times.begin(), times.end()) * (long long)n;

    while (minT <= maxT) {
        avgT = ((maxT + minT) / 2);
        for (auto t : times) nhuman += avgT / t;

        if (n <= nhuman) {
            answer = avgT;
            maxT = avgT - 1;
        }
        else {
            minT = avgT + 1;
            
        }
        nhuman = 0;

    }

    return answer;
}

int main() {
    vector<int> tim = { 7,10 };
    long long ans = solution(6,tim);
    if (ans == 28) {
        cout << "OKOK!!" << endl;
    }
    else {
        cout << "Right!" << endl;
    }

    return 0;
}
```

- 징검다리

```cpp
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(int distance, vector<int> rocks, int n) {
    int answer = 0;
    sort(rocks.begin(), rocks.end());
    
    int left = 1;
    int right = distance;
    
    while (left <= right) {
        int mid = (left + right) / 2;
        int remove = 0;
        int lastRocksIdx = -1;
        for (int i = 0; i <= rocks.size(); ++i) {
            int d = lastRocksIdx == -1 ? rocks[i] : 
            i == rocks.size() ? distance - rocks.back() : rocks[i] - rocks[lastRocksIdx];
            
            if (d < mid) {
                remove++;
            }
            else lastRocksIdx = i;
        }
        
        if (remove > n) {
            right = mid - 1;
        } else if (remove <= n) {
            left = mid + 1;
            answer = answer < mid ? mid : answer;
        }
    }
    
    return answer;
}
```
