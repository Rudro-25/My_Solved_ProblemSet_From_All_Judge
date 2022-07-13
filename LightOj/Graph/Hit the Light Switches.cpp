//kosaraju's algo- SCC
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define dhoom3   ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);

const int N= 2e5+5;
vector<ll> adj[N],tr[N],order,SCC;
ll val[N],indegree[N];
bool vis[N];
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
    #ifndef ONLINE_JUDGE
     freopen("input.txt", "r", stdin);
     freopen("output.txt", "w", stdout);
    #endif
   dhoom3;
   int Test=1;
   cin>>Test;
   for(ll tt=1;tt<=Test;tt++){
       ll n,m; cin>>n>>m;
       for(ll i=1;i<=n;i++){
           adj[i].clear(), tr[i].clear(),vis[i]=0;
           order.clear();
           val[i]=-1; indegree[i]=0;
       }
       ll aa[m+1],bb[m+1];
       for(ll i=1;i<=m;i++){
           ll a,b; cin>>a>>b;
           aa[i]=a,bb[i]=b;
           adj[a].pb(b);
           tr[b].pb(a);
       }
       for(ll i=1;i<=n;i++){
           if(!vis[i]) dfs(i);
       }
       for(ll i=1;i<=n;i++) vis[i]=0;
       ll cnt=0;
       for(ll i=n-1;i>=0;i--){
           if(!vis[order[i]]){
               cnt++;
               SCC.clear();
               dfs1(order[i]);
               for(int node: SCC){
                 val[node]=cnt;
                 //cout<<node<<' ';
               }
              // cout<<endl;
               //cout<<node<<' '; cout<<endl;
           }
       }
       ll ans=0;
       for(ll i=1;i<=m;i++){
         if(val[aa[i]] != val[bb[i]])  indegree[val[bb[i]]]++;
       }
       for(ll i=1;i<=cnt;i++){
        if(!indegree[i]) ++ans;
       }
       cout<<"Case "<<tt<<": ";
       cout<<ans<<endl;
    
   }
   //cout << (ans ? "YES\n" : "No\n") ;
   return 0;
}
/*
7 8
1 2
2 3
3 1
4 3
7 4
7 5
6 7
5 6

ans:
6 7 5
4
2 3 1
*/
