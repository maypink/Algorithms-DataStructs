#include <iostream>
#include <vector>
#include <fstream>
#include <queue>
 
using namespace std;
void bfs(vector<vector<int>>&graph, queue<int>&vert, vector<int>used, vector<int>&destination) {
    int curVert;
    while (!vert.empty()) {
        curVert = vert.front();
        vert.pop();
        for (int j = 0; j < graph[curVert].size(); j++) {
            if (used[graph[curVert][j]] == 0) {
                vert.push(graph[curVert][j]);
                used[graph[curVert][j]]++;
                destination[graph[curVert][j]] = destination[curVert] + 1;
            }
        }
    }
}
 
int main()
{
    int n, m, edge1, edge2;
    vector<vector<int>> graph;
    queue <int> vert;
    vector <int> used;
    vector <int> destination;
 
    ifstream cin("pathbge1.in");
    cin >> n >> m;
    used.resize(n+1);
    destination.resize(n+1);
    graph.assign(n + 1, vector<int>());
 
    for (int i = 0; i < m; i++) {
        cin >> edge1 >> edge2;
        graph[edge1].push_back(edge2);
        graph[edge2].push_back(edge1);
    }
 
    vert.push(1);
    used[1] = 1;
    destination[1] = 0;
 
    bfs(graph, vert, used, destination);
 
    ofstream cout("pathbge1.out");
    for (int i = 1; i < destination.size(); i++) {
        cout << destination[i] << " ";
    }
}
