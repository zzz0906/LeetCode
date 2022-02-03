class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        deque<int> q_min;
        deque<int> q_max;
        deque<int> index_min;
        deque<int> index_max;
        if (k == 0 && t != 0) return false;
        if (k == 0 && t == 0) return true;
        q_min.push_back(nums[0]);
        q_max.push_back(nums[0]);
        index_min.push_back(0);
        index_max.push_back(0);
        int tail_min = 0;
        int tail_max = 0;
        for (int i = 1; i <= k; i++){
            while (!q_min.empty() && q_min.back() > nums[i]){
                q_min.pop_back();
                index_min.pop_back();
            }
            q_min.push_back(nums[i]);
            index_min.push_back(i);
            while (!q_max.empty() && q_max.back() < nums[i]){
                q_max.pop_back();
                index_max.pop_back();
            }
            q_max.push_back(nums[i]);
            index_max.push_back(i);
        }
        if (abs(q_max.front() - q_min.front()) > t) return false;
        int index = k+1;
        int begin = 1;
        while (index < nums.size()){
            while (!q_min.empty() && q_min.back() > nums[index]){
                q_min.pop_back();
                index_min.pop_back();
            }
            q_min.push_back(nums[index]);
            index_min.push_back(index);
            while (index_min.front() < begin){
                q_min.pop_front();
                index_min.pop_front();
            }
            while (!q_max.empty() && q_max.back() < nums[index]){
                q_max.pop_back();
                index_max.pop_back();
            }
            q_max.push_back(nums[index]);
            index_max.push_back(index);
            while (index_max.front() < begin){
                q_max.pop_front();
                index_max.pop_front();
            }
            if (abs(q_max.front() - q_min.front()) > t) return false;
            index++;
            begin++;
        }
        return true;
    }   
};