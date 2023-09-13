
int _solution(int n, vector<vector<int>> edge) {
    //memset(dist, -1, sizeof(dist));
    int answer = 0;
    int max = 0;
    
    queue<int> q;
    
    for (auto i : edge) {
        for (auto j : i) {
            cout << j << ' ';
        }
        cout << endl;
    }
    cout << endl; cout << endl; cout << endl;
    sort(edge.begin(), edge.end());
    //왜 정렬해?
    for (auto i : edge) {
        for (auto j : i) {
            cout << j << ' ';
        }
        cout << endl;
    }

    for (int i = 0; i < (int)edge.size(); i++) {
        check[edge[i][0]][edge[i][1]] = 1;
        check[edge[i][1]][edge[i][0]] = 1;
        //매트릭스 방식
    }

    q.push(1);
    visited[1] = true;

    while (!q.empty()) {

        int node = q.front();
        q.pop();

        for (int i = 0; i <= n; i++) {
            if (check[node][i] == 1 && visited[i] == false) {
                q.push(i);
                visited[i] = true;
                dist[i] = dist[node] + 1;
                
                if (dist[i] > max)
                    max = dist[i];
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        if (max == dist[i]) {
            answer++;
        }
    }
    return answer;
}