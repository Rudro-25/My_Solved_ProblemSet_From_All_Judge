//Minimum spanning tree cost + edge find using kruskal + DSU
//complexity: mlogn

#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define pb push_back
#define MP make_pair
#define all(x) x.begin(),x.end()
#define Max 10000000000000000

ll par[1000007],n,m,cnt=0;
ll mst_cost;

struct Edge{
	int from,to,cost;
}edges[6005];

bool cmp(Edge x,Edge y){
	return x.cost<y.cost;
}

ll find_par(ll x)
{
	if(par[x]==x) return x;
	return par[x]=find_par(par[x]);
}

void mst()
{
	ll len=cnt,ct=0;
	for(ll i=1;i<=n;i++) par[i]=i;
	for(ll i=0;i<len;i++){
		ll x= find_par(edges[i].from);
		ll y= find_par(edges[i].to);

		if(x==y){
			edges[i]=edges[cnt-1];
			--cnt;
		}
		else{
			++ct;
			par[x]=y;
			mst_cost += edges[i].cost;
		}
	}
	if(ct != n-1) mst_cost=-1;
}

int main()
{

	ll t; cin>>t;
	for(ll i=1;i<=t;i++){
		cin>>n>>m;
		cnt=0;
		cout<<"Case "<<i<<": "<<endl;

		for(ll i=0;i<m;i++){
			ll u,v,c; cin>>u>>v>>c;
			edges[cnt].from=u;
			edges[cnt].to=v;
			edges[cnt].cost=c;
			cnt++;
			sort(edges,edges+cnt,cmp);
			mst_cost=0;
			mst();
			cout<<mst_cost<<endl;
		}
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
