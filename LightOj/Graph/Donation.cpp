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

const int N= 50+5;
ll ar[N][N];
vector<pair<ll,pair<ll,ll>>> g;
ll par[57];
ll mst_cost,cnt;
bool chk;

ll find_par(ll x)
{
	if(par[x]==x) return x;
	return par[x]=find_par(par[x]);
}

void ds_union(ll u,ll v)
{
	ll par_u=find_par(u);
	ll par_v=find_par(v);
	if(par_u!=par_v){
		par[par_v]=par_u;
		++cnt; chk=true;
	}
}

void mst(ll n)
{
	ll i=0;
	while(cnt !=n-1 && i < g.size()){
		chk=false;
		ds_union(g[i].second.first,g[i].second.second);
		if(chk) mst_cost += g[i].first;
		i++;
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
	   g.clear();
       ll n,ans=0,baki=0; cin>>n;
	   for(ll i=1;i<=n;i++){
		for(ll j=1;j<=n;j++){
			cin>>ar[i][j];
			if(i==j) ans+=ar[i][j];
			else if(ar[i][j]){
				baki+=ar[i][j];
				g.pb({ar[i][j],{i,j}});
			}
		}
	   }
       for(ll i=1;i<=n;i++) par[i]=i;
	   cnt=0,mst_cost=0;
	   sort(all(g));
	   mst(n);

	   ans+= baki-mst_cost;

	   if(cnt != n-1) ans=-1;
	   cout<<"Case "<<tt<<": "<<ans<<endl;
    
   }
   //cout << (ans ? "YES\n" : "No\n") ;
   return 0;
}
/*

*/
