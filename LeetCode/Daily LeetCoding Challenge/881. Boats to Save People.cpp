class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int n= people.size(),k=limit,ans=0;
        multiset<int> st;
       for(int i=0;i<n;i++){
        st.insert(people[i]);
       }
       while(st.size()){
         auto it= st.rbegin();
         int val= *it;
         st.erase(st.find(val));
         ++ans;
         if(st.size()){
            auto itt= st.upper_bound(k-val);
            if(itt!=st.begin()){
                --itt;
                int bal= *itt;
                st.erase(st.find(bal));
            }
         }
       }

       return ans;
    }
};
