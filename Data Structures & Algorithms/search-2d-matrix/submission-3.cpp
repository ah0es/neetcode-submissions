
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] == target) {
                return true;
            }

            if (nums[mid] > target) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return false;
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int left = 0;
        int right = matrix.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (matrix[mid][0] == target) {
                return true;
            }

            if (matrix[mid][0] > target) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        int row = left - 1;

        if (row < 0) {
            return false;
        }

        return search(matrix[row], target);
    }
};
