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
ll par[107],n;
vector<pair<ll,ll>> ans;
map<pair<ll,ll>,ll> mp;
ll mst_cost;

ll find_par(ll x)
{
	if(par[x]==x) return x;
	return par[x]=find_par(par[x]);
}

void ds_union(ll u,ll v,ll cc)
{
	ll par_u=find_par(u);
	ll par_v=find_par(v);
	if(par_u!=par_v){
		par[par_v]=par_u;
		ans.pb({u,v});
        mst_cost += cc;
	}
}

void mst(ll ct)
{
	ll i=0;
	while(ans.size()!= ct-1 && i<n){
        //cout<<g[i].second.first<<' '<<g[i].second.second<<' '<<g[i].first<<endl;
		ds_union(g[i].second.first,g[i].second.second,g[i].first);
		i++;
       // mst_cost+=g[i].first;
	}
}

int main()
{
    
    #ifndef ONLINE_JUDGE
     freopen("input.txt", "r", stdin);
     freopen("output.txt", "w", stdout);
    #endif
    int Test=1;
    cin>>Test;
        for(ll tt=1;tt<=Test;tt++){
        ll cnt=0; cin>>n;
        map<string,int> mpp;
        g.clear(); mst_cost=0; ans.clear();
        for(ll i=0;i<n;i++){
            string s,t; int cost; cin>>s>>t>>cost;
            if(!mpp[s]) mpp[s]=++cnt;
            if(!mpp[t]) mpp[t]=++cnt;
            g.pb({cost,{mpp[s],mpp[t]}});
            mp[MP(mpp[s],mpp[t])]=cost;
            //cout<<mpp[s]<<' '<<mpp[t]<<' '<<cost<<endl;
        }
        //cout<<cnt<<endl;

        for(ll i=1;i<=cnt;i++) par[i]=i;

        sort(all(g));
        mst(cnt);

        cout<<"Case "<<tt<<": ";
        if(ans.size() != cnt-1) cout<<"Impossible"<<endl;
        else cout<<mst_cost<<endl;
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
