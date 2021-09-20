long long int maxSum(int a[], int n)
{
    // final sequence stored in the vector
//     vector<int> finalSequence;
 
//     sort(a, a + n);
 
//     for (int i = 0; i < n / 2; ++i) {
//         finalSequence.push_back(a[i]);
//         finalSequence.push_back(a[n - i - 1]);
//     }
 
//     // If there are odd elements, push the
//     // middle element at the end.
//     if (n % 2 != 0)
//         finalSequence.push_back(a[n/2]);
 
//     long long int MaximumSum = 0;
  
//     for (int i = 0; i < n - 1; ++i) {
//         MaximumSum = MaximumSum + abs(finalSequence[i] -
//                                   finalSequence[i + 1]);
//     }
 
//     // absolute difference of last element
//     // and 1st element
//     MaximumSum = MaximumSum + abs(finalSequence[n - 1] -
//                                       finalSequence[0]);
 
//     // return the value
//     return MaximumSum;
  sort(arr.begin(), arr.end());
    int n = arr.size(), sum = 0;
    for (int i = 0, j = n - 1 - i; i <= j; ++i, --j) {
        if (i == j) {
            sum += abs(arr[j] - arr[0]);
            break;
        }
        sum += abs(arr[j] - arr[i]); // max with prev min
        if (j - i != 1) {
            sum += abs(arr[j] - arr[i + 1]); // max with next min
        }
        if (j - i == 1) { // last minimum of maximums with the 0 one
            sum += abs(arr[j] - arr[0]);
        }
}
