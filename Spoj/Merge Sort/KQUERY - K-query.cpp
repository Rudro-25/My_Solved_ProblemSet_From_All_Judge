//https://www.spoj.com/problems/KQUERY/
//Merge Sort

#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define vi vector<int>
#define dhoom3   ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);

const int N= 2e5+5;
vector<int> tree[4*N];
ll ar[N];
void merge(vi &a, vi &b, vi &c){
  int i=0,j=0;
   while(i < a.size() && j < b.size()){
       if(a[i]<=b[j])
         c.pb(a[i]), ++i;
       else 
         c.pb(b[j]), ++j;
   }
   while(i < a.size()) c.pb(a[i]), ++i;
   while(j < b.size()) c.pb(b[j]), ++j;
}
void build(int si,int ss,int se){
   if(ss==se){
       tree[si].pb(ar[ss]);
       return;
   }

   int mid= (ss+se)/2;
   int Left= 2*si, Right=2*si+1;
   build(Left,ss,mid);
   build(Right,mid+1,se);

   merge(tree[Left], tree[Right], tree[si]);
}
int query(int si,int ss,int se,int qs,int qe,int k){
    if(ss>qe || se<qs) return 0;
    if(ss>=qs && se<=qe){
        int res= tree[si].end()-upper_bound(tree[si].begin(),tree[si].end(),k);
        return res;
    }
    int mid= (ss+se)/2;  
    int l= query(2*si,ss,mid,qs,qe,k);
    int r= query(2*si+1,mid+1,se,qs,qe,k);

    return l+r;
}

int main(){
   dhoom3;
   int Test=1;
   while(Test--){
       ll n,q; cin>>n;
       for(ll i=1;i<=n;i++) cin>>ar[i];

       build(1,1,n);
       cin>>q;
       while(q--){
           ll l,r,k; cin>>l>>r>>k;
           cout<<query(1,1,n,l,r,k)<<endl;
       }
   }
   return 0;
}
/*
8 2
1 4 3 5 6 4 3 2
3 7 4
2 6 5

ans:
2
3
*/
