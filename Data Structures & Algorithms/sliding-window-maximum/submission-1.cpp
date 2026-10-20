class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        priority_queue<pair<int, int>> pq;

        int l = 0;

        for (int r = 0; r < nums.size(); r++) {
            pq.push({nums[r], r});

            if (r - l + 1 > k) {
                l++;
            }

            while (!pq.empty() && pq.top().second < l) {
                pq.pop();
            }

            if (r - l + 1 == k) {
                ans.push_back(pq.top().first);
            }
        }

        return ans;
    }
};