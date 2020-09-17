class Solution {
public:
    TreeNode{
        TreeNode* leftb, righto;
    }
    int findMaximumXOR(vector<int>& nums) {
        TreeNode* root = new TreeNode();
        for （auto num:nums){
            int bin[32];
            for(int i = 0; i <= 31; i++){
                if(num & (1<<i))
                    bin[i]=1;
                else
                    bin[i]=0;
            }
            TreeNode* current = root;
            for (int i = 31; i >= 0; i--){
                if (bin[i] == 1){
                    if (current->righto != NULL) {current->righto;continue;}
                    else {current->righto = new TreeNode(); current = current->righto;}
                }else{
                    if (current->leftb != NULL) {current = current->leftb;continue;}
                    else {current->leftb = new TreeNode(); current = current->leftb;}
                }
            }
        }
        int ans = 0;
        for (auto num : nums){
            int bin[32];
            for(int i = 0; i <= 31; i++){
                if(num & (1<<i))
                    bin[i]=1;
                else
                    bin[i]=0;
            }
            TreeNode* current = root;
            int current_res[31];
            for (int = 31; i >= 0; i--){
                if (bin[i] == 1){
                    if (current->leftb != NULL) {current = current->leftb; current_res[i] = 1;}
                    else {current = current->righto; current_res[i] =0;}
                }else{
                    if (current->righto!= NULL) {current = current->righto; current_res[i] = 1;}
                    else {current = current->leftb; current_res[i] =0;}
                }
            }
            multi = 1;
            int current_dec = 0;
            for (int i = 0; i <= 31; i++){
                current_dec += current_res[i]*multi;
                multi *= 2;
            }
            ans = max(ans,current_dec)
        }
        return ans;
    }
};  