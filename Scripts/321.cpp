#include <vector> 
#include <iostream>
using namespace std;
class Solution {
public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int> > records_1;
        vector<vector<int> > records_2;
        for (int i = 0; i <= 9; i++){
            vector<int> tmp;
            records_1.push_back(tmp);
        }
        for (int i = 0; i <= 9; i++){
            vector<int> tmp;
            records_2.push_back(tmp);
        }

        for (int i = 0; i < nums1.size(); i++)
            records_1[nums1[i]].push_back(i);
        for (int i = 0; i < nums2.size(); i++)
            records_2[nums2[i]].push_back(i);
        vector<int> answer;
        int rest1 = nums1.size();
        int rest2 = nums2.size();
        while (answer.size() < k){
            int st = 9;
            while (true){
                int max1 = -1;
                int pos1 = 0;
                if (records_1[st].size() != 0){
                    for (int i = 0; i < records_1[st].size(); i++){
                        if (records_1[st][i] >= nums1.size() - rest1 && nums1.size() - records_1[st][i] - 1 + rest2 >= k - answer.size()){
                        
                        //rest1 = nums1.size() - records_1[st][i] - 1;
                        //records_1[st].erase(records_1[st].begin(),records_1[st].begin() + i);
                        //answer.push_back(st);
                        max1 = st;
                        pos1 = i;
                        break;
                        }
                    }
                }
                int max2 = -1;
                int pos2 = 0;
                if (records_2[st].size() != 0){
                    for (int i = 0; i < records_2[st].size(); i++)
                        if (records_2[st][i] >= nums2.size() - rest2 && nums2.size() - records_2[st][i] - 1 + rest1 >= k - answer.size()){
                        //rest1 = nums1.size() - records_1[st][i] - 1;
                        //records_1[st].erase(records_1[st].begin(),records_1[st].begin() + i);
                        //answer.push_back(st);
                        max2 = st;
                        pos2 = i;
                        break;
                        }
                }
                if (max2 != -1 || max1 != -1){
                    if (max2 > max1){
                        rest2 = nums2.size() - records_2[max2][pos2] - 1;
                        records_2[max2].erase(records_2[max2].begin(),records_2[max2].begin() + pos2);
                        answer.push_back(max2);
                    }else{
                        rest1 = nums1.size() - records_1[max1][pos1] - 1;
                        records_1[max1].erase(records_1[max1].begin(),records_1[max1].begin() + pos1);
                        answer.push_back(max1);
                    }
                    break;
                }
                st --;
            }
        }
        return answer;
    }
};

int main(){
    vector<int> v1; v1.push_back(3);v1.push_back(4);v1.push_back(6);v1.push_back(5);
    vector<int> v2; v2.push_back(9);v2.push_back(2);v2.push_back(5);v2.push_back(8);v2.push_back(3);
    Solution s;
    s.maxNumber(v1,v2,3);
}