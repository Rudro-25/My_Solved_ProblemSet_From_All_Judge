//https://www.hackerearth.com/practice/data-structures/advanced-data-structures/fenwick-binary-indexed-trees/practice-problems/algorithm/help-ashu-1/

//https://codeforces.com/edu/course/2/lesson/4/1/practice/contest/273169/problem/A
//A. Segment Tree for the Sum

#include <bits/stdc++.h>
using namespace std;

#define      PSB         push_back
#define      MP          make_pair
#define      ll          long long
#define      FastIO      ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
constexpr ll mod = 1e9  + 7;
const ll N=5e6+5;
const ll INF =1e18;

//Segment tree(1 based)
struct fun{
  ll sum,max,min,even,odd;
};
fun merge(fun a, fun b){
  fun c;
  c.sum = a.sum + b.sum ;
  c.even = a.even + b.even ;
  c.odd = a.odd + b.odd ;
  c.max = max( a.max , b.max );
  c.min = min( a.min , b.min );
  return c;
}

ll a[N];
fun b[4*N];

void build(ll l, ll r, ll node){  //(left_range, right_range, cur_node)
  if(l == r){
    b[node].sum = a[l];
    b[node].max = a[l];
    b[node].min = a[l];
    if(a[l]%2==0) b[node].even=1, b[node].odd=0;
    else b[node].even=0, b[node].odd=1;
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
  return {0,0,INF,0,0};
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
    b[node].sum = v;
    b[node].max = v;
    b[node].min = v;
    if(v%2==0) b[node].even=1, b[node].odd=0;
    else b[node].even=0, b[node].odd=1;
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

    ll n,q;
    cin>>n;

    for(ll i=1;i<=n;i++) cin>>a[i];

    build(1,n,1);
    cin>>q;
    while(q--){
      ll t,l,r; cin>>t>>l>>r;

      if(t==0){
        up(1,n,1,l,r);
      }
      else if(t==1){
        fun A= query(1,n,1,l,r);
        cout<<A.even<<endl;
      }
      else{
         fun A= query(1,n,1,l,r);
         cout<<A.odd<<endl;
      }


        

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
