//https://www.spoj.com/problems/SUBMERGE/

#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define dhoom3   ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);

const int N= 2e5+5;
vector<ll> adj[N];
ll tin[N],low[N],timer;
bool vis[N];
set<ll> ans;
void Find_CutPoint(int node,int par=-1){
    ll children=0;
    vis[node]=1;
    low[node]=tin[node]= ++timer;
    for(int child: adj[node]){
        if(child==par) continue; 
        if(vis[child]) low[node]=min(low[node],tin[child]);
        else{
            Find_CutPoint(child,node);
            if(low[child]>=tin[node] && par!=-1){
                ans.insert(node);
            }
            low[node]=min(low[node],low[child]);
            children++;
        }
    }
    if(children>1 && par==-1) ans.insert(node);
}

int main(){
   dhoom3;

   while(1){
       ll n,m; cin>>n>>m;
       if(!n) break;
       ans.clear();
       for(ll i=1;i<=n;i++){
           adj[i].clear();
           vis[i]=false; tin[i]=low[i]=1e9;
       }
       for(ll i=0;i<m;i++){
           ll x,y; cin>>x>>y;
           adj[x].pb(y); adj[y].pb(x);
       }
       timer=0;
       for(ll i=1;i<=n;i++)
         if(!vis[i]) Find_CutPoint(i);

       cout<<ans.size()<<endl;
   }
   //cout << (ans ? "YES\n" : "No\n") ;
   return 0;
}
/*
6 8
1 3 
6 1
6 3
4 1
6 4
5 2
3 2
3 5
*/
