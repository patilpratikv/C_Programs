#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef unsigned char BYTE;

int main ()
{
    int i, first_digit, second_digit, j, XOR_of_digits, loop_count, new_count;
    char buffer [33], new_val[33];
    new_count = 32;
    // Enter integer number as input
    printf ("Enter a number: ");
    scanf ("%d",&i);
    // Convert integer to binary number
    itoa (i,buffer,2);
    // display binary number
    printf ("Old Binary: %s\n",buffer);
    // COunt number of two bit pairs
    loop_count = ceil(strlen(buffer)/2);
    // loop though pair of two bits starting from rightmost bits
    for (j = 0; j <= loop_count; j++){
        // mask right most bits in byte
        first_digit = i & 0x0001;
        // mask second right most bit in byte
        second_digit = (i>>1) & 0x0001;
        // XOR those two bits
        XOR_of_digits = first_digit ^ second_digit;
        // If XOR is 1 that means those two bits are different
        if (XOR_of_digits){
            // Append the new bits to variable new_val
            //printf("Digits are different\n");
            if (first_digit){
                new_val[new_count] = '0';
                new_count--;
                new_val[new_count] = '1';
                new_count--;
            }
            else{
                new_val[new_count] = '1';
                new_count--;
                new_val[new_count] = '0';
                new_count--;
            }
        }
        // If XOR is 0 that means those two bits are same
        else{
            // Append the new bits to variable new_val
            //printf("Digits are same\n");
            if (first_digit){
                new_val[new_count] = '1';
                new_count--;}
            else{
                new_val[new_count] = '0';
                new_count--;
            }
            if (second_digit){
                new_val[new_count] = '1';
                new_count--;
            }
            else{
                new_val[new_count] = '0';
                new_count--;
            }
        }
        // Get rid of 2 rightmost bits and consider next 2 rightmost bits.
        i >>= 2;
    }
    i = new_count + 1;
    // Display new bits
    printf("New Binary:");
    for(j = i; j <= 32; j++){
        printf("%c", new_val[j]);
    }
    return 0;
}
