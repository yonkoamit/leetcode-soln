class Solution {
public:
    bool checkPal(int d, int & x)
    {
        if(d==0) return 1;
        bool ans = checkPal(d/10,x) & (d % 10 == x % 10);
        x /= 10;
        return ans;
    }
        
    bool isPalindrome(int x) {
        if (x<0) return 0;
        return checkPal(x,x);
    }
};