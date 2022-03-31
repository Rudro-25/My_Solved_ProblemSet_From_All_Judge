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
ll a[N],b[N];

void solve(){
   ll n,x;
   cin>>n>>x;

   for(ll i=0;i<n;i++){
      cin>>a[i]; b[i]=a[i];
   }
   sort(a,a+n);
   ll val1=-1,val2=-1,val3=-1,pos1=-1,pos2=-1,pos3=-1;
   for(ll i=0;i<n-2;i++){
      ll l=i+1,r=n-1;
      while(l<r){
         ll cur= a[i]+a[l]+a[r];
         if(cur==x){
            val1=a[i],val2=a[l],val3=a[r];
            break;
         }
         else if(cur<x) l++;
         else r--;
      }
   }
   if(val1==-1) cout<<"IMPOSSIBLE"<<endl;
   else{
      for(ll i=0;i<n;i++){
         if(b[i]==val1 && pos1==-1) pos1=i+1;
         else if(b[i]==val2 && pos2==-1) pos2=i+1;
         else if(b[i]==val3 && pos3==-1) pos3=i+1;
      }
      cout<<pos1<<' '<<pos2<<' '<<pos3<<endl;
      //cout<<val1<<' '<<val2<<' '<<val3<<endl;
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
/*
7 14
5 6 7 8 9 2 3

*/
