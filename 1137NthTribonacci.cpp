class Solution {
public:
    int tribonacci(int n) {
        // Just PickUp last 3 num and sumup to cal. curr val.
       int a=0;
       int b=1;
       int c=1;

       if(n == 0)
        return 0;
        if(n == 1 || n==2)
            return 1;
        
        for(int i=3;i<=n;i++)
        {
            int sum = a+b+c;
            a=b;
            b=c;
            c=sum;
        }

        return c;
    }

};