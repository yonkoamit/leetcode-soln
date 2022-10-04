    #include<bits/stdc++.h>
    using namespace std;
    vector<int> sz(10001);
    vector<int> par(10001);


    bool comp(const pair<pair<int,int>,int> &p1,const pair<pair<int,int>,int> &p2)
    {
        return p1.second<p2.second;
    }

    void Union (int node1,int node2)
    {
        int s1=sz[node1],s2=sz[node2];
        if(s1==s2)
        {
            sz[node1]+=1;
            par[node2]=node1;
        }
        if(s1<s2) swap(s1,s2);
        par[node2]=node1;


    }

    int find(int node1)
    {
        if(node1==par[node1]) return node1;
        return par[node1]=find(par[node1]);
    }

    void solve()
    {       
        int n,m;
        cin>>n>>m;
        vector<pair<pair<int,int>,int>> v;
        for(int i=0;i<m;i++)
        {
            int x,y,w;
            cin>>x>>y>>w;
            v.push_back({{x,y},w});

        }

        sort(v.begin(),v.end(),comp);
        for(int i=1;i<=n;i++) {sz[i]=1;par[i]=i;}
        long long ans=0;
        for(int i=0;i<m;i++)
        {
            int x=v[i].first.first,y=v[i].first.second,weight=v[i].second;
            int p1=find(x),p2=find(y);
            if(p1==p2) continue;
            ans+=weight;
            Union(x,y);
        }

        cout<<ans<<"\n";
        






    }
    int main()
    {   ios_base::sync_with_stdio(false);
        cin.tie(0);cout.tie(0);
        int t=1;
        while(t--)
            solve();

    }        
