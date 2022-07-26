#include <bits/stdc++.h>
using namespace std;

#define      pb         push_back
#define      ll          long long
#define      ff          first
#define      ss          second
#define      FastIO      ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
constexpr ll mod = 1e9  + 7;
const ll N=2e4+5;
ll xi[]={-1,0,0,1,0,0};
ll yi[]={0,-1,0,0,1,0};
ll zi[]={0,0,-1,0,0,1};
bool ok[26][26][26];
bool visited[26][26][26];
ll cost[26][26][26];
ll sx,sy,sz,tx,ty,tz;
ll solve(){
	bool chk=false;
	queue<pair<pair<ll,ll>,ll>> q;
	q.push({{sx,sy},sz});
	cost[sx][sy][sz]=0;
	while(!q.empty()){
		auto it= q.front();
		q.pop();
		ll xx=it.ff.ff,yy=it.ff.ss,zz=it.ss;
		//cout<<xx<<' '<<yy<<' '<<zz<<endl;
		visited[xx][yy][zz]=1;
		if(xx==tx && yy==ty && zz==tz){
			chk=true; break;
		}
		for(ll i=0;i<6;i++){
		  ll newx=xx+xi[i],newy=yy+yi[i],newz=zz+zi[i];
		  if(newx>=26) newx-=26; if(newy>=26) newy-=26;  if(newz>=26) newz-=26; 
		  if(newx<0) newx+=26; if(newy<0) newy+=26;  if(newz<0) newz+=26; 
		  //cout<<newx<<' '<<newy<<' '<<newz<<endl;
		  if(!visited[newx][newy][newz]){
		  	visited[newx][newy][newz]=1;
		  	q.push({{newx,newy},newz});
	        cost[newx][newy][newz]= cost[xx][yy][zz] + 1;
		  }
		}
	}
	ll cur=-1;
	if(chk) cur= cost[tx][ty][tz];
	//cout<<chk<<' '<<cur<<endl;
	
	return cur;
}


int main(){
  FastIO

  int test; cin>>test;
  for(int tt=1;tt<=test;tt++){
  	memset(ok,1,sizeof(ok));
  	memset(visited,0,sizeof(visited));
	  	string s,t; cin>>s>>t;
	  	
	  	ll q; cin>>q;
	  	while(q--){
	  		string s1,s2,s3; cin>>s1>>s2>>s3;
	  		for(ll i=0;i<s1.size();i++){
	  			for(ll j=0;j<s2.size();j++){
	  				for(ll k=0;k<s3.size();k++){
	  					ll x=s1[i]-'a',y=s2[j]-'a',z=s3[k]-'a';
	  					//cout<<x<<' '<<y<<' '<<z<<endl;
	  					ok[x][y][z]=0;
	  				}
	  			}
	  		}
	  	}
	  	    ll ans=-1;
	  		sx=s[0]-'a',sy=s[1]-'a',sz=s[2]-'a';
	  		tx=t[0]-'a',ty=t[1]-'a',tz=t[2]-'a';
	  		//cout<<ok[sx][sy][sz]<<' '<<ok[tx][ty][tz]<<endl;
	  		if(ok[sx][sy][sz] && ok[tx][ty][tz]){
	  			ans= solve();
	  		}
            cout<<"Case "<<tt<<": "<<ans<<endl;
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
