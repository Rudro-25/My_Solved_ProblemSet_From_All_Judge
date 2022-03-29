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
//*s.find_by_order(x) //val at x index in sorted order.
//s.order_of_key(x); //index of x or if not find x , it show index no in sort array.


constexpr ll mod = 1e9 + 7;
const ll N=3e6+5;
ll ans[N];

void solve(){
   ll n,answer=0;
   cin>>n;
   vector<pair<pair<ll,ll>,ll>> vp;

   for(ll i=0;i<n;i++){
      ll x,y; cin>>x>>y;
      vp.pb({{x,y},i});
   }
   sort(all(vp));

   multiset<pair<ll,ll>> st;
   ll cnt=0;
   for(ll i=0;i<n;i++){
      ll val= vp[i].first.first;
      auto it= st.lower_bound({val,0LL});
      if(it==st.begin()){
         ++answer;
         ans[vp[i].second]=++cnt;
         st.insert({vp[i].first.second,cnt});
      }
      else{
         it--;
         ll bal= it->second;
         ans[vp[i].second]= bal;
         st.insert({vp[i].first.second,bal});
         st.erase(it);
      }
      
   }

   cout<<answer<<endl;
   for(ll i=0;i<n;i++)
      cout<<ans[i]<<' ';
   


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
10
6 6
5 5
6 6
10 10
7 7
10 10
6 6
8 8
3 3
9 9

ans:
3
3 1 2 2 1 1 1 1 1 1 
*/
