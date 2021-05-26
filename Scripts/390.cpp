class Solution {
public:
    int lastRemaining(int n) {
        int size = n;
        vector<bool> choose(size,false);
        int start = 0;
        int emli = 0;
        bool left_to_right = true;
        while (emli < size - 1){
            cout << start << endl;
            if (left_to_right){
                choose[start] = true;
                while (start < size){
                    while (start < size && choose[start] == true)
                        start ++;
                    start ++;
                    while (start < size && choose[start] == true)
                        start ++;
                    if (start < size){
                        choose[start] = false;
                        emli ++;
                    }
                    if (emli == size - 1)
                        break;
                }
                start = size - 1;
                //find a number that has never been choosen
                while (choose[start] == true)
                    start --;
            }else{
                choose[start] = true;
                while (start >= 0){
                    // two false
                    while (start >= 0 && choose[start] == true)
                        start --;
                    start --;
                    while (start >= 0 && choose[start] == true)
                        start --;
                    if (start >= 0){
                        choose[start] = true;
                        emli ++;
                    }
                    if (emli == size - 1)
                        break;
                }
                start = 0;
                while (choose[start] == true)
                    start ++;
            }
            left_to_right = !left_to_right;
        }
        for (int i = 0; i < size; i++)
            if (choose[i] == false)
                return i + 1;
        return -1;
    }
};