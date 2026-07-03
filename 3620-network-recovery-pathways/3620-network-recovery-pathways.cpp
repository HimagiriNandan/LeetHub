class Solution {
public:
    bool check(int limit,
               vector<vector<pair<int,int>>>& graph,
               vector<bool>& online,
               long long k)
    {
        int n = graph.size();

        vector<int> indegree(n);

        for(int u=0;u<n;u++)
        {
            for(auto &[v,c]:graph[u])
            {
                if(c>=limit &&
                   (v==n-1 || online[v]))
                    indegree[v]++;
            }
        }

        queue<int> q;

        for(int i=0;i<n;i++)
            if(indegree[i]==0)
                q.push(i);

        vector<long long> dist(n, LLONG_MAX);

        dist[0]=0;

        while(!q.empty())
        {
            int u=q.front();
            q.pop();

            for(auto &[v,c]:graph[u])
            {
                if(c<limit)
                    continue;

                if(v!=n-1 && !online[v])
                    continue;

                if(dist[u]!=LLONG_MAX)
                    dist[v]=min(dist[v],dist[u]+c);

                indegree[v]--;

                if(indegree[v]==0)
                    q.push(v);
            }
        }

        return dist[n-1]<=k;
    }

    int findMaxPathScore(vector<vector<int>>& edges,
                         vector<bool>& online,
                         long long k)
    {
        int n=online.size();

        vector<vector<pair<int,int>>> graph(n);

        int mx=0;

        for(auto &e:edges)
        {
            graph[e[0]].push_back({e[1],e[2]});
            mx=max(mx,e[2]);
        }

        int lo=0;
        int hi=mx;
        int ans=-1;

        while(lo<=hi)
        {
            int mid=(lo+hi)/2;

            if(check(mid,graph,online,k))
            {
                ans=mid;
                lo=mid+1;
            }
            else
                hi=mid-1;
        }

        return ans;
    }
};