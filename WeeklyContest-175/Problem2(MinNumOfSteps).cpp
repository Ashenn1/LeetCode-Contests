class Solution {
public:
    int minSteps(string s, string t) {
        
        int res = 0;
        int saved = 0;
        
        map<char,int> s_map;
        map<char,int> t_map;
        
        for(int i = 0; i< s.length();i++){
            
            s_map[s[i]]++;
            t_map[t[i]]++;
            
        }
        
        for(map<char,int>::iterator it = s_map.begin(); it!=s_map.end(); it++){
            
            if(s_map[it->first] != t_map[it->first]){
                res +=  abs(s_map[it->first] - t_map[it->first]);
            }
                
            if(s_map[it->first] != 0 && t_map[it->first] != 0  && t_map[it->first] > s_map[it->first])
                saved += (t_map[it->first]  - s_map[it->first]);
            
        } 
        
        
    return (res-saved);
                
   }
        

};