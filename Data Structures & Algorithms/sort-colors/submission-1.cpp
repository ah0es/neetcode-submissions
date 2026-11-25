class Solution {

    int partition(vector<int>& nums, int low, int high) {
        int pivot = nums[high];
        int l = low;

        for(int i = low; i < high; i++) {
            if(nums[i] <= pivot) {
                swap(nums[i], nums[l]);
                l++;
            }
        }

        swap(nums[l], nums[high]);
        return l;
    }

    void quickSort(vector<int>& nums, int low, int high) {
        if(low >= high) return;

        int pivotIndex = partition(nums, low, high);

        quickSort(nums, low, pivotIndex - 1);
        quickSort(nums, pivotIndex + 1, high);
    }

public:
    void sortColors(vector<int>& nums) {
        quickSort(nums, 0, nums.size() - 1);
    }
};