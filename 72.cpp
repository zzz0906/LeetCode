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
        //left 1 oblique 2 up 3
        for (int i = 0; i < word1.size();i++)
            if (word1[i] == word2[0])
                f[i][0] = 1;
        for (int i = 0; i < word2.size();i++)
            if (word1[0] == word2[i])
                f[0][i] = 1;
        for (int i = 0; i < word1.length();i++){
            for (int j = 0; j < word2.length();j++){
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
            pos[index] = pair<int,int>(currentx,currenty);
            if (c[currentx][currenty] == 2){
                currentx--;currenty--;
            }
            if (c[currentx][currenty] == 1)
                currentx--;
            if (c[currentx][currenty] ==3)
                currenty--;
            index++;
        }
        // we get the LCS and its position.
    }
};