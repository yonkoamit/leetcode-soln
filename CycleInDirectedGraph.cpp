// - https://leetcode.com/problems/course-schedule/
// - https://practice.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/

class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool hasCycle(int node,vector < bool > &vis , vector < bool > &recSt, vector < int >adj[]){
        recSt[node]=true;
        vis[node]=true;
        for(auto child:adj[node]){
            if(vis[child] and recSt[child]) return true;
            if(!vis[child] and hasCycle(child,vis,recSt,adj)) return true;
        }
        recSt[node]=false;
        return false;
    }
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        vector < bool > vis(V),recSt(V);
        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(hasCycle(i,vis,recSt,adj)) return true;
            }
        }
        return false;
    }
};
