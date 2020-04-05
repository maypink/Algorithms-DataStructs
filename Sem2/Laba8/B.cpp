#include <iostream>
#include <vector>
#include <fstream>
 
using namespace std;
 
string check(vector<vector<int>>&matrix, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if ((i == j) && (matrix[i][j] == 1)) return "NO";
            if (matrix[i][j] != matrix[j][i]) return "NO";
        }
    }
    return "YES";
}
int main()
{
    int n;
    vector <vector<int>> matrix;
    ifstream cin("input.txt");
    cin >> n;
    matrix.assign(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }
    ofstream cout("output.txt");
    cout<<check(matrix, n);
}
