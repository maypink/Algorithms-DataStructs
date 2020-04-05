#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include "iomanip"
using namespace std;
 
double calcDist(int coord1x, int coord1y, int coord2x, int coord2y) {
    return sqrt((coord1x - coord2x) * (coord1x - coord2x) + (coord1y - coord2y) * (coord1y - coord2y));
}
 
int main()
{
    ifstream cin("spantree.in");
    int N, coord1, coord2;
    cin >> N;
    vector <vector <double>> graph;
    graph.assign(N, vector<double>(N));
    vector<pair<int, int>> coordinates;
 
    for (int i = 0; i < N; i++) {
        cin >> coord1 >> coord2;
        coordinates.push_back(make_pair(coord1, coord2));
    }
     
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            graph[i][j] = calcDist(coordinates[i].first,coordinates[i].second,coordinates[j].first,coordinates[j].second);
        }
    }
   
    const int INF = 1e9;
    vector <double> dist(N, INF);
    dist[0] = 0;
    vector <bool> used(N, false);
    double ans = 0;
    int curVert = 0;
    for (int i = 0; i < N; ++i)
    {
        double min_dist = INF; 
        int curVert = 0;
        for (int j = 0; j < N; ++j)
            if (!used[j] && dist[j] < min_dist)
            {
                min_dist = dist[j];
                curVert = j;
            }
        ans += min_dist;
        used[curVert] = true;
        for (int v = 0; v < N; ++v)
            dist[v] = min(dist[v], graph[curVert][v]);
    }
    ofstream cout("spantree.out");
    cout << fixed << setprecision(10) << ans;
}
