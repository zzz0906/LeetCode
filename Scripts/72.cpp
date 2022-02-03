#include <iostream>
#include <stdio.h>
#include <string>
#include <stack>
using namespace std;
class Solution {
public:
    int minDistance(string word1, string word2) {
        int f [word1.size()+2][word2.size()+2];
        int c [word1.size()+2][word2.size()+2];
        memset(f, 0, sizeof(f));
        memset(c, 0, sizeof(f));
        //up 1 oblique 2 left 3
        for (int i = 0; i < word1.size();i++)
            if (word1[i] == word2[0]){
                f[i][0] = 1;
                c[i][0] = 0;
            }else{
                if (i == 0)
                    continue;
                if (f[i-1][0] > f[i][0]){
                    f[i][0] = f[i-1][0];
                    c[i][0] = 1;
                }
            }
        for (int i = 0; i < word2.size();i++)
            if (word1[0] == word2[i]){
                f[0][i] = 1;
                c[i][0] = 0;
            }
            else{
                if (i == 0)
                    continue;
                if (f[0][i-1] > f[0][i]){
                    f[0][i] = f[0][i-1];
                    c[i][0] = 3;
                }
            }
        for (int i = 1; i < word1.length();i++){
            for (int j = 1; j < word2.length();j++){
                if (word1[i] == word2[j]){
                    f[i][j] = f[i-1][j-1]+1;
                    c[i][j] = 2;
                }
                else if (f[i-1][j] > f[i][j-1]){
                    f[i][j] = f[i-1][j];
                    c[i][j] = 1;
                }else{
                    f[i][j] = f[i][j-1];
                    c[i][j] = 3;
                }
            }
        }
        pair<int,int> pos [max(word1.size(), word2.size())];
        int currentx = word1.size()-1;
        int currenty = word2.size()-1;
        int index = 0;
        while (c[currentx][currenty] != 0){
            if (c[currentx][currenty] == 0 || c[currentx][currenty] == 2){
                pos[index] = pair<int,int>(currentx,currenty);
                index++;
            }
            //cout<<currentx<<currenty<<endl;
            if (c[currentx][currenty] == 2){
                currentx--;currenty--;
            }
            else if (c[currentx][currenty] == 1)
                currentx--;
            else if (c[currentx][currenty] == 3)
                currenty--;
            
        }
        if (c[currentx][currenty] == 0 || c[currentx][currenty] == 2){
                pos[index] = pair<int,int>(currentx,currenty);
                index++;
        }
        //final position
        for (int i = 0; i <index;i++)
            cout<<pos[i].first<<pos[i].second<<endl;
        int lastforor = 0;
        int lastfortarget = 0;
        int cost = 0;
        for (int i = 0; i <index; i++){
            int modifyle = pos[i].second - lastfortarget;
            int orgle = pos[i].first - lastforor;
            if (modifyle == orgle){
                cost+=modifyle;
            }else{
                cost+=modifyle + abs(modifyle-orgle);
            }
            lastfortarget = pos[i].second+1;
            lastforor = pos[i].first+1;
        }
        int modifyle = (word2.size()-1)-(pos[index-1].second);
        int orgle = (word1.size()-1)-(pos[index-1].first);
        if (modifyle == orgle){
            cost+=modifyle;
        }else{
            cost+=modifyle + abs(modifyle-orgle);
        }
        // we get the LCS and its position.
        // Then we need to conduct edit distance
        return cost;
    }
};
int main(){
    Solution s;
    cout<<s.minDistance("intention","execution")<<endl;
    // 3 + 1 + 3 = 7
    
}