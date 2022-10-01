class Solution {
public:
    int surfaceArea(vector<vector<int>>& grid) {
        int n=grid.size();
        int ans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                int sum=0;
                sum+=2*(max(grid[i][j]-1,0));
                ans+=6*(grid[i][j]);
                if(i-1>=0) sum+=min(grid[i][j],grid[i-1][j]);
                if(i+1<n) sum+=min(grid[i][j],grid[i+1][j]);
                if(j-1>=0) sum+=min(grid[i][j],grid[i][j-1]);
                if(j+1<n) sum+=min(grid[i][j],grid[i][j+1]);
                ans-=sum;
            }
        }
        return ans;
    }
};
