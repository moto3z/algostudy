# BFS&DFS - 타겟 넘버

생성일: 2020년 12월 9일 오후 8:17

# 문제

- [문제링크](https://programmers.co.kr/learn/courses/30/lessons/43165) : [https://programmers.co.kr/learn/courses/30/lessons/43165](https://programmers.co.kr/learn/courses/30/lessons/43165)

# 풀이

# 코드

```cpp
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int path[20] = { 0 };
vector<int> g_num;
int ans=0, g_tgt = 0;

void dfs(int dep,int lev) {
	if (dep == lev) {
		int sum = 0;
		for (int i = 0; i < lev; i++) {
			sum += path[i]*g_num[i];
		}
		if (sum == g_tgt) {
			ans++;
		}
		return;
	}
	else {
		path[dep] = 1;
		dfs(dep + 1,lev);
		path[dep] = -1;
		dfs(dep + 1,lev);

	}
}

int solution(vector<int> numbers, int target) {
    int answer = 0;
	int num = numbers.size();
	g_tgt = target;
	g_num = numbers;

	dfs(0, num);
	
	cout << ans;

    return ans;
}
int main() {

	cout << "strat test "<<endl;
	int num1[] = { 1,1,1,1,1 };
	vector <int> tc1_num;
	for (int i = 0; i < 5; i++) {
		tc1_num.push_back(num1[i]);
	}
	int ret = solution(tc1_num,3);
	if (ret == 5) {
		cout << "OK! return : " << ret << endl;
	}
	else {
		cout << "exp5, Wrong answer : " << ret << endl;
	}

	return 0;
}
```

# 해설

```cpp
snipet
```