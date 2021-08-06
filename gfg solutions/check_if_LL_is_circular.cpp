bool isCircular(Node *head)
{
   // Your code here
   
   Node *tail = head;
   
   while(tail)
   {
       if(tail->next == head)
       return true;
       tail = tail->next;
   }
   return false;
}
