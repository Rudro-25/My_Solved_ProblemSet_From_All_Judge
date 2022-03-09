//For range sum in update + query with logn complexity with lazy propogation
//https://lightoj.com/problem/computing-fast-average

#include <bits/stdc++.h>
#include <stdio.h>
#define fin freopen("input", "r", stdin)
#define whatis(x) cerr << #x << ": " << x << endl;
#define mx 400005

using namespace std;
using ll = long long;

ll arr[mx],cc;
struct info {
    ll prop, sum;
} tree[mx];

//Tree(! index based)
// index- 0 1 2 3  4 5  6 7 8  9 10 11 12 13
// value- 0 8 5 3 -5 10 1 2 4 -9 3  7  1  0

void propagate(int node,int b,int e){
    if(tree[node].prop==-1){
        return;
    }
    tree[node].sum= (e-b+1)*tree[node].prop;
    if(e>b){
        int Left = node * 2;
        int Right = (node * 2) + 1;
        tree[Left].prop= tree[node].prop;
        tree[Right].prop= tree[node].prop;
    }
    tree[node].prop= -1;
}

void update(int node, int b, int e, int i, int j, ll x)
{
    propagate(node,b,e);
    if (i > e || j < b)
        return;
    if (b >= i && e <= j)
    {
        tree[node].prop = x;
        propagate(node,b,e);
        return;
    }
    int Left = node * 2;
    int Right = (node * 2) + 1;
    int mid = (b + e) / 2;
    update(Left, b, mid, i, j, x);
    update(Right, mid + 1, e, i, j, x);
    tree[node].sum = tree[Left].sum + tree[Right].sum;
}

ll query(int node, int b, int e, int i, int j)
{
    propagate(node,b,e);
    if (i > e || j < b)
        return 0;

    if (b >= i and e <= j){
      return tree[node].sum ;
    }

    int Left = node << 1;
    int Right = (node << 1) + 1;
    int mid = (b + e) >> 1;

    ll p1 = query(Left, b, mid, i, j);
    ll p2 = query(Right, mid + 1, e, i, j);

    return p1 + p2;
}

int main() {
//  ios_base::sync_with_stdio(false);
//  cin.tie(NULL);
    

    int test; cin>>test;
    while(test--){
       cout<<"Case "<<++cc<<": "<<endl;
       int n,q;
       cin >> n >> q;

       for(ll i=0;i<=4*n;i++){
          arr[i]=0; 
          tree[i].sum=0;
          tree[i].prop=0;
      }

      // init(1, 1, n);
      while(q--){
          ll t,l,r,val; cin>>t;
          if(t==1){
             cin>>l>>r>>val;
             l++; r++;
             update(1, 1, n, l, r, val);
          }
          else{
            cin>>l>>r;
            l++,r++;
            ll ans= query(1, 1, n, l, r);
            //cout<<ans<<endl;
            ll dif= r-l+1;
            if(ans%dif==0){
               cout<<ans/dif<<endl;
               continue;
            }
            ll gd= __gcd(ans,dif);
            ans/=gd,dif/=gd;

            cout<<ans<<"/"<<dif<<endl;
          }
      } 
  }

    return 0;
}

/*

*/
