#include <stdio.h>
long long mod_pow(long long base, long long exp, long long mod) {
    long long result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}
long long encrypt(long long plaintext, long long e, long long n) {
    return mod_pow(plaintext, e, n);
}

int main() 
{
    long long n = 3233;
    long long e = 17;   
    long long plaintext = 123;
    long long ciphertext = encrypt(plaintext, e, n);
    printfprintf("\n192210189 harish\n------------------------------\n");
    printf("Plaintext: %lld\n", plaintext);
    printf("Ciphertext: %lld\n", ciphertext);
	return 0;
}
