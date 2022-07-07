#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define dhoom3   ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);

const int N= 25;
char ch[N][N];
ll dist[N][N],n,m; 
bool vis[N][N];
int dx[8]={1,0,-1,0,1,1,-1,-1};
int dy[8]={0,1,0,-1,-1,1,1,-1};
void bfs(ll x,ll y){
    dist[x][y]=0;
    vis[x][y]= true;
    queue<pair<ll,ll>> q;
    q.push({x,y});
    while(!q.empty()){
        ll f= q.front().first, s=q.front().second;
        q.pop();
        for(ll i=0;i<4;i++){
          ll newx= dx[i]+f,newy=dy[i]+s;
          if(newx>0 && newy>0 && newx<=n && newy<=m && !vis[newx][newy] && ch[newx][newy]!='#' && ch[newx][newy]!='m'){
            q.push({newx,newy});
            vis[newx][newy]=1;
            dist[newx][newy]=dist[f][s]+1;
          }
        }
    }
}

int main(){
   dhoom3; 
   int Test=1;
   cin>>Test;
   for(ll tt=1;tt<=Test;tt++){
       cin>>n>>m;

       ll ax,ay,bx,by,cx,cy,hx,hy;
       for(ll i=1;i<=n;i++){
        for(ll j=1;j<=m;j++){
          cin>>ch[i][j];
          if(ch[i][j]=='a') ax=i,ay=j;
          else if(ch[i][j]=='b') bx=i,by=j;
          else if(ch[i][j]=='c') cx=i,cy=j;
          else if(ch[i][j]=='h') hx=i,hy=j;
          vis[i][j]=false;
        }
       }

       bfs(hx,hy);
       ll ans=max(dist[ax][ay],dist[bx][by]);
       ans=max(ans,dist[cx][cy]);

       
       cout<<"Case "<<tt<<": ";
       cout<<ans<<endl;
    
   }
   //cout << (ans ? "YES\n" : "No\n") ;
   return 0;
}
/*

*/
