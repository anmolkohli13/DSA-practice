/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};*/

//Function to remove duplicates from sorted linked list.
Node *removeDuplicates(Node *head)
{
 // your code goes here
 
 Node *cur = head;
 Node *nex = cur->next;
 
 while(nex != NULL)
 {
     if(cur->data != nex->data)
     {
         cur = nex;
         nex = nex->next;
         
     }
     else
     {
         cur->next = nex->next;
         delete nex;
         nex = cur->next;
     }
     
 }

 return head;
}
