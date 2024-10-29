// decrypt.c
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char keyArray[5][5] = {
    {'l', 'a', 'b', 'o', 'r'},
    {'c', 'd', 'e', 'f', 'g'},
    {'h', 'i', 'j', 'k', 'm'},
    {'n', 'p', 's', 't', 'u'},
    {'v', 'w', 'x', 'y', 'z'}
};

// Decrypts a string using the keyArray cipher
char* decrypt(const char* s) {
    size_t sLen = strlen(s);
    if (sLen % 2 != 0) {
        fprintf(stderr, "Invalid encrypted string length.\n");
        return NULL;
    }

    char* decrypted_message = malloc(sLen / 2 + 1);
    if (!decrypted_message) {
        fprintf(stderr, "Memory allocation error.\n");
        exit(1);
    }

    for (size_t i = 0, j = 0; i < sLen; i += 2) {
        int row = s[i] - '0';
        int col = s[i + 1] - '0';
        decrypted_message[j++] = keyArray[row][col];
    }
    decrypted_message[sLen / 2] = '\0';

    return decrypted_message;
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Usage: %s <encrypted string>\n", argv[0]);
        return 1;
    }

    char* decrypted_message = decrypt(argv[1]);
    if (decrypted_message) {
        printf("Decrypted Message: %s\n", decrypted_message);
        free(decrypted_message);
    } else {
        printf("Error: Decryption failed.\n");
    }

    return 0;
}
