/*Linked list Node structure

struct Node
{
	int data;
	Node* next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
	
};
*/ 

class Solution {
    struct node {
        Node *curr;    //Current node
        int idx;    //List index number
        node(Node *a,int b)
        {
            curr = a;
            idx = b;
        }
    };
    struct compare {
    bool operator()(node a, node b)
    {
        return a.curr->data >b.curr->data;
    }
};
public:
    Node* mergeKLists(Node *lists[],int k) {
        //int k = lists.size();
        if(k==0)
            return NULL;
        Node *head,*tail;
        head=tail=NULL;
        priority_queue<node,vector<node>,compare> heap;
        vector<Node*> ptr(k);   //Current node ptrs for all the lists
        //Assign all the current ptrs and BUILD_HEAP
        for(int i=0;i<k;++i)
        {
            ptr[i]=lists[i];
            if(ptr[i]!=NULL)
                heap.push(node(ptr[i],i));
        }
        
        if(heap.empty())
            return NULL;
        //Insert 1st node
        head=tail=heap.top().curr;
        int idx = heap.top().idx;
        heap.pop();
        ptr[idx]=ptr[idx]->next;
        if(ptr[idx])    //Push newly pointed node if not NULL
            heap.push(node(ptr[idx],idx));
        
        //Make list with rest of the nodes
        while(!heap.empty())
        {
            Node *temp=heap.top().curr; //Pop root node
            idx=heap.top().idx;
            heap.pop();
            
            tail->next=temp;    //Add newnode to list
            tail=tail->next;
            ptr[idx]=ptr[idx]->next;    //Update current pointer
            if(ptr[idx])   //Push newly pointed node if not NULL
                heap.push(node(ptr[idx],idx));
        }
        return head;
    }
};
