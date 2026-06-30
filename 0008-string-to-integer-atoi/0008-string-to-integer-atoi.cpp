class Solution {
public:
    int myAtoi(string s) {
       long res= 0;
       int i = 0, sign = 1;
       while(i < s.size() && s[i] == ' ')
       i++;

       if(i < s.size() && (s[i] == '-' || s[i] == '+')){
        sign = (s[i] == '-') ? -1 : 1;
        i++;
       }
       while(i < s.size() && s[i] >= '0' && s[i] <= '9'){
        int digit = s[i] - '0';
        res = res * 10 + digit;
        if(sign == 1 && res > INT_MAX){
            return INT_MAX;
        }
        if(sign == -1 && -res < INT_MIN){
            return INT_MIN;
        }
        i++;
       }
       return sign * res;
    }
};