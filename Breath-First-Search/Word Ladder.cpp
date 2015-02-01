/*
Given two words (start and end), and a dictionary, find the length of shortest transformation sequence from start to end, such that:
Only one letter can be changed at a time
Each intermediate word must exist in the dictionary
For example,

Given:
start = "hit"
end = "cog"
dict = ["hot","dot","dog","lot","log"]
As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
return its length 5.

Note:
Return 0 if there is no such transformation sequence.
All words have the same length.
All words contain only lowercase alphabetic characters.
*/

/*
广搜
可能会超时，所以要遍历当前front只改变一位的值
*/


struct Node {
    string word;
    int level;
    Node (string word, int level) : word(word), level(level){}
};

class Solution {
public:
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        if (start.empty() || end.empty() || dict.empty()) {
            return 0;
        }

        int res; 
        bool flag = false;
        queue<Node*> que;
        unordered_set<string> visit;
        Node *startNode = new Node(start, 1);
    
        visit.insert(start);
        que.push(startNode);
        while (!que.empty()) {
            Node *front = que.front();
            que.pop();
            
            for (int i = 0; i < start.length(); i++) {
                for (char j = 'a'; j <= 'z'; j++) { //O(26 ^ length)
                    string posibleWord = front->word;
                    posibleWord[i] = j;
                    
                    if (posibleWord == end) {
                        res = front->level + 1;
                        flag = true; break;
                    }
                    
                    if (visit.find(posibleWord) == visit.end() && dict.find(posibleWord) != dict.end()) {
                        visit.insert(posibleWord);
                        Node *find = new Node(posibleWord, front->level + 1);
                        que.push(find);
                    }
                }
            }
            if (flag) {
                return res;   
            }
        }
        return 0;
    }

    
};
