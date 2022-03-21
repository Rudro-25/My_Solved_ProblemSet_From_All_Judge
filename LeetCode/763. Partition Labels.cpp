class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> ans;
        int n=s.size();
        int cur[26],cnt[26];
        for(int i=0;i<26;i++) cnt[i]=cur[i]=0;
        for(int i=0;i<n;i++) cnt[s[i]-'a']++;
        
        int ct=0;
        for(int i=0;i<n;i++){
            cur[s[i]-'a']++; ct++;
            bool ok=true;
            for(int j=0;j<26;j++){
                if(!cur[j] || cur[j]==cnt[j]) continue;
                else ok=false;
            }
            if(ct && ok){
                ans.push_back(ct);
                ct=0;
            }
        }
        
        return ans;
    }
};
