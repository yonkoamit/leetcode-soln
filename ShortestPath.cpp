class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int v, vector<vector<int>> adj[], int S)
    {
        vector < int > dist(v,INT_MAX);
        dist[S]=0;
        priority_queue < pair < int , int > , vector < pair < int , int > >, greater < pair < int , int > > > Q;
        Q.push({dist[0],S});
        while(!Q.empty()){
            pair<int , int > nodeTop = Q.top();
            int node = nodeTop.second;
            Q.pop();
            for(auto nodes:adj[node]){
                int curNode = nodes[0];
                int weightFromNode = nodes[1];
                if(dist[curNode]>weightFromNode+dist[node]){
                    dist[curNode]=weightFromNode+dist[node];
                    Q.push({dist[curNode],curNode});
                }
            }
        }
        return dist;
    }
};
