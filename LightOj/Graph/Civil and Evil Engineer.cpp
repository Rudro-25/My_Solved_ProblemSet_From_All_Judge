//MST-Kruskal Algo

#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define dhoom3   ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);

const int N= 2e4+5;
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
bool cmp(edge a,edge b){
  if(a.w > b.w) return true;
  return false;
}
int find(int a){
    if(par[a]==-1) return a;
    return par[a]=find(par[a]);
}
void merge(int a,int b){
    par[a]=b;
}

int main(){
   dhoom3;
   int Test=1,tt=0;
   cin>>Test;
   while(Test--){
        ll n,m=0; cin>>n;
        for(ll i=0; ;i++){
          ll aa,bb,cc; cin>>aa>>bb>>cc;
          if(!aa && !bb && !cc) break;
           ar[i].a=aa,ar[i].b=bb,ar[i].w=cc;
           m++;
        }
        //Find min span tree
        for(ll i=0;i<=n;i++) par[i]=-1;
        sort(ar,ar+m,comp);
        int mn_st=0;
        for(ll i=0;i<m;i++){
            int a= find(ar[i].a);
            int b= find(ar[i].b);

            if(a!=b){
                mn_st += ar[i].w;
                edgeList.pb({ar[i].a,ar[i].b});
                merge(a,b);
            }
        }
        //cout<<mn_st<<endl;
        //Find Max Span tree
        for(ll i=0;i<=n;i++) par[i]=-1;
        sort(ar,ar+m,cmp);
        int mx_st=0;
        for(ll i=0;i<m;i++){
            int a= find(ar[i].a);
            int b= find(ar[i].b);

            if(a!=b){
                mx_st += ar[i].w;
                edgeList.pb({ar[i].a,ar[i].b});
                merge(a,b);
            }
        }
        //cout<<mx_st<<endl;
        ll sum=mn_st+mx_st;
        cout<<"Case "<<++tt<<": ";
        if(sum%2==0) cout<<sum/2<<endl;
        else cout<<sum<<"/"<<"2"<<endl;
    }
   //cout << (ans ? "YES\n" : "No\n") ;
   return 0;
}
/*
4 5
1 2 7
1 4 6
4 2 9
4 3 8
2 3 6

ans:
19
1 4
2 3
1 2
*/
