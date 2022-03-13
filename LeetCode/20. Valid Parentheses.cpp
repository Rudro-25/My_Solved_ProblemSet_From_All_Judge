class Solution {
public:
    bool isValid(string s) {
        if(s.size()%2) return false;
        stack<char> st;
        for(int i=0;i<s.size();i++){
           if(s[i]=='(' || s[i]=='{' || s[i]=='[') st.push(s[i]);
            else{
                if(st.empty()) return false;
                else if(s[i]==')' &&st.top()!='(') return false;
                else if(s[i]=='}' &&st.top()!='{') return false;
                else if(s[i]==']' &&st.top()!='[') return false;
                else st.pop();
            }
        }
        if(st.empty()) return true;
        else return false;
    }
};
