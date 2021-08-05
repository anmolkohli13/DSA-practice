Node *reverse(Node *head){
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
    
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        Node *curr1 = reverse(first);
        Node *curr2 = reverse(second);
        int carry=0,sum;
        
        sum = (curr1->data + curr2->data);
        Node *ansNode = new Node(sum % 10);
        Node *ansHead = ansNode;
        carry = sum / 10;
        curr1 = curr1->next;
        curr2 = curr2->next;
        
        //loops to cover rest of the operations
        while(curr1 != NULL and curr2 != NULL){
            sum = (curr1->data + curr2->data +carry);
            ansNode -> next = new Node(sum % 10);
            ansNode = ansNode -> next;
            carry = sum / 10;
            curr1 = curr1->next;
            curr2 = curr2->next;
        }
        while(curr1 != NULL){
            sum = (curr1->data + carry);
            ansNode -> next = new Node(sum % 10);
            ansNode = ansNode -> next;
            carry = sum / 10;
            curr1 = curr1->next;
        }
        while(curr2 != NULL){
            sum = (curr2->data + carry);
            ansNode -> next = new Node(sum % 10);
            ansNode = ansNode -> next;
            carry = sum / 10;
            curr2 = curr2->next;
        }
        if(carry){
            ansNode ->next = new Node(carry);   
        }
        return reverse(ansHead);
    }
