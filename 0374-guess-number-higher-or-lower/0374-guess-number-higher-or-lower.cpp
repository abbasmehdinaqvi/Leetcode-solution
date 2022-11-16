/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int l = 1;
        int r = pow(2, 31) - 1;
        
        while(l <= r)
        {
            int m = l + ((r - l) / 2);
            
            int ans = guess(m);
            
            if(ans == 0)
                return m;
            
            if(ans == 1)
                l = m + 1;
            
            if(ans == -1)
                r = m - 1;
        }
        return 0;
    }
};