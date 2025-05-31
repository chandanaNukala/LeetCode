class Solution {
public:
    int fib(int n) {
        int result=0;
        if(n==0) return result;
        if(n==1 || n==2){
            result=1;
        }
        else{
            result=fib(n-1)+fib(n-2);
        }

        return result;
    }
};