void sortedInsert(stack<int> &s, int element)
{
    if(s.empty() || element >= s.top())
    {
        s.push(element);
        return;
    }

        int temp = s.top();
        s.pop();
        sortedInsert(s,element);
        s.push(temp);
        return;
}
void SortedStack :: sort()
{
  //Your code here
  if(s.size() == 1)
  return;
   
      int temp = s.top();
      s.pop();
      sort();
      sortedInsert(s,temp);
      return;
   
   
}
