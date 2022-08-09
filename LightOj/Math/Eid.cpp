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

const int N= 5e6+5;
bool chk[1005];
vector<ll> prime;
void pre_cal(){
	for(ll i=2;i<=1000;i++){
	  if(!chk[i]){
	  	prime.pb(i);
		for(ll j=i*i;j<=1000;j+=i){
			chk[j]=1;
		}
	  }
	}
}
string multiply(string cur,ll val){
	ll carry=0;
	string ans="";
	for(ll i=0;i<cur.size();i++){
		ll cc= cur[i]-'0';
		ll vv= (cc*val)+carry;
		ans+= vv%10 + '0';
		carry= vv/10;
	}
	while(carry){
		ans+= carry%10 + '0';
		carry/=10;
	}
	return ans;
}
int main(){
   dhoom3; 
   pre_cal();
   int Test=1;
   cin>>Test;
   for(ll tt=1;tt<=Test;tt++){
       map<ll,ll> mp;
       ll n; cin>>n;
       for(ll i=0;i<n;i++){
       	  ll x; cin>>x;
       	  for(ll j=0;j<prime.size() && prime[j]*prime[j]<=x;j++){
       	  	ll val=1;
       	  	while(x%prime[j]==0){
       	  		val*=prime[j];
       	  		x/=prime[j];
       	  	}
       	  	mp[prime[j]]=max(mp[prime[j]],val);
       	  }
       	  if(x>1) mp[x]=max(mp[x],x);
       }
       string ans="1";
       for(auto it: mp){
       	 ans = multiply(ans,it.second);
       }
       reverse(all(ans));
       
       cout<<"Case "<<tt<<": "<<ans<<endl;
   }
   //cout << (ans ? "YES\n" : "No\n") ;
   return 0;
}
/*

*/
