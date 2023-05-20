class Solution {
public:
    
    int myAtoi(string s) {
       int len=s.size();
       int i=0;
       while(s[i]==' '){
           i++;
       }
        
        bool neg=s[i]=='-';
        bool pos=s[i]=='+';
        
        int num=0;
        
        neg==true?i++:i;
        pos==true?i++:i;
        
        while(i<len and s[i]>='0' and s[i]<='9'){
            
            int digit=s[i]-'0';
            if((num>INT_MAX/10) or (num==INT_MAX/10 and digit>7)){
                return neg==true?INT_MIN:INT_MAX;
            }
            num=num*10+digit;
            i++;
        }
        
        num=neg?-num:num;
        
       /* num=(num>INT_MAX)?INT_MAX:num;
        num=(num<INT_MIN)?INT_MIN:num;*/
        
        return num;
    }
};