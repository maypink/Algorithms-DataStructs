#include <iostream>
#include <fstream>
#include <vector>
 
using namespace std;
int main()
{
    int n, m, edge1, edge2;
    ifstream cin("input.txt");
    cin >> n >> m;
    vector <vector<int>> graph;
    graph.assign(n + 1, vector<int>());
    for (int i = 0; i < m; i++) {
        cin >> edge1 >> edge2;
        graph[edge1].push_back(edge2);
        graph[edge2].push_back(edge1);
    }
    ofstream cout("output.txt");
    for (int i = 1; i <= n; i++) {
        cout << graph[i].size() << " ";
    }
}
