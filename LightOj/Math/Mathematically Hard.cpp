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
ll n;
unsigned long long phi[N];
// every i er jonne 1 to i with i koto gula co-prime ase 
ll pre_cal(){          //nloglogn complexity
  phi[0]=0; phi[1]=0;
  for(ll i=2;i<N;i++) phi[i]=i;

  for(ll i=2;i<N;i++){
    if(phi[i]==i){
        for(ll j=i;j<N;j+=i){
            phi[j]-=phi[j]/i;
        }
    }
    phi[i]= ((unsigned long long)phi[i]* (unsigned long long)phi[i])+phi[i-1];
  }

}

int main(){
   dhoom3; 
   pre_cal();
   int Test=1;
   cin>>Test;
   for(ll tt=1;tt<=Test;tt++){
       ll a,b; cin>>a>>b;
       unsigned long long ans= phi[b]-phi[a-1];
       cout<<"Case "<<tt<<": "<<ans<<endl;
   }
   //cout << (ans ? "YES\n" : "No\n") ;
   return 0;
}
/*

*/
