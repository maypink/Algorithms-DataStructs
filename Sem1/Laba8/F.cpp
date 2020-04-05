#include <iostream>
#include <vector>
#include <fstream>
#include <queue>
#include <stack>
 
using namespace std;
 
int bfs(vector<vector<int>>& graph, queue<int>& track, vector<int>used, vector<int>& distance, vector<string>&way, int finish, int m) {
    int curVert;
    while (!track.empty()) {
        curVert = track.front();
        track.pop();
        for (int j = 0; j < graph[curVert].size(); j++) {
 
            if (used[graph[curVert][j]] == 0) {
                if ((graph[curVert][j] == curVert + 1)&&(m!=1)) {
                    way[graph[curVert][j]]=way[curVert]+'R';
                } else if ((graph[curVert][j] == curVert - 1)&&(m!=1)) {
                    way[graph[curVert][j]]= way[curVert] + 'L';
                } else if (graph[curVert][j] == curVert + m) {
                    way[graph[curVert][j]] = way[curVert] + 'D';
                }
                else if (graph[curVert][j] == curVert - m) {
                    way[graph[curVert][j]] = way[curVert] + 'U';
                };
 
                track.push(graph[curVert][j]);
                used[graph[curVert][j]]++;
                distance[graph[curVert][j]] = distance[curVert] + 1;
                if (graph[curVert][j] == finish) return distance[graph[curVert][j]];
                 
            }
        }
    }
    return 0;
}
 
int main()
{
    int n, m, start, finish;
    char labString;
    vector <char> labirint;
    ifstream cin("input.txt");
    cin >> n >> m;
    for (int i = 0; i < n * m; i++) {
        cin >> labString;
        if (labString == 'S') {
            start = i;
        }
        else if (labString == 'T') {
            finish = i;
        }
        labirint.push_back(labString);
    }
 
    vector<vector<int>> graph;
    graph.assign(labirint.size() + 1, vector<int>());
    for (int i = 0; i < labirint.size(); i++) {
        if ((labirint[i] == '.') || (labirint[i] == 'S') || (labirint[i] == 'T')) {
            if ((i - 1 > -1) && (i % m != 0)&&((labirint[i - 1] == '.') || (labirint[i - 1] == 'S') || (labirint[i - 1] == 'T'))) {
                graph[i].push_back(i - 1);
            }
            if ((i + 1 < n * m) && ((i + 1) % m != 0) && ((labirint[i + 1] == '.') || (labirint[i + 1] == 'S') || (labirint[i + 1] == 'T'))) {
                graph[i].push_back(i + 1);
            }
            if ((i + m < n * m) && ((labirint[i + m] == '.') || (labirint[i + m] == 'S') || (labirint[i + m] == 'T'))) {
                graph[i].push_back(i + m);
            }
            if ((i - m > -1) && ((labirint[i - m] == '.') || (labirint[i - m] == 'S') || (labirint[i - m] == 'T'))) {
                graph[i].push_back(i - m);
            }
        }
    }
    vector <int>distance;
    distance.resize(n * m);
 
    vector <int> used;
    used.resize(n * m);
    used[start] = 1;
 
    queue <int> track;
    track.push(start);
 
    vector<string> way;
    way.resize(graph.size());
 
    int distanceFinish = bfs(graph, track, used, distance, way, finish, m);
 
    ofstream cout("output.txt");
    if (distanceFinish == 0) {
        cout << -1;
    }
    else {
        cout << distanceFinish << "\n" << way[finish];
    }
}
