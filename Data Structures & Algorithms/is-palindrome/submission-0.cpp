class Solution {
    int check(char s1){
        if(s1 >= 'a' && s1 <= 'z')return s1-'a';
        else return s1-'A';
    }
public:
    bool isPalindrome(string s) {
        int n = s.size();
        int left = 0, right = n-1;

        while(left < right){
            
            while(left < right && !((s[left]>='0'&&s[left]<='9')||
            (s[left]>='a'&&s[left]<='z')||
            (s[left]>='A'&&s[left]<='Z')))left++;

            while(left < right && !((s[right]>='0'&&s[right]<='9')||
            (s[right]>='a'&&s[right]<='z')||
            (s[right]>='A'&&s[right]<='Z')))right--;

            char s1 = s[left];
            char s2 = s[right];

            if(s1>='0'&&s1<='9'){
                if(s1 != s2)return false;
            }
            else {
                if(s2 >= '0' && s2 <= '9') return false;
                if(check(s1) != check(s2)) return false;
            }
            left++;
            right--;
        }
        return true;
    }
};
