#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int NODE_COUNT = 7;
bool VISITED[7];      // 방문확인
//vector<int> a[7 + 1]; // 각 노드의 인덱스가 1부터 처리될수있도록
int MATRIX[8][8];

void bfs(int start)
{
    queue<int> q;
    q.push(start);
    VISITED[start] = true;
    while(!q.empty()) {
        int current = q.front();
        q.pop();
        printf("%d ",current);
        for(int i=0 ; i<NODE_COUNT ; i++) {
            int next_node = MATRIX[current][i];
            if(!VISITED[next_node]) {
                q.push(next_node);
                VISITED[next_node] = true;
            }
        }
    }
}

int main(void) {
    
}