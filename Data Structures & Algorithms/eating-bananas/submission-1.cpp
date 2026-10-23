class Solution {
private:
    long long calcHours(vector<int>& piles, int k) {
        long long totalH = 0;

        for (int j = 0; j < piles.size(); j++) {
            totalH += ceil((double)piles[j] / k);
        }

        return totalH;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {

        int maxValue = INT_MIN;
        for (int i = 0; i < piles.size(); i++) {
            if (piles[i] > maxValue) {
                maxValue = piles[i];
            }
        }
        
        int ans = INT_MAX;
        int l = 1;
        int r = maxValue;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            long long totalH = calcHours(piles, mid);

            if (totalH <= h) {
                r = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }

        return l;

    }
};