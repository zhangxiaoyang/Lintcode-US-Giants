描述
序列化和反序列化一棵二叉树。


思路
使用先序遍历来序列和反序列化。


代码一
/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     * This method will be invoked first, you should design your own algorithm 
     * to serialize a binary tree which denote by a root node to a string which
     * can be easily deserialized by your own "deserialize" method later.
     */
    string serialize(TreeNode *root) {
        static string result;
            
        if (root == NULL) {
            result += "#,";
            return result;
        }
        
        stringstream tmp;
        tmp << root->val;
        result += tmp.str();
        result += ',';
        serialize(root->left);
        serialize(root->right);
        
        return result;
    }

    /**
     * This method will be invoked second, the argument data is what exactly
     * you serialized at method "serialize", that means the data is not given by
     * system, it's given by your own serialize method. So the format of data is
     * designed by yourself, and deserialize it here as you serialize it in 
     * "serialize" method.
     */
    TreeNode *deserialize(string data) {
        vector<string> strs = split(data, ',');
        return _deserialize(strs);
    }
    TreeNode* _deserialize(vector<string>& strs) {
        static int index = 0;
        if (index >= strs.size() || strs[index] == "#") {
            index++;
            return NULL;
        }
            
        TreeNode* root = new TreeNode(atoi(strs[index++].c_str()));
        root->left = _deserialize(strs);
        root->right = _deserialize(strs);
        return root;
    }
    vector<string> split(string s, char splitter) {
        const char* base = s.c_str();
        const char *p = base;
        const char *q = base;
        vector<string> v;

        while (*p != '\0') {
            if (p == q) {
                while (*q != splitter && *q != '\0')
                    q++;
            }
            v.push_back(s.substr(p - base, q - p));
            q++;
            p = q;
        }
        return v;
    }
};


代码二
/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     * This method will be invoked first, you should design your own algorithm 
     * to serialize a binary tree which denote by a root node to a string which
     * can be easily deserialized by your own "deserialize" method later.
     */
    string serialize(TreeNode *root) {
        static string result;
            
        if (root == NULL) {
            result += "#,";
            return result;
        }
        
        stringstream tmp;
        tmp << root->val;
        result += tmp.str();
        result += ',';
        serialize(root->left);
        serialize(root->right);
        
        return result;
    }

    /**
     * This method will be invoked second, the argument data is what exactly
     * you serialized at method "serialize", that means the data is not given by
     * system, it's given by your own serialize method. So the format of data is
     * designed by yourself, and deserialize it here as you serialize it in 
     * "serialize" method.
     */
    TreeNode *deserialize(string data) {
        vector<string> strs = split(data, ',');
        return _deserialize(strs);
    }
    TreeNode* _deserialize(vector<string>& strs) {
        static int index = 0;
        if (index >= strs.size() || strs[index] == "#")
            return NULL;
            
        TreeNode* root = new TreeNode(atoi(strs[index].c_str()));
        index++;
        root->left = _deserialize(strs);
        index++;
        root->right = _deserialize(strs);
        return root;
    }
    vector<string> split(string s, char splitter) {
        const char* base = s.c_str();
        const char *p = base;
        const char *q = base;
        vector<string> v;

        while (*p != '\0') {
            if (p == q) {
                while (*q != splitter && *q != '\0')
                    q++;
            }
            v.push_back(s.substr(p - base, q - p));
            q++;
            p = q;
        }
        return v;
    }
};

