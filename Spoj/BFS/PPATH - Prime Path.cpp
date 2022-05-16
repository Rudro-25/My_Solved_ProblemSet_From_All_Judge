//https://www.spoj.com/problems/PPATH/

#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define dhoom3   ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);

const int N= 1e5+5;
vector<ll> adj[N];
vector<ll> Primes;
ll dist[N];
bool vis[N];
bool isPrime(int n){
    for(ll i=2;i*i<=n;i++){
        if(n%i==0) return false;
    }
    return true;
}
bool check(int a,int b){
    ll cnt=0;
    while(a && b){
        if(a%10 != b%10) cnt++;
        a/=10; b/=10;
    }
    return (cnt==1);
}
void Build_Graph(){
    for(ll i=1000;i<=9999;i++){
        if(isPrime(i)) Primes.pb(i);
    }

    for(ll i=0;i<Primes.size();i++){
        for(ll j=i+1;j<Primes.size();j++){
            if(check(Primes[i],Primes[j])){
                adj[Primes[i]].pb(Primes[j]);
                adj[Primes[j]].pb(Primes[i]);
            }
        }
    }
}
void bfs(int src){
    queue<ll> q;
    vis[src]=1;
    q.push(src);
    dist[src]=0;
    while(!q.empty()){
        ll node= q.front();
        //cout<<node<<' '<<dist[node]<<endl;
        q.pop();
        for(int child: adj[node]){
            if(!vis[child]){
                dist[child]=dist[node]+1;
                q.push(child);
                vis[child]=1;
            }
        }
    }
}

int main(){
   dhoom3;
   Build_Graph();
   int Test=1;
   cin>>Test;
   while(Test--){
       ll a,b; cin>>a>>b; 
       for(ll i=1000;i<=9999;i++) dist[i]=-1,vis[i]=false;

       bfs(a);
       
       if(dist[b]==-1) cout<<"Impossible"<<endl;
       else cout<<dist[b]<<endl;
   }
   //cout << (ans ? "YES\n" : "No\n") ;
   return 0;
}
/*
1
1009 1039
1033 8179
*/
