    #include<bits/stdc++.h>
	#define pi pair<int,int>
    using namespace std;
   

    void solve()
    {       
        int n,m;
        cin>>n>>m;
        vector<pi> adj[n+1];
        for(int i=0;i<m;i++)
        {
            int x,y,w;
            cin>>x>>y>>w;
            adj[x].push_back({w,y});
            adj[y].push_back({w,x});

        }

        priority_queue<pi,vector<pi>,greater<pi>> pq;

        vector<bool> vis(n+1,0);
        vector<int> par(n+1);
        vector<int> key(n+1);
        par[1]=0;
        key[1]=0;
        pq.push({0,1});
        for(int i=2;i<=n;i++) {par[i]=-1;key[i]=INT_MAX;}

        long long minCost=0;
        while(!pq.empty())
        {
        	pi p=pq.top();
        	pq.pop();

        	int weight=p.first;
        	int node=p.second;
        	// cout<<weight<<" "<<node<<"s\n";

        	if(vis[node]) continue;

        	vis[node]=1;
        	
        	for(auto y: adj[node])
        	{   
        		if(vis[y.second]) continue;
        		if(y.first< key[y.second])
        		{   key[y.second]=y.first;
        			pq.push(y);
        			// cout<<y.second<<" ";
        			par[y.second]=node;
        		}
        	}
        }
        for(int i=1;i<=n;i++)
        	cout<<par[i]<<" "<<i<<"\n";

        






    }
    int main()
    {   ios_base::sync_with_stdio(false);
        cin.tie(0);cout.tie(0);
        int t=1;
        while(t--)
            solve();

    }            
