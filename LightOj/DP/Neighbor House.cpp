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
       ll n; cin>>n;
       ll dp[n][3];
       for(ll i=0;i<n;i++){
        ll a,b,c; cin>>a>>b>>c;
        if(!i) dp[0][0]=a,dp[0][1]=b,dp[0][2]=c;
        else{
          dp[i][0]= min(dp[i-1][1],dp[i-1][2])+a;
          dp[i][1]= min(dp[i-1][0],dp[i-1][2])+b;
          dp[i][2]= min(dp[i-1][1],dp[i-1][0])+c;
        }
       }
       ll ans=min(dp[n-1][0],dp[n-1][1]);
       ans=min(ans,dp[n-1][2]);

       cout<<"Case "<<tt<<": "<<ans<<endl;
   }
   //cout << (ans ? "YES\n" : "No\n") ;
   return 0;
}
/*

*/
