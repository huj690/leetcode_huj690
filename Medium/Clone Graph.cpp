/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
 
 /*dfs*/
/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
	UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
		if (node == nullptr) {
	        return nullptr;
	    }
		if (visit.count(node->label) > 0) {
			return visit[node->label];
		}
		
		UndirectedGraphNode *newNode = new UndirectedGraphNode(node->label);
		visit[node->label] = newNode;
		
		for (int i = 0; i < node->neighbors.size(); i++) {
			newNode->neighbors.push_back(cloneGraph(node->neighbors[i]));
		}
        
        return newNode;
	}
private:
	unordered_map<int, UndirectedGraphNode*> visit;
};
