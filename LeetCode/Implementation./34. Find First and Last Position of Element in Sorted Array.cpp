class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.size()==0) return {-1,-1};
        sort(nums.begin(),nums.end());
        auto it= lower_bound(nums.begin(),nums.end(),target);
        if( it== nums.end() || *it != target) return {-1,-1};
        auto itt= upper_bound(nums.begin(),nums.end(),target);
        int p1= (it-nums.begin()), p2= (itt-nums.begin());
        return {p1,p2-1};
    }
};
