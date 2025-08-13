#include <bits/stdc++.h>
using namespace std;

int v, e;
vector<vector<int>> adjList;

queue<int> bfs;
vector<int> visited; 
int BFS(int start, int finish) {
    visited.resize(v + 1, false);

    visited[start] += 1;
    bfs.push(start);
    
    while(!bfs.empty()) {
        int currNode = bfs.front();
        bfs.pop();
        cout << "mengunjungi currNode" << endl;

        for(auto next : adjList[currNode]) {
            if(visited[next] == -1) {
                visited[next] = visited[currNode] + 1;
                bfs.push(next);
            }
        }

    }

    return visited[finish];
}

int main() {
    // inisialisasi queue menggunakan library atau manual
    
    // inisialisasi v banyak simpul dan e banyak busur
    cin >> v >> e;

    adjList.resize(v + 1);

    for(int i = 0; i < e; i++) {
        int x, y;
        cin >> x >> y;

        adjList[x].push_back(y);
    }

    int start, end;
    cin >> start >> end;

    visited.resize(v + 1, -1);
    int ans = BFS(start, end);
    if(ans != -1) cout << ans << endl;
    else cout << "TIDAK MUNGKIN" << endl; 
}