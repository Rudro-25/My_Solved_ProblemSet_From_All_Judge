#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define dhoom3   ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);

const int N= 1e4+5;
int n,m; // number of nodes and edge
vector<ll> adj[N];  // adjacency list of graph

vector<bool> visited;
vector<int> tin, low;
int timer;
vector<pair<ll,ll>> ans;

void dfs(int v, int p = -1) {
    visited[v] = true;
    tin[v] = low[v] = timer++;
    for (int to : adj[v]) {
        if (to == p) continue;
        if (visited[to]) { //Back edge
            low[v] = min(low[v], tin[to]);
        } else {  //Forward edge
            dfs(to, v);
            if (low[to] > tin[v]){
                //cout<<v+1<<' '<<to+1<<endl; // v-to is the bridge
                ans.pb({min(v,to),max(v,to)});
            }
            low[v] = min(low[v], low[to]);
//Bridge is a edge after removed that edge graph divided by two more parts.
        }
    }
}


int main(){
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
   dhoom3; 
   int Test=1;
   cin>>Test;
   for(ll tt=1;tt<=Test;tt++){
       ans.clear();
       cin>>n;
       for(ll i=0;i<=n;i++) adj[i].clear();
       for(ll i=0;i<n;i++){
        ll u; cin>>u;
        string s; cin>>s; 
        ll k=0;
        for(ll j=1;j<s.size()-1;j++){
          ll val= s[j]-'0';
          k*=10; k+=val;
        }
        for(ll j=0;j<k;j++){
          ll v; cin>>v;
          adj[u].pb(v); adj[v].pb(u);
        }
       }

        timer = 0;
        visited.assign(n, false);
        tin.assign(n, -1);
        low.assign(n, -1);
        for (int i = 0; i < n; ++i) {
            if (!visited[i])
                dfs(i);
        }
        cout<<"Case "<<tt<<":"<<endl;
        cout<<ans.size()<<" critical links"<<endl;
        sort(ans.begin(),ans.end());
        for(ll i=0;i<ans.size();i++)
          cout<<ans[i].first<<" - "<<ans[i].second<<endl;

   }
   //cout << (ans ? "YES\n" : "No\n") ;
   return 0;
}
/*

*/
