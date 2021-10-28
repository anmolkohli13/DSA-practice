// The functions should be written in a way that array become sorted 
// in increasing order when heapSort() is called.

class Solution
{
    public:
    //Heapify function to maintain heap property.
    void heapify(int arr[], int n, int i)  
    {
      // Your Code Here
      int l=2*i+1;
        int r=2*i+2;
        int s=i;
        if(l<n && arr[l]>arr[s])
           s=l;
        if(r<n && arr[r]>arr[s])
           s=r;
        if(s!=i) {
            int temp=arr[i];
            arr[i]=arr[s];
            arr[s]=temp;
            heapify(arr,n,s);
        }
    }

    public:
    //Function to build a Heap from array.
    void buildHeap(int arr[], int n)  
    { 
    // Your Code Here
    for(int i=(n-2)/2;i>=0;i--) {
            heapify(arr,n,i);
        }
    }

    
    public:
    //Function to sort an array using Heap Sort.
    void heapSort(int arr[], int n)
    {
        //code here
        buildHeap(arr,n);
        while(n>0) {
            int temp=arr[0];
            arr[0]=arr[n-1];
            arr[n-1]=temp;
            n--;
            heapify(arr,n,0);
        }
    }
};
