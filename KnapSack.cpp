//https://practice.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1/

int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
       vector < int > ans (W+1);
       for(int i=0;i<n;i++){
           for(int j=W;j>0;j--){
               if(wt[i]<=j){
                   ans[j]=max(ans[j],val[i]+ans[j-wt[i]]);
               }
           }
       }
       return ans[W];
    }
