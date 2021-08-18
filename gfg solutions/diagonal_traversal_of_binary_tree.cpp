/* A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; */



vector<int> diagonal(Node *root)
{
   // your code here
   
   queue<Node*>Q;
   Node * p = root;
   vector<int>vec;
   
   Q.push(p);
   
   while(!Q.empty())
   {
       p = Q.front();
       Q.pop();
       while(p)
       {
           if(p->left)
           Q.push(p->left);
           
           vec.push_back(p->data);
           
           p = p->right;
           
       }
   }
   return vec;
   
