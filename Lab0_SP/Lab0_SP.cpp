#include <stdio.h>
#include <stdbool.h>
#include <limits.h>
#include <float.h>

void printChar() {
    printf("The minimum value of CHAR = %d\n", CHAR_MIN);
    printf("The maximum value of CHAR = %d\n", CHAR_MAX);
    printf("The size of CHAR          = %d\n\n", sizeof(char));

    printf("The minimum value of SIGNED CHAR = %d\n", SCHAR_MIN);
    printf("The maximum value of SIGNED CHAR = %d\n", SCHAR_MAX);
    printf("The size of SIGNED CHAR          = %d\n\n", sizeof(signed char));

    printf("The minimum value of UNSIGNED CHAR = %d\n", 0);
    printf("The maximum value of UNSIGNED CHAR = %d\n", UCHAR_MAX);
    printf("The size of UNSIGNED CHAR          = %d\n\n", sizeof(unsigned char));
}

void printShort() {
    printf("The minimum value of SHORT = %d\n", SHRT_MIN);
    printf("The maximum value of SHORT = %d\n", SHRT_MAX);
    printf("The size of SHORT          = %d\n\n", sizeof(short));

    printf("The minimum value of UNSIGNED SHORT = %d\n", 0);
    printf("The maximum value of UNSIGNED SHORT = %d\n", USHRT_MAX);
    printf("The size of UNSIGNED SHORT          = %d\n\n", sizeof(unsigned short));
}

void printInt() {
    printf("The minimum value of INT = %d\n", INT_MIN);
    printf("The maximum value of INT = %d\n", INT_MAX);
    printf("The size of INT          = %d\n\n", sizeof(int));

    printf("The minimum value of UNSIGNED INT = %u\n", 0);
    printf("The maximum value of UNSIGNED INT = %u\n", UINT_MAX);
    printf("The size of UNSIGNED INT          = %d\n\n", sizeof(unsigned int));
}

void printLong() {
    printf("The minimum value of LONG = %li\n", LONG_MIN);
    printf("The maximum value of LONG = %li\n", LONG_MAX);
    printf("The size of LONG          = %d\n\n", sizeof(long));

    printf("The minimum value of UNSIGNED LONG = %lu\n", 0);
    printf("The maximum value of UNSIGNED LONG = %lu\n", ULONG_MAX);
    printf("The size of UNSIGNED LONG          = %d\n\n", sizeof(unsigned long));

    printf("The minimum value of LONG LONG = %lli\n", LLONG_MIN);
    printf("The maximum value of LONG LONG = %lli\n", LLONG_MAX);
    printf("The size of LONG LONG          = %d\n\n", sizeof(long long));

    printf("The minimum value of UNSIGNED LONG LONG = %llu\n", 0);
    printf("The maximum value of UNSIGNED LONG LONG = %llu\n", ULLONG_MAX);
    printf("The size of UNSIGNED LONG LONG          = %d\n\n", sizeof(unsigned long long));
}

void printFloat() {
    printf("The minimum value of FLOAT = %f\n", FLT_MIN);
    printf("The maximum value of FLOAT = %f\n", FLT_MAX);
    printf("The size of FLOAT          = %d\n\n", sizeof(float));
}

void printDouble() {
    printf("The minimum value of DOUBLE = %f\n", DBL_MIN);
    printf("The maximum value of DOUBLE = %f\n", DBL_MAX);
    printf("The size of DOUBLE          = %d\n\n", sizeof(double));

    printf("The minimum value of LONG DOUBLE = %Lf\n", LDBL_MIN);
    printf("The maximum value of LONG DOUBLE = %Lf\n", LDBL_MAX);
    printf("The size of LONG DOUBLE          = %d\n\n", sizeof(long double));
}

void printBool() {
    printf("The minimum value of BOOL(false) = %d\n", false);
    printf("The maximum value of BOOL(true)  = %d\n", true);
    printf("The size of BOOL                 = %d\n\n", sizeof(bool));
}

int main(void) {
    printChar();
    printShort();
    printInt();
    printLong();
    printFloat();
    printDouble();
    printBool();
}