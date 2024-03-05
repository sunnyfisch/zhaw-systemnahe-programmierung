/**
 *  P02 Praktikum
 *
 *  Das Programm liest einen Monat (1-12) und ein Jahr (1600-2400) ein und
 *  gibt die Anzahl der Tage dieses Monats aus.
 *
 *  @author Gerrit Burkert, Adaptation bazz
 *  @version 15-FEB-2013, 16-OCT-2017, 17-OCT-2019, 16-FEB-2022
 */

#include <stdio.h>
#include <stdlib.h>

#define ERROR_IN_MONTH 1
#define ERROR_IN_YEAR 2

///// Student Code
enum month {JAN=1, FEB, MAR, APR, MAI, JUN, JUL, AUG, SEP, OKT, NOV, DEZ};

int gibIntWert(char* prompt, int start, int end) {
    int number;
    char input[50];
    do {
        printf("Input: %s", prompt);
        fgets(input, 5, stdin);
        number = atoi(input);
    } while (number < start && number > end);
    return number;
}

int istSchaltjahr(int jahr) {
    if ((jahr % 4) == 0 && (jahr % 100 != 0) ) {
        return 1;
    } else if ((jahr % 400 == 0)) {
        return 1;
    } else {
        return 0;
    }
}

int tageProMonat(int jahr, int monat) {
    switch (monat) {
        case JAN:
        case MAR:
        case MAI:
        case JUL:
        case AUG:
        case OKT:
        case DEZ:
            return 31;
        case FEB:
            return istSchaltjahr(jahr) ? 29 : 28;
        case APR:
        case JUN:
        case SEP:
        case NOV:
            return 30;
        default:
            return 0;
    }
}
///// END Student Code


int main (int argc, char *argv[]) {
    
    int monat, jahr;
     
    //  Monat einlesen und Bereich ueberpruefen
    monat = gibIntWert("Monat", 1, 12);
    jahr  = gibIntWert("Jahr", 1600, 9999);
	
    //  Ausgabe zum Test
    printf("Monat: %d, Jahr: %d \n", monat, jahr);    
    
    //  Ausgabe zum Test (hier mit dem ternaeren Operator "?:")
    printf("%d ist %s Schaltjahr\n", jahr, istSchaltjahr(jahr) ? "ein" : "kein");

    // Ausgabe
    printf("Der Monat %02d-%d hat %d Tage.\n", monat, jahr, tageProMonat(jahr, monat));
   
    return 0;
}
