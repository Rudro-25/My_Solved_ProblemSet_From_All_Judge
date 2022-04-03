class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size(),pos=-1;
        vector<int> use,ans;
        for(int i=n-1;i>0;i--){
            if(nums[i]>nums[i-1]){
                pos=i; break;
            }
        }
        if(pos==-1){
            reverse(nums.begin(),nums.end());
        }
        else{
            int poss=-1,mn=105;
            for(int i=pos;i<n;i++){
                if(nums[i]>nums[pos-1] && nums[i]<mn){
                    mn=nums[i],poss=i;
                }
            }
            swap(nums[pos-1],nums[poss]);
            sort(nums.begin()+pos,nums.end());
        }
    }
};
