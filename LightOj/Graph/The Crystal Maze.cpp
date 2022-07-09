//A. Segment Tree for the Sum

#include <bits/stdc++.h>
using namespace std;

#define      pb         push_back
#define      mp          make_pair
#define      ll          long long
#define      FastIO      ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
constexpr ll mod = 1e9  + 7;
const ll N=2e5+5;
int dx[8]={1,0,-1,0,1,1,-1,-1};
int dy[8]={0,1,0,-1,-1,1,1,-1};

char ch[505][505];
bool vis[505][505];
ll ans[505][505],crystal,n,m;
vector<pair<ll,ll>> vp;
void dfs(ll x,ll y){
  vp.pb({x,y});
  vis[x][y]=1;
  if(ch[x][y]=='C') crystal++;
  for(ll i=0;i<4;i++){
    ll newx=x+dx[i];
    ll newy=y+dy[i];
    if(newx>=0 && newy>=0 && newx<n && newy<m && !vis[newx][newy] && ch[newx][newy] != '#'){
        dfs(newx,newy);
    }
  }
}

int main(){
  FastIO

//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
   int Test=1;
   cin>>Test;
   for(ll tt=1;tt<=Test;tt++){
        cout<<"Case "<<tt<<":"<<endl;
        memset(vis,0,sizeof(vis));
        ll q;
        cin>>n>>m>>q;
        for(ll i=0;i<n;i++){
            for(ll j=0;j<m;j++){
                cin>>ch[i][j];
            }
        }


        for(ll i=0;i<n;i++){
            for(ll j=0;j<m;j++){
                if(!vis[i][j] && ch[i][j] != '#'){
                    //cout<<i<<' '<<j<<' ';
                    vp.clear(); crystal=0;
                    dfs(i,j);
                    //cout<<crystal<<endl;
                    for(ll k=0;k<vp.size();k++){
                        ans[vp[k].first][vp[k].second]=crystal;
                    }
                }
            }
        }

        while(q--){
            ll x,y; cin>>x>>y;
            --x,--y;
            cout<<ans[x][y]<<endl;
        }
        
   }

  return 0;
}
/*
1
5 1
6 5 3 2 1
c 1


ans:
11
8
14

*/
