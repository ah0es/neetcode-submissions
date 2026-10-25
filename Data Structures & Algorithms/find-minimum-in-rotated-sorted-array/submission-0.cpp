class Solution {
public:
    int findMin(vector<int> &nums) {
        int size = nums.size() - 1;
        int l = nums[0];
        int r = nums[size];

        while(l > r){
            l = r;
            r = nums[--size];
        }
        return l;
    }
};
