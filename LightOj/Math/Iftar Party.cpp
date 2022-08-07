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

const int N= 2e5+5;

int main(){
   dhoom3; 
   int Test=1;
   cin>>Test;
   for(ll tt=1;tt<=Test;tt++){
       ll p,l; cin>>p>>l;
       ll dif= p-l;
       vector<ll> ans;
       for(ll i=1;i*i<=dif;i++){
       	 if(dif%i==0){
       	 	if(i>l) ans.pb(i);
       	 	ll x= dif/i;
       	 	if(x != i && x>l) ans.pb(x);
       	 }
       }
       sort(all(ans));
       if(!ans.size()){
       	cout<<"Case "<<tt<<": "<<"impossible"<<endl;
       }
       else{
       	cout<<"Case "<<tt<<": ";
	       for(auto it: ans)
	         cout<<it<<' ';
	       cout<<endl;
	   }
       
       
    
   }
   //cout << (ans ? "YES\n" : "No\n") ;
   return 0;
}
/*

*/
