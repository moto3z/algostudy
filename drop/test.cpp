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
  
    ari();//아리스토테네스의 체
    sort(numbers.begin(), numbers.end(), greater<int>());
    //정렬


    vector<bool> temp(stoi(numbers)+1);
    // 

    
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
}


