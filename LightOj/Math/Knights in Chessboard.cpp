#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define ll long long
#define pb push_back
#define dhoom3   ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
template <typename T>
using ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
//ordered_set<ll> s;
//*s.find_by_order(x) //ans at x index in sorted order.
//s.order_of_key(x); //index of x or if not find x , it show index no in sort array.

const int N= 2e5+5;

int main(){
   #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
   #endif
   dhoom3; 
   int Test=1;
   cin>>Test;
   for(ll tt=1;tt<=Test;tt++){
       ll n,m,ans; cin>>n>>m;
       if(n==1 || m==1) ans=max(n,m);
       else if(n==2 || m==2){
         ll len= max(n,m);
         ans= (len/4)*4;
         len%=4; len=min(len,2LL);
         ans += (len*2);
       }
       else{
        ans= (n*m+1)/2;
       }

       cout<<"Case "<<tt<<": "<<ans<<endl;
   }
   //cout << (ans ? "YES\n" : "No\n") ;
   return 0;
}
/*

*/
