#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define ll long long
#define pb push_back
#define dhoom3   ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
//ordered_set<ll> s;
//*s.find_by_order(x) //ans at x index in sorted order.
//s.order_of_key(x); //index of x or if not find x , it show index no in sort array.

const int mx= 1e5+3;
const int maxm = 1429431 + 20;
ll ans[mx];
void pre_cal(){
   ordered_set<ll> oset;
   oset.insert(0);
   for(ll i=1;i<maxm;i+=2) oset.insert(i);
   ans[1]=1;
   for(ll i=2;i<mx;i++){
     if(i>=oset.size()) break;
     ll x= *oset.find_by_order(i);

     vector<ll> v;
     for(ll j=x;j<maxm;j+=x){
        if(j>=oset.size()) break;
        v.pb(*oset.find_by_order(j));
     }
     for(int val: v) oset.erase(val);
     ans[i]=x;
   }
}

int main(){
   //freopen("input.txt","r",stdin);
   //freopen("output.txt","w",stdout); 
   pre_cal();
   dhoom3; 
   int Test=1;
   cin>>Test;
   for(ll tt=1;tt<=Test;tt++){
       ll n; cin>>n;

       cout<<"Case "<<tt<<": "<<ans[n]<<endl;
       
    
   }
   //cout << (ans ? "YES\n" : "No\n") ;
   return 0;
}
/*

*/
