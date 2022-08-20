#pragma GCC diagnostic ignored "-Wunused-variable"
#pragma GCC diagnostic ignored "-Wunused-parameter"
#pragma GCC diagnostic ignored "-Wunused-but-set-variable" 
#pragma GCC diagnostic ignored "-Wformat"
#pragma GCC diagnostic ignored "-Wsign-compare"
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define ll long long
#define PSB push_back
#define all(x) x.begin(),x.end()
#define dhoom3   ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
template <typename T>
using ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
/*ordered_set<ll> s;
*s.find_by_order(x) //ans at x index in sorted order.
s.order_of_key(x); //index of x or if not find x , it show index no in sort array.*/

const int N= 2e5+5;
ll n,m;
vector<pair<ll,ll>> adj[N];
ll d[N];
///
const int INF = 1000000000;
//vector<vector<pair<int, int>>> adj;

void spfa(int s) {
    vector<int> cnt(n+1, 0);
    vector<bool> inqueue(n+1, false);
    queue<int> q;

    d[s] = 0;
    q.push(s);
    inqueue[s] = true;
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        inqueue[v] = false;

        for (auto edge : adj[v]) {
            int to = edge.first;
            int len = edge.second;

            if (d[v] + len < d[to]) {
                d[to] = d[v] + len;
                if (!inqueue[to] && cnt[to]<n) {
                    q.push(to);
                    inqueue[to] = true;
                    cnt[to]++;
                    // if (cnt[to] > n)
                        // return false;  // negative cycle
                }
            }
        }
    }
}
///

int main(){
   dhoom3; 
   int Test=1;
   cin>>Test;
   for(ll tt=1;tt<=Test;tt++){
      cin>>n;
      ll val[n+1];
	  for(ll i=1;i<=n;i++){
	  	cin>>val[i];
	  	adj[i].clear();
	  	d[i]=INF;
	  }
	  
	  cin>>m;
	  for(int i=0;i<m;i++){
	    int a,b; cin>>a>>b;
	    ll dif= (val[b]-val[a]);
	    ll dis= dif*dif*dif;
	    adj[a].PSB({b,dis});
	  }
	  spfa(1);
       
      cout<<"Case "<<tt<<": "<<endl;
	  ll q; cin>>q;
	  while(q--){
	  	ll x; cin>>x;
	  	 if(d[x]==INF || d[x]<3) cout<<"?"<<endl;
	  	 else cout<<d[x]<<endl;
	  }
       
    
   }
   //cout << (ans ? "YES\n" : "No\n") ;
   return 0;
}
/*

*/
