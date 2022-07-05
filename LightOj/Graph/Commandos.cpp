#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define dhoom3   ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);

const int N= 2e5+5;
vector<ll> adj[N];
ll dist1[N],dist2[N]; 
bool vis[N];
void bfs(ll src,ll *dist){
    dist[src]=0;
    vis[src]= true;
    queue<ll> q;
    q.push(src);
    while(!q.empty()){
        ll top= q.front();
        q.pop();
        for(int child: adj[top]){
            if(!vis[child]){
              q.push(child);
              dist[child]= dist[top]+1;
              vis[child]=true;
            }
        }
    }
}

int main(){
   dhoom3; 
   int Test=1;
   cin>>Test;
   for(ll tt=1;tt<=Test;tt++){
       ll n,m; cin>>n>>m;
       for(ll i=0;i<=n;i++){
        vis[i]=false; adj[i].clear();
       }
       for(ll i=0;i<m;i++){
        ll x,y; cin>>x>>y;
        adj[x].pb(y); adj[y].pb(x);
       }
       ll s,t; cin>>s>>t;

       bfs(s,dist1);
       memset(vis, 0, sizeof(vis));
        bfs(t,dist2);
        ll ans=0;
        for(ll i=0;i<n;i++){
          ans=max(ans,dist1[i]+dist2[i]);
        }

       cout<<"Case "<<tt<<": "<<ans<<endl;
       
    
   }
   //cout << (ans ? "YES\n" : "No\n") ;
   return 0;
}
/*

*/
