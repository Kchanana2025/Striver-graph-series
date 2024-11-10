

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// we can do this problem using topological sort.Now how to implement topological sort in this question?
// we can say that if one string comes before second string.then it must be a reason for it eg
// if baa comes before abcd then in dictionary b will come before a
// so in order to calculate the order of letters we can create node b and a and make a directed edge from
// b to a and when we will write topological sort of that graph we will get the order of letters in that alien dictionary.

// also in case k=5 and letters only involve a,b,c,d toh e ko alag component ki trah treat krlograph mein
// aur uss node ki value ko hm topological sort mein aage daal skte hain aur peeche bhi daal skte hain
// Both string.length() and string.size() give same value

// O(N)+O(V+2E)+O(V)
// O(N)+O(V+E)+O(N)+O(N)+O(N)
// O(N)+O(V+E)+O(N)+O(N)+O(N)+O(k)

class Solution
{
    vector<int> topologicalSort(vector<vector<int>> &adj)
    {
        // Your code here
        int V = adj.size();
        queue<int> q;
        vector<int> ans;
        vector<int> indegree(V, 0);
        for (int i = 0; i < V; i++)
        {
            for (auto it : adj[i])
                indegree[it]++;
        }

        for (int i = 0; i < indegree.size(); i++)
        {
            if (indegree[i] == 0)
            { // nodes whoes indegree is zero must be pushed into the queue
                q.push(i);
            }
        }

        int count = 0;
        while (!q.empty())
        {
            auto it = q.front();
            q.pop();
            ans.push_back(it);
            count++;
            for (auto x : adj[it])
            {
                indegree[x]--;
                if (indegree[x] == 0)
                {
                    q.push(x);
                }
            }
        }

        // If count is less than V, there's a cycle
        if (count != V)
            return {}; // Return empty vector to indicate a cycle
        return ans;
    }

public:
    string findOrder(string dict[], int n, int k)
    {
        vector<vector<int>> adj(k); // no of letters in dictionary equals the no of nodes in graph

        for (int i = 0; i < n - 1; i++)
        {
            string s1 = dict[i];
            string s2 = dict[i + 1];
            int len = min(s1.length(), s2.length());

            // Check for Case 1
            if (s1.length() > s2.length() && s1.substr(0, len) == s2)
            {
                return ""; // Impossible to determine order
            }
            for (auto j = 0; j < len; j++)
            {
                if (s1[j] != s2[j])
                {
                    adj[(s1[j] - 'a')].push_back(s2[j] - 'a'); // we did -'a' so that value is stored in terms of 0 and 1
                    break;
                }
            }
        }
        // graph is prepared till here
        // now lets do topological sorting

        vector<int> vec = topologicalSort(adj);

        // Check for Case 2 (cycle detection)
        if (vec.empty())
            return ""; // Impossible to determine order due to cycle

        string ans = "";
        for (auto it : vec)
        {
            ans = ans + char(it + 'a');
        }
        return ans;
    }

    // cross question what if the ordering or letters is not possible?
    //  2 cases mein ordering of letters is not possible:if larger string appears before shorter and it is a cyclic dependency
    //  i.e a<b<a
    //  Test case 1:
    //  s1:abcd
    //  s2:abc
    //  till minimum length of both string,strings are matching so shorter string
    // should have been before larger string but this is not the case thereforce dictionary
    //  is wrong and ordering is not possible

    // Test case 2:
    //  s1:abc
    //  s2:bat
    //  s3:ade
    //  from s1,s2->a<b
    //  from s2,s3->b<a
    // thereforce dictionary is wrong and ordering is not possible
};
// we convert letters to numbers to simplify the process of constructing a graph

// Characters in the alphabet ('a' to 'z') are not directly usable as array indices. By converting letters to integers
//  (e.g., 'a' to 0, 'b' to 1, ..., 'z' to 25), we can easily work with arrays to store adjacency lists, indegree counts,
//  and other data structures typically used in graph algorithms.