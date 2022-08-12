#pragma GCC diagnostic ignored "-Wunused-variable"
#pragma GCC diagnostic ignored "-Wunused-parameter"
#pragma GCC diagnostic ignored "-Wunused-but-set-variable" 
#pragma GCC diagnostic ignored "-Wformat"
#pragma GCC diagnostic ignored "-Wsign-compare"
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define ll long long
#define pb push_back
#define all(x) x.begin(),x.end()
#define dhoom3   ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
template <typename T>
using ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
/*ordered_set<ll> s;
*s.find_by_order(x) //ans at x index in sorted order.
s.order_of_key(x); //index of x or if not find x , it show index no in sort array.*/
ll nsum(ll n){
	 ll ans= (n*(n+1))/2;
	 return ans;
}
ll cnt[30];

int main(){
   dhoom3; 
   int Test=1;
   cin>>Test;
   for(ll tt=1;tt<=Test;tt++){
    ll n; cin>>n;
    ll ans=0;
    for(ll i=2;i*i<=n;i++){
    	ll mx=n/i;
    	ans+= nsum(mx)-nsum(i-1);
    	ans += (mx-i)*i;
    }
    cout<<"Case "<<tt<<": "<<ans<<endl;

   }
   //cout << (ans ? "YES\n" : "No\n") ;
   return 0;
}
/*

*/
