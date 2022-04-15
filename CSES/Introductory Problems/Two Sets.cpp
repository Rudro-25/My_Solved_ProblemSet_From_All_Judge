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
   ll n,ans=0;
   cin>>n;
       vector<ll> ans1,ans2;
       ll sum= (n*(n+1))/2;
       ll haf= sum/2;
       ll baki= haf;
       for(ll i=n;i>=1;i--){
           if(haf>=i){
               ans1.pb(i); haf-=i;
           }
           else{
               ans2.pb(i); baki-=i;
           }
       }
       if(!haf && !baki && ans1.size() && ans2.size()){
            cout<<"YES"<<endl;
            cout<<ans1.size()<<endl;
            for(auto it: ans1) cout<<it<<' '; cout<<endl;
            cout<<ans2.size()<<endl;
            for(auto it: ans2) cout<<it<<' '; cout<<endl;
       }
       else cout<<"NO"<<endl;
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
