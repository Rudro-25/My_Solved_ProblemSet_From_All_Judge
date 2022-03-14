//single position update and range query.
//https://cses.fi/problemset/task/2166/

#include <bits/stdc++.h>
using namespace std;

#define      PSB         push_back
#define      MP          make_pair
#define      ll          long long
#define      FastIO      ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
constexpr ll mod = 1e9  + 7;
const ll N=5e6+5;
const ll INF =1e18;

struct seg{
  ll c_sum,t_sum,c_sum_l,c_sum_r;
};
seg merge(seg a, seg b){
  seg c;
  //c.c_sum = a.sum_l ;
  c.c_sum = max( a.c_sum_l, a.t_sum+b.c_sum_l);
  //c.c_sum = max (c.c_sum , a.c_sum_r + b.c_sum_l) ;
  c.t_sum = (a.t_sum + b.t_sum) ;
  c.c_sum_l = max(a.c_sum_l,a.t_sum + b.c_sum_l );
  c.c_sum_r = max(b.c_sum_r,b.t_sum + a.c_sum_r );
  
  return c;
}

ll a[N];
seg b[4*N];

void build(ll l, ll r, ll node){
  if(l == r){
    b[node].c_sum = a[l];
    b[node].t_sum = a[l];
    b[node].c_sum_l = a[l];
    b[node].c_sum_r = a[l];
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
 
seg dummy(){
  return {0,0,0,0};
}
 
seg query(ll l, ll r, ll node, ll x, ll y){
  if(y < l || x > r) return dummy();
  if(x <= l && y >= r) return b[node];
  ll mid = (l + r)/2;
  ll n1 = 2*node;
  ll n2 = n1 + 1;
  return merge(query(l , mid , n1 , x , y) , query(mid+1 , r , n2 , x , y));
}
void update(ll l, ll r, ll node, ll x, ll v){
  if(x < l || x > r) return;
  if(l == r){
    b[node].c_sum = v;
    b[node].t_sum = v;
    b[node].c_sum_l = v;
    b[node].c_sum_r = v;
    return;
  }
  ll mid = (l + r)/2;
  ll n1 = 2*node;
  ll n2 = n1 + 1;
  update(l, mid , n1, x , v);
  update(mid+1, r, n2 , x , v);
  b[node] = merge(b[n1] , b[n2]);
}

int main(){
  FastIO;

    ll n,q;
    cin>>n>>q;

    for(ll i=1;i<=n;i++) cin>>a[i];

    build(1,n,1);
    /*for(ll i=0;i<20;i++)
      cout<<b[i].min<<' ';
    cout<<endl;*/

    while(q--){
        ll t; cin>>t;
        if(t==1){
            ll pos,val; cin>>pos>>val;
            update(1,n,1,pos,val);
        }
        else{
            ll l,r; cin>>l>>r;
            seg A= query(1,n,1,l,r);
            cout<<max(0LL,A.c_sum)<<endl;
        }
    }

    

  return 0;
}
/*
//asking for 0 index of [L,r)
5 0
5 -4 4 3 -5


ans:
8
*/

