#include <iostream>
#include <vector>
#include <fstream>
#include <stack>
 
using namespace std;
 
void dfs(vector<vector<int>>&graph, vector<int>&used, vector<int>&order, int cur, stack <int>&vert) {
    used[cur] = 1;
    for (int i = 0; i < graph[cur].size(); i++) {
        if (used[graph[cur][i]] == 0) {
            dfs(graph, used, order, graph[cur][i], vert);
            used[0]++;
            order[graph[cur][i]] = used[0];
            vert.push(graph[cur][i]);
             
        }
    }
}
 
void dfs_comp(vector<vector<int>>&graphInv, vector<int>&comp, int cur, int &cur_comp) {
    comp[cur] = cur_comp;
    for (int i = 0; i < graphInv[cur].size(); i++) {
        if (comp[graphInv[cur][i]] == 0) {
            dfs_comp(graphInv, comp, graphInv[cur][i], cur_comp);
        } 
    }
}
 
int main()
{
    int n, m, edge1, edge2;
    ifstream cin("cond.in");
    cin >> n >> m;
    vector<vector<int>> graph;
    vector<vector<int>> graphInv;
    vector<int> order;
    vector <int> used;
    stack<int> vert;
    vector <int> comp;
     
    order.resize(n + 1);
    used.resize(n + 1);
    comp.resize(n + 1);
    graph.assign(n+1, vector<int>());
    graphInv.assign(n + 1, vector<int>());
    for (int i = 0; i < m; i++) {
        cin >> edge1 >> edge2;
        graph[edge1].push_back(edge2);
        graphInv[edge2].push_back(edge1);
    }
 
    for (int i = 1; i < graph.size(); i++) {  //получаем порядок выкатывания и нумерацию вершин от большего
        if (used[i] == 0) {
            dfs(graph, used, order, i, vert);
            used[0]++;
            order[i] = used[0];
            vert.push(i);
        }
    }
 
    int cur_comp = 1;
    int cur_vert = 0;
    for (int i = 1; i < graphInv.size(); i++) {
        cur_vert = vert.top();
        vert.pop();
        if (comp[cur_vert] == 0) {
            dfs_comp(graphInv, comp, cur_vert, cur_comp);
            cur_comp++;
        }
    }
 
    ofstream cout("cond.out");
 
    cout << cur_comp-1 << "\n";
    for (int i = 1; i < comp.size(); i++) {
        cout << comp[i] << " ";
    }
 
}
