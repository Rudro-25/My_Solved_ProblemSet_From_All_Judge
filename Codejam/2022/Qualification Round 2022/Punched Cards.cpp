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
   int n,m;
   cin>>n>>m;

   n*=2; n++; 
   m*=2; m++;
   
   cout<<"Case #"<<++cc<<":"<<endl;
   for(ll i=0;i<n;i++){
      if(i%2){
         for(ll j=0;j<m;j++){
            if(i<=1 && j<=1) cout<<".";
            else if(j%2) cout<<".";
            else cout<<"|";
         }
         cout<<endl;
      }
      else{
         for(ll j=0;j<m;j++){
            if(i<=1 && j<=1) cout<<".";
            else if(j%2) cout<<"-";
            else cout<<"+";
         }
         cout<<endl;
      }
   }
   


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
