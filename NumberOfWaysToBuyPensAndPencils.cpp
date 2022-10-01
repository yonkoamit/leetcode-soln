class Solution {
public:
    long long waysToBuyPensPencils(int total, int cost1, int cost2) {

        long long ans=0;
        int x=(total)/cost1;
        for(int i=0;i<=x;i++)
        {
            int c=total-(cost1*i);
            int c1=(c/cost2);
            ans+=(c1+1);
        }
        return ans;
        
    }
};
