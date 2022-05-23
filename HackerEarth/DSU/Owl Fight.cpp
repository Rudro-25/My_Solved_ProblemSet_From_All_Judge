https://assessment.hackerearth.com/challenges/college/codemania-20/algorithm/owl-fight/

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
ll parent[N],val[N];

void make_set(int v) {
    parent[v] = v;
    val[v]=v;
}

int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b)
        parent[b] = a, val[a]=max(val[a],val[b]);
}

int main(){
  FastIO

    cin>>n>>m;  // n nodes and m edges.
    for(ll i=1;i<=n;i++) make_set(i);

    for(ll i=0;i<m;i++){
        ll x,y; cin>>x>>y;
        if(find_set(x) != find_set(y)){
            union_sets(x,y);
        }
    }
    ll q; cin>>q;
    while(q--){
        ll x,y; cin>>x>>y;
        ll g1= find_set(x),g2= find_set(y);
        if(val[g1] == val[g2]) cout<<"TIE"<<endl;
        else if(val[g1]>val[g2]) cout<<x<<endl;
        else cout<<y<<endl;
    }


  return 0;
}
/*

ans:

*/
