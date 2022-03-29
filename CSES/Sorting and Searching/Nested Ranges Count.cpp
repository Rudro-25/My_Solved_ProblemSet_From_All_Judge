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
//ordered_set<ll> s;
//*s.find_by_order(x) //val at x index in sorted order.
//s.order_of_key(x); //index of x or if not find x , it show index no in sort array.
 
constexpr ll mod = 1e9 + 7;
const ll N=3e6+5;
ll ans1[N],ans2[N];
 
void solve(){
   ll n,k=1;
   cin>>n;
   ordered_set<ll> st;
   vector<pair<pair<ll,ll>,ll>> vp,vpp;
 
   for(ll i=0;i<n;i++){
      ll x,y; cin>>x>>y;
      vp.pb({{x,-y},i});
      vpp.pb({{y,-x},i});
   }
 
   sort(all(vp)); sort(all(vpp));
   map<ll,ll> mp;
   ll mx=0,mn=1e9;
   for(ll i=0;i<n;i++){
      ll val= vpp[i].first.second;
      ll pos= st.order_of_key(val);
      //cout<<pos<<endl;
      ans1[vpp[i].second]=pos+mp[val];
      st.insert(val); 
      mp[val]++;
   }
   st.clear();
   mn=1e9;
   mp.clear();
   for(ll i=0;i<n;i++){
      ll val= vp[i].first.second;
      ll pos= st.order_of_key(val);
      //cout<<pos<<endl;
      ans2[vp[i].second]=pos+mp[val];
      st.insert(val); 
      mp[val]++;
   }
 
   for(ll i=0;i<n;i++) cout<<ans1[i]<<' '; cout<<endl;
   for(ll i=0;i<n;i++) cout<<ans2[i]<<' '; cout<<endl;
 
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
