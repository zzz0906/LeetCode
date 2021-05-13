/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * long guess(long num);
 */

class Solution {
public:
    int guessNumber(int n) {
        long long left = 1; long right = n;
        long long mid = (left + right) / 2;
        long long feedback = guess(mid);
        
        while (feedback != 0){
            if (feedback == -1)
                right = mid - 1;
            if (feedback == 1)
                left = mid + 1;
            mid = (left + right) / 2;
            feedback = guess(mid); 
        }
        return mid;
    }
};