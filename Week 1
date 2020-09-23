#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int number;
    do{
        number = get_int("Press a positive number: ");
    }while(number<=0 || number>=10);
    for(int i=0; i<number; i++){
        for(int j=number-i-1; j>0; j--){
            printf(" ");
        }
        for(int k=0; k<=i; k++){
            printf("#");
        }
        printf("\n");
    }
}
