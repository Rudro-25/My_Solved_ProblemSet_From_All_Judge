#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define dhoom3   ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);

const int N= 510;
vector<int> adj[N];
int ans,cc,n,m;

void bfs(int src){

   vector<int> dist(n, INT_MAX ); 
   vector<int> par(n, -1); 
   queue<int> q;
   q.push(src);
   dist[src]=0;
   par[src]=-1;

   while(!q.empty()){
     ll val= q.front();
     q.pop();
     for(int nxt: adj[val]){
        if(dist[nxt]==INT_MAX){
          dist[nxt]= dist[val]+1;
          q.push(nxt);
          par[nxt]=val;
        }
        else if(nxt != par[val]){
          ans=min(ans,dist[val]+dist[nxt]+1);
          //if(ans==2) cout<<src<<' '<<val<<' '<<nxt<<endl;
        }
     }
   }
}

int main(){
   dhoom3;
   int Test=1;
   cin>>Test;
   while(Test--){
       cin>>n>>m;
       for(ll i=0;i<n;i++) adj[i].clear();

       for(ll i=0;i<m;i++){
         ll u,v; cin>>u>>v;
         adj[u].pb(v); adj[v].pb(u);
       }
       ans= INT_MAX;
       for(ll i=0;i<n;i++){
          bfs(i);
       }
       cout<<"Case "<<++cc<<": ";
       if(ans==INT_MAX) cout<<"impossible"<<endl;
       else cout<<ans<<endl;


       
       
    
   }
   //cout << (ans ? "YES\n" : "No\n") ;
   return 0;
}
/*

*/
