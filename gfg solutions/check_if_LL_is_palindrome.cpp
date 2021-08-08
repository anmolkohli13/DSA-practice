struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

class Solution{
  public:
    //Function to check whether the list is palindrome.
    
    Node *reverse(Node *head)
    {
        Node *prev = NULL;
        Node *curr = head;
        while(curr != NULL){
            Node *next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    
    bool isPalindrome(Node *head)
    {
        //Your code here
        
         Node* slow=head;
          Node*  fast=head;
        while(fast!=NULL && fast->next!=NULL)
        {
          slow=slow->next;
            fast=fast->next->next;
        } 
        fast=head;
        slow=reverse(slow);
        // return checkit(str);
        while(slow!=NULL)
        {
            if(fast->data!=slow->data)
            {
                return false;
            }  
            slow=slow->next;
            fast=fast->next;
        } 
        return true;
    }
    
//     bool checkit(string str)
//     {
//         int n=str.length();
//         for(int i=0;i<n;i++)
//         {
//             if(str[i]!=str[n-i-1])
//             {
//                 return false;
//             }   
//         }  
//         return true;
//     }


//  bool isPalindrome(Node* head) {
//         string str="";
//         Node* t=head;
//         while(t!=NULL)
//         {
//             str.push_back(t->data);
//             t=t->next;
//         }   
//         return checkit(str);
// }
    
    
};

