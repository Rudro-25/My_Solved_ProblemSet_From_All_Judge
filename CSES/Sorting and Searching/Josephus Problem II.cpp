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
//ordered_set<ll> s;
//*s.find_by_order(x) //val at x index in sorted order.
//s.order_of_key(x); //index of x or if not find x , it show index no in sort array.
 
constexpr ll mod = 1e9 + 7;
const ll N=3e6+5;
 
void solve(){
   ll n,k=1;
   cin>>n>>k;
   ordered_set<ll> st;
   for(ll i=1;i<=n;i++) st.insert(i);
   ll p=k%n;
   while(st.size()){
     ll val= *st.find_by_order(p);
     st.erase(val);
     if(st.size()) p= (p+k)%st.size();
     cout<<val<<' ';
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
