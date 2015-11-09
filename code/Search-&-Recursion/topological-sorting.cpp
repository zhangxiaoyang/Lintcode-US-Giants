描述
给定一个有向图，输出topological sorting序列，也就是说按照箭头的方向输出，如果没法区分前后次序，则随意输出次序。比如a->b->c, a->d->c，可以输出a, b, d, c或a, d, b, c。


思路
需要先找到起点，一个图中可能有多个起点，比如a->b->c，d->c，这里a和d都可以作为起点。做到这点的方法是，一次遍历图中的每个结点，记录下每个结点对应neighbors结点的次数visited[node]，即有几个箭头指向这个结点，也就是说还可以访问node结点visited[node]次。然后在对每一个起点进行dfs。


代码
/**
 * Definition for Directed graph.
 * struct DirectedGraphNode {
 *     int label;
 *     vector<DirectedGraphNode *> neighbors;
 *     DirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    /**
     * @param graph: A list of Directed graph node
     * @return: Any topological order for the given graph.
     */
    vector<DirectedGraphNode*> topSort(vector<DirectedGraphNode*> graph) {
        map<DirectedGraphNode*, int> visited;
        for (int i = 0; i < graph.size(); i++) {
            for (int j = 0; j < graph[i]->neighbors.size(); j++) {
                if (visited.find(graph[i]->neighbors[j]) == visited.end())
                    visited[graph[i]->neighbors[j]] = 1;
                else
                    visited[graph[i]->neighbors[j]] += 1;
            }
        }        
        
        vector<DirectedGraphNode*> result;
        for (int i = 0; i < graph.size(); i++) {
            if (visited.find(graph[i]) == visited.end()) {
                visited[graph[i]] = 0;
                dfs(graph, graph[i], visited, result);        
            }
        }
        return result;
    }
    
    void dfs(vector<DirectedGraphNode*>& graph, DirectedGraphNode* node, map<DirectedGraphNode*, int>& visited, vector<DirectedGraphNode*>& result) {
        visited[node]--;
        
        result.push_back(node);
        for (int i = 0; i < node->neighbors.size(); i++) {
            visited[node->neighbors[i]]--;
            if (visited[node->neighbors[i]] == 0)
                dfs(graph, node->neighbors[i], visited, result);
        }
    }
};

