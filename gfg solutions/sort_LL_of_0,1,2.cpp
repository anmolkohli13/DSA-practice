#include <bits/stdc++.h>

using namespace std;
/* Link list Node */
struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node *start = NULL;


 // } Driver Code Ends
/*
 
  Node is defined as
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
    //Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node *head) {
        
        // Add code here
        
        // if(head == NULL || head->next == NULL)
        // return head;
        
        // Node *curr = head;
        // int c0=0,c1=0,c2=0;
        
        // while(curr){
        //     if(curr->data == 0) c0++;
        //     else if(curr->data == 1) c1++;
        //     else c2++;
        //     curr = curr->next;
        // }
        
        // curr = head;
        
        // while(c0-- && curr)
        // {
        //     curr->data = 0;
        //     curr = curr->next;
        // }
        // while(c1-- && curr)
        // {
        //     curr->data = 1;
        //     curr = curr->next;
        // }
        // while(c2-- && curr)
        // {
        //     curr->data = 2;
        //     curr = curr->next;
        // }
        // return head;
        
        if(!head || !head->next) return head;
        
        struct Node *cur=head,*end=head,*front=head,*pre=NULL;
        int count=0,i=0;
        
        while(end->next){
            end=end->next;
            count++;
            
        }
        
        while(i<=count)
        {
            if(!cur) break;
            if(cur->data==1){
                pre=cur;
                cur=cur->next;
                
            }
            
            else if(cur->data==2)
            {
            //struct Node *temp=cur->next;
            end->next=cur;
            if(!pre)//first node
            {
                front=front->next;
                cur->next=NULL;
                end=cur;
                cur=front;
            
            }else{
            //if(pre->next)
                pre->next=pre->next->next;
                cur->next=NULL;
                end=cur;
                cur=pre->next;
        }
        
        }
        else if(cur->data==0)
        {
            if(!pre)
            {
                pre=cur;
                cur=cur->next;
            }
        else{
        //struct Node *temp=cur->next;
        //if(pre->next)
            pre->next=pre->next->next;
            cur->next=front;
            front=cur;
            cur=pre->next;
        }
        }
        i++;
        }
        
        return front;
        
        
    }
};


// { Driver Code Starts.

// Function to sort a linked list of 0s, 1s and 2s
void printList(struct Node *Node) {
    while (Node != NULL) {
        printf("%d ", Node->data);
        Node = Node->next;
    }
    printf("\n");
}

/* Drier program to test above function*/
void insert(int n1) {
    int n, value, i;
    // scanf("%d",&n);
    n = n1;
    struct Node *temp;
    for (i = 0; i < n; i++) {
        scanf("%d", &value);

        if (i == 0) {
            start = new Node(value);
            temp = start;
            continue;
        } else {
            temp->next = new Node(value);
            temp = temp->next;
            temp->next = NULL;
        }
    }
}

int main() {

    int n;

    int t;
    scanf("%d", &t);

    while (t--) {
        scanf("%d", &n);

        insert(n);
        Solution ob;
        struct Node *newHead = ob.segregate(start);
        printList(newHead);
    }

    return 0;
}  // } Driver Code Ends
