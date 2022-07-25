#include <bits/stdc++.h>
using namespace std;

#define      pb         push_back
#define      ll          long long
#define      FastIO      ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
constexpr ll mod = 1e9  + 7;
const ll N=2e4+5;

vector<ll> adj[N];
vector<int> toposort;
ll ind[N],m,cnt;

bool solve(int n){
	toposort.clear();
    queue<int> q;
    for(ll i=1;i<=n;i++)
    if(!ind[i]) q.push(i);

    while(!q.empty()){
        int cur= q.front();
        toposort.pb(cur);
        q.pop();

        for(int child: adj[cur]){
            ind[child]--;
            if(!ind[child]) q.push(child);
        }
    }
    if(toposort.size()==cnt) return true;
    else return false;
}

int main(){
  FastIO

  int test; cin>>test;
  for(int tt=1;tt<=test;tt++){
	  	map<string,ll> mp;
	  	cnt=0; 
	  	 cin>>m;
	  	 for(ll i=1;i<=m+m;i++) ind[i]=0,adj[i].clear();
		  for(ll i=0;i<m;i++){
		  	string s,t; cin>>s>>t;
		  	if(!mp[s]) mp[s]=++cnt;
		  	if(!mp[t]) mp[t]=++cnt; 
		    ll x=mp[s],y=mp[t]; 
		    //cerr<<x<<' '<<y<<endl;
		    adj[x].pb(y);
		    ind[y]++;
		  }
		  
		  if(solve(cnt)) cout<<"Case "<<tt<<": "<<"Yes"<<endl;
		  else cout<<"Case "<<tt<<": "<<"No"<<endl;
  }


  return 0;
}
/*
5 4
1 2
1 4
1 5
2 3

ans:
1 5 4 2 3
*/
