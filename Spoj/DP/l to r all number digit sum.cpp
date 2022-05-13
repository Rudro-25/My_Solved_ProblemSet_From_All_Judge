//https://www.spoj.com/problems/CPCRC1C/
//find sum of l r

#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define dhoom3   ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);

const int N= 2e5+5;
ll dp[11][100][2],val[N];
ll getSum(int pos,int n,int sum,bool flag){
    if(pos>n) return sum;
    if(dp[pos][sum][flag] !=-1) return dp[pos][sum][flag];
    ll limit=9;
    if(!flag) limit=val[pos];
    ll res=0;
    for(ll i=0;i<=limit;i++){
        if(i<limit || flag) res+= getSum(pos+1,n,sum+i,1);
        else res+= getSum(pos+1,n,sum+i,0);
    }
    return dp[pos][sum][flag] = res;
}

ll digitSum(string s){
    ll res=0;
    for(ll i=0;i<s.size();i++){
        res+=s[i]-'0';
    }
    return res;
}

int main(){
   dhoom3;
   int Test=1;
   //cin>>Test;
   while(1){
       string a,b; cin>>a>>b;
       if(a=="-1") break;

       //for L
       memset(dp,-1,sizeof dp);
       for(ll i=0;i<a.size();i++) val[i+1]=a[i]-'0';
       ll L= getSum(1,a.size(),0,0);

       //for R
       memset(dp,-1,sizeof dp);
       for(ll i=0;i<b.size();i++) val[i+1]=b[i]-'0';
       ll R= getSum(1,b.size(),0,0);

       ll ans= R-L+digitSum(a);

       cout<<ans<<endl;
   }
   //cout << (ans ? "YES\n" : "No\n") ;
   return 0;
}
/*
345

ans: 3417
*/
