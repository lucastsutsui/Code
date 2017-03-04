/*
Functions to deal with dates
*/

int monthN[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
int monthL[12] = {31,29,31,30,31,30,31,31,30,31,30,31};
int accN[13] = {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365};
int accL[13] = {0, 31, 60, 91, 121, 152, 182, 213, 244, 274, 305, 335, 366};

/*
Check if a year is leap
*/
bool isLeap (int n){
    return (n%4 == 0 && (n%100 != 0 || n%400 == 0));
}

/*
Find the date after passing n days
*/
void nDaysAfter (int n, int &d, int &m, int &y){
    n += d-1;
    d = 1;
    if (isLeap(y)){ n += accL[m-1]; m = 1; }
    else { n += accN[m-1]; m = 1; }
        
    while (n){
        if (isLeap(y)){
            if (n >= 366){ n -= 366; y++; }
            else if (n >= monthL[m-1]){ n -= monthL[m-1]; m++; }
            else { d += n; n = 0; }
        }
        else {
            if (n >= 365){ n -= 365; y++; }
            else if (n >= monthN[m-1]){ n -= monthN[m-1]; m++; }
            else { d += n; n = 0; }
        }
    }
}
