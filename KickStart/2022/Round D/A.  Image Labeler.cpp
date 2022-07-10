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

const int N= 12000+5;
ll nl[N],nr[N],ml[N],mr[N];
ll nn[N],mm[N];

int main(){
   //freopen("input.txt","r",stdin);
   //freopen("output.txt","w",stdout);
   dhoom3; 
   int Test=1;
   cin>>Test;
   for(ll tt=1;tt<=Test;tt++){
       ll n; cin>>n;
       ll a[n+1],sum=0;
       for(ll i=1;i<=n;i++){
        cin>>a[i];
        sum+=a[i];  nl[i]=sum;
        nn[i]=sum;
       }
       sum=0;
       for(ll i=n,ct=1;i>0;i--,++ct){
        sum+=a[i];  nr[i]=sum;
        nn[ct]=max(nn[ct],sum);
       }
       for(ll i=1;i<=n;i++){
          for(ll j=n,ct=1;j>i;j--,++ct){
            if((i+ct)>n) break;
            nn[i+ct]=max(nn[i+ct],nl[i]+nr[j]);
          }
       }
       //for b
       ll m; cin>>m;
       ll b[m+1]; sum=0;
       for(ll i=1;i<=m;i++){
        cin>>b[i];
        sum+=b[i];  ml[i]=sum;
        mm[i]=sum;
       }
       sum=0;
       for(ll i=m,ct=1;i>0;i--,++ct){
        sum+=b[i];  mr[i]=sum;
        mm[ct]=max(mm[ct],sum);
       }
       for(ll i=1;i<=m;i++){
          for(ll j=m,ct=1;j>i;j--,++ct){
            if((i+ct)>m) break;
            mm[i+ct]=max(mm[i+ct],ml[i]+mr[j]);
          }
       }
       ll k; cin>>k;
       ll ans= 0;
       if(n>=k) ans=max(ans,nn[k]);
       if(m>=k) ans=max(ans,mm[k]);

       for(ll i=1;i<=n;i++){
        ll baki=k-i;
        if(i>=k) break;
        if(baki>=m) continue;
        ans=max(ans,nn[i]+mm[baki]);
       }

       cout<<"Case #"<<tt<<": "<<ans<<endl;
       
    
   }
   //cout << (ans ? "YES\n" : "No\n") ;
   return 0;
}
/*

*/
