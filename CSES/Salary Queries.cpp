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

void solve(){
   ll n,q;
   cin>>n>>q;
   vector<ll> a(n);
   ordered_set<ll> st;
   for(ll i=0;i<n;i++){
     cin>>a[i];
     st.insert(a[i]);
   }

   while(q--){
        char ch; int l,r;
        cin>>ch>>l>>r;
        if(ch=='?'){
            ll ans= st.order_of_key(r+1) - st.order_of_key(l);
            cout<<ans<<endl;
        }
        else{
            st.erase(st.find_by_order(st.order_of_key(a[l-1])));
            a[l-1]=r;
            st.insert(r);
        }
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
