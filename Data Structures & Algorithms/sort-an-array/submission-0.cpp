class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        map<int, int> mp;

        for (int n : nums) {
            mp[n]++;
        }

        vector<int> ans;

        for (auto p : mp) {
            while (p.second > 0) {
                ans.push_back(p.first);
                p.second--;
            }
        }

        return ans;
    }
};