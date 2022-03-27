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
ll a[N],ind[N];

void solve(){
   ll n,q; cin>>n>>q;
   for(ll i=0;i<n;i++){
      cin>>a[i];
      ind[a[i]]=i;
   }
   ind[n+1]=n+1;
   
   ll ans=1;
   for(ll i=1;i<=n;i++){
     if(ind[i]<ind[i-1]) ans++;
   }
   
   //cout<<ans<<endl;

   while(q--){
      ll x,y; cin>>x>>y;
      ll xx=a[x-1],yy=a[y-1];
      ll mx= max(xx,yy);
      swap(a[x-1],a[y-1]);
      if(ind[xx]<ind[xx-1] && (xx-yy)!=1) ans--;
      if(ind[yy]<ind[yy-1] && (yy-xx)!=1) ans--;
      if(ind[xx+1]<ind[xx]) ans--;
      if(ind[yy+1]<ind[yy]) ans--;
      swap(ind[xx],ind[yy]);
      //cout<<ans<<' ';
      if(ind[xx]<ind[xx-1] && (xx-yy)!=1) ans++;
      if(ind[yy]<ind[yy-1] && (yy-xx)!=1) ans++;
      if(ind[xx+1]<ind[xx]) ans++;
      if(ind[yy+1]<ind[yy]) ans++;
      cout<<ans<<endl;
   }

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
/*
5
4 2 1 5 3
*/
