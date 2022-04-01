#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define      ll                  long long
#define      pb                 push_back
#define      mp                 make_pair
#define      all(x)             x.begin(),x.end()
#define      Ceil(x,y)           ((x+y-1)/y)
#define      gcd(a,b)            __gcd(a,b)
#define      lcm(a,b)           (a*b)/gcd(a,b)
#define      InTheNameOfGod      ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);

template <typename T>
using ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

constexpr ll mod = 1e9 + 7;
const ll N=3e6+5;
vector<ll> adj[N];
bool vis[N],check[N];
ll ans;
void dfs(ll v,ll par=-1){
    vis[v] = true;
    for (int u : adj[v]) {
        if (!vis[u])
            dfs(u,v);
    }
    if(!check[v] && !check[par] && par!=-1){
      ++ans; check[v]=check[par]=true;
    }
}


void solve(){
   ll n;
   cin>>n;
   
   for(ll i=2;i<=n;i++){
      ll a,b; cin>>a>>b;
      adj[a].pb(b); adj[b].pb(a);
   }
   
   for(ll i=1;i<=n;i++){
      if(adj[i].size()==1){
         dfs(i); break;
      }
   }

   cout<<ans<<endl;



}

int main(){
   InTheNameOfGod;
   ll Test=1;
   //cin>>Test;
   while(Test--){
     solve();
    }
  return 0;
}
