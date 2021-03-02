class Solution {
public:
    /**
     * Argsort(currently support ascending sort)
     * @tparam T array element type
     * @param array input array
     * @return indices w.r.t sorted array
     */
    template<typename T>
    std::vector<size_t> argsort(const std::vector<T> &array) {
        std::vector<size_t> indices(array.size());
        std::iota(indices.begin(), indices.end(), 0);
        std::sort(indices.begin(), indices.end(),
              [&array](int left, int right) -> bool {
                  // sort indices according to corresponding array element
                  return array[left] < array[right];
              });
        return indices;
    }
    int n;
    vector<int> c;
    int lowbit(int x){
        return x & -x;
    }
    void add(int x, int k) {
        while (x <= n) {  // 不能越界
            c[x] = c[x] + k;
            x = x + lowbit(x);
        }
    }
    int getsum(int x) {  // a[0]……a[x]的和
        int ans = 0;
        while (x >= 0) {
            ans = ans + c[x];
            x = x - lowbit(x);
        }
        return ans;
    }
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> fwick_tree(0,nums.size());
        vector<size_t> sorted_nums_indices = argsort(nums);
        vector<int> answer;
        this->n = nums.size();
        c = vector<int>(0,n);
        for (int i = nums.size() - 1; i >= 0; i--){
            add(sorted_nums_indices[i],1);
            answer.push_back(getsum(sorted_nums_indices[i]));
        }
        return answer;
    }
};