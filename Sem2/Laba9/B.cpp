#include <iostream>
#include <fstream>
#include <vector>
 
using namespace std;
 
bool dfs(vector<int>& used, vector<vector<int>>& List, vector<int>& from, int& start, int& end, int& cur) {
    used[cur] = 1;
    for (int i = 0; i < List[cur].size(); i++) {
        if (used[List[cur][i]] == 0) {
            from[List[cur][i]] = cur;
            if (dfs(used, List, from, start, end, List[cur][i]))
                return true;
        }
        else if (used[List[cur][i]] == 1 && from[List[cur][i]] != cur) {
            start = cur;
            end = List[cur][i];
            return true;
        }
    }
    used[cur] = 2;
    return false;
}
 
int main() {
    ifstream inp("cycle.in");
    ofstream outp("cycle.out");
    int GraphVertex, GraphEdge;
    inp >> GraphVertex >> GraphEdge;
    vector<vector<int>> List(GraphVertex, vector<int>());
    int Edge1, Edge2;
    for (int i = 0; i < GraphEdge; i++) {
        inp >> Edge1 >> Edge2;
        Edge1 -= 1;
        Edge2 -= 1;
        List[Edge1].push_back(Edge2);
    }
    vector<int> used(GraphVertex, 0);
    vector<int> from(GraphVertex, 0);
    int start, end;
    start = -1;
    for (int i = 0; i < GraphVertex; i++) {
        if (used[i] == 0) {
            if (dfs(used, List, from, start, end, i))
                break;
        }
    }
    if (start > -1) {
        vector<int> way;
        way.push_back(end + 1);
        for (int i = start; i != end; i = from[i])
            way.push_back(i + 1);
        outp << "YES\n";
        for (int i = way.size() - 1; i >= 0; i--)
            outp << way[i] << ' ';
        return 0;
    }
    outp << "NO";
    return 0;
}
