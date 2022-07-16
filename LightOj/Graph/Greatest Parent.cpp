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

int n;
vector <pair <int, int> > graph[MX];
ll wei[MX];
const int L = 20;
int anc[MX][L],mx_val[MX];
int depth[MX];
int parent[MX];


void parDFS(int v, int p, int d) {
    parent[v] = p; depth[v] = d;
    for(ll i=0;i<(int)(graph[v]).size();i++) {
        int nxt = graph[v][i].first;
        if (nxt == p) continue;
		mx_val[nxt]= max(mx_val[nxt],mx_val[v]);
        parDFS(nxt, v, d+1);
    }
}

void preprocess() {
    parDFS(0, -1, 1);  //0 based
    for(ll i=0;i<n;i++) for(ll j=0;j<L;j++) anc[i][j] = -1;
    for(ll i=0;i<n;i++) anc[i][0] = parent[i];
    for(ll j=1;j<L;j++) {
         for(ll i=0;i<n;i++) {
            if (anc[i][j-1] != -1) {
                anc[i][j] = anc[anc[i][j-1]][j-1];
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
	   ll q; cin>>n>>q;
	   for(ll i=0;i<n;i++) graph[i].clear();
	   for(ll i=1;i<n;i++){
		 ll y,c; cin>>y>>c;
		 graph[i].pb({y, c});
		 graph[y].pb({i, c});
		 mx_val[i]=c;
	   }
	   mx_val[0]=1;
	   preprocess();
	   cout<<"Case "<<tt<<":"<<endl;
	   while(q--){
		 ll node,val; cin>>node>>val;
		 ll l=1,r=depth[node],Rnode=node,ans;
		 while(l<r){
			ll dist= log2(r-l); 
			ll mid_node= anc[Rnode][dist];
			ll dep= depth[mid_node];
			if(mx_val[mid_node] >= val){
				ans= mid_node;
				r=dep-1;
				Rnode= parent[mid_node];
			}
			else{
				l= dep+1;
			}
			if(l==r && mx_val[Rnode]>=val) ans=Rnode;
		 }
		 cout<<ans<<endl;
	   }

	   //cout<<"Case "<<tt<<": "<<ans<<endl;
    
   }
   //cout << (ans ? "YES\n" : "No\n") ;
   return 0;
}
/*

*/
