class Solution {
public:
    vector<string> ans;
    string num_g;
    long long target_g;
    stack<string> st;
    long long get_value(){
        // cout<<"I can get value"<<endl;
        // cout<<st.size()<<endl;
        stack<string> st_tmp = st;
        stack<string> tmp;
        while (!st_tmp.empty()){
            string sym = st_tmp.top();
            st_tmp.pop();
            if (sym == "*"){
                long long m1 = stoll(tmp.top());
                tmp.pop();
                long long m2 = stoll(st_tmp.top());
                st_tmp.pop();
                tmp.push(to_string(m1*m2));
            }else tmp.push(sym);
        }
        //cout<<tmp.size()<<endl;
        long long ans = stoll(tmp.top());
        tmp.pop();
        while (!tmp.empty()){
            //cout<<tmp.size()<<endl;
            if (tmp.top() == "+"){
                tmp.pop();
                long long a2 = stoll(tmp.top()); tmp.pop();
                ans += a2;
            }else if (tmp.top() == "-"){
                tmp.pop();
                long long a2 = stoll(tmp.top()); tmp.pop();
                ans -= a2;
            }
        }
        //cout<<"I finished -- get_value()"<<endl;
        return ans;
    }
    void dfs(long long cur,string cur_expression,long long val, long long diff){
        if (cur == num_g.length()){
            //cout<<cur_expression<<endl;
            //long long cur_val = get_value();
            if (val == target_g)
                ans.push_back(cur_expression);
            return;
        }
        string cur_str = num_g.substr(cur,num_g.length()-cur);
        // 3+5785 ->5785
        if (cur_str[0] == '0'){
            long long i = 1;
            string split_part =cur_str.substr(0,i);
            if (cur_expression == ""){
                long long tmp_val = stoll(split_part);
                string tmp_expr = split_part;
                dfs(cur+i,tmp_expr,tmp_val,tmp_val);
            }else{
                //+
                long long tmp_val = stoll(split_part);
                string tmp_expr = cur_expression + '+' + split_part;
                dfs(cur+i,tmp_expr,val+tmp_val,tmp_val); 
                //-
                tmp_expr = cur_expression + '-' + split_part;
                dfs(cur+i,tmp_expr,val-tmp_val,-1*tmp_val);
                //*
                tmp_expr = cur_expression + '*' + split_part;
                dfs(cur+i,tmp_expr,val-diff+diff*tmp_val,diff*tmp_val); 
            }
            return;
        }
        for (int i = 1; i <= cur_str.size();i++){
            string split_part =cur_str.substr(0,i);
            if (cur_expression == ""){
                long long tmp_val = stoll(split_part);
                string tmp_expr = split_part;
                dfs(cur+i,tmp_expr,tmp_val,tmp_val);
            }else{
                //+
                long long tmp_val = stoll(split_part);
                string tmp_expr = cur_expression + '+' + split_part;
                dfs(cur+i,tmp_expr,val+tmp_val,tmp_val); 
                //-
                tmp_expr = cur_expression + '-' + split_part;
                dfs(cur+i,tmp_expr,val-tmp_val,-1*tmp_val);
                //*
                tmp_expr = cur_expression + '*' + split_part;
                dfs(cur+i,tmp_expr,val-diff+diff*tmp_val,diff*tmp_val); 
            }
        }
    }
    vector<string> addOperators(string num, int target) {
        num_g = num;
        target_g = target;
        dfs(0,"",0,0);
        return ans;
    }
};