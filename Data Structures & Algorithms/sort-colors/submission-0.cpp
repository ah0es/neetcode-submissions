class Solution {
    void merge(vector<int>& nums,int left,int mid,int right){
        int l = left;
        int r = mid;
        vector<int> temp;
        while(l < mid && r < right){
            if(nums[l] <= nums[r]){
                temp.push_back(nums[l]);
                l++;
            }else{
                temp.push_back(nums[r]);
                r++;
            }
        }

        while(l < mid){
            temp.push_back(nums[l]);
            l++;
        }
        while(r < right){
            temp.push_back(nums[r]);
            r++;
        }

        for(int i = 0; i < temp.size();i++){
            nums[left + i] = temp[i];
        }
    }

    void mergeSort(vector<int>& nums,int left,int right){
        if(right - left <= 1) return;
        int mid = left + (right - left) / 2;

        mergeSort(nums,left,mid);
        mergeSort(nums,mid,right);
        merge(nums,left,mid,right);
    }

public:
    void sortColors(vector<int>& nums) {
        mergeSort(nums,0,nums.size());
    }
};