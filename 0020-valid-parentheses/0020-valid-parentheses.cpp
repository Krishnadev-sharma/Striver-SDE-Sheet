class Solution {
public:
    bool isValid(string s) {
     char st[s.size()];
     int top = -1;
     for(char c : s){
        if(c == '(') st[++top] = ')';
        else if(c == '{') st[++top] = '}';
        else if(c == '[') st[++top] = ']'; 
        else {
        if(top < 0 || st[top--] != c)
         return false;
     }
     }
     return top == -1;
    }
};