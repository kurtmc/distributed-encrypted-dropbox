#include <openssl/evp.h>

unsigned char *aes_encrypt(EVP_CIPHER_CTX *e, unsigned char *plaintext, int *len);
unsigned char *aes_decrypt(EVP_CIPHER_CTX *e, unsigned char *ciphertext, int *len);
int generate_keys(EVP_CIPHER_CTX *de, EVP_CIPHER_CTX *en);
