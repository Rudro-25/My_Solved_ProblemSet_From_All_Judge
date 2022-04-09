#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define      ll                  long long
#define      pb                 push_back
#define      mp                 make_pair
#define      all(x)             x.begin(),x.end()
#define      Ceil(x,y)           ((x+y-1)/y)
#define      gcd(a,b)            __gcd(a,b)
#define      lcm(a,b)           (a*b)/gcd(a,b)
#define      InTheNameOfGod      ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);

template <typename T>
using ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

constexpr ll mod = 1e9 + 7;
const ll N=3e6+5;
ll cc;

void solve(){
   //cout<<"Case "<<++cc<<": "<<endl;
   ll n;
   cin>>n;
   ll val=1,sum=0;
   vector<ll> v,ans;
   for(ll i=0;i<30;i++){
    sum+=val; v.pb(val); val*=2;
   }
   ll bal=1e6;
   for(ll i=bal;i<bal+70;i++){
    sum+=i; v.pb(i);
   }

   for(ll i=0;i<v.size();i++) cout<<v[i]<<' ';
   cout<<endl;

   ll sum1=0,sum2=0;
   for(ll i=0;i<n;i++){
     ll a; cin>>a;
     if(sum1<=sum2){sum1+=a; ans.pb(a);}
     else sum2+=a;
     sum+=a;
   }

   ll target= sum/2;
   ll baki= target-sum1;

   for(ll i=0;i<30;i++){
    if(v[i]&baki){
      ans.pb(v[i]); sum1+=v[i];
    }
   }

   //cout<<sum<<' '<<sum1<<' '<<endl;

   for(auto it: ans)
    cout<<it<<' ';
   cout<<endl;
   
}

int main(){
   InTheNameOfGod;
   ll Test=1;
   cin>>Test;
   while(Test--){
     solve();
    }
  return 0;
}
/*
1126 1026 1027 1028 1029 1030 1031 1032 1033 1034 1035 1036 1037 1038 1039 1040 1041 1042 1043 1044 1045 1046 1047 1048 1049 1050 1051 1052 1053 1054 1055 1056 1057 1058 1059 1060 1061 1062 1063 1064 1065 1066 1067 1068 1069 1070 1071 1072 1073 1074 1075 1076 1077 1078 1079 1080 1081 1082 1083 1084 1085 1086 1087 1088 1089 1090 1091 1092 1093 1094 1095 1096 1097 1098 1099 1100 1101 1102 1103 1104 1105 1106 1107 1108 1109 1110 1111 1112 1113 1114 1115 1116 1117 1118 1119 1120 1121 1122 1123 1124

*/
