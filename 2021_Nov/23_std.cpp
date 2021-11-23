class Solution {
public:
    int largestComponentSize(vector<int>& A) {
        int n = 0, mx = 0, res = 0;
        unordered_map<int, int> m;
        for (int num : A) mx = max(mx, num);
        vector<int> root(mx + 1);
        for (int i = 1; i <= mx; ++i) root[i] = i;
        for (int num : A) {
            for (int d = sqrt(num); d >= 2; --d) {
                if (num % d == 0) {
                    root[find(root, num)] = root[find(root, d)];
                    root[find(root, num)] = root[find(root, num / d)];
                }
            }
        }
        for (int num : A) {
            res = max(res, ++m[find(root, num)]);
        }
        return res;
    }
    int find(vector<int>& root, int x) {
        return root[x] == x ? x : (root[x] = find(root, root[x]));
    }
};