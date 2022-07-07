#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define dhoom3   ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);

const int N= 1e3+5;
vector<ll> adj[N];
ll val[N],sum;
ll cnt,cur;
bool vis[N],chk;
void dfs(ll node){
  cnt++; cur+=val[node];
  vis[node]=true;
  for(int child: adj[node]){
    if(!vis[child]) dfs(child);
  }
}


int main(){
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
   dhoom3; 
   int Test=1;
   cin>>Test;
   for(ll tt=1;tt<=Test;tt++){
       sum=0; chk=true;
       ll n,m; cin>>n>>m;
       for(ll i=1;i<=n;i++){
         cin>>val[i];
         sum+=val[i];
         adj[i].clear();
       }
       for(ll i=0;i<m;i++){
         ll u,v; cin>>u>>v;
         adj[u].pb(v); adj[v].pb(u);
       }
       cout<<"Case "<<tt<<": ";
       if(sum%n != 0) chk=false;
       memset(vis,0,sizeof(vis));
       ll vag= sum/n;
       for(ll i=1;i<=n;i++){
        if(!vis[i]){
          cnt=0,cur=0;
          dfs(i);
          if(cur%cnt != 0 || cur/cnt != vag) chk=false;
        }
       }

       if(chk) cout<<"Yes"<<endl;
       else cout<<"No"<<endl;

       
    
   }
   //cout << (ans ? "YES\n" : "No\n") ;
   return 0;
}
/*

*/
