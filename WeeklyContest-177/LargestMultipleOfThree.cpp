// Ref : https://leetcode.com/problems/largest-multiple-of-three/discuss/518830/C%2B%2BJava-Concise-O(n)

class Solution {
public:
    string largestMultipleOfThree(vector<int>& digits) {
        
        int sum = 0;
        int c1[] = {1 , 4 , 7 , 2, 5, 8} , c2[] = {2 , 5 , 8 , 1, 4, 7};
        int digitCnt[10] = {};
        string res = "";
        
        for(auto d : digits){
            sum += d;
            digitCnt[d]++;
        }
        
        while(sum % 3 != 0){
            
            for(auto i : (sum % 3 == 1)? c1 : c2){
                
                if(digitCnt[i]){
                    --digitCnt[i];
                    sum -= i;
                    cout<<sum<<endl;
                    break;
                }
            }
        }
        
        for(int i = 9; i >= 0; i--){ 
            // string function returns the second parameter num of times of the first param
            // Ex. string (4 , '9') returns "9999"
            res+= string(digitCnt[i] , '0'+i); 
            
        }
        
        return (res.size() && res[0]=='0')? "0": res;
        
    }
};