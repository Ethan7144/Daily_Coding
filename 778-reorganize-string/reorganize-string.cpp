class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char, int> freq;
        int maxFreq = 0;

        for(char c : s){
            freq[c]++;
            maxFreq = max(maxFreq, freq[c]);
        }

        if(maxFreq > (s.size() + 1) / 2) {
            return "";
        }

        priority_queue<pair<int, char>> maxHeap;

        for(auto& [c, f] : freq){
            maxHeap.push({f,c});
        }


        pair<int, char> prev = {0, '#'};
        string result;
        while(!maxHeap.empty()){
            auto [freq, ch] = maxHeap.top();
            maxHeap.pop();

            result += ch;

            if(prev.first > 0){
                maxHeap.push(prev);
            }

            prev = {freq - 1, ch};
        }

        return result;
    }
};