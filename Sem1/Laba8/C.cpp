#include <iostream>
#include <vector>
#include <fstream>
 
using namespace std;
 
string check(vector<vector<int>>&matrix, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (((i != j) && (matrix[i][j] == 1) && (matrix[j][i] == 1))||(matrix[i][j]>1)) return "YES";
        }
    }
    return "NO";
};
 
int main()
{
    int n, m, edge1, edge2;
    vector <vector<int>> matrix = {0, vector<int>(0)};
    ifstream cin("input.txt");
    cin >> n >> m;
    matrix.assign(n, vector<int>(n));
    for (int i = 0; i < m; i++) {
        cin >> edge1 >> edge2;
        matrix[edge1-1][edge2-1]++;
    }
    ofstream cout("output.txt");
    cout<<check(matrix, n);
}
