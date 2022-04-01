#include <bits/stdc++.h>
using namespace std;

#define      PSB         push_back
#define      ll          long long
#define      FastIO      ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
constexpr ll mod = 1e9  + 7;
const ll N=3e6+5;

vector<ll> adj[N]; 
ll ans[N],n;

int bfs(ll s){
   int top;
   queue<int> q;
   vector<ll> d(n+1, -1);
   q.push(s);
   d[s]=0;
   while (!q.empty()) {
       top = q.front();
       q.pop();

       for (int v : adj[top]) {
           if (d[v]==-1) {
               q.push(v);
               d[v] = d[top] + 1;
               ans[v] = max(ans[v],d[v]);
           }
        }
   }

   return top; 
}

int main(){
  FastIO

    cin>>n;  // n nodes 
    for(ll i=1;i<n;i++){
        ll x,y; cin>>x>>y;
        adj[x].PSB(y); adj[y].PSB(x);
    }
    
    ll diam_end_1 = bfs(1);
    ll diam_end_2 = bfs(diam_end_1);
    bfs(diam_end_2);

    for(ll i=1;i<=n;i++) cout<<ans[i]<<' '; cout<<endl;

  return 0;
}
/*

ans:

*/
