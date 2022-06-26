#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define dhoom3   ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);

const int N= 2e5+5;
ll chk[1005],cnt,cc,ans;
ll k,n,m; 
bool vis[1005];
vector<ll> adj[1005];
void dfs(int v){
  vis[v]=true;
  chk[v]++;
  if(chk[v]==k) ++ans;
  for(int child: adj[v]){
    if(!vis[child]) dfs(child);
  }
}

int main(){
   dhoom3;
   int Test=1;
   cin>>Test;
   while(Test--){
       cin>>k>>n>>m;
       for(ll i=1;i<=n;i++) chk[i]=0,adj[i].clear();
       ll a[k];
       for(ll i=0;i<k;i++){
         cin>>a[i];
       }

       for(ll i=0;i<m;i++){
         ll u,v; cin>>u>>v;
         adj[u].pb(v);
       }
       ans=0;
       for(ll i=0;i<k;i++){
         for(ll j=1;j<=n;j++) vis[j]=false;
         dfs(a[i]);
       }
       cout<<"Case "<<++cc<<": "<<ans<<endl;
   }
   //cout << (ans ? "YES\n" : "No\n") ;
   return 0;
}
/*

*/
