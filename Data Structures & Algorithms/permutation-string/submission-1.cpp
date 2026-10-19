class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int size = s1.size();

        if (size > s2.size()) return false;

        unordered_map<char, int> s1freq;
        for (char c : s1) {
            s1freq[c]++;
        }

        unordered_map<char, int> s2freq;
        int lw = 0;

        for (int i = 0; i < s2.size(); i++) {
            s2freq[s2[i]]++;

            if (i - lw + 1 > size) {
                s2freq[s2[lw]]--;
                if (s2freq[s2[lw]] == 0) {
                    s2freq.erase(s2[lw]);
                }
                lw++;
            }

            if (i - lw + 1 == size && s1freq == s2freq) {
                return true;
            }
        }

        return false;
    }
};