#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define ll long long
#define pb push_back
#define dhoom3   ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
template <typename T>
using ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
/*ordered_set<ll> s;
*s.find_by_order(x) //ans at x index in sorted order.
s.order_of_key(x); //index of x or if not find x , it show index no in sort array.*/

const int N= 2e2+5;
vector<ll> adj[N];
bool vis[N];
ll root,ans,sum;
map<pair<ll,ll>,ll> mp;
void dfs(ll node,ll par){
	vis[node]=true;
	for(int child: adj[node]){
		if(child != par && !vis[child]){
			sum+= mp[{node,child}];
			dfs(child,node);
		}
	}
}

int main(){
   dhoom3; 
   int Test=1;
   cin>>Test;
   for(ll tt=1;tt<=Test;tt++){
       ll n; cin>>n;
       for(ll i=1;i<=n;i++){
       	adj[i].clear();
       }
       mp.clear();
       ll u,v,c;
       for(ll i=0;i<n;i++){
       	 cin>>u>>v>>c;
       	 mp[{v,u}]=c; mp[{u,v}]=0;
       	 adj[u].pb(v); adj[v].pb(u);
       }
       memset(vis,0,sizeof(vis));
       sum=mp[{u,v}];
       dfs(v,u);
       ans=sum;
       //cout<<ans<<endl;
       //v_to_u
       memset(vis,0,sizeof(vis));
       sum=mp[{v,u}];
       dfs(u,v);
       ans=min(ans,sum);
       
       cout<<"Case "<<tt<<": "<<ans<<endl;
    
   }
   //cout << (ans ? "YES\n" : "No\n") ;
   return 0;
}
/*

*/
