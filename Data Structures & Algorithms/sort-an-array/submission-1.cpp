class Solution {

private:
    void mergeSort(vector<int>& nums, int left, int right) {
        if (right - left <= 1) {
            return;
        }

        int mid = left + (right - left) / 2;

        mergeSort(nums, left, mid);
        mergeSort(nums, mid, right);

        merge(nums, left, mid, right);
    }

    void merge(vector<int>& nums, int left, int mid, int right) {
        vector<int> temp;

        int i = left;
        int j = mid;

        while (i < mid && j < right) {
            if (nums[i] <= nums[j]) {
                temp.push_back(nums[i]);
                i++;
            } else {
                temp.push_back(nums[j]);
                j++;
            }
        }

        while (i < mid) {
            temp.push_back(nums[i]);
            i++;
        }

        while (j < right) {
            temp.push_back(nums[j]);
            j++;
        }

        for (int k = 0; k < temp.size(); k++) {
            nums[left + k] = temp[k];
        }
    }

public:

    vector<int> sortArray(vector<int>& nums) {
       
       mergeSort(nums,0,nums.size());
       return nums;
    }
};