class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        multiset<int> st;
        for(auto it: stones)  st.insert(it);
        
        while(st.size()>1){
            int v1= *st.rbegin();
            st.erase(st.find(v1));
            int v2= *st.rbegin();
            st.erase(st.find(v2));
            if(v1>v2) st.insert(v1-v2);
        }
     return *st.begin();
    }
};
