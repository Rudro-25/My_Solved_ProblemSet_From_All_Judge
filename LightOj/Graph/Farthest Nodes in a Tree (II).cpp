#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define dhoom3   ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);

const int N= 3e4+5;
vector<ll> adj[N];
ll d1[N],d2[N];
bool used[N];
ll n,mx,ind;
map<pair<ll,ll>,ll> mp;
void bfs(ll s,ll *d){
  queue<ll> q;
  q.push(s);
  d[s]=0;
  used[s] = true;
  while (!q.empty()) {
      int v = q.front();
      q.pop();
      for (int u : adj[v]) {
          if (!used[u]) {
              used[u] = true;
              q.push(u);
              d[u] = d[v] + mp[{u,v}];
              if(d[u]>mx){
                mx=d[u]; ind=u;
              }
          }
      }
  } 
}



int main(){
   dhoom3; 
   int Test=1;
   cin>>Test;
   for(ll tt=1;tt<=Test;tt++){
       mp.clear();
       cin>>n;
       for(ll i=0;i<n;i++) adj[i].clear(),used[i]=false;
       for(ll i=1;i<n;i++){
         ll u,v,c; cin>>u>>v>>c;
         adj[u].pb(v); adj[v].pb(u);
         mp[{u,v}]=c,mp[{v,u}]=c;
       }

      mx=0,ind=-1;
      bfs(0, d1);
      memset(used,0,sizeof(used));
      mx=0;
      bfs(ind,d1);
      memset(used,0,sizeof(used));
      bfs(ind,d2);
      
      cout<<"Case "<<tt<<":"<<endl;
      for(ll i=0;i<n;i++){
        //cout<<d1[i]<<' '<<d2[i]<<endl;
        cout<<max(d1[i],d2[i])<<endl;
      }
    
   }
   //cout << (ans ? "YES\n" : "No\n") ;
   return 0;
}
/*

*/
