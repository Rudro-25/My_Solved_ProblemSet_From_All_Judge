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
const ll N=1e6;
vector<ll> adj[N];
ll cc,ans,mn[N];
ll val[N],p[N];
bool vis[N];
void dfs(ll x,ll par=-1){
   vis[x]=true;
   bool ck=false;
   for(auto v: adj[x]){
      if(!vis[v] && v){
         dfs(v,x);
         ck=true;
      }
   }
   if(!ck){
         ans+=val[x];
         mn[x]=val[x];
         //cout<<x<<' '<<val[x]<<endl;
   }
   if(adj[x].size()>1 || p[x]==0){
      ans+= max(0LL,val[x]-mn[x]);
      mn[x]= max(val[x],mn[x]);
      //cout<<x<<' '<<val[x]-mn[x]<<endl;
   }
   if(par!=-1){
      mn[par]= min(mn[par],mn[x]);
   }
}

void solve(){
   cout<<"Case #"<<++cc<<": ";
   ll n;
   cin>>n;
   for(ll i=0;i<=n;i++){
      adj[i].clear();
      mn[i]= 1e15; vis[i]=false;
   }
   vis[0]=true;
   for(ll i=1;i<=n;i++) cin>>val[i];
   for(ll i=1;i<=n;i++){
      cin>>p[i];
      adj[p[i]].pb(i); adj[i].pb(p[i]);
   }
   ans=0;
   for(ll i=1;i<=n;i++){
      if(!p[i]){
         dfs(i);
      }
   }

   cout<<ans<<endl;
}

int main(){
   InTheNameOfGod;
   ll Test=1;
   cin>>Test;
   while(Test--){
     solve();
    }
  return 0;
}
