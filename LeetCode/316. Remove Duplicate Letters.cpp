class Solution {
public:
    string removeDuplicateLetters(string s) {
        string ans="";
        bool vis[30]; int cnt[30];
        for(int i=0;i<26;i++) vis[i]=false,cnt[i]=0;
        for(int i=0;i<s.size();i++) cnt[s[i]-'a']++;
        
        for(int i=0;i<s.size();i++){
            cnt[s[i]-'a']--;
            if(!vis[s[i]-'a']){
              while(ans.size() && ans.back()>s[i] && cnt[ans.back()-'a']){
                vis[ans.back()-'a']=0;
                ans.pop_back();
              }
                ans+=s[i];
                vis[s[i]-'a']=1;
            }
        }
        return ans;
    }
};
