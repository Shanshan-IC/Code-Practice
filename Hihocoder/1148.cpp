#include <iostream>
#include <cstring>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    int startDay, endDay, startYear, endYear;
    char startMonth[20], endMonth[20];
    int i = 1;
    while (n--) {
        int count = 0;
        scanf("%s %d, %d", startMonth, &startDay, &startYear);
        scanf("%s %d, %d", endMonth, &endDay, &endYear);
        if (strcmp(startMonth, "February")!= 0 && strcmp(startMonth, "January")!= 0)
            startYear++;
        if ((strcmp(endMonth, "February")== 0 && endDay<29) || strcmp(endMonth, "January")== 0)
            endYear--;
        count = (endYear / 4 - endYear / 100 + endYear / 400) - (startYear / 4 - startYear / 100 + startYear / 400);
        if ((startYear%4==0 && startYear%100 !=0) || (startYear%400 ==0))
            count++;
        cout << "Case #" << i << ": " << count << endl;
        i++;
    }
    
    return 0;
}