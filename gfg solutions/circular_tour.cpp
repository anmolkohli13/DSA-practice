/*
The structure of petrolPump is 
struct petrolPump
{
    int petrol;
    int distance;
};*/

/*You are required to complete this method*/
class Solution{
  public:
  
    //Function to find starting point where the truck can start to get through
    //the complete circle without exhausting its petrol in between.
    int tour(petrolPump p[],int n)
    {
       //Your code here
       
       int front = 0, rear = 0;
       int bal = 0, prevbal = 0;
       
       for(int i = 0; i < n; i++)
       {
            if(front == rear)
            {
                prevbal += bal;
                bal = 0;
            }
            
            bal+=(p[rear].petrol-p[rear].distance);
            rear++;
            if(bal<0)
            front=rear;
        }
        
        if(bal+prevbal>=0)
            return front;
        else
            return -1;
    }
};
