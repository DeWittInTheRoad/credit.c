/**
  *
  * credit.c
  *
  * Brandon DeWitt
  *
  * A program for validating credit card numbers.
  *
  */


#include <stdio.h>
#include <cs50.h>
int get_digits(long n);

int main(void)
{

long creditcard = 0;
int digits = 0;
int checksum = 0;

//378282246310005

do{
    printf("Enter credit card number: ");
    creditcard = get_long_long();
}
while (creditcard < 1);

// check to make sure card is a valid amount of digits.
digits = get_digits(creditcard);

if (digits < 13 || digits > 16){
    printf("INVALID\n");
}

// add numbers to an array
int card_numbers[digits];

 for (int i = digits-1; i > -1; i--){
    card_numbers[i] = creditcard%10;
    creditcard = creditcard/10;
}


for (int i = digits - 1; i > -1; i-=2){
    checksum += card_numbers[i]; //add odd numbers together;
   }
for (int i = digits - 2; i > -1; i-=2){
    int product = 0;
    product = (card_numbers[i]*2); //if even and >= 10 add product of digits together (IE: 10 is 1+0 = 1)
    if (product >= 10){
        checksum += product%10 + product/10;
    }
    else {
    checksum += (card_numbers[i]*2); //add even numbers together;
   }
}

//If last digit is a 0 card is valid, now check for card type AmEx is 15 digits start with 34 or 37, MasterCard 16 digits starts with 51-55, Visa 13 or 16 digits starting with 4.
    if ( (checksum)%10 == 0){
        if (digits == 15 && card_numbers[0] == 3 && (card_numbers[1] == 4 || card_numbers[1] == 7 )) printf("AMEX\n");
        else if (digits == 16 && card_numbers[0] == 5 && (card_numbers[1] >= 1 && card_numbers[1] <= 5 )) printf("MASTERCARD\n");
        else if ( (digits == 13 || digits ==16) && card_numbers[0] == 4 ) printf("VISA\n");
        else {
          printf("INVALID\n");
        }
    }
        else {
            printf("INVALID\n");
        }



}

// Find digit amount without breaking down the original credit card variable.
int get_digits(long n){

    int digits = 0;
    while (n > 0){
    n/=10;
    digits++;
}

return digits;
}




