//https://cses.fi/problemset/task/1676

#include <bits/stdc++.h>
using namespace std;

#define      PSB         push_back
#define      MP          make_pair
#define      ll          long long
#define      FastIO      ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
constexpr ll mod = 1e9  + 7;
const ll N=3e6+5;
const ll INF =1e18;

ll n,m;
ll parent[N],Rank[N],mx;

void make_set(int v) {
    parent[v] = v; Rank[v]= 1;
}

int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void union_set2(int a,int b){ //union by Rank
   a= find_set(a);
   b= find_set(b);
   if(a!=b){
       if(Rank[a] < Rank[b]) swap(a,b);
       parent[b]= a;
       Rank[a] += Rank[b];
       mx= max(mx,Rank[a]);
   }
}

int main(){
  FastIO

    cin>>n>>m;  // n nodes and m edges.

    for(ll i=1;i<=n;i++) make_set(i);
    ll comp=n; mx=1;
    while(m--){
        ll x,y; cin>>x>>y;
        if(find_set(x) != find_set(y)){
            --comp;
            union_set2(x,y);
        }
        cout<<comp<<' '<<mx<<endl;
    }

  return 0;
}
/*
5 3
2 3

ans:
2/3 different set merge into 1
*/
