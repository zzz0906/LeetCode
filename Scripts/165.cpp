class Solution {
public:
    int compareVersion(string version1, string version2) {
        int pre = 0;
        vector<string> version1_split;
        vector<string> version2_split;
        //split the version
        for (int i = 0; i < version1.size(); i++){
            if (version1[i] == '.'){
                version1_split.push_back(version1.substr(pre,i-pre));
                pre = i + 1;
            }
        }
        version1_split.push_back(version1.substr(pre,version1.size()-pre));
        pre = 0;
        for (int i = 0; i < version2.size(); i++){
            if (version2[i] == '.'){
                version2_split.push_back(version2.substr(pre,i-pre));
                pre = i + 1;
            }
        }
        version2_split.push_back(version2.substr(pre,version2.size()-pre));
        int index = 0;
        while (version2_split.size() < version1_split.size()) version2_split.push_back("0");
        while (version1_split.size() < version2_split.size()) version1_split.push_back("0");
        while (index < version2_split.size() && index < version1_split.size()){
            while (version1_split[index].size() > 1 && version1_split[index][0] == '0'){
                version1_split[index] = version1_split[index].substr(1,version1_split[index].size()-1);
            }
            while (version2_split[index].size() > 1 && version2_split[index][0] == '0'){
                version2_split[index] = version2_split[index].substr(1,version2_split[index].size()-1);
            }
            //cout<<version1_split[index];cout<<version2_split[index]<<endl;
            
            if (stoi(version1_split[index]) > stoi(version2_split[index])) return 1;
            if (stoi(version1_split[index]) < stoi(version2_split[index])) return -1;
            index ++;
        }
        return 0;
    }
};