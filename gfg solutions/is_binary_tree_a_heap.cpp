// User Function template for C++

// Structure of node
/*struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/

class Solution {
  public:
    bool isHeap(struct Node * root)
    {
        queue<Node*> q;
    q.push(root);
    bool nullish = false;
    while (!q.empty()) 
    {
        Node* temp = q.front();
        q.pop();
        if (temp->left) 
        {
            if (nullish 
                || temp->left->data 
                >= temp->data) 
            {
                return false;
            }
            q.push(temp->left);
        }
        else {
            nullish = true;
        }
        if (temp->right)
        {
            if (nullish
                || temp->right->data
                >= temp->data) 
            {
                return false;
            }
            q.push(temp->right);
        }
        else
        {
            nullish = true;
        }
    }
    return true;
    }
};
