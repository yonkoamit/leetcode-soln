class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size();
        if(n==0) return 0;
        int k = n - 1;
        int i = 0;
        while(i!=k)
        {
            if(nums[i] == val)
            {
                swap(nums[i],nums[k]);
                k--;
            }
            else
                i++;
        }
        if(nums[k]==val) return k;
        return k+1;
       
    }
};