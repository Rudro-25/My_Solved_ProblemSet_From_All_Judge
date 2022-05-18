//kosaraju's algo- SCC
//https://www.hackerearth.com/practice/algorithms/graphs/strongly-connected-components/practice-problems/algorithm/a-walk-to-remember-qualifier2/

#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define dhoom3   ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);

const int N= 2e5+5;
vector<ll> adj[N],tr[N],order,SCC;
bool vis[N];
ll ans[N];
void dfs(int node){
    vis[node]=1;
    for(int child: adj[node]){
        if(!vis[child]) dfs(child);
    }
    order.pb(node);
}
void dfs1(int node){
    vis[node]=1;
    for(int child: tr[node]){
        if(!vis[child]) dfs1(child);
    }
    SCC.pb(node);
}

int main(){
   dhoom3;
   int Test=1;
   //cin>>Test;
   while(Test--){
       ll n,m; cin>>n>>m;
       for(ll i=0;i<=n;i++){
           adj[i].clear(), tr[i].clear(),vis[i]=0;
           order.clear();
       }
       for(ll i=0;i<m;i++){
           ll a,b; cin>>a>>b;
           adj[a].pb(b);
           tr[b].pb(a);
       }
       for(ll i=1;i<=n;i++){
           if(!vis[i]) dfs(i);
       }
       for(ll i=0;i<=n;i++) vis[i]=0;
       for(ll i=n-1;i>=0;i--){
           if(!vis[order[i]]){
               SCC.clear();
               dfs1(order[i]);
               if(SCC.size()>1){
                   for(int node: SCC)
                    ans[node]=1;
               }
           }
       }
       for(ll i=1;i<=n;i++)
       cout<<ans[i]<<' ';
    
   }
   //cout << (ans ? "YES\n" : "No\n") ;
   return 0;
}
/*
5 5 
1 2
2 3
3 4
4 5
4 2

ans:
0 1 1 1 0
*/
