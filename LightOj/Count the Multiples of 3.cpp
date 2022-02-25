//For range sum in update + query with logn complexity with lazy propogation

#include <bits/stdc++.h>
#include <stdio.h>
#define fin freopen("input", "r", stdin)
#define whatis(x) cerr << #x << ": " << x << endl;
#define mx 500005

using namespace std;
using ll = long long;

ll arr[mx],cc;
struct info {
    ll one, two, three, prop;
} tree[mx];

void init(int node, int b, int e)
{
    if (b == e) {
        tree[node].one = 0;
        tree[node].two = 0;
        tree[node].three = 1;
        tree[node].prop=0;
        return;
    }
    int Left = node * 2;
    int Right = node * 2 + 1;
    int mid = (b + e) / 2;
    init(Left, b, mid);
    init(Right, mid + 1, e);
    tree[node].one = tree[Left].one + tree[Right].one;
    tree[node].two = tree[Left].two + tree[Right].two;
    tree[node].three = tree[Left].three + tree[Right].three;
}
//Tree(! index based)
// index- 0 1 2 3  4 5  6 7 8  9 10 11 12 13
// value- 0 8 5 3 -5 10 1 2 4 -9 3  7  1  0

void update(int node, int b, int e, int i, int j)
{
    if (i > e || j < b)
        return;
    if (b >= i && e <= j)
    {
        tree[node].prop ++ ;
        swap(tree[node].one,tree[node].two);
        swap(tree[node].one,tree[node].three);
        return;
    }
    int Left = node * 2;
    int Right = (node * 2) + 1;
    int mid = (b + e) / 2;
    update(Left, b, mid, i, j);
    update(Right, mid + 1, e, i, j);
    
    tree[node].one = tree[Left].one + tree[Right].one;
    tree[node].two = tree[Left].two + tree[Right].two;
    tree[node].three = tree[Left].three + tree[Right].three;
    tree[node].prop%=3;
    ll bal= tree[node].prop;
    while(bal--){
      swap(tree[node].one,tree[node].two);
      swap(tree[node].one,tree[node].three);
    }
}

ll query(int node, int b, int e, int i, int j,int carry=0)
{
    if (i > e || j < b)
        return 0;

    if (b >= i and e <= j){
        if(carry%3==1){
          return tree[node].two;
        }else if(carry%3==2){
          return tree[node].one;
        }else{
          return tree[node].three;
        }
    }

    int Left = node << 1;
    int Right = (node << 1) + 1;
    int mid = (b + e) >> 1;

    ll p1 = query(Left, b, mid, i, j, carry + tree[node].prop);
    ll p2 = query(Right, mid + 1, e, i, j, carry + tree[node].prop);

    return p1 + p2;
}

int main() {
//  ios_base::sync_with_stdio(false);
//  cin.tie(NULL);

    int test; cin>>test;
    while(test--){
      cout<<"Case "<<++cc<<": "<<endl;
      int n,q;
      cin >> n>>q;

      for(ll i=0;i<=4*n;i++){
          arr[i]=0; 
          tree[i].one=0;
          tree[i].two=0;
          tree[i].three=0;
          tree[i].prop=0;
      }

      //for (int i = 1; i <= n; ++i) arr[i]=0;

      init(1, 1, n);
      while(q--){
          ll t,l,r; cin>>t>>l>>r;
          l++,r++;
          if(t==0){
             update(1, 1, n, l, r);
          }
          else{
            ll ans= query(1, 1, n, l, r);
            cout<<ans<<endl;
          }
      }
    }

    return 0;
}

/*
1
10 9
0 0 9
0 3 7
0 1 4
1 1 7
0 2 2
1 2 4
1 8 8
0 5 8
1 6 9


ans: 
Case 1:
2
3
0
2

*/
