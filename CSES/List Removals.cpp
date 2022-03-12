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
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

constexpr ll mod = 1e9 + 7;
const ll N=3e6+5;

void solve(){
   ll n;
   ordered_set<ll> st;
   cin>>n;
   vector<ll> x(n); 
   for(ll i=0;i<n;i++){
    cin>>x[i];
    st.insert(i);
   }
   for(ll i=0;i<n;i++){
     ll ind; cin>>ind; 
     --ind;
     int pos= *st.find_by_order(ind);
     st.erase(pos);
     cout<<x[pos]<<' ';
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
