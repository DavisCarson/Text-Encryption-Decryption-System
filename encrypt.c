// encrypt.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char keyArray[5][5] = {
    {'l', 'a', 'b', 'o', 'r'},
    {'c', 'd', 'e', 'f', 'g'},
    {'h', 'i', 'j', 'k', 'm'},
    {'n', 'p', 's', 't', 'u'},
    {'v', 'w', 'x', 'y', 'z'}
};

// Precompute positions for quick lookups during encryption
void buildCharMap(int map[26][2]) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            map[keyArray[i][j] - 'a'][0] = i;
            map[keyArray[i][j] - 'a'][1] = j;
        }
    }
}

// Encrypts a string using the keyArray cipher
char* encrypt(const char* s, int charMap[26][2]) {
    size_t sLen = strlen(s);
    char* encrypted_message = malloc(sLen * 2 + 1);
    if (!encrypted_message) {
        fprintf(stderr, "Memory allocation error.\n");
        exit(1);
    }

    for (size_t i = 0, pos = 0; i < sLen; i++) {
        int row = charMap[s[i] - 'a'][0];
        int col = charMap[s[i] - 'a'][1];
        encrypted_message[pos++] = '0' + row;
        encrypted_message[pos++] = '0' + col;
    }
    encrypted_message[sLen * 2] = '\0';

    return encrypted_message;
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Usage: %s <plaintext string>\n", argv[0]);
        return 1;
    }

    int charMap[26][2];
    buildCharMap(charMap);

    char* encrypted_message = encrypt(argv[1], charMap);
    printf("Encrypted Message: %s\n", encrypted_message);
    free(encrypted_message);
    return 0;
}
