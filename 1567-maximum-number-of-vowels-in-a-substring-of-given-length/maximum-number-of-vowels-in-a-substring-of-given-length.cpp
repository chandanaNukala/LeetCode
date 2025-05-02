class Solution {
public:
    bool isVowel(char c) {
        c = tolower(c);  
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
    int maxVowels(string s, int k) {
       
        int vowels=0;
        int l;
        for(l=0;l<k;l++){
            if(isVowel(s[l])){
                vowels++;
            } 
        }
        l=0;
        int max_vowels=vowels;
        for(int i=k;i<s.length();i++){
            if(isVowel(s[l]) ){
                vowels--;
                if(isVowel(s[i])){
                    vowels++;
                }
            }
            else{
                if(isVowel(s[i])){
                    vowels++;
                }
            }
            max_vowels=max(max_vowels,vowels);
            l++;
            cout<<s[l]<<s[i]<<endl;
            cout<<vowels<<endl;
        }
        return max_vowels;
        
    }
};