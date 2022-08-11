#pragma GCC diagnostic ignored "-Wunused-variable"
#pragma GCC diagnostic ignored "-Wunused-parameter"
#pragma GCC diagnostic ignored "-Wunused-but-set-variable" 
#pragma GCC diagnostic ignored "-Wformat"
#pragma GCC diagnostic ignored "-Wsign-compare"
#include <bits/stdc++.h>
using namespace std;

#define      pb         push_back
#define      ll          long long
#define      ff          first
#define      ss          second
#define      FastIO      ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
constexpr ll mod = 1e9  + 7;
const ll N=2e4+5;
ll x[]={1,0,-1,0};
ll y[]={0,1,0,-1};
vector<pair<ll,ll>> pos(30);
bool vis[11][11];
ll dist[11][11];
char ch[11][11];
ll ans=-1,n;
void bfs(ll curx,ll cury,ll target,ll dis){
	queue<pair<ll,ll>> q;
	q.push({curx,cury});
	vis[curx][cury]=1;
	dist[curx][cury]=0;
	
	while(!q.empty()){
		auto it= q.front();
		//cout<<it.first<<' '<<it.second<<endl;
		q.pop();
	    for(ll i=0;i<4;i++){
			ll newx= it.first+x[i], newy=it.second+y[i];
			//cout<<newx<<' '<<newy<<' '<<"f"<<endl;
			if(newx>=0&&newx<n&&newy>=0&&newy<n&&!vis[newx][newy]&&ch[newx][newy]!='#'&&(ch[newx][newy]-'A')<=target){
				q.push({newx,newy});
				dist[newx][newy]= dist[it.first][it.second]+1;
				vis[newx][newy]=1;
				if((ch[newx][newy]-'A')==target){
					ans=dist[newx][newy];
				}
			}
		}	
	}
}

int main(){
  FastIO

  int test; cin>>test;
  for(int tt=1;tt<=test;tt++){
  	//for(ll i=0;i<30;i++) pos[i]=-1;
  	 ll cnt=0; cin>>n;
  	 for(ll i=0;i<n;i++){
  	 	for(ll j=0;j<n;j++){
  	 		cin>>ch[i][j];
  	 		if(ch[i][j]>='A' && ch[i][j]<='Z'){
  	 			cnt++;
  	 			pos[ch[i][j]-'A']={i,j};
  	 		}
  	 	}
  	 }
  	 ll answer=0;
  	 for(ll i=0;i<cnt-1;i++){
  	 	memset(vis,0,sizeof(vis));
  	 	ans=-1;
  	 	bfs(pos[i].first,pos[i].second,i+1,0);
  	 	//cout<<ans<<endl;
  	 	if(ans==-1) {answer=-1; break;}
  	 	answer+=ans;
  	 }
  	 if(answer==-1) cout<<"Case "<<tt<<": "<<"Impossible"<<endl;
  	 else cout<<"Case "<<tt<<": "<<answer<<endl;
  	 
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
