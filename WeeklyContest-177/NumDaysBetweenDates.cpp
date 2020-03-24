class Solution {
public:
    
    // Count days form 0000-00-00 until the given years then subtract the dates from each other.
    int daysBetweenDates(string date1, string date2) {
        
        const int monthDays[12] = {31, 28, 31, 30, 31, 30, 
                           31, 31, 30, 31, 30, 31};
        
        int date1_y = stoi(date1.substr(0,4));
        int date1_m = stoi(date1.substr(5,7));
        int date1_d = stoi(date1.substr(8,9));
        
        int date2_y = stoi(date2.substr(0,4));
        int date2_m = stoi(date2.substr(5,7));
        int date2_d = stoi(date2.substr(8,9));
        
        long sum_days1 = date1_y*365 + date1_d;
        long sum_days2 = date2_y*365 + date2_d;
        
        for(int i = 0; i< date1_m-1; i++){
            sum_days1 += monthDays[i];
        }
        for(int i = 0; i< date2_m-1; i++){
            sum_days2 += monthDays[i];
        }
        cout<<sum_days1<<" "<<sum_days2<<endl;
        
        // Sum over all leap years count until this year
        if( date1_m > 2)
            sum_days1 += ( (date1_y)/400 - (date1_y)/100 + (date1_y)/4);
        else if (date1_m <= 2)
            sum_days1 += ( (date1_y-1)/400 - (date1_y-1)/100 + (date1_y-1)/4);
        
        if( date2_m > 2)
            sum_days2 += ( (date2_y)/400 - (date2_y)/100 + (date2_y)/4);
        else if (date2_m <= 2)
            sum_days2 += ( (date2_y-1)/400 - (date2_y-1)/100 + (date2_y-1)/4);
        
        return abs(sum_days1 - sum_days2);
        
    }
};