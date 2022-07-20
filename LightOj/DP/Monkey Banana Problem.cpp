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

ll dp[105][105];

int main(){
   #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
   #endif
   dhoom3; 
   int Test=1;
   cin>>Test;
   for(ll tt=1;tt<=Test;tt++){
    memset(dp,0,sizeof(dp));
       ll n; cin>>n;
       for(ll i=1;i<=n;i++){
        for(ll j=1;j<=i;j++){
            ll a; cin>>a;
            dp[i][j]=a;
            if(i>1){
                if(j==1) dp[i][j]+=dp[i-1][j];
                else if(j==i) dp[i][j]+=dp[i-1][j-1];
                else dp[i][j]+= max(dp[i-1][j],dp[i-1][j-1]);
            }
        }
       }
       for(ll i=n-1;i>=1;i--){
        for(ll j=1;j<=i;j++){
            ll a; cin>>a;
            dp[i][j]=a+max(dp[i+1][j],dp[i+1][j+1]);
        }
       }

       cout<<"Case "<<tt<<": "<<dp[1][1]<<endl;
       
    
   }
   //cout << (ans ? "YES\n" : "No\n") ;
   return 0;
}
/*

*/
