class TimeMap {
private:
    unordered_map<string, vector<pair<int, string>>> timeMap;

public:
    TimeMap() {
    }
    
    void set(string key, string value, int timestamp) {
        timeMap[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        string res = "";
        if (!timeMap.contains(key)){return res;}

        int l = 0; int r = timeMap[key].size() - 1;
        vector<pair<int, string>>& vals = timeMap[key];

        while (l <= r){
            int mid = l + (r - l) / 2;
            if (vals[mid].first == timestamp){
                res = vals[mid].second;
                break;
            }

            else if (vals[mid].first < timestamp){
                res = vals[mid].second;
                l = mid + 1;
            }

            else{r = mid - 1;}
        }

        return res;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
