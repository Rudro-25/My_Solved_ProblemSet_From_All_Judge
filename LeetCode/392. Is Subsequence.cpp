class Solution {
public:
    bool isSubsequence(string s, string t) {
        int len= s.size(),pos=0;
        for(int i=0;i<t.size();i++){
            if(s[pos]==t[i]) pos++;
            if(pos==len) return true;
        }
        if(pos==len)return true;
        return false;
    }
};
