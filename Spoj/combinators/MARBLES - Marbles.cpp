//How many N digit number using 1-k number and num is no-decreasing.
//Explain:
//Star: No of position/digit = N
//Bars : no of dif digit available - 1 = K-1
//https://www.spoj.com/problems/MARBLES/


#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define dhoom3   ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);

const int N= 2e5+5;

ll nCr(ll n,ll k){
    ll mn= min(k,n-k),ans=1;
    for(ll i=1;i<=mn;i++){
        ans*=(n-i+1);ans/=i;
    }

    return ans;
}

int main(){
   dhoom3;
   int Test=1;
   cin>>Test;
   while(Test--){
       ll n,k; cin>>n>>k;
       
       cout<<nCr(n-1,k-1)<<endl;
   }
   return 0;
}
/*
2 2

ans: 3 [11,12,22]
*/
