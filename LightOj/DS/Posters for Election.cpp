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
  ll val;
};

ll a[N];
fun b[4*N];
set<ll> st;

void build(ll l, ll r, ll node){  //(left_range, right_range, cur_node)
  if(l == r){
    b[node].val=-1;
    return;
  }
  ll mid = (l + r)/2;
  ll n1 = 2*node;
  ll n2 = n1 + 1;
  build(l, mid , n1);
  build(mid+1, r, n2);
  if(b[n1].val==b[n2].val) b[node].val = b[n1].val;
  return;
}
 
 
void query(ll l, ll r, ll node){ //(left_range, right_range, cur_node, left_query_range, right_query_range)
  if(b[node].val != -1){
    st.insert(b[node].val); return;
  }
  if(l==r) return;
  ll mid = (l + r)/2;
  ll n1 = 2*node;
  ll n2 = n1 + 1;
  query(l,mid,n1);
  query(mid+1,r,n2);
}
//point update
void up(ll l, ll r, ll node, ll x, ll y,ll k){ //(left_range, right_range, cur_node, pos, value)
  if(y < l || x > r) return;
  if(x <= l && y >= r) {b[node].val=k; return;}
  ll mid = (l + r)/2;
  ll n1 = 2*node;
  ll n2 = n1 + 1;
  if(b[node].val != -1){
    b[n1].val=b[n2].val=b[node].val;
    b[node].val=-1;
  }
  up(l , mid , n1 , x , y,k);
  up(mid+1 , r , n2 , x , y,k);
  if(b[n1].val==b[n2].val) b[node].val = b[n1].val;
}

int main(){
  FastIO

    ll Test; cin>>Test;
    for(ll j=1;j<=Test;j++){
        ll n,q;
        cin>>n;

        //for(ll i=1;i<=n;i++) cin>>a[i];

        build(1,2*n,1);
        ll k=0;
        for(ll i=0;i<n;i++){
          ll l,r; cin>>l>>r;
            up(1,2*n,1,l,r,++k);
        }
        st.clear();
        query(1,2*n,1);

        cout<<"Case "<<j<<": "<<st.size()<<endl;
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
