class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> mergedArray;
        if(nums1.empty()){
            mergedArray = nums2;
        }else if(nums2.empty()){
           mergedArray = nums1; 
        }else{
            int n = nums1.size();
            int m = nums2.size();

            int i = 0 , j = 0;
            while(i < n && j < m){

                if(nums1[i] < nums2[j]){
                    mergedArray.push_back(nums1[i]);
                    i++;
                }else{
                    mergedArray.push_back(nums2[j]);
                    j++;
                }
            }
            while(i < n){
                mergedArray.push_back(nums1[i]);
                i++;
            }
            while(j < m){
                mergedArray.push_back(nums2[j]);
                j++;
            }
        }
        int size = mergedArray.size();
        if(size % 2 == 0){
            double median = (mergedArray[size / 2 - 1] + mergedArray[size / 2]) / 2.0;
            return median;
        }
        return mergedArray[size / 2];
    }
};