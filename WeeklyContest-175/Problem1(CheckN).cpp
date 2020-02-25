class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
    
        for(int i =0 ; i< arr.size(); i++){
            int cnt = i+1;
            while(cnt < arr.size()){
                if( arr[i] == arr[cnt]*2 || arr[cnt] == arr[i]*2)
                    return true;
                cnt++;
            }
            
        }
        
        return false;
        
        
    }
};