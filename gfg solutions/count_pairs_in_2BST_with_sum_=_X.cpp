/*Structure of the Node of the BST is as
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution
{
public:
    
    void store(Node *root, unordered_set<int>&s)
    {
        if(root)
        {
            store(root->left,s);
            s.insert(root->data);
            store(root->right,s);
        }
    }


    int countPairs(Node* root1, Node* root2, int x)
    {
        unordered_set<int> s1,s2;
        
        store(root1,s1);
        store(root2,s2);
        
        int count = 0;
        
        for(auto i: s1)
        {
            if(s2.find(x-i) != s2.end())
            {
                count++;
            }
        }
        return count;
        
    }
};
