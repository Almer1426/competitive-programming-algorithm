#include <bits/stdc++.h>
using namespace std;

int v, e;
vector<vector<int>> adjList;

stack<int> dfs;
vector<bool> visited; 
bool DFS(int start, int finish) {
    visited.resize(v + 1, false);

    visited[start] = true;
    dfs.push(start);
    
    while(!dfs.empty()) {
        int currNode = dfs.top();
        dfs.pop();
        cout << "mengunjungi currNode" << endl;

        for(auto next : adjList[currNode]) {
            if(!visited[next]) {
                visited[next] = true;
                dfs.push(next);
            }
        }

    }

    return visited[finish];
}

int main() {
    // inisialisasi stack menggunakan library atau manual
    
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

    bool status = DFS(start, end);
    if(status) cout << "TRUE";
    else cout << "FALSE";
}