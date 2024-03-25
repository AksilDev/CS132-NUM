#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define MAX 1000

int binaryToDecimal(int n) {
    int dec_value = 0;
    int base = 1;
    
    while (n) {
        int last_digit = n % 10;
        if (last_digit != 0 && last_digit != 1) {
            printf("Invalid binary input.\n");
            return -1; // invalid
        }
        n = n / 10;
        dec_value += last_digit * base;
        base = base * 2;
    }
    
    return dec_value;
}

int binaryToOctal(int n) {
    int dec_value = binaryToDecimal(n);
    if (dec_value == -1) //not valid input of binrrryy
        return -1;
    
    int oct = 0, i = 1;
    
    while (dec_value != 0) {
        oct += (dec_value % 8) * i;
        dec_value /= 8;
        i *= 10;
    }
    
    return oct;
}

void binaryToHexadecimal(int n) {
    int dec_value = binaryToDecimal(n);
    if (dec_value == -1) {
        printf("Invalid binary input.\n");
        return;
    }

    char hexa[MAX];
    int i = 0;
    
    while (dec_value != 0) {
        int temp = dec_value % 16;
        if (temp < 10) {
            hexa[i++] = temp + 48;
        } else {
            hexa[i++] = temp + 55;
        }
        dec_value /= 16;
    }

    printf("Hexadecimal: ");
    for (int j = i - 1; j >= 0; j--) {
        printf("%c", hexa[j]);
    }
    printf("\n");
}

void decimalToBinary(int n) {
    long long binary = 0;
    int remainder, base = 1;
    
    while (n > 0) {
        remainder = n % 2;
        binary += remainder * base;
        n /= 2;
        base *= 10;
    }
    
    printf("Binary: %lld\n", binary);
}

void decimalToOctal(int n) {
    int octal = 0, base = 1;
    
    while (n > 0) {
        octal += (n % 8) * base;
        n /= 8;
        base *= 10;
    }
    
    printf("Octal: %d\n", octal);
}

void decimalToHexadecimal(int n) {
    char hexa[MAX];
    int i = 0;
    
    while (n != 0) {
        int temp = n % 16;
        if (temp < 10) {
            hexa[i++] = temp + 48;
        } else {
            hexa[i++] = temp + 55;
        }
        n /= 16;
    }

    printf("Hexadecimal: ");
    for (int j = i - 1; j >= 0; j--) {
        printf("%c", hexa[j]);
    }
    printf("\n");
}

int octalToBinary(int n) {
    int dec_value = 0, base = 1;
    
    while (n) {
        int last_digit = n % 10;
        if (last_digit >= 8) {
            printf("Invalid octal input.\n");
            return -1; //if invaleeed
        }
        dec_value += last_digit * base;
        base *= 8;
        n /= 10;
    }

    decimalToBinary(dec_value);
    return 0;
}

int octalToDecimal(int n) {
    int dec_value = 0, base = 1;
    
    while (n) {
        int last_digit = n % 10;
        if (last_digit >= 8) {
            printf("Invalid octal input.\n");
            return -1; //invalid onleee
        }
        dec_value += last_digit * base;
        base *= 8;
        n /= 10;
    }

    return dec_value;
}

void octalToHexadecimal(int n) {
    int dec_value = octalToDecimal(n);
    if (dec_value == -1) {
        printf("Invalid octal input.\n");
        return;
    }

    decimalToHexadecimal(dec_value);
}

int hexadecimalToDecimal(char hex[]) {
    int len = strlen(hex);
    int base = 1;
    int dec = 0;

    for (int i = len - 1; i >= 0; i--) {
        if (hex[i] >= '0' && hex[i] <= '9') {
            dec += (hex[i] - '0') * base;
        } else if (hex[i] >= 'A' && hex[i] <= 'F') {
            dec += (hex[i] - 'A' + 10) * base;
        } else if (hex[i] >= 'a' && hex[i] <= 'f') {
            dec += (hex[i] - 'a' + 10) * base;
        }
        base *= 16;
    }

    return dec;
}

void hexadecimalToBinary(char hex[]) {
    int dec_value = hexadecimalToDecimal(hex);
    decimalToBinary(dec_value);
}

void hexadecimalToOctal(char hex[]) {
    int dec_value = hexadecimalToDecimal(hex);
    decimalToOctal(dec_value);
}

int main() {
    int first, second, n;
    char choice[MAX];
    while (1) {
        printf("Number Conversion System\nProgrammer: Axcel Macansantos\n\n");
        
        printf("1 for binary\t2 for decimal\n3 for octal\t\t4 for hexa\nEnter: ");
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
                    case 2:
                        printf("Decimal Value: %d\n", binaryToDecimal(n));
                        break;
                    case 3:
                        printf("Octal Value: %d\n", binaryToOctal(n));
                        break;
                    case 4:
                        binaryToHexadecimal(n);
                        break;
                    default:
                        printf("Invalid input\n");
                        break;
                }
                break;
            case 2:
                switch (second) {
                    case 1:
                        decimalToBinary(n);
                        break;
                    case 3:
                        decimalToOctal(n);
                        break;
                    case 4:
                        decimalToHexadecimal(n);
                        break;
                    default:
                        printf("Invalid input\n");
                        break;
                }
                break;
            case 3:
                switch (second) {
                    case 1:
                        octalToBinary(n);
                        break;
                    case 2:
                        printf("Decimal Value: %d\n", octalToDecimal(n));
                        break;
                    case 4:
                        octalToHexadecimal(n);
                        break;
                    default:
                        printf("Invalid input\n");
                        break;
                }
                break;
            case 4:
                char hex[MAX];
                printf("Enter hexadecimal number: ");
                scanf("%s", hex);
                switch (second) {
                    case 1:
                        hexadecimalToBinary(hex);
                        break;
                    case 2:
                        printf("Decimal: %d\n", hexadecimalToDecimal(hex));
                        break;
                    case 3:
                        hexadecimalToOctal(hex);
                        break;
                    default:
                        printf("Invalid input\n");
                        break;
                }
                break;
            default:
                printf("Invalid input\n");
                break;
        }

        printf("To exit type 'diliNAKO' ");
        scanf("%s", choice);

        if (strcmp(choice, "diliNAKO") == 0)
            break;
    }

    return 0;
}
