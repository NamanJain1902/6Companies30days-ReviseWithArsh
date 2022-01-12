
class Solution {
  public:
  
    // To store number of days in all months from January to Dec.
    const int monthDays[12] = {31, 28, 31, 30, 31, 30,
                               31, 31, 30, 31, 30, 31};
    // This function counts number of leap years before the 
    // given date
    
    int countLeapYears(int d, int m, int y) 
    {
        // Check if the current year needs to be considered 
        // for the count of leap years or not 
        if (m <= 2) 
            y--; 
      
        // An year is a leap year if it is a multiple of 4, 
        // multiple of 400 and not a multiple of 100. 
        return y / 4 - y / 100 + y / 400; 
    }
    
    // This function returns number of days between two given dates 
    int noOfDays(int d1, int m1, int y1, int d2, int m2, int y2) {
        // COUNT TOTAL NUMBER OF DAYS BEFORE FIRST DATE 'dt1' 
  
        // initialize count using years and day 
        int n1 = y1 * 365 + d1; 
      
        // Add days for months in given date 
        for (int i=0; i<m1 - 1; i++) 
            n1 += monthDays[i]; 

        // Since every leap year is of 366 days, 
        // Add a day for every leap year 
        n1 += countLeapYears(d1,m1,y1); 

        // SIMILARLY, COUNT TOTAL NUMBER OF DAYS BEFORE 'dt2' 
        int n2 = y2 * 365 + d2; 
        for (int i=0; i<m2 - 1; i++) 
            n2 += monthDays[i]; 
        n2 += countLeapYears(d2,m2,y2); 

        // return difference between two counts 
        return abs(n2 - n1); 
    }
};

