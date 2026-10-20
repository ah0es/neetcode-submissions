class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;

        // Store indices, not values
        deque<int> dq;

        int left = 0;

        for (int right = 0; right < nums.size(); right++) {

            // Step 1: Keep the window size at most k
            while (right - left + 1 > k) {
                left++;
            }

            // Step 2: Remove indices outside the current window
            if (!dq.empty() && dq.front() < left) {
                dq.pop_front();
            }

            // Step 3: Remove smaller or equal values from the back
            while (!dq.empty() && nums[dq.back()] <= nums[right]) {
                dq.pop_back();
            }

            // Step 4: Add the current index
            dq.push_back(right);

            // Step 5: If the window is complete, save its maximum
            if (right - left + 1 == k) {
                ans.push_back(nums[dq.front()]);
            }
        }

        return ans;
    }
};