描述
从字符表中寻找给定的词表中的词，只能向左、向右、向上、向下查找。例如，
[doaf,
agai,
dcan]，给定{"dog", "dad", "dgdg", "can", "again"}，则返回{"dog", "dad", "can", "again"}。


思路
使用Trie，即前缀树，对于英文字母来说，每一个结点有26个孩子，分别表示字符a~z。使用dfs进行查找，当当前字符串在Trie中，才进一步判断是否存在该字符，否则直接返回。需要使用visited[.]数组来记录某个单元格是否被访问，比如，对某个单元格dfs时，先要将该单元格的visited置为true，这样防止后面的dfs又搜索到当前单元格。最后把visited还原成false。


代码
class TrieNode {
public:
    bool isWord;
    vector<TrieNode*> children;
    TrieNode():isWord(false), children(26, NULL) {}
};
class Trie {
public:
    TrieNode root;
    Trie(vector<string>& words) {
        for (int i = 0; i < words.size(); i++)
            add(words[i]);
    }
    
    void add(string word) {
        TrieNode* node = &root;
        for (int i = 0; i < word.size(); i++) {
            if (node->children[word[i] - 'a'] == NULL)
                node->children[word[i] - 'a'] = new TrieNode();
            node = node->children[word[i] - 'a'];
        }
        node->isWord = true;
    }
    
    bool containsWord(string& word) {
        TrieNode* node = &root;
        for (int i = 0; i < word.size(); i++) {
            if (node->children[word[i] - 'a'] == NULL)
                return false;
            node = node->children[word[i] - 'a'];
        }
        if (node->isWord)
            return true;
        return false;
    }
    
    bool startsWith(string& word) {
        TrieNode* node = &root;
        for (int i = 0; i < word.size(); i++) {
            if (node->children[word[i] - 'a'] == NULL)
                return false;
            node = node->children[word[i] - 'a'];
        }
        return true;
    }
};

class Solution {
public:
    /**
     * @param board: A list of lists of character
     * @param words: A list of string
     * @return: A list of string
     */
    vector<string> wordSearchII(vector<vector<char> > &board, vector<string> &words) {
        Trie trie(words);
        set<string> result;
        vector<vector<bool> > visited(board.size(), vector<bool>(board[0].size(), false));
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                dfs(board, i, j, visited, trie, "", result);
            }
        }
        return vector<string>(result.begin(), result.end());
    }
    
    void dfs(vector<vector<char> >& board, int x, int y, vector<vector<bool> >& visited, Trie& trie, string word, set<string>& result) {
        if (x < 0 || y < 0 || x >= board.size() || y >= board[0].size())
            return;
        if (visited[x][y])
            return;
            
        word += board[x][y];
        if (!trie.startsWith(word))
            return;
            
        if (trie.containsWord(word))
            result.insert(word);

        visited[x][y] = true;
        dfs(board, x, y + 1, visited, trie, word, result);
        dfs(board, x, y - 1, visited, trie, word, result);
        dfs(board, x + 1, y, visited, trie, word, result);
        dfs(board, x - 1, y, visited, trie, word, result);
        visited[x][y] = false;
    }
};

