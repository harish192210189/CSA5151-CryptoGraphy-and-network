#include <stdio.h>
#include <stdlib.h>
#include <math.h>
unsigned long long mod_exp(unsigned long long base, unsigned long long exp, unsigned long
long modulus) {
 unsigned long long result = 1;
 base %= modulus;
 while (exp > 0) {
 if (exp & 1) {
 result = (result * base) % modulus;
 }
 base = (base * base) % modulus;
 exp >>= 1;
 }
 return result;
}
unsigned long long encrypt(unsigned long long character, unsigned long long e, unsigned long
long n) {
 return mod_exp(character, e, n);
}
int main() {
 unsigned long long p, q, n, phi, e, character;
 char message[1000];
 p = 9973; // Example prime numbers (should be much larger in practice)
 q = 9857;
 n = p * q;
 phi = (p - 1) * (q - 1);
 e = 65537;
 int i;
 printf("\n192210189 harish\n------------------------------\n");
 printf("Enter the message (all uppercase letters without spaces): ");
 scanf("%s", message);
 printf("Encrypted message: ");
 for ( i = 0; message[i] != '\0'; i++) {
 character = message[i] - 'A'; // Convert character to number (A=0, B=1, ..., Z=25)
 unsigned long long encrypted_char = encrypt(character, e, n);
 printf("%llu ", encrypted_char);
 }
 printf("\n");
 return 0;}
 
