//Minimum spanning tree cost + edge find using kruskal + DSU
//complexity: mlogn

#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define pb push_back
#define MP make_pair
#define all(x) x.begin(),x.end()
#define Max 10000000000000000

vector<pair<ll,pair<ll,ll>>> g;
ll par[100007];
//vector<pair<ll,ll>> ans;
map<pair<ll,ll>,ll> mp;
int n,m,mst_cost,ans,ctt;
//
const int MX = 100005; //check the limits, dummy
const int N = 100005;
vector <pair <int, int> > graph[MX];
ll wei[MX];
const int L = 20;
int anc[MX][L],mx_val[MX][L];
int depth[MX];
int parent[MX];
bool chk;

/*START-MST*/
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
		//ans.pb({u,v});
		chk=true; ++ctt;
	}
}
void mst(ll n)
{
	ll i=0; ctt=0;
	while(ctt!=n-1 && i<m){
		chk=false;
		ds_union(g[i].second.first,g[i].second.second);
		if(chk){
			ll x=g[i].second.first, y=g[i].second.second, c= g[i].first;
			graph[x].pb({y, c});
            graph[y].pb({x, c});
		}
		i++;
	}
}
//End-MST//

//START-LCA//
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
				ans=max(ans,mx_val[a][i]); //
                a = anc[a][i];
                dist -= 1 << i;
            }
        }
    }
	//cout<<a<<' '<<b<<endl;

    if (a == b) return a;

    for(ll j=(L)-1;j>=0;j--) {
        if (anc[a][j] != -1 && anc[a][j] != anc[b][j]) {
			//cout<<a<<' '<<b<<' '<<j<<' '<<mx_val[a][j]<<' '<<mx_val[b][j]<<endl;
			ans=max(ans,mx_val[a][j]); ans=max(ans,mx_val[b][j]); //
            a = anc[a][j]; b = anc[b][j];
        }
    }
	ans=max(ans,mx_val[a][0]); ans=max(ans,mx_val[b][0]);
    return parent[a];
}

void parDFS(int v, int p, int d) {
    parent[v] = p; depth[v] = d;
    for(ll i=0;i<(int)(graph[v]).size();i++) {
        int nxt = graph[v][i].first;
        if (nxt == p) continue;
        //wei[nxt] = wei[v] + graph[v][i].second;
        parDFS(nxt, v, d+1);
    }
}

void preprocess() {
    parDFS(0, -1, 0);  //0 based
    for(ll i=0;i<n;i++) for(ll j=0;j<L;j++) anc[i][j] = -1,mx_val[i][j]=0;
    for(ll i=1;i<n;i++){
		anc[i][0] = parent[i];
		ll x= i,y= parent[i];
		ll mn=min(x,y), mx= max(x,y);
		mx_val[i][0]= mp[{mn,mx}];
	}
    ll vv=1;
    for(ll j=1;j<L;j++) {
        vv*=2;
         for(ll i=0;i<n;i++) {
            if (depth[i]>=vv) {
                anc[i][j] = anc[anc[i][j-1]][j-1];
				mx_val[i][j]=max(mx_val[i][j-1],mx_val[anc[i][j-1]][j-1]);
            }
        }
    }
}

//END-LCA//

int main()
{
	#ifndef ONLINE_JUDGE
     freopen("input.txt", "r", stdin);
     freopen("output.txt", "w", stdout);
    #endif
    int Test=1;
   cin>>Test;
   for(ll tt=1;tt<=Test;tt++){
		cin>>n>>m;
        //CLEAR
		g.clear();
		mp.clear();
		for(ll i=0;i<=n;i++){
			graph[i].clear();
		}
        //MST-Start//
		for(ll i=1;i<=m;i++){
			ll u,v,c;
			cin>>u>>v>>c;  --u,--v;
			g.pb({c,{u,v}});
			ll uu= min(u,v),vv=max(u,v);
			if(!mp[MP(uu,vv)]) mp[MP(uu,vv)]=c;
			else mp[MP(uu,vv)] = min(mp[MP(uu,vv)],c);
		}

		for(ll i=0;i<=n;i++) par[i]=i;
		sort(all(g));
		mst(n);
		//MST-End//

		//LCA+ Start//
		wei[0] = 0; //o based
		preprocess();
		cout<<"Case "<<tt<<": "<<endl;
        ll Q; cin>>Q;
		while(Q--) {
			int X, Y; cin >> X >> Y; --X,--Y;
			ans=0;
			int lc = LCA(X, Y);
			cout<<ans<<endl;
		}

		//END- //
   }

	return 0;
}

/*
4 5
1 2 2
1 3 4
2 3 1
3 4 4
2 4 5

ans:
Edges of the mst:
2 3
1 2
3 4

Minimum spanning tree cost:
7

*/
