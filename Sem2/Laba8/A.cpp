#include <iostream>
#include <vector>
#include <fstream>

using namespace std;


int main()
{
	int n, m, edge1, edge2;
	ifstream cin("input.txt");
	vector <vector<int>> matrix = { 0, vector<int>(0) };
	cin >> n >> m;
	matrix.assign(n, vector<int>(n));
	for (int i = 0; i < m; i++) {
		cin >> edge1 >> edge2;
		matrix[edge1-1][edge2-1] = 1;
	}
	ofstream cout("output.txt");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << matrix[i][j]<<" ";
		}
		cout << "\n";
	}

}
