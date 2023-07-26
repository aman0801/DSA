class Solution {
public:
    double solve(vector<int>& dist, int mid) {
        double ans = 0.0;
        int n = dist.size();
        for (int i = 0; i < n - 1; i++) {
            double t = double(dist[i]) / double(mid);
            ans += ceil(t);
        }
        ans += double(dist[n - 1]) / double(mid);
        return ans;
    }

    int minSpeedOnTime(vector<int>& dist, double hour) {
        int n = dist.size();
        if (hour < n - 1)
            return -1;

        int l = 1;
        int r = 1e7;
        int min_speed = -1;

        while (l <= r) {
            int mid = l + (r - l) / 2;
            double estimatedTime = solve(dist, mid);
            if (estimatedTime <= hour) {
                min_speed = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return min_speed;
    }
};
