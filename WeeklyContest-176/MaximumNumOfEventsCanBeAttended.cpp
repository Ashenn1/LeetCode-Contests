/*
    Passes as AC in contest but TLE out of it.
*/


class Solution {
public:
    
    static bool compareEvents(vector<int> v1 , vector<int>v2){
        return (v1[0] < v2[0]);
    }
    
    int maxEvents(vector<vector<int>>& events) {
        
        sort(events.begin() , events.end() , compareEvents);
        
        vector<vector<int>> tmp = events;
        int maxEvents = 0;
        int delIndex = 0;
        int event_i = 0; // to keep track of the num of events.
        int max_days = 0; // last day
        
        int day = tmp[0][0]; // first day
        
        
        //To get max_days
        for(int idx = 0; idx < events.size();idx++){
            if(events[idx][1] > max_days)
                max_days = events[idx][1];
        }
        
        while(day <= max_days){
            
            int min = 100001; int cnt = 0;
            
            while(cnt < tmp.size()){
                
                if( abs(day-tmp[cnt][1]) < min && tmp[cnt][0] <= day && day <= tmp[cnt][1] ){
                    
                        min = abs(day-tmp[cnt][1]);
                        delIndex = cnt;
                    }
                
                cnt++;
                
            }
            
            //cout<<min <<" " << event_i <<" "<<day <<endl;
        
            // if found an event to attend
            if(min < 100001){
                       //cout<<tmp[delIndex][0]<<" "<<tmp[delIndex][1]<<endl;
                       maxEvents++;
                       tmp.erase(tmp.begin() + delIndex);
                       day++; event_i++;
                   }
            
            //If there is no events today then let time pass to the next event.
            else if(event_i < events.size()) {
                
                if(events[event_i][0] > day)
                    day = events[event_i][0];
                else
                    day++;
            }
            
            //No more events to attend.
            else
                break;
            
        }
        
        return maxEvents;
    }
};