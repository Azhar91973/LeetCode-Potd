class Solution {
    private:
    int solve(int i,int prev,int &n,int &k,string &s,vector<vector<int>> &dp)
    {
        if(i>=n)
            return 0;

        if(dp[i][prev+1] != -1)
            return dp[i][prev+1];


        int include=0; 
        // if the abs diff is < k then include the char
        if(prev == -1 || abs((s[prev] - '0') - (s[i] - '0')) <= k)
        {
            include = 1+solve(i+1,i,n,k,s,dp);
        }

        int exclude = solve(i+1,prev,n,k,s,dp);
        
        // return the maximum possible ans
        return dp[i][prev+1] = max(include,exclude); 
    }
   
public:
    int longestIdealString(string s, int k) {

        int n = s.length();
        vector<vector<int>> dp(n,vector<int> (n,-1));
        return solve(0,-1,n,k,s,dp); 
    }
};