//https://www.codechef.com/problems/MULTQ3

//For range sum in update + query with logn complexity with lazy propogation

#include <bits/stdc++.h>
#define mx 100005

using namespace std;
using ll = long long;

//prop tar subtree koto bar update hobe eta store kore..
struct info {
    int prop,zero,one,two;
} tree[mx * 4];

void build(int node, int b, int e) //(cur_node, range_begin, range_end)
{
    if (b == e) {
        tree[node].zero = 1;
        tree[node].one = 0;
        tree[node].two = 0;
        return;
    }
    int Left = node * 2;
    int Right = node * 2 + 1;
    int mid = (b + e) / 2;
    build(Left, b, mid);
    build(Right, mid + 1, e);
    tree[node].zero = tree[Left].zero + tree[Right].zero;
    tree[node].one = tree[Left].one + tree[Right].one;
    tree[node].two = tree[Left].two + tree[Right].two;
}
//Tree(! index based)
// index- 0 1 2 3  4 5  6 7 8  9 10 11 12 13
// value- 0 8 5 3 -5 10 1 2 4 -9 3  7  1  0

void update(int node, int b, int e, int i, int j) //(cur_node, range_begin, range_end, query_begin, query_end, value)
{
    if(tree[node].prop != 0){
        int val= tree[node].prop;
        tree[node].prop= 0;
        val%=3;
        for(ll k=0;k<val;k++){
            // swap(tree[node].zero,tree[node].one);
            // swap(tree[node].zero,tree[node].two);
            int a= tree[node].two;
            tree[node].two= tree[node].one;
            tree[node].one= tree[node].zero;
            tree[node].zero= a;
        }

        if(b != e)
          tree[2*node].prop += val, tree[2*node+1].prop += val;
    }
    if (i > e || j < b) return;
    if (b >= i && e <= j)
    {
            int a= tree[node].two;
            tree[node].two= tree[node].one;
            tree[node].one= tree[node].zero;
            tree[node].zero= a;
        
        if(b != e)
          tree[2*node].prop ++, tree[2*node+1].prop ++;
        return;
    }
    int Left = node * 2;
    int Right = (node * 2) + 1;
    int mid = (b + e) / 2;
    update(Left, b, mid, i, j);
    update(Right, mid + 1, e, i, j);
    tree[node].zero = tree[Left].zero + tree[Right].zero;
    tree[node].one = tree[Left].one + tree[Right].one;
    tree[node].two = tree[Left].two + tree[Right].two;
}
    //subtree don't know about tree[node].prop so recalculate that


int query(int node, int b, int e, int i, int j) //(cur_node, range_begin, range_end, query_begin, query_end)
{
    if(tree[node].prop != 0){
        int val= tree[node].prop;
        tree[node].prop= 0;
        val%=3;
        for(ll k=0;k<val;k++){
            int a= tree[node].two;
            tree[node].two= tree[node].one;
            tree[node].one= tree[node].zero;
            tree[node].zero= a;
        }

        if(b != e)
          tree[2*node].prop += val, tree[2*node+1].prop += val;
    }
    if (i > e || j < b)  return 0;

    if (b >= i and e <= j) return tree[node].zero;

    int Left = node << 1;
    int Right = (node << 1) + 1;
    int mid = (b + e) >> 1;

    return query(Left,b,mid,i,j) + query(Right,mid+1,e,i,j);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(0);

    int n,q;
    //cin >> n >> q;
    scanf("%d %d", &n,&q);

    //for (int i = 1; i <= n; ++i) cin >> arr[i];

    build(1, 1, n);

    while(q--){
        int t,l,r; 
        scanf("%d %d %d", &t,&l,&r);
        if(t==1){
            int ans= query(1,1,n,l+1,r+1);
            printf("%d\n",ans);
        }
        else{
            update(1,1,n,l+1,r+1);
        }
    }
    

    return 0;
}

/*
7 6
4 -9 3 7 1 0 2
1 2 5
2 1 2 10
1 2 5
2 4 5 2
2 5 7 2
1 2 7
ans:

2
12
24
*/
