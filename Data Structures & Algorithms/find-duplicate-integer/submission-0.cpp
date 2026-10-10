class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int,int> dup;
        for(int num : nums){
            dup[num]++;
            if(dup[num] > 1) return num;
            
            
        }
        return -1;
    }
};
