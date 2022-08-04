


#include <bits/stdc++.h>
using namespace std;

#define      pb         push_back
#define      ll          long long
#define      FastIO      ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
constexpr ll mod = 1e9  + 7;
const int N= 2e5+5;
int par[N];
vector<pair<ll,ll>> edgeList;
struct edge{
    int a,b,w;
};
edge ar[N];
bool comp(edge a,edge b){
  if(a.w < b.w) return true;
  return false;
}
int find(int a){
    if(par[a]==a) return a;
    return par[a]=find(par[a]);
}
void merge(int a,int b){
    par[a]=b;
}

int main(){
  FastIO

    ll test; cin>>test;
    for(ll tt=1;tt<=test;tt++){
    	ll n,m,cost; cin>>n>>m>>cost;
        for(ll i=1;i<=n;i++) par[i]=i;
        edgeList.clear();
        ll ct=0;
        for(ll i=0;i<m;i++){
        	ll aa,bb,cc; cin>>aa>>bb>>cc;
        	if(cc>=cost) continue;
            ar[ct].a=aa,ar[ct].b=bb,ar[ct].w=cc;
            ++ct;
        }
        sort(ar,ar+ct,comp);
        int sum=0;
        for(ll i=0;i<ct;i++){
            int a= find(ar[i].a);
            int b= find(ar[i].b);
            //cout<<ar[i].a<<' '<<ar[i].b<<endl;

            if(a!=b){
                sum += ar[i].w;
                edgeList.pb({ar[i].a,ar[i].b});
                merge(a,b);
            }
        }
        ll comp=0;
        for(ll i=1;i<=n;i++) if(par[i]==i) ++comp;
        //cout<<sum<<endl;
        ll ans1= sum+(comp*cost);
        ll ans2= comp;
    	
    	
	    cout<<"Case "<<tt<<": "<<ans1<<' '<<ans2<<endl;
    }
    

  return 0;
}

/*
5 5
1 2
2 3
1 3
2 4
4 5

ans:
4
2
those are cut/articulation points
*/
