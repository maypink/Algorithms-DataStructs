#include <iostream>
#include <fstream>
#include <vector>
 
using namespace std;
 
void dfs(vector<vector<int>>&graph, vector<int>&fract, int cur, bool &flag) {
    for (int i = 0; i < graph[cur].size(); i++) {
        if (fract[graph[cur][i]] == 0) {
            fract[graph[cur][i]] = -fract[cur];
            dfs(graph, fract, graph[cur][i], flag);
        }
        else if (fract[graph[cur][i]] != 0) {
            if (fract[graph[cur][i]] == fract[cur]) {
                flag = 0;
                return;
            };
        }
    }
}
 
int main()
{
    int n, m, edge1, edge2;
    bool flag = 1;
    ifstream cin("bipartite.in");
    cin >> n >> m;
    vector <vector<int>> graph;
    vector<int> fract;
    graph.assign(n + 1, vector<int>());
    fract.resize(n + 1);
    for (int i = 0; i < m; i++) {
        cin >> edge1 >> edge2;
        graph[edge1].push_back(edge2);
        graph[edge2].push_back(edge1);
    }
 
    for (int i = 1; i < graph.size(); i++) {
        if (fract[i] == 0) {
            fract[i] = 1;
            dfs(graph, fract, i, flag);
        }
    }
 
    ofstream cout("bipartite.out");
 
    if (flag) {
        cout << "YES";
    }
    else {
        cout << "NO";
    }
}
