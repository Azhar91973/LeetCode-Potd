class Solution {
public:

    /*
        Idea is to remove all the leaf node's why?
        Bcz those node which have higher indegree having min height so eliminating the all smaller indegree nodes 
                
    */

    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        vector<int> indegree(n,0);
        // Making adj list and storing the indegree of each node
        for(int i=0;i<edges.size();i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
            indegree[edges[i][0]]++;
            indegree[edges[i][1]]++;
        }

        queue<int> q;
        // inset all the leaf nodes
        for(int i=0;i<n;i++)
        {
            if(indegree[i] == 1)
            {
                 q.push(i);
                 indegree[i]--;
            }
        }
        vector<int> ans;
        // bfs
        while(!q.empty())
        {
            int len = q.size();
                ans.clear();
            for(int i=0;i<len;i++)
            {
                int node = q.front();
                q.pop();
                ans.push_back(node);
                for(auto nbr:adj[node])
                {
                    indegree[nbr]--;
                    if(indegree[nbr] ==1)
                        q.push(nbr);
                }

            }
        }

        if(n==1)  ans.push_back(0);

        return ans;

    }
};