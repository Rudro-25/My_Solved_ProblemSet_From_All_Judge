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
ll cc;

void solve(){
   cout<<"Case #"<<++cc<<": ";
   ll n=4,mx=0;
   vector<ll> a(n),b(n),c(n),d(n),ans(n); 
   for(ll i=0;i<n;i++) cin>>a[i];
   for(ll i=0;i<n;i++) cin>>b[i];
   for(ll i=0;i<n;i++) cin>>c[i];
   
   for(ll i=0;i<n;i++){
      ll mn= min(a[i],b[i]);
      mn= min(mn,c[i]);
      if(mn==0){
         cout<<"IMPOSSIBLE"<<endl;
         return;
      }
      mx+=mn;
      ans[i]=1;
      d[i]= mn-1;
   }

   if(mx<N){
      cout<<"IMPOSSIBLE"<<endl;
      return;
   }
   ll lage= N-4;
   for(ll i=0;i<n;i++){
      ll baki= min(lage,d[i]);
      ans[i]+=baki;
      lage-=baki;
   }
   for(ll i=0;i<n;i++)
      cout<<ans[i]<<' ';
   cout<<endl;

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
