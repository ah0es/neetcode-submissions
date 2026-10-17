class Solution {
private:
    int getMaxFreq(const unordered_map<char, int>& freqChar) {
        int maxFreq = 0;

        for (const auto& entry : freqChar) {
            maxFreq = max(maxFreq, entry.second);
        }

        return maxFreq;
    }

public:
int characterReplacement(string s, int k) {
    unordered_map<char, int> freqChar;

    int lw = 0;
    int longestSubString = 0;

    for (int i = 0; i < s.size(); i++) {
        freqChar[s[i]]++;

        int subStringLength = i - lw + 1;

        while (subStringLength - getMaxFreq(freqChar) > k) {
            freqChar[s[lw]]--;
            lw++;

            subStringLength = i - lw + 1;
        }

        longestSubString = max(longestSubString, subStringLength);
    }

    return longestSubString;
}
};