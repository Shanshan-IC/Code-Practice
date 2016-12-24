#include <iostream>
#include <iomanip> 

using namespace std;

int main() {
    int cash;
    float num;
    scanf("%d", &cash);
    scanf("%f", &num);
    if (cash > num-0.5 || (cash%5 != 0))
        printf("%.2f\n", num);
    else
        printf("%.2f\n", num-cash-0.5);
    
    return 0;
}