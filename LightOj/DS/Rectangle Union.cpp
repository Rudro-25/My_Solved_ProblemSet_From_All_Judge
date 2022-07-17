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
struct node{
    ll x,y1,y2,state;
} ara[N];

bool comp(const node &a, const node &b){
    return a.x < b.x;
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
       ll n,ind=0; cin>>n;
       for(ll i=0;i<n;i++){
        ll x1,x2,y1,y2; cin>>x1>>y1>>x2>>y2;
        ara[ind].x=x1, ara[ind].y1=y1, ara[ind].y2=y2, ara[ind].state=0;
        ind++;
        ara[ind].x=x2, ara[ind].y1=y1, ara[ind].y2=y2, ara[ind].state=1;
        ind++;
       }

       sort(ara,ara+ind,comp);
       multiset<ll> ms;
       ll ans=0,pre;
       for(ll i=0;i<ind;i++){
        if(ms.size()){
            ll mxy= *(--ms.end());
            ll mny= *ms.begin();
            ans+= (ara[i].x-pre) * (mxy-mny);
        }
        if(ara[i].state==0){
            ms.insert(ara[i].y1);
            ms.insert(ara[i].y2);
        }
        else{
            ms.erase(ms.find(ara[i].y1));
            ms.erase(ms.find(ara[i].y2));
        }
        pre=ara[i].x;
       }

       cout<<"Case "<<tt<<": "<<ans<<endl;
   }
   //cout << (ans ? "YES\n" : "No\n") ;
   return 0;
}
/*

*/
