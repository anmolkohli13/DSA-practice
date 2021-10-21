/* The structure of the class is
class StackQueue{
private:   
    // These are STL stacks ( http://goo.gl/LxlRZQ )
    stack<int> s1;
    stack<int> s2;
public:
    void push(int);
    int pop();
}; */

//Function to push an element in queue by using 2 stacks.
void StackQueue :: push(int x)
{
    // Your Code
    s1.push(x);
}

//Function to pop an element from queue by using 2 stacks.
int StackQueue :: pop()
{
        // Your Code
        if(s1.empty())
        return -1;
        
        int temp;
        while(!s1.empty())
        {
            temp = s1.top();
            s1.pop();
            s2.push(temp);
        }
        s2.pop();
        int ans = temp;
        while(!s2.empty())
        {
            temp = s2.top();
            s2.pop();
            s1.push(temp);
        }
        return ans;
}
