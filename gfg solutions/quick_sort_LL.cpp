/* a node of the singly linked list 
struct node
{
    int data;
    struct node *next;
    
    node(int x){
        data = x;
        next = NULL;
    }
}; */

//you have to complete this function
struct node * partition(struct node *head, struct node *tail){
node * prev=head, *cur=head->next;
node *pivot = head;
while(cur != tail->next){
if(cur->data < pivot->data){
swap(prev->next->data,cur->data);
prev = prev->next;
}
cur = cur->next;
}
swap(pivot->data,prev->data);
return prev;
}

void quickSortRec(struct node * head, struct node *tail){
if(head == tail || tail == NULL || head == NULL )
return;
// To find the pivot element
struct node *pivot = partition(head , tail);

// Recursive calls to quickSortRec procedure
quickSortRec(head, pivot);
quickSortRec(pivot->next, tail);
}

void quickSort(struct node **headRef) {
node *tail = *headRef;
//To find the tail
while(tail->next != NULL)
tail = tail->next;
quickSortRec(*headRef, tail);
}
