class Solution {
public:
    int maxVowels(string s, int k) {
        if(s.length() < k){
            return 0;
        }
        unordered_set<char> vowels = {'a','e','i','o','u'};

        int max_vowels = 0, window_vow = 0;

        for(int i = 0; i < s.length(); i++){
            if(vowels.count(s[i])){
                window_vow++;
            }
            if(i >= k && vowels.count(s[i - k])){
                window_vow--;
            }
            if(i >= k - 1) {
                max_vowels = max(max_vowels, window_vow);
            }
        }


        return max_vowels;
    }
};