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
  int i = 0;

  while (hex[i] != '\0') {
    int c = toupper(hex[i]);
    if (c < '0' || (c > '9' && c < 'A') || c > 'F') {
      printf("Invalid hexadecimal digit %c\n", hex[i]);
      return;
    }

    int fourBit = 0;
    int j = 1;
    while (j <= 4) {
      fourBit += (c % 2) * j;
      c /= 2;
      j *= 2;
    }

    
    for (j = 4; j > 0; j--) {
      printf("%d", (fourBit >> (j - 1)) % 2);
    }

    i++;
  }
  printf("\n");
}

void hexadecimalToOctal(char hex[]) {
  int decimal = hexadecimalToDecimal(hex);
  if (decimal == -1) {
    printf("Invalid hexadecimal input.\n");
    return;
  }

  int octal = 0, base = 1;
  while (decimal != 0) {
    int remainder = decimal % 8;
    octal += remainder * base;
    decimal /= 8;
    base *= 10;
  }

  printf("%d\n", octal);
}


