class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        set<int> st;
        for(int i=0;i<nums.size();i++){
            if(nums[i]%2) nums[i]*=2;
            st.insert(nums[i]);
        }
        
        int ans= (*st.rbegin()-*st.begin());
        while(*st.rbegin()%2==0){
            int val= *st.rbegin();
            st.erase(val);
            st.insert(val/2);
            ans=min(ans,*st.rbegin()-*st.begin());
        }
        return ans;
    }
};
