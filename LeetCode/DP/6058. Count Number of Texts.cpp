//https://leetcode.com/contest/weekly-contest-292/problems/count-number-of-texts/

class Solution {
public:
    int countTexts(string s) {
        int n=s.size();
        long long dp[n][5],mod=1e9+7;
        int cnt=0;
        long long ans=1;
       for(int i=0;i<n;i++){
           if(!i) cnt=1;
           else{
               if(s[i]==s[i-1]) ++cnt;
               else cnt=1;
           }
           for(int j=0;j<4;j++){
              if(!j){
                  if(cnt>1) dp[i][j]=dp[i-1][4];
                  else dp[i][j]=1;
              }
               else if(j==1){
                   if(cnt>1){
                       if(cnt==2) dp[i][j]=1;
                       else dp[i][j]=dp[i-2][4];
                   }
                   else dp[i][j]=0;
               }
               else if(j==2){
                   if(cnt>2){
                       if(cnt==3) dp[i][j]=1;
                       else dp[i][j]=dp[i-3][4];
                   }
                   else dp[i][j]=0;
               }
               else{
                   if(s[i]=='7' || s[i]=='9'){
                       if(cnt>3){
                            if(cnt==4) dp[i][j]=1;
                            else dp[i][j]=dp[i-4][4];
                        }
                        else dp[i][j]=0;
                   }
                   else dp[i][j]=0;
               }
               //cout<<dp[i][j]<<endl;
           }
           
           if((cnt==1 && i)) ans = (ans*dp[i-1][4])%mod;
           dp[i][4]= (dp[i][0]+dp[i][1]+dp[i][2]+dp[i][3])%mod;
           if(i==n-1) ans = (ans*dp[i][4])%mod;
       }
      return ans;
    }
};
