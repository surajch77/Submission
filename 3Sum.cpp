int Solution::threeSumClosest(vector<int> &A, int B) {

    sort(A.begin(), A.end());
    int N = A.size();
    
    int minDiff = INT_MAX;
    int result = 0;
    for(int i=0; i<N-1; ++i){
        int left = i + 1;
        int right = N - 1;
        int currentValue = A[i];
        if(i > 0 and currentValue > B and currentValue > 0) return result;
        while(left < right){
            int currentSum = currentValue + A[left] + A[right];
            int diff = currentSum - B;
            if(abs(diff) <= abs(minDiff)){
                result = currentSum;
                minDiff = diff;
            }
            
            if(currentSum < B)
                left++;
            else
                right--;
        }
    }
    return result;
    
}
