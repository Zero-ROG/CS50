#include <stdio.h>
#include <string.h>

int main()
{
    int n;
    char plaintext[99];
    char ciphertext[99];

    scanf("%d", &n);
    getchar();
    printf("plaintext: ");
    scanf("%[^\n]", plaintext);

        int len = strlen(plaintext);
    for(int i=0; i<strlen(plaintext); i++){
        if(plaintext[i] > 64 && plaintext[i] < 91){
            ciphertext[i] = (char)(((plaintext[i] - 65 + n) % 26) + 65);
        }
        else if(plaintext[i] > 96 && plaintext[i] < 123){
            ciphertext[i] = (char)(((plaintext[i] - 97 + n) % 26) + 97);
        }
        else{
            ciphertext[i] = plaintext[i];
        }
    }

    printf("ciphertext: %s\n", ciphertext);
    return 0;
}
