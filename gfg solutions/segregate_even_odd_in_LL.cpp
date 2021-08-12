
/*
struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution{
public:
    Node* divide(int N, Node *head){
        // code here
        
        vector<int> odd,even;
        Node *t = head;
        while(t)
        {
            if(t->data %2 == 0)
            {
                even.push_back(t->data);
                t = t->next;
            }
            else
            {
                odd.push_back(t->data);
                t = t->next;
            }
        }
        t = head;
        int i = 0, j= 0;
        while(i < even.size())
        {
            t->data = even[i++];
            t = t->next;
        }
        while(j < odd.size())
        {
            t->data = odd[j++];
            t = t->next;
        }
        return head;
        
        
        
    }
};
