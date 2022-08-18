//https://lightoj.com/problem/points-in-rectangle

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) x.begin(),x.end()
#define dhoom3   ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);

const int N= 6e4+5;
const int L= 17;
vector<ll> adj[N];
ll gin[N],start[N],endd[N];
ll anc[N][L],depth[N],parent[N];
ll n,timer;
void dfs(int node,int par,int lvl){
	parent[node]=par;
	start[node]=++timer;
	depth[node]=lvl;
	for(int child: adj[node]){
		if(child == par) continue;
		dfs(child,node,lvl+1);
	}
	endd[node]=++timer;
}
int LCA(int a, int b) {
    if (depth[a] < depth[b]) {
        int c = b;
        b = a;
        a = c;
    }
    int dist = depth[a] - depth[b];
    while (dist > 0) {
        for(ll i=0;i<L;i++) {
            if (dist & 1 << i) {
                a = anc[a][i];
                dist -= 1 << i;
            }
        }
    }

    if (a == b) return a;

    for(ll j=(L)-1;j>=0;j--) {
        if (anc[a][j] != -1 && anc[a][j] != anc[b][j]) {
            a = anc[a][j]; b = anc[b][j];
        }
    }
    return parent[a];
}
void preprocess(){
	for(ll i=0;i<=n;i++) for(ll j=0;j<L;j++) anc[i][j]=-1;
	for(ll i=1;i<=n;i++) anc[i][0] = parent[i];
    for(ll j=1;j<L;j++) {
         for(ll i=1;i<=n;i++) {
            if (anc[i][j-1] != -1) {
                anc[i][j] = anc[anc[i][j-1]][j-1];
            }
        }
    }
	
}
int tree[N];

int query(int idx){
    int sum = 0;
    while (idx > 0){
        sum += tree[idx];
        idx -= (idx & -idx);
    }
    return sum;
}

void update(int idx, int val, int n){
    while (idx <= n){
        tree[idx] += val;
        idx += (idx & -idx);
    }
}

int main(){ 
   dhoom3;
   int Test=1;
   cin>>Test;
   for(ll tt=1;tt<=Test;tt++){
   	   timer=0;
   	   cin>>n;
   	   for(ll i=1;i<=n;i++){
   	   	cin>>gin[i];
   	   	adj[i].clear();
   	   }
   	   for(ll i=0;i<=2*n;i++) tree[i]=0;
   	   
   	   for(ll i=1;i<n;i++){
   	   	ll x,y; cin>>x>>y;
   	   	++x,++y;
   	   	adj[x].pb(y); adj[y].pb(x);
   	   }
   	   dfs(1,1,0);
   	   preprocess();
   	   //cout<<parent[4]<<endl;
   	   for(ll i=1;i<=n;i++){
   	   	 update(start[i],gin[i],2*n);
   	   	 update(endd[i],-gin[i],2*n);
   	   }
   	   ll q; cin>>q;
   	   cout<<"Case "<<tt<<": "<<endl;
   	   while(q--){
   	   	ll t; cin>>t;
   	   	if(t==0){
   	   		ll u,v; cin>>u>>v;
   	   		++u,++v;
   	   		ll lc= LCA(u,v);
   	   		ll ans=0;
   	   		ans+= query(start[u])+query(start[v])-(2*query(start[lc]))+gin[lc];
   	   		cout<<ans<<endl;
   	   	}
   	   	else{
   	   		ll u,val; cin>>u>>val;
   	   		++u;
   	   		update(start[u],-gin[u],2*n);
   	   		update(endd[u],gin[u],2*n);
   	   		gin[u]=val;
   	   		update(start[u],gin[u],2*n);
   	   		update(endd[u],-gin[u],2*n);
   	   	}
   	   }

   }
   //cout << (ans ? "YES\n" : "No\n") ;
   return 0;
}
/*



*/
