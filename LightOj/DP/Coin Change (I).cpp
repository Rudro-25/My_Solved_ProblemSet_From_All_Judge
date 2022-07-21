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
//s.find_by_order(x) //ans at x index in sorted order.
//s.order_of_key(x); //index of x or if not find x , it show index no in sort array.

const int mod = 1e8+7;

ll dp[55][1005];
ll a[55],c[55],n;
int solve(ll id,ll baki){
    if(baki==0) return dp[id][baki]= 1;
    if(id>n) return dp[id][baki]= 0;
    if(dp[id][baki] != -1) return dp[id][baki];
    ll sum=0;

    for(ll i=0;i<=c[id];i++){
        ll s= i*a[id];
        if(s<=baki) sum = (sum + solve(id+1,baki-s)) % mod;
    }
    return dp[id][baki]= sum%mod;
}

int main(){
   #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
   #endif
   dhoom3; 
   int Test=1;
   cin>>Test;
   for(ll tt=1;tt<=Test;tt++){
    memset(dp,-1,sizeof(dp));
       ll k; cin>>n>>k;
       for(ll i=1;i<=n;i++) cin>>a[i];
       for(ll i=1;i<=n;i++) cin>>c[i];

       cout<<"Case "<<tt<<": "<<solve(1,k)<<endl;
   }
   //cout << (ans ? "YES\n" : "No\n") ;
   return 0;
}
/*

*/
