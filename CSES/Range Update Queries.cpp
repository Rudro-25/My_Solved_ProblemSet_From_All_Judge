//For range sum in update + query with logn complexity with lazy propogation

#include <bits/stdc++.h>
#include <stdio.h>
#define fin freopen("input", "r", stdin)
#define whatis(x) cerr << #x << ": " << x << endl;
#define mx 200005

using namespace std;
using ll = long long;

ll arr[mx];
struct info {
    ll prop, sum;
} tree[mx * 4];

void init(int node, int b, int e)
{
    if (b == e) {
        tree[node].sum = arr[b];
        return;
    }
    int Left = node * 2;
    int Right = node * 2 + 1;
    int mid = (b + e) / 2;
    init(Left, b, mid);
    init(Right, mid + 1, e);
    tree[node].sum = tree[Left].sum + tree[Right].sum;
}
//Tree(! index based)
// index- 0 1 2 3  4 5  6 7 8  9 10 11 12 13
// value- 0 8 5 3 -5 10 1 2 4 -9 3  7  1  0

void update(int node, int b, int e, int i, int j, ll x)
{
    if (i > e || j < b)
        return;
    if (b >= i && e <= j)
    {
        tree[node].sum += ((e - b + 1) * x);
        tree[node].prop += x;
        return;
    }
    int Left = node * 2;
    int Right = (node * 2) + 1;
    int mid = (b + e) / 2;
    update(Left, b, mid, i, j, x);
    update(Right, mid + 1, e, i, j, x);
    tree[node].sum = tree[Left].sum + tree[Right].sum + (e - b + 1) * tree[node].prop;
}

ll query(int node, int b, int e, int i, int j, ll carry = 0)
{
    if (i > e || j < b)
        return 0;

    if (b >= i and e <= j)
        return tree[node].sum + carry * (e - b + 1);

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

    int n, q;
    cin >> n >>q;

    for (int i = 1; i <= n; ++i) {
        cin >> arr[i];
    }

    init(1, 1, n);

    while(q--){
        ll t,l,r,val; cin>>t;
        if(t==1){
           cin>>l>>r>>val;
           update(1,1,n,l,r,val);
        }else{
            ll pos; cin>>pos;
            ll ans= query(1,1,n,pos,pos);
            cout<<ans<<endl;
        }
    }

    return 0;
}

/*

*/
