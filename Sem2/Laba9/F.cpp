#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
short dfs(int start, const vector < vector < int>> & graph, vector<short> & used, short player) {
    short buffer = player;
    for (const int& i : graph[start]) {
        if (used[i] == 0) {
            used[i] = 2;
            if (player == 1) {
                buffer = min(dfs(i, graph, used, -1), buffer);
            }
            else {
                buffer = max(dfs(i, graph, used, 1), buffer);
            }
        }
        else {
            if (used[i] == 1 and player == 1) {
                buffer = -1;
            }
            if (used[i] == -1 and player == -1) {
                buffer = 1;
            }
        }
    }
    used[start] = buffer;
    return buffer;
}
 
int main()
{
    int n, m, start, edge1, edge2;
    ifstream cin("game.in");
    cin >> n >> m >> start;
    vector<vector<int>> graph;
    vector<short> used(n + 1);
    graph.assign(n + 1, vector<int>());
    for (int i = 0; i < m; i++) {
        cin >> edge1 >> edge2;
        graph[edge1].push_back(edge2);
    }
    int player = 1;
    int buf = 0;
    buf=dfs(start, graph, used, player);
    ofstream cout("game.out");
    if (buf == -1) {
        cout << "First player wins";
    }
    else {
        cout << "Second player wins";
    }
}
