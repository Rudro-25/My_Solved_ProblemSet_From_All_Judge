//https://www.spoj.com/problems/CEQU/

#include<bits/stdc++.h>
using namespace std;

#define ll long long int
ll cc;

int main(){
   int Test=1;
   cin>>Test;
   while(Test--){
       ll a,b,c; cin>>a>>b>>c; 
       int g= __gcd(a,b);

       if(c%g) cout<<"Case "<<++cc<<": No"<<endl;
       else cout<<"Case "<<++cc<<": Yes"<<endl;
   }
   return 0;
}
/*
57 81

ans: 10 -7
*/
