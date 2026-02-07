#include <stdio.h>
#include <string.h>

#define KEY 4   // Secret shift value

// Function to encrypt the password
void encrypt(char password[]) {
    for (int i = 0; password[i] != '\0'; i++) {
        password[i] = password[i] + KEY;
    }
}

// Function to decrypt the password
void decrypt(char password[]) {
    for (int i = 0; password[i] != '\0'; i++) {
        password[i] = password[i] - KEY;
    }
}

int main() {
    char password[50];
    char loginPassword[50];
    char storedPassword[50];

    printf("=== Secure Password Protection System ===\n");

    // Create password
    printf("Create Password: ");
    scanf("%s", password);

    // Encrypt and store password
    strcpy(storedPassword, password);
    encrypt(storedPassword);

    printf("Encrypted Password Stored: %s\n", storedPassword);

    // Login process
    printf("\n--- Login ---\n");
    printf("Enter Password: ");
    scanf("%s", loginPassword);

    // Decrypt stored password for verification
    decrypt(storedPassword);

    if (strcmp(loginPassword, storedPassword) == 0) {
        printf("✅ Access Granted\n");
    } else {
        printf("❌ Access Denied\n");
    }

    return 0;
}
