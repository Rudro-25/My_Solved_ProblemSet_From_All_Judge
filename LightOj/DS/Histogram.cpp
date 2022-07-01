//largest rectangle area in histogram
//O(n)

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
ll cc;

void solve(){
   int n;
   cin>>n;
   ll pre[n+1],suf[n+1];
   vector<int>a(n+1);
   for(int i=1;i<=n;i++) cin>>a[i];
   
   stack<pair<ll,ll>> st;
   st.push({0,0});
   for(ll i=1;i<=n;i++){
     while(1){
       auto it= st.top();
       if(it.first>=a[i]) st.pop();
       else{
        pre[i]=it.second;
        break;
       }
     }
     st.push({a[i],i});
   }
   st.push({0,n+1});
   for(ll i=n;i>0;i--){
     while(1){
       auto it= st.top();
       if(it.first>=a[i]) st.pop();
       else{
        suf[i]=it.second;
        break;
       }
     }
     st.push({a[i],i});
   }
   ll ans=0;
   for(ll i=1;i<=n;i++){
    ll cur= (suf[i]-pre[i]-1)*a[i];
    ans=max(ans,cur);
   }
   
   cout<<"Case "<<++cc<<": ";
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
/*
6
2 1 5 6 2 3

ans: 10 [3,4]

*/
