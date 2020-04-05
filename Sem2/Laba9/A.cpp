#include <iostream>
#include <fstream>
#include <vector>
#include <stack>
 
using namespace std;
 
void dfs(vector <vector<int>>& graph, vector<int>& rightOrder, vector<int>& used, int cur) {
    used[cur] = 1;
    for (int i = 0; i < graph[cur].size(); i++) {
        if ((used[graph[cur][i]] == 0) && (graph[graph[cur][i]].size() != 0)) {
            dfs(graph, rightOrder, used, graph[cur][i]);
            used[graph[cur][i]] = 2;
            rightOrder.push_back(graph[cur][i]);
        }
        else if ((used[graph[cur][i]] == 0) && (graph[graph[cur][i]].size() == 0)) {
            used[graph[cur][i]] = 2;
            rightOrder.push_back(graph[cur][i]);
        }
        else if (used[graph[cur][i]] == 1) {
            cout << -1;
            exit(0);
        }
    }
};
 
void topologicalSort(vector <vector<int>>&graph, vector<int>&rightOrder, vector<int>&used) {
    for (int i = 1; i < graph.size(); i++) {
        for (int j = 0; j < graph[i].size(); j++) {
            if ((used[graph[i][j]] == 0)&&(graph[graph[i][j]].size()!=0)) {
                dfs(graph, rightOrder, used, graph[i][j]);
                used[graph[i][j]] = 2;
                rightOrder.push_back(graph[i][j]);
            }
            else if (used[graph[i][j]] == 0) {
                rightOrder.push_back(graph[i][j]);
                used[graph[i][j]] = 2;
            }
        }
        if (used[i] != 2) {
            used[i] = 2;
            rightOrder.push_back(i);
        }
    }
};
 
 
int main()
{
    int n, m, edge1, edge2;
    vector <vector <int>> graph;
    vector <int> rightOrder;
    vector <int> used;
    ifstream cin("topsort.in");
    cin >> n >> m;
    graph.assign(n+1, vector<int>());
    used.resize(graph.size());
    for (int i = 0; i < m; i++) {
        cin >> edge1 >> edge2;
        graph[edge1].push_back(edge2);
    }
 
    topologicalSort(graph, rightOrder, used);
 
    ofstream cout("topsort.out");
 
    for (int i = rightOrder.size() - 1; i > -1; i--) {
        cout << rightOrder[i] << " ";
    }
     
}
