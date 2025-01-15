class TimeMap {
public:
    unordered_map<string, vector<pair<int, string>>> ump;
    int size;

    TimeMap() { size = 0; }

    void set(string key, string value, int timestamp) {
        ump[key].push_back({timestamp, value});
        size++;
    }

    string get(string key, int timestamp) {
        if (ump.find(key) == ump.end() || ump[key][0].first > timestamp)
            return "";

        int lo = 0, hi = ump[key].size() - 1;

        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;

            if (ump[key][mid].first == timestamp) {
                return ump[key][mid].second;
            } else if (ump[key][mid].first > timestamp) {
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }

        return ump[key][lo].second;
    }
};
