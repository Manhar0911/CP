  
  //solution using dynamic programming in O(n^2) and O(n) space
  int minJumps(int arr[], int n){
        // Your code here
        int dp[n];
        for(int i=0;i<n;i++)dp[i] = INT_MAX;
        dp[0] = 0;
        
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(dp[j] != INT_MAX && j+arr[j]>= i )
                {
                    if(dp[j]+1<dp[i])
                    dp[i] = dp[j] + 1;
                }
            }
        }
        if(dp[n-1]!=INT_MAX)
        return dp[n-1];
        else
        return -1;
    }

////  solution in O(n) time and O(1) space
    int minJumps(int arr[], int n){
        // base case
        if(n == 1)return 0;
        if(arr[0] == 0)return -1;

        int jump = 1;
        int maxr = arr[0];
        int step = arr[0];
        for(int i=1;i<n;i++)
        {
            if(i==n-1)
            return jump;
            maxr = max(maxr,i+arr[i]);
            step--;
            if(step==0)
            {
                jump++;
                if(i>=maxr)
                return -1;
                else
                step = maxr-i;
            } 
        }
    }