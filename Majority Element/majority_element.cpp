class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int>m;
        int n = nums.size();
        for(auto i: nums)
        {
            m[i]++;
        }
        for(auto j: m)
        {
            if(j.second > n/2)
                return j.first;
        }
        return 0;
        
    }
};