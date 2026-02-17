class Solution {
public:
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string> result;
    
        for (int hour = 0; hour < 12; ++hour) {

            for (int minute = 0; minute < 60; ++minute) {
                int hourBits = __builtin_popcount(hour);
                int minuteBits = __builtin_popcount(minute);
            
                if (hourBits + minuteBits == turnedOn) {
                    string timeString = to_string(hour) + ":" + 
                                       (minute < 10 ? "0" : "") + 
                                       to_string(minute);
                  
                    result.push_back(timeString);
                }
            }
        }
      
        return result;
        
    }
};