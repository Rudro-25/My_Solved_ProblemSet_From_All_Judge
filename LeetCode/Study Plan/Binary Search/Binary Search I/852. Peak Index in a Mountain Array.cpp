class Solution {
public:
    #define ll long long
    int peakIndexInMountainArray(vector<int>& arr) {
        ll l=1,r=arr.size()-2,ans=-1;
        while(l<=r){
            ll mid=(l+r)/2;
            if(arr[mid]>arr[mid-1] && arr[mid]>arr[mid+1]){
                ans= mid; break;
            }
            else if(arr[mid]>arr[mid+1]) r=mid-1;
            else l=mid+1;
        }
        
        return ans;
    }
};
