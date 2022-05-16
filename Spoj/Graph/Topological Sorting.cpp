//https://www.spoj.com/problems/TOPOSORT/

#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define dhoom3   ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);

const int N= 2e5+5;
vector<ll> adj[N];
vector<int> toposort;
ll ind[N];

bool kahn(int n){
    priority_queue<int,vector<int>,greater<int>> pq;
    for(ll i=1;i<=n;i++)
    if(!ind[i]) pq.push(i);

    while(!pq.empty()){
        int cur= pq.top();
        toposort.pb(cur);
        pq.pop();

        for(int child: adj[cur]){
            ind[child]--;
            if(!ind[child]) pq.push(child);
        }
    }
    
    return toposort.size()==n;
}

int main(){
   dhoom3;
   int Test=1;
   //cin>>Test;
   while(Test--){
       ll n,m; cin>>n>>m;

       for(ll i=0;i<m;i++){
           ll x,y; cin>>x>>y;
           adj[x].pb(y);
           ind[y]++;
       }

       if(!kahn(n)){
           cout<<"Sandro fails."<<endl;
       }
       else{
           for(int val: toposort)
             cout<<val<<' ';
           cout<<endl;
       }
    
   }

   return 0;
}
/*
8 9
1 4
1 2
4 2
4 3
3 2
5 2
3 5
8 2
8 6

ans:
TopSort : 1 4 3 5 7 8 2 6
*/
