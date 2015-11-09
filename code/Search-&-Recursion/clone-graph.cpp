描述
深拷贝一个无向图。


思路
使用一个map，把所有的结点拷贝出来，key是旧的结点，value的新拷贝出的结点。然后再遍历一遍旧的图，填充neighbors，即把结点连接起来。


代码
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
    /**
     * @param node: A undirected graph node
     * @return: A undirected graph node
     */
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> mapper;
        queue<UndirectedGraphNode*> cache;
        
        if (node == NULL)
            return node;
            
        cache.push(node);
        cloneNode(node, mapper);
        
        while (!cache.empty()) {
            int count = cache.size();
            for (int i = 0; i < count; i++) {
                UndirectedGraphNode* node = cache.front();
                cloneNode(node, mapper);
                cache.pop();
                
                for (int j = 0; j < node->neighbors.size(); j++) {
                    if (mapper.find(node->neighbors[j]) == mapper.end())
                        cache.push(node->neighbors[j]);
                }
            }
        }
        
        for (unordered_map<UndirectedGraphNode*, UndirectedGraphNode*>::iterator i = mapper.begin(); i != mapper.end(); i++) {
            for (int j = 0; j < i->first->neighbors.size(); j++) {
                i->second->neighbors.push_back(mapper[i->first->neighbors[j]]);
            }
        }
        
        return mapper[node];
    }
    
    UndirectedGraphNode* cloneNode(UndirectedGraphNode* node, unordered_map<UndirectedGraphNode*, UndirectedGraphNode*>& mapper) {
        UndirectedGraphNode* clonedNode = NULL;
        if (mapper.find(node) == mapper.end()) {
            clonedNode = new UndirectedGraphNode(node->label);
            mapper[node] = clonedNode;
        }
        else
            clonedNode = mapper[node];
        return clonedNode;
    }
};

