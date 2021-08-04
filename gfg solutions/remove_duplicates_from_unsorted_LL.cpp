/*The structure of linked list is the following

struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/


class Solution
{
    public:
    //Function to remove duplicates from unsorted linked list.
    Node * removeDuplicates( Node *head) 
    {
     // your code goes here
     
     unordered_set<int>st;
     
     Node *cur = head, *prev = NULL;
     
     while(cur != NULL)
     {
         if(st.find(cur->data) == st.end())
         {
             st.insert(cur->data);
             prev = cur;
             cur = cur->next;
             //nex = nex->next;
         }
         else
         {
             prev->next = cur->next;
             //delete nex;
             delete cur;
             cur = prev->next;
         }
     }
     
     return head;
    }
};
