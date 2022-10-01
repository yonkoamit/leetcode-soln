class Solution {
public:
    int findClosestNumber(vector<int>& nums) {
        int ans=nums[0];
        int res=abs(nums[0]);
        for(auto &x:nums)
        {
            if(abs(x)<res)
            {
                res=abs(x);
                cout<<x<<" ";
                ans=min(ans,x);
            }
            if(abs(x)==res) ans=max(ans,x);
        }
        return ans;
        
    }
};
