#include <bits/stdc++.h>
using namespace std;

#define      PSB         push_back
#define      ll          long long
#define      MP          make_pair
#define      FastIO      ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
constexpr ll mod = 1e9  + 7;
const ll N=3e6+5;

int n,m;
const int INF = 1000000000;
vector<vector<pair<int, int>>> adj(105);
vector<int> d,p,path;

//complexity: ( nlogn + m ).
void dijkstra(int s, vector<int> & d, vector<int> & p) {
    //int n = adj.size();
    d.assign(n, INF);
    p.assign(n, -1);

    d[s] = 0;
    using pii = pair<int, int>;
    priority_queue<pii, vector<pii>, greater<pii>> q;
    q.push({0, s});
    while (!q.empty()) {
        int v = q.top().second;
        int d_v = q.top().first;
        q.pop();
        if (d_v != d[v]) //Checking outdated data
            continue;

        for (auto edge : adj[v]) {  
            int to = edge.first;
            int len = edge.second;

            if (d[v] + len < d[to]) {
                d[to] = d[v] + len;
                p[to] = v;
                q.push({d[to], to});
            }
        }
    }
}

int main(){
  FastIO
   
   ll Test;  cin>>Test;
   for(ll tt=1;tt<=Test;tt++){

        cin>>n>>m;
        for(ll i=0;i<n;i++) adj[i].clear();

        for(int i=0;i<m;i++){
            int a,b,w; cin>>a>>b>>w;
            --a,--b;
            adj[a].PSB(MP(b,w));
            adj[b].PSB(MP(a,w));
        }

        dijkstra(0, d, p);

        cout<<"Case "<<tt<<": ";
        if(d[n-1]==INF) cout<<"Impossible"<<endl;
        else cout<<d[n-1]<<endl;

    }

  return 0;
}

/*
4 4
1 2 4
1 3 2
2 4 1
3 4 2

ans:
0 4 2 4
1 3 4

*/
