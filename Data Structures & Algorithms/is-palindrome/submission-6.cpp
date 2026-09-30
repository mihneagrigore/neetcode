class Solution {
public:
    bool isPalindrome(string s) {
        bool ok = true;
        int i = 0, j = s.size() - 1;
        while (i < j) {
            while( i < j && !isdigit(s[i]) && !isalpha(s[i]) )
                i++;

            while( i < j && !isdigit(s[j]) && !isalpha(s[j]) )
                j--;

            cout<<s[i]<<' '<<s[j]<<endl;

            if(tolower(s[i]) != tolower(s[j]))
                ok = false;

            i++;
            j--;
        }

        return ok;
    }
};
