//https://www.hackerearth.com/practice/data-structures/disjoint-data-strutures/basics-of-disjoint-data-structures/practice-problems/algorithm/reunion-of-1s-1b5bd063/

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
    parent[v] = -1; Rank[v]= 0;
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
    string s; cin>>s;
    mx=0;
    for(ll i=0;i<n;i++){
        if(s[i]=='1'){
            Rank[i]=1; parent[i]= i;
            mx= max(mx,1LL);
            if(s[i-1] == '1' && i>0){
                union_set2(i,i-1);
            }
        }
    }

    while(m--){
        ll t; cin>>t;
        if(t==1) cout<<mx<<endl;
        else{
            ll pos; cin>>pos;
            --pos;
            if(s[pos]=='1') continue; 
            else{
                s[pos]='1';
                Rank[pos]=1; parent[pos]= pos;
                mx= max(mx, 1LL);
                if(s[pos-1] == '1' && pos>0){
                    union_set2(pos,pos-1);
                }
                 if(s[pos+1] == '1' && pos<n-1){
                    union_set2(pos,pos+1);
                }
            }
        }
    }


  return 0;
}
/*
5 3
2 3

ans:
2/3 different set merge into 1
*/
