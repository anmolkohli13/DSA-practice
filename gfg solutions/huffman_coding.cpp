struct Node
{
int data;
Node *left;
Node *right;

Node(int x)
{
data = x;
left = right = NULL;
}
};

// To compare two points
struct compare {

bool operator()(Node* l, Node* r)

{
return (l->data > r->data);
}
};
class Solution{
public:
    void preOrder(vector<string> &res, Node *root, string s)
{
if (!root)
return;

if ( !root->left && !root->right)
res.push_back(s);
preOrder(res, root->left , s + "0");
preOrder(res, root->right , s + "1");
}

vector<string> huffmanCodes(string S, vector<int> f, int N)
{
priority_queue<Node*, vector<Node*>, compare> pq;

for (int i = 0; i < f.size(); i++)
{
Node *temp = new Node(f[i]);
pq.push(temp);
}

vector<string> res;
for (int i = 1; i < N; i++)
{
Node *x = pq.top();
// cout << x << endl;
pq.pop();
Node *y = pq.top();
// cout << y << endl;
pq.pop();

Node *temp = new Node(x->data + y->data);
temp->left = x;
temp->right = y;
pq.push(temp);
}

preOrder(res, pq.top() , "");
return res;
}
};
