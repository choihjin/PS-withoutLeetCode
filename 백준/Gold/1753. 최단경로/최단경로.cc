#include <bits/stdc++.h>
using namespace std;
#define INF 0xffffff

vector<pair<int, int> > adj_list[20002];
int v, e, start;

void addEdge(int from, int to, int w);
void dijkstra(int start);

int main() {
    cin >> v >> e >> start;
    for(int i=0; i<e; i++) {
        int from, to, weight;
        cin >> from >> to >> weight;
        addEdge(from-1, to-1, weight);
    }

    dijkstra(start-1);

    return 0;
}

void addEdge(int from, int to, int w) 
{
    adj_list[from].push_back(make_pair(to, w));
}

void dijkstra(int start) 
{
    vector<int> dist(v, INF);
    priority_queue<pair<int, int> > Q;
    
    dist[start] = 0;
    Q.push(make_pair(0, start));
 
    while (!Q.empty()) {
        int cost = -Q.top().first;
        int cur = Q.top().second;
        Q.pop();
 
        for (int i = 0; i < adj_list[cur].size(); i++) { 
            int next = adj_list[cur][i].first;
            int next_cost = cost + adj_list[cur][i].second;
            if (next_cost < dist[next] ) {
                dist[next] = next_cost;
                Q.push(make_pair(-next_cost, next));
            }
        }
    }

    for(auto a : dist) {
        if(a == INF) cout << "INF\n";
        else cout << a << "\n";
    }
}