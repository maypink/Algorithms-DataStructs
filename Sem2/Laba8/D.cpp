#include <iostream>
#include <vector>
#include <fstream>
 
using namespace std;
 
void dfs(vector<int>& used, vector<vector<int>>& component, vector<vector<int>>& graph, int i) {
    component.back().push_back(i);
    used[i]=component.size();
    for (int j = 0; j < graph[i].size(); j++) {
        if ((graph[graph[i][j]].size() == 0) && (used[graph[i][j]] == 0)) {
            component.back().push_back(graph[i][j]);
            used[graph[i][j]]=component.size();
        }
        else if (used[graph[i][j]] == 0)
        {
            dfs(used, component, graph, graph[i][j]);
        }
    }
};
 
int main()
{
    int n, m, edge1, edge2;
    vector <vector<int>> graph;
    vector <vector<int>> component;
    ifstream cin("components.in");
    cin >> n >> m;
    vector <int> used;
    used.resize(n + 1);
    for (int i = 0; i < used.size(); i++) {
        used[i] = 0;
    }
    graph.assign(n + 1, vector<int>());
    for (int i = 0; i < m; i++) {
        cin >> edge1 >> edge2;
        graph[edge1].push_back(edge2);
        graph[edge2].push_back(edge1);
 
    }
    for (int i = 1; i <= n; i++) {
        if ((graph[i].size() != 0) && (used[i] == 0)) {
            component.push_back(vector<int>());
            dfs(used, component, graph, i);
        }
        else if (used[i] == 0) {
            component.push_back(vector<int>());
            component.back().push_back(i);
            used[i]=component.size();
        }
    }
 
    ofstream cout("components.out");
 
    cout << component.size() << "\n";
 
    for (int i = 1; i < used.size(); i++) {
        cout << used[i] << " ";
    }
 
 
}
