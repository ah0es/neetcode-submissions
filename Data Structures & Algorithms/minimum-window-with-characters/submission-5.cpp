
class Solution {
public:
    bool isValid(unordered_map<char, int>& sFreq,
        unordered_map<char, int>& tFreq) {
        for (auto& p : tFreq) {
            if (sFreq[p.first] < p.second) {
                return false;
            }
        }
        return true;
    }

    string minWindow(string s, string t) {
        if (t.size() > s.size()) return "";

        unordered_map<char, int> tFreq;
        unordered_map<char, int> sFreq;
        vector<int> indexes;

        for (char c : t) {
            tFreq[c]++;
        }

        for (int i = 0; i < s.size(); i++) {
            char c = s[i];

            if (tFreq.find(c) != tFreq.end()) {
                indexes.push_back(i);
            }
        }

        int left = 0;
        int right = 0;
        int l = 0;
        int shortestSubString = INT_MAX;

        for (int r = 0; r < indexes.size(); r++) {
            int rightCharIndex = indexes[r];
            char c = s[rightCharIndex];

            sFreq[c]++;

            while (isValid(sFreq, tFreq)) {
                int windowLength = indexes[r] - indexes[l] + 1;

                if (shortestSubString > windowLength) {
                    left = indexes[l];
                    right = indexes[r];
                    shortestSubString = windowLength;
                }

                int leftCharIndex = indexes[l];
                char leftChar = s[leftCharIndex];

                sFreq[leftChar]--;

                if (sFreq[leftChar] == 0) {
                    sFreq.erase(leftChar);
                }

                l++;
            }
        }

        if (shortestSubString == INT_MAX) return "";

        return s.substr(left, right - left + 1);
    }
};

