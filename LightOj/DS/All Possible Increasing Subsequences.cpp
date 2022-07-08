//A. Segment Tree for the Sum

#include <bits/stdc++.h>
using namespace std;

#define      PSB         push_back
#define      MP          make_pair
#define      ll          long long
#define      FastIO      ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
constexpr ll mod = 1e9  + 7;
const ll N=1e5+5;
const ll INF =1e18;

//Segment tree(1 based)
struct fun{
  ll sum,max,min;
};
fun merge(fun a, fun b){
  fun c;
  c.sum = (a.sum + b.sum) % mod ;
//   c.max = max( a.max , b.max );
//   c.min = min( a.min , b.min );
  return c;
}

ll a[N],ar[N];
fun b[4*N];

void build(ll l, ll r, ll node){  //(left_range, right_range, cur_node)
  if(l == r){
    b[node].sum = a[l];
    // b[node].max = a[l];
    // b[node].min = a[l];
    return;
  }
  ll mid = (l + r)/2;
  ll n1 = 2*node;
  ll n2 = n1 + 1;
  build(l, mid , n1);
  build(mid+1, r, n2);
  b[node] = merge(b[n1] , b[n2]);
  return;
}
 
fun dummy(){
  return {0,0,INF};
}
 
fun query(ll l, ll r, ll node, ll x, ll y){ //(left_range, right_range, cur_node, left_query_range, right_query_range)
  if(y < l || x > r) return dummy();
  if(x <= l && y >= r) return b[node];
  ll mid = (l + r)/2;
  ll n1 = 2*node;
  ll n2 = n1 + 1;
  return merge(query(l , mid , n1 , x , y) , query(mid+1 , r , n2 , x , y));
}
//point update
void up(ll l, ll r, ll node, ll x, ll v){ //(left_range, right_range, cur_node, pos, value)
  if(x < l || x > r) return;
  if(l == r){
    b[node].sum = (b[node].sum + v) % mod;
    // b[node].max = v;
    // b[node].min = v;
    return;
  }
  ll mid = (l + r)/2;
  ll n1 = 2*node;
  ll n2 = n1 + 1;
  up(l, mid , n1, x , v);
  up(mid+1, r, n2 , x , v);
  b[node] = merge(b[n1] , b[n2]);
}

int main(){
  FastIO

//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
   int Test=1;
   cin>>Test;
   for(ll tt=1;tt<=Test;tt++){

        ll n,q;
        cin>>n;

        for(ll i=1;i<=n;i++) a[i]=0;

        build(1,n,1);
        map<ll,ll> mp,pos;

        for(ll i=1;i<=n;i++){
            cin>>ar[i];
            mp[ar[i]]++;
        }
        ll ct=0;
        for(auto it: mp){
            pos[it.first]= ++ct;
        }
        ll ans=0;
        for(ll i=1;i<=n;i++){
            ll val= pos[ar[i]];
            if(val==1){
                ans= (ans+1)%mod;
                up(1,n,1,val,1);
            }
            else{
                fun A= query(1,n,1,1,val-1);
                ll bal= A.sum + 1;
                ans= (ans + bal) % mod;
                up(1,n,1,val,bal);
            }
        }

        cout<<"Case "<<tt<<": "<<ans<<endl;
   }

  return 0;
}
/*
5 5
5 4 2 3 5
2 0 3
1 1 1
2 0 3
1 3 1
2 0 5


ans:
11
8
14

*/
