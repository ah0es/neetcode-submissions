class TimeMap {
private:
    string search(vector<pair<int, string>>& list, int target) {
        int l = 0;
        int r = list.size() - 1;
        int mid = 0;
        int answer = -1;
        while (l <= r) {
            mid = l + (r - l) / 2;
            
            if (list[mid].first == target) {
                return list[mid].second;
            }

            if (list[mid].first < target) {
                answer = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return answer == -1 ? "" : list[answer].second;
    }

public:
    unordered_map<string, vector<pair<int, string>>> timeMap;

    TimeMap() {
    }

    void set(string key, string value, int timestamp) {
        timeMap[key].push_back({timestamp, value});
    }

    string get(string key, int timestamp) {
        if (timeMap.find(key) == timeMap.end()) {
            return "";
        } else {
            return search(timeMap[key], timestamp);
        }
    }
};