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
   cout<<"Case #"<<++cc<<": ";
   ll n;
   string s;
   cin>>s;
   n=s.size();
   ll vis[n];
   for(ll i=0;i<n;i++) vis[i]=0;
   ll mn=100000;
   for(ll i=n-1;i>=0;i--){
      ll bal= s[i]-'A';
      if(i==n-1) vis[i]=bal;
      else{
         if(s[i]!=s[i+1]) vis[i]=s[i+1]-'A';
         else vis[i]=vis[i+1];
      }
   }

   for(ll i=0;i<n;i++){
      ll bal=s[i]-'A';
      if(i==n-1){
         cout<<s[i];
      }
      else{
         if(vis[i]>bal){
            cout<<s[i]<<s[i];
         }
         else cout<<s[i];
      }
   }
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
