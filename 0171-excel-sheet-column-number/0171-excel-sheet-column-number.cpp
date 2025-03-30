class Solution {
public:
    int titleToNumber(string col) {
        int sum =0, p = 0;
        int n=col.length();

        for(int i = n-1; i>=0; i--){
            int temp=col[i]-64;
            sum = sum+pow(26,p++)*temp;
        }
        return sum;
    }
};