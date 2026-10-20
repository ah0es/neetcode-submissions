class Solution {
public:
  

    string minWindow(string s, string t) {
        if (t == "") return "";

        unordered_map<char, int> tFreq;
        unordered_map<char, int> sFreq;

        for (char c : t) {
            tFreq[c]++;
        }

        

        int left = 0;
        int right = 0;
        int l = 0;
        int shortestSubString = INT_MAX;
        int having = 0;
        int need = t.size();
        for (int r = 0; r < s.size(); r++) {
            char c = s[r];
            sFreq[c]++;

            if (tFreq.find(c) != tFreq.end() &&
                sFreq[c] <= tFreq[c]) {
                having++;
            }

            while (having == need) {
                int windowLenght = r - l + 1;
                if (windowLenght < shortestSubString) {
                    left = l;
                    right = r;
                    shortestSubString = windowLenght;
                }
                sFreq[s[l]]--;
                if (tFreq.find(s[l]) != tFreq.end() &&
                    sFreq[s[l]] < tFreq[s[l]]) {
                    having--;
                }
                if (sFreq[s[l]] == 0) {
                    sFreq.erase(s[l]);
                }
                l++;
            }

        }

        if (shortestSubString == INT_MAX) return "";

        return s.substr(left, right - left + 1);
    }
};