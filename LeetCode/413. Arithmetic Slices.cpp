class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int ans=0,n=nums.size();
        for(int i=0;i<n-1;i++){
            int bal= nums[i+1]-nums[i];
            for(int j=i+2;j<n;j++){
                int cur= nums[j]-nums[j-1];
                if(cur==bal) ++ans;
                else break;
            }
        }
        return ans;
    }
};
