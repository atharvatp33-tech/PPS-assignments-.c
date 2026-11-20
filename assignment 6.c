#include <stdio.h>
#include <stdlib.h>

#define BASE 1000000000ULL   /* each slot holds 9 decimal digits */

static void multiply(unsigned int *d, size_t *len, unsigned int m)
{
    unsigned long long carry = 0;

    for (size_t i = 0; i < *len; i++) {
        unsigned long long cur = (unsigned long long)d[i] * m + carry;
        d[i] = (unsigned int)(cur % BASE);
        carry = cur / BASE;
    }
    while (carry) {
        d[(*len)++] = (unsigned int)(carry % BASE);
        carry /= BASE;
    }
}

/* Without recursion */
static void factorial_iterative(unsigned int n, unsigned int *d, size_t *len)
{
    d[0] = 1;
    *len = 1;
    for (unsigned int i = 2; i <= n; i++)
        multiply(d, len, i);
}

/* With recursion */
static void factorial_recursive(unsigned int n, unsigned int *d, size_t *len)
{
    if (n <= 1) {
        d[0] = 1;
        *len = 1;
        return;
    }
    factorial_recursive(n - 1, d, len);
    multiply(d, len, n);
}

static void print_big(const unsigned int *d, size_t len)
{
    printf("%u", d[len - 1]);
    for (size_t i = len - 1; i-- > 0; )
        printf("%09u", d[i]);
    printf("\n");
}

int main(void)
{
    long long input;

    printf("Enter a non-negative integer: ");
    if (scanf("%lld", &input) != 1 || input < 0 || input > 1000000LL) {
        printf("Invalid input.\n");
        return 1;
    }
    unsigned int n = (unsigned int)input;

    size_t cap = (size_t)n + 2;
    unsigned int *d = (unsigned int *)malloc(cap * sizeof *d);
    if (!d) {
        printf("Not enough memory.\n");
        return 1;
    }
    size_t len;

    factorial_iterative(n, d, &len);
    printf("Iterative: %u! = ", n);
    print_big(d, len);

    factorial_recursive(n, d, &len);
    printf("Recursive: %u! = ", n);
    print_big(d, len);

    free(d);
    return 0;
}
