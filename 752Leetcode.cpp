 class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        
        /*
        # Observation
        1) A state( Initial State"0000") Contains 4 char. And We Can either add 1 to a char or subtract 1 to a char
        2) Check all the possible states ( "1000", "0100", "0010", "0001" ..... upto "9999")
        3) In one Step we have to move only one lock or Add/Subtract to the state
        
        */


        // Creating the set and inserting all the deadends for removing the similar deadends
        unordered_set<string> dead(deadends.begin(),deadends.end());

        // taking a queue to do dfs
        queue<pair<string,int>> q;
        // taking a set to track the visited state
        unordered_set<string> visited;

        // if starting state is not found in the dead end then proceed
        if(dead.find("0000") == dead.end())
        {
            // insert the starting state
            q.push({"0000",0});
            // mark the state as visited
            visited.insert("0000");
        }
        // do bfs
        while(!q.empty())
        {
            pair<string,int> current = q.front();
            q.pop();

            string s = current.first;
            int steps = current.second;
            // if target found then return the steps
            if(s == target)
                return steps;
            // find all the possibility
            for(int i=0;i<4;i++)
            {
                // adding 1 at ith index of the state 
                string temp1 = s.substr(0,i)+to_string((s[i] - '0' +1)%10) + s.substr(i+1);
                // substracting 1 at ith index of the state
                string temp2 = s.substr(0,i)+to_string((s[i]-'0' - 1 + 10)%10) + s.substr(i+1);
                // Now check if the temp1 state is not traversed yet and not visited yet 
                if(dead.find(temp1) == dead.end() && visited.find(temp1) == visited.end())
                {
                    // then traverse temp1 state and mark the state as visited
                    q.push({temp1,steps+1});
                    visited.insert(temp1);
                }
                //  Now check if the temp2 state is not traversed yet and not visited yet 
                if(dead.find(temp2) == dead.end() && visited.find(temp2) == visited.end())
                {
                    // then traverse temp2 state and mark the state as visited
                    q.push({temp2,steps+1});
                    visited.insert(temp2);
                }
            }
         
        }
        // if till here the result is not found then return 
           return -1;
    }
};