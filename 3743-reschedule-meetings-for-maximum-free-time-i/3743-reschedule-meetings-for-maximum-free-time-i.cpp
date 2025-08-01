class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        int n = startTime.size();
        vector<int> freeSlots;
        freeSlots.push_back(startTime[0]);
        for(int i = 1; i < n; i++){
            freeSlots.push_back(startTime[i] - endTime[i-1]);
        }
        freeSlots.push_back(eventTime - endTime[n-1]);
        int currFreeTime = accumulate(freeSlots.begin(), freeSlots.begin() + k + 1, 0);
        int maxFreeTime = currFreeTime;
        for(int i = k + 1; i < n + 1; i++){
            currFreeTime += freeSlots[i];
            currFreeTime -= freeSlots[i-(k+1)];
            maxFreeTime = max(maxFreeTime, currFreeTime);
        }
        return maxFreeTime;
    }
};