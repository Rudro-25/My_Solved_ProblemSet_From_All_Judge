#include <bits/stdc++.h>
using namespace std;

#define      PSB         push_back
#define      ll          long long
#define      FastIO      ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
constexpr ll mod = 1e9  + 7;
const ll N=1e4+5;

int n,m; // number of nodes and edge
vector<ll> adj[N];  // adjacency list of graph

vector<bool> visited;
vector<int> tin, low;
int timer,ans;
set<int> st;

void dfs(int v, int p = -1) {
    visited[v] = true;
    tin[v] = low[v] = timer++;
    int children=0;
    for (int to : adj[v]) {
        if (to == p) continue;
        if (visited[to]) {
            low[v] = min(low[v], tin[to]);
        } else {
            dfs(to, v);
            low[v] = min(low[v], low[to]);
            if (low[to] >= tin[v] && p!=-1){
                ++ans;  // v is the cut points
                st.insert(v);
            }
            ++children;
        }
    }
    if(p == -1 && children > 1) //checked for root has >=2 subtree/Forward edge or not
       { ++ans; st.insert(v); }
//cutpoint is a node after removed that node graph divided by two more parts.
}

int main(){
  FastIO

    ll test; cin>>test;
    for(ll tt=1;tt<=test;tt++){
    	cin>>n>>m;  // n nodes and m edges.
    	for(ll i=0;i<n;i++){
    		adj[i].clear(); 
    	}
	    for(ll i=0;i<m;i++){
	        ll x,y; cin>>x>>y;
	        x--,y--;
	        adj[x].PSB(y); adj[y].PSB(x);
	    }
	
	    timer = 0,ans=0;
	    st.clear();
	    visited.assign(n, false);
	    tin.assign(n, -1);
	    low.assign(n, -1);
	    for (int i = 0; i < n; ++i) {
	        if (!visited[i])
	            dfs(i);
	    }
	    cout<<"Case "<<tt<<": "<<st.size()<<endl;
    }
    

  return 0;
}

/*
5 5
1 2
2 3
1 3
2 4
4 5

ans:
4
2
those are cut/articulation points
*/
