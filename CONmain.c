#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define MAX 1000

int binaryToDecimal(int n);
int binaryToOctal(int n);
void binaryToHexadecimal(int n);

void decimalToBinary(int n);
void decimalToOctal(int n);
void decimalToHexadecimal(int n);

int octalToBinary(int n);
int octalToDecimal(int n);
void octalToHexadecimal(int n);

int hexadecimalToDecimal(char hex[]);
void hexadecimalToBinary(char hex[]);
void hexadecimalToOctal(char hex[]);

int main() {
    int first, second, n;
    char choice[MAX];
    while (1) {
        printf("Number Conversion System\nProgrammer: Axcel Macansantos\n\n");
        
        printf("1 for binary\t2 for decimal\n3 for octal\t4 for hexa\nEnter: ");
        scanf("%d", &first);

        switch (first) {
            case 1: printf("Base =  BINARY\n\n"); break;
            case 2: printf("Base =  DECIMAL\n\n"); break;
            case 3: printf("Base =  OCTAL\n\n"); break;
            case 4: printf("Base =  HEXA\n\n"); break;
            default: printf("Invalid input\n"); continue;
        }

        printf("\n1 to binary\t\t2 to decimal\n3 to octal\t\t4 to hexa\nEnter: ");
        scanf("%d", &second);

        switch (second) {
            case 1: printf("Conversion to BINARY\n\n"); break;
            case 2: printf("Conversion to DECIMAL\n\n"); break;
            case 3: printf("Conversion to OCTAL\n\n"); break;
            case 4: printf("Conversion to HEXA\n\n"); break;
            default: printf("Invalid input\n"); continue;
        }

        printf("Enter the number: ");
        scanf("%d", &n);

        switch (first) {
            case 1:
                switch (second) {
                    case 2:printf("Decimal Value: %d\n", binaryToDecimal(n));break;
                    case 3:printf("Octal Value: %d\n", binaryToOctal(n));break;
                    case 4:binaryToHexadecimal(n);break;
                    default:printf("Invalid input\n");break;
                }
                break;
            case 2:
                switch (second) {
                    case 1:decimalToBinary(n);break;
                    case 3:decimalToOctal(n);break;
                    case 4:decimalToHexadecimal(n);break;
                    default:printf("Invalid input\n");break;
                }
                break;
            case 3:
                switch (second) {
                    case 1:octalToBinary(n);break;
                    case 2:printf("Decimal Value: %d\n", octalToDecimal(n));break;
                    case 4:octalToHexadecimal(n);break;
                    default:printf("Invalid input\n");break;
                }
                break;
            case 4:
                
                printf("Enter hexadecimal number: ");
                char hex[MAX];
                scanf("%s", hex);
                
                switch (second) {
                    case 1:hexadecimalToBinary(hex);break;
                    case 2:printf("Decimal: %d\n", hexadecimalToDecimal(hex));break;
                    case 3:hexadecimalToOctal(hex);break;
                    default:printf("Invalid input\n");break;
                }
                break;
            default:printf("Invalid input\n");break;
        }

        printf("To exit type 'EXIT' ");
        scanf("%s", choice);

        if (strcmp(choice, "EXIT") == 0)
            break;
    }

    return 0;
}
