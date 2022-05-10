//centroid decomposition
//O(nlogn)
//https://codeforces.com/contest/321/problem/C

#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define dhoom3   ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);

const int N= 2e5+5;
set<int> adj[N];
vector<int> nTree[N];
int par[N],sub[N];
char ans[N];
int find_subTreeSize(int node,int p){
    sub[node]=1;
    for(int child: adj[node]){
        if(child!=p){
            sub[node] += find_subTreeSize(child,node);
        }
    }
    return sub[node];
}
int find_centroid(int node,int p,int n){
    for(int child: adj[node]){
        if(child!=p && sub[child]>n/2){
            return find_centroid(child,node,n);
        }
    }
    return node;
}
int decompose(int node,int p){
    int SubTreeSize = find_subTreeSize(node,-1); 
    int centroid = find_centroid(node,p,SubTreeSize);
    //cout<<"Root: "<<node<<" SubTreeSize: "<<SubTreeSize<<" Centroid: "<<centroid<<endl;
    par[centroid]=p;
    for(int child: adj[centroid]){
        adj[child].erase(centroid);
        int val= decompose(child,centroid);
        nTree[centroid].pb(val);
    }
    return centroid;
}
bool dfs(int node,int par,char c){
    if(c>'Z') return false;
    ans[node]=c;
    bool ck=1;
    for(int child: nTree[node]){
        if(child!=par) ck &= dfs(child,node,c+1);
    }
    return ck;
}

int main(){
   dhoom3;
   int Test=1;
   //cin>>Test;
   while(Test--){
       ll n; cin>>n;
       for(ll i=1;i<n;i++){
           ll x,y; cin>>x>>y;
           adj[x].insert(y); adj[y].insert(x);
       }
       int root= decompose(1,-1);
    //    cout<<"Parent array as follow: "<<endl;
    //    for(ll i=1;i<=n;i++){
    //        cout<<"par["<<i<<"]="<<par[i]<<endl;
    //    }
      if(!dfs(root,root,'A')) cout<<"Impossible!";
      else{
          for(ll i=1;i<=n;i++)
              cout<<ans[i]<<' ';
      }
   }
   return 0;
}
/*
15
2 1
2 3
2 4
2 5
5 6
5 8
6 7
8 9
9 10
9 13
10 11
10 12
13 14
13 15

ans:

*/ 
