*******************************************************************************/
#include <stdio.h>
#include <math.h>

// Binary to Decimal
int binaryToDecimal(long long binary) {
	int decimal = 0, i = 0;

	while (binary != 0) {
		int remainder = binary % 10;  
		binary /= 10;                 
		decimal += remainder * pow(2, i); 
		i++;
	}

	return decimal;
}

// Decimal to Binary
long long decimalToBinary(int decimal) {
	long long binary = 0;
	int i = 1;
	while (decimal != 0) {
		binary += (decimal % 2) * i;
		decimal /= 2;
		i *= 10;
	}
	return binary;
}

// Decimal to Hexadecimal
void decimalToHexadecimal(int decimal) {
	printf("%X", decimal); 
}

// Hexadecimal to Decimal
int hexadecimalToDecimal(char hex[]) {
	int decimal = 0;
	sscanf(hex, "%x", &decimal); 
	return decimal;
}

// Binary to Hexadecimal
void binaryToHexadecimal(long long binary) {
	int decimal = binaryToDecimal(binary);
	decimalToHexadecimal(decimal);
}

// Hexadecimal to Binary
void hexadecimalToBinary(char hex[]) {
	int decimal = hexadecimalToDecimal(hex);
	printf("%lld", decimalToBinary(decimal));
}

int main() {
    int n;
    long long binary;
    int decimal;
    char hex[20];
	printf(" Binary to Decimal - 1 \n Decimal to Binary - 2 \n Decimal to Hexadecimal - 3 \n Hexadecimal to Decimal - 4 \n Binary to Hexadecimal - 5 \n Hexadecimal to Binary - 6  \n Enter a Code :   ");
	scanf("%d",&n);

	if (n == 1) {
        printf("Enter a Binary: ");
        scanf("%lld", &binary);
        printf("Decimal: %d\n", binaryToDecimal(binary));
    } else if (n == 2) {
        printf("Enter a Decimal: ");
        scanf("%d", &decimal);
        printf("Binary: %lld\n", decimalToBinary(decimal));
    } else if (n == 3) {
        printf("Enter a Decimal: ");
        scanf("%d", &decimal);
        printf("Hexadecimal: ");
        decimalToHexadecimal(decimal);
        printf("\n");
    } else if (n == 4) {
        printf("Enter a Hexadecimal: ");
        scanf("%s", hex);
        printf("Decimal: %d\n", hexadecimalToDecimal(hex));
    } else if (n == 5) {
        printf("Enter a Binary: ");
        scanf("%lld", &binary);
        printf("Hexadecimal: ");
        binaryToHexadecimal(binary);
        printf("\n");
    } else if (n == 6) {
        printf("Enter a Hexadecimal: ");
        scanf("%s", hex);
        printf("Binary: ");
        hexadecimalToBinary(hex);
        printf("\n");
    } else {
        printf("Invalid Code\n");
    }

    return 0;
}
