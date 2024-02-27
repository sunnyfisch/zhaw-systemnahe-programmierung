#include <stdio.h>
#include <stdlib.h>
#define NUM_ROWS 8

int main (void)
{
    (void) printf("Enter conversion rate (1.00 BTC -> CHF): ");
    double factor = 0;
    scanf("%lf", &factor);
    for (int i = 0; i <= NUM_ROWS; i = i + 1) {
        int amount = (i+1)*200;
        printf("%6i CHF\t\t<-->\t%4.5f BTC\n", amount, (amount/factor));
    }
    return EXIT_SUCCESS;
}
