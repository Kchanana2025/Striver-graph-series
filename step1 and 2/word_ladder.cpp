// Time Complexity: O(N * M * 26)*O(1)

// Where N = size of wordList Array and M = word length of words present in the wordList..

// Note that, hashing operations in an unordered set takes O(1) time, but if you want to use set here, then the time complexity would increase by a factor of log(N) as hashing operations in a set take O(log(N)) time.

// Aux Space Complexity:  O( 2N ) { for creating an unordered set and copying all values from wordList into it and queue}

// Where N = size of wordList Array.
// Tot space complexity:O(3N)

// Let’s first understand the Brute force approach to this problem. In Brute force, we just
// simply replace the startingWord character by character and then check whether the transformed word is present in the wordList. If a word is present in the wordList, we try replacing another character in that word by again following similar steps as above, in order to attain the targetWord. We do this for all the characters in the startWord and then eventually return the minimum length of transforming the startWord to targetWord.

class Solution
{
public:
    int ladderLength(string beginWord, string endWord, vector<string> &wordList)
    {
        queue<pair<string, int>> pending_nodes; // string followed by  length of transformation sequence
        unordered_set<string> st(wordList.begin(), wordList.end());
        pending_nodes.push({beginWord, 1});
        st.erase(beginWord);

        while (!pending_nodes.empty())
        {
            auto it = pending_nodes.front();
            pending_nodes.pop();
            string word = it.first;
            int level = it.second;

            if (word == endWord)
                return level;

            for (int i = 0; i < word.size(); i++)
            {
                char original_letter = word[i];
                for (char ch = 'a'; ch <= 'z'; ch++)
                {
                    word[i] = ch;
                    if (st.find(word) != st.end())
                    { // element is prest in set(i.e it is unvisited)
                        st.erase(word);
                        pending_nodes.push({word, level + 1});
                    }
                }
                word[i] = original_letter;
            }
        }
        return 0;
    }
};