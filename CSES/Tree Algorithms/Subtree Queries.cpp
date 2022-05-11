//https://cses.fi/problemset/task/1137

#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
const int INF= 1e9;
#define dhoom3   ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);

const int N= 2e5+5;
ll val[N],nTree[N],n,m;
ll S[N],T[N],timer;
vector<ll> adj[N];
void dfs(int node,int par=-1){
    S[node]=++timer;
    nTree[timer]=val[node];
    //cout<<timer<<' '<<node<<endl;
    for(int child: adj[node]){
        if(child!=par) dfs(child,node);
    }
    T[node]=timer;
}

//Segment tree(1 based)
struct fun{
  ll sum,max,min;
};
fun merge(fun a, fun b){
  fun c;
  c.sum = a.sum + b.sum ;
  c.max = max( a.max , b.max );
  c.min = min( a.min , b.min );
  return c;
}

fun b[4*N];

void build(ll l, ll r, ll node){
  if(l == r){
    b[node].sum = nTree[l];
    b[node].max = nTree[l];
    b[node].min = nTree[l];
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
 
fun query(ll l, ll r, ll node, ll x, ll y){
  if(y < l || x > r) return dummy();
  if(x <= l && y >= r) return b[node];
  ll mid = (l + r)/2;
  ll n1 = 2*node;
  ll n2 = n1 + 1;
  return merge(query(l , mid , n1 , x , y) , query(mid+1 , r , n2 , x , y));
}
void up(ll l, ll r, ll node, ll x, ll v){
  if(x < l || x > r) return;
  if(l == r){
    b[node].sum = v;
    b[node].max = v;
    b[node].min = v;
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
   dhoom3;
   int Test=1;
   //cin>>Test;
   while(Test--){
       cin>>n>>m;
       for(ll i=1;i<=n;i++) cin>>val[i];
       for(ll i=1;i<n;i++){
           ll x,y; cin>>x>>y;
           adj[x].pb(y); adj[y].pb(x);
       }
       dfs(1);
    //    for(ll i=1;i<=n;i++){
    //        cout<<nTree[i]<<' ';
    //    }cout<<endl;
       build(1,n,1);

       while(m--){
           ll t; cin>>t;
           if(t==1){
               ll pos,val; cin>>pos>>val;
             //val[s]=x;
             up(1,n,1,S[pos],val);
           }
           else{
               ll node; cin>>node;
               //cout<<S[node]<<' '<<T[node]<<endl;
               fun A= query(1,n,1,S[node],T[node]);
               cout<<A.sum<<endl;
           }
       }
       

       

      
   }
   return 0;
}
/*
10 10
4 9 5 10 4 7 5 9 3 6
1 7
5 7
3 6
1 3
8 2
8 9
10 4
4 5
2 6
1 8 5
1 2 9
1 8 8
1 7 9
1 2 8
1 2 1
2 1
2 1
1 2 10
1 4 8

ans:

*/ 
