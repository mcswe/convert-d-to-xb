/* 
AUTHOR: github.com/mcswe
DATE: JAN 24, 2021
PURPOSE: To convert a decimal value from stdin into its binary or hexidecimal representation, until
receiving an end-of-file signal.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void PrintBinary(unsigned x);
void PrintHex(unsigned x);

int main(int argc, char* argv[]) {
    while(!feof(stdin)) {
        char str[100];
        fgets(str, 100, stdin);
        unsigned x = atoi(str);
        
        if(feof(stdin)) {
            break;
        }
        //print hex
        if(strcmp(argv[1], "-x") == 0) {
            PrintHex(x);
        }
        // print binary
        if(strcmp(argv[1], "-b") == 0) {
            PrintBinary(x);
        }
    }
}

/* PURPOSE: this function takes in a decimal value and converts it to its binary equivalent */
void PrintBinary(unsigned x) {
    for (int i = 31; i >= 0; i--) {
        unsigned mask = 1; 
        unsigned y = x >> i;
        if(y & mask) {
            printf("1");
        }
        else {
            printf("0");
        }    
    }
    printf("\n");
}

/* PURPOSE: this function takes in a decimal value and converts it to its hexidecimal equivalent. */
void PrintHex(unsigned x) {
    char hex[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
    printf("0x");
    if(x==0) {
        printf("0");
    }
    else {
        int lead = 1; // detect leading zeros
        for (int i = 7; i >= 0; i--) {
            unsigned y = x >> i*4;
            unsigned mask = 15; // 15 will get the rightmost four bits --> 0000....1111
            unsigned group = mask & y;
            if(lead == 0 || group != 0) { // checks if value is a leading 0 or first instance of nonzero
            printf("%c", hex[group]);
            lead = 0;  
            } 
        }  
    }
    printf("\n");

}
