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
/*ordered_set<ll> s;
*s.find_by_order(x) //ans at x index in sorted order.
s.order_of_key(x); //index of x or if not find x , it show index no in sort array.*/

const int N= 2e5+5;
ll ar[20][20],n;
ll dp[1<<16][16];
int bitmask(int mask,int pos){
	if(pos>=n) return 0;
	else if(dp[mask][pos] != -1) return dp[mask][pos];
	ll cur=0;
	for(ll j=0;j<n;j++){
		if((mask & (1<<j))==0) {
			cur= max(cur, ar[pos][j] + bitmask(mask|(1<<j),pos+1));
		}
	}
	return dp[mask][pos]=cur;;
}

int main(){
   dhoom3; 
   int Test=1;
   cin>>Test;
   for(ll tt=1;tt<=Test;tt++){
       memset(dp,-1,sizeof(dp));
       cin>>n;
       for(ll i=0;i<n;i++){
       	for(ll j=0;j<n;j++){
       		cin>>ar[i][j];
       	}
       }
       ll ans= bitmask(0,0);
       
       cout<<"Case "<<tt<<": "<<ans<<endl;
   }
   //cout << (ans ? "YES\n" : "No\n") ;
   return 0;
}
/*

*/
