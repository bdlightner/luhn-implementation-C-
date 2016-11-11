/* luhn.c - Luhn algorithm test program */

#include <stdio.h>

int check_number(char *number)
{
    int i, sum, ch, num, twoup;

    sum = 0;
    twoup = 0;
    for (i = strlen(number) - 1; i >= 0; --i) {
        ch = number[i];
        num = (ch >= '0' && ch <= '9') ? ch - '0' : 0;
        if (twoup) num += num;
        if (num > 9) num = (num / 10) + (num % 10);
        sum += num;
        twoup = ++twoup & 1;
    }
    sum = 10 - (sum % 10);
    if (sum == 10) sum = 0;
    return (sum == 0) ? 1 : 0;
}

int calc_digit(char *number)
{
    int i, sum, ch, num, twoup;

    sum = 0;
    twoup = 1;
    for (i = strlen(number) - 1; i >= 0; --i) {
        ch = number[i];
        num = (ch >= '0' && ch <= '9') ? ch - '0' : 0;
        if (twoup) num += num;
        if (num > 9) num = (num / 10) + (num % 10);
        sum += num;
        twoup = ++twoup & 1;
    }
    sum = 10 - (sum % 10);
    if (sum == 10) sum = 0;
    return sum;
}

main(int argc, char **argv)
{
    int ok, check_digit;
    char *number;

    if (argc <= 1) {
        printf("usage: %s number ...\n", *argv);
        exit(1);
    }
    while (--argc) {
        ++argv;
        number = *argv;
        ok = check_number(number);
        check_digit = calc_digit(number);
        printf("%s %s check\n", number, (ok) ? "passes" : "fails");
        printf("%s needs check-digit '%d'\n", number, check_digit);
    }
    exit(0);
}
