#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    unsigned int p; 
    unsigned int q; 
    unsigned int g;
    unsigned int x;
    unsigned int y;
} DSAParams;

typedef struct {
    unsigned int r;
    unsigned int s;
} DSASignature;

unsigned int mod_exp(unsigned int base, unsigned int exp, unsigned int mod) {
    unsigned int result = 1;
    base = base % mod;
    while (exp > 0) {
        if (exp % 2 == 1)
            result = (result * base) % mod;
        exp = exp >> 1;
        base = (base * base) % mod;
    }
    return result;
}

DSASignature dsa_sign(const char *message, DSAParams *params) {
    DSASignature signature;

    unsigned int k = rand() % (params->q - 1) + 1; 
    unsigned int r = mod_exp(params->g, k, params->p) % params->q;

    
    unsigned int z = atoi(message);

    unsigned int k_inverse = 1;
    while ((k * k_inverse) % params->q != 1) {
        k_inverse++;
    }

    unsigned int s = (k_inverse * (z + params->x * r)) % params->q;

    signature.r = r;
    signature.s = s;

    return signature;
}

int dsa_verify(const char *message, DSASignature *signature, DSAParams *params) {
    unsigned int w, u1, u2, v;


    unsigned int z = atoi(message);

    unsigned int s_inverse = 1;
    while ((signature->s * s_inverse) % params->q != 1) {
        s_inverse++;
    }

    u1 = (z * s_inverse) % params->q;
    u2 = (signature->r * s_inverse) % params->q;

    v = (mod_exp(params->g, u1, params->p) * mod_exp(params->y, u2, params->p) % params->p) % params->q;

    return v == signature->r;
}

int main() {
    DSAParams params;
    params.p = 23; 
    params.q = 11; 
    params.g = 2;  
    params.x = 6;
    params.y = mod_exp(params.g, params.x, params.p); 

    const char *message = "15"; 


    DSASignature signature = dsa_sign(message, &params);
 printf("\n192210189 harish\n------------------------------\n");

    
    if (dsa_verify(message, &signature, &params)) {
        printf("DSA Signature verified successfully!\n");
    } else {
        printf("DSA Signature verification failed!\n");
    }

    return 0;
}
