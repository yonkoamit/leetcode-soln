// problem link https://leetcode.com/problems/min-cost-to-connect-all-points/
// idea is to pick a node and push all the non visited child into PQ(min heap {weight,node})

int MST(vector < pair < int , int > > graph[] , int n){
        int cost=0;
        vector < bool > vis(n);
        priority_queue < pair < int , int >,vector <pair < int , int > > , greater < pair < int , int  >  > > pq;
        int node=0,weight =0;
        pq.push({weight,node});
        while(!pq.empty()){
            pair < int , int > top = pq.top();
            pq.pop();
            node = top.second;
            weight = top.first;
            if(vis[node]) continue;
            vis[node]=true;
            cost+=weight;
            for(auto neigh:graph[node]){
                if(!vis[neigh.first]){
                    pq.push({neigh.second,neigh.first});
                }
            }
        }
        return cost;
    }
