class Solution {
private:

    int partition(vector<int>& nums, int low, int high) {
        int pivotIndex = low + rand() % (high - low + 1);

        swap(nums[pivotIndex], nums[high]);

        int pivot = nums[high];
        int i = low;

        for (int j = low; j < high; j++) {
            if (nums[j] <= pivot) {
                swap(nums[j], nums[i]);
                i++;
            }
        }

        swap(nums[high], nums[i]);

        return i;
    }

    void quickSort(vector<int>& nums, int low, int high) {
        if (low >= high) return;

        int pivotIndex = partition(nums, low, high);

        quickSort(nums, low, pivotIndex - 1);
        quickSort(nums, pivotIndex + 1, high);
    }

public:

    vector<int> sortArray(vector<int>& nums) {
        quickSort(nums, 0,nums.size() - 1);
        return nums;
    }
};