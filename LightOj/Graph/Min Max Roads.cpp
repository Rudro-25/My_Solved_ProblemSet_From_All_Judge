#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define ll long long
#define pb push_back
#define all(x) x.begin(),x.end()
#define dhoom3   ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
template <typename T>
using ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
//ordered_set<ll> s;
//*s.find_by_order(x) //ans at x index in sorted order.
//s.order_of_key(x); //index of x or if not find x , it show index no in sort array.

const int MOD = 1000000007;
const char nl = '\n';
const int MX = 100005; //check the limits, dummy

int n,mx,mn;
vector <pair <int, int> > graph[MX];
ll wei[MX];
const int L = 20;
int anc[MX][L],mx_val[MX][L],mn_val[MX][L];
int depth[MX];
int parent[MX];

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
				mx=max(mx,mx_val[a][i]);
				mn=min(mn,mn_val[a][i]);
                a = anc[a][i];
                dist -= 1 << i;
            }
        }
    }

    if (a == b) return a;

    for(ll j=(L)-1;j>=0;j--) {
        if (anc[a][j] != -1 && anc[a][j] != anc[b][j]) {
			mx=max(mx,mx_val[a][j]); mn=min(mn,mn_val[a][j]);
			mx=max(mx,mx_val[b][j]); mn=min(mn,mn_val[b][j]);
            a = anc[a][j]; b = anc[b][j];
        }
    }
	mx=max(mx,mx_val[a][0]); mn=min(mn,mn_val[a][0]);
	mx=max(mx,mx_val[b][0]); mn=min(mn,mn_val[b][0]);
    return parent[a];
}

void parDFS(int v, int p, int d) {
    parent[v] = p; depth[v] = d;
    for(ll i=0;i<(int)(graph[v]).size();i++) {
        int nxt = graph[v][i].first;
        if (nxt == p) continue;
        mx_val[nxt][0]=graph[v][i].second;
		mn_val[nxt][0]=graph[v][i].second;
        parDFS(nxt, v, d+1);
    }
}

void preprocess() {
    for(ll i=0;i<n;i++) for(ll j=0;j<L;j++) anc[i][j] = -1,mx_val[i][j]=0,mn_val[i][j]=1e6;
    parDFS(0, -1, 0);  //0 based
	for(ll i=0;i<n;i++) anc[i][0] = parent[i];
    for(ll j=1;j<L;j++) {
         for(ll i=0;i<n;i++){
            if (anc[i][j-1] != -1) {
                anc[i][j] = anc[anc[i][j-1]][j-1];
				mx_val[i][j]= max(mx_val[i][j-1],mx_val[anc[i][j-1]][j-1]);
				mn_val[i][j]= min(mn_val[i][j-1],mn_val[anc[i][j-1]][j-1]);
            }
        }
    }
}

int main(){
   #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
   #endif
   dhoom3; 
   int Test=1;
   cin>>Test;
   for(ll tt=1;tt<=Test;tt++){
	   ll q; cin>>n;
	   for(ll i=0;i<n;i++) graph[i].clear();
	   for(ll i=1;i<n;i++){
		 ll x,y,c; cin>>x>>y>>c;
		 --x,--y;
		 graph[x].pb({y, c});
		 graph[y].pb({x, c}); 
	   }
	   preprocess();
	   cout<<"Case "<<tt<<":"<<endl;
	   cin>>q;
	   while(q--){
		 ll l,r; cin>>l>>r;
		 --l,--r;
		 mx=0,mn=1e6;
		 LCA(l,r);
		 cout<<mn<<' '<<mx<<endl;
	   }

	   //cout<<"Case "<<tt<<": "<<ans<<endl;
    
   }
   //cout << (ans ? "YES\n" : "No\n") ;
   return 0;
}
/*

*/
