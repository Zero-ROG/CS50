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
        //len必须+1，因为ciphertext需要把plaintext最后的\0也复制进去，否则会出bug
    for(int i=0; i<len+1; i++){
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
