# Text Encryption & Decryption System

This repository contains C programs to encrypt and decrypt messages using a custom cipher grid based on a Playfair-like matrix. The system consists of two main components, `encrypt.c` and `decrypt.c`.

## How It Works

The encryption and decryption are based on a predefined 5x5 character matrix. The characters in the plaintext message are transformed into a sequence of grid coordinates that act as the encrypted message, which can then be reversed during decryption.

### Key Features

#### Custom Cipher Grid
- The cipher uses a 5x5 matrix (`keyArray`) filled with alphabet letters. Each character in the message is mapped to its row and column position within this grid, converting it to numeric coordinates during encryption.

#### Quick Lookup Table
- A character map is precomputed for faster access to row and column positions within the grid, significantly speeding up the encryption process.

#### Memory Management
- Both encryption and decryption functions allocate memory dynamically, ensuring optimal resource use during runtime.

## File Overview

### `encrypt.c`
- **`buildCharMap`**: Constructs a map for quick lookups, storing the grid positions of each letter.
- **`encrypt`**: Converts each character of the plaintext into grid coordinates, producing a numeric string as the encrypted message.
- **`main`**: Reads a plaintext message, encrypts it, and prints the result.

### `decrypt.c`
- **`decrypt`**: Reverses the encryption by mapping each coordinate pair back to the corresponding character in the cipher grid.
- **`main`**: Reads an encrypted message, decrypts it, and displays the original text.

### `Makefile`
- Contains commands for compiling both `encrypt` and `decrypt` programs, as well as cleaning up binary files.

## Example Run

To run the encryption and decryption:
1. Clone the repository.
2. Compile and execute using `make run`.

#### Example:
```bash
make
./encrypt attackatdawn
# Output: Encrypted Message: 013333011023013311014130
./decrypt 013333011023013311014130
# Output: Decrypted Message: attackatdawn
```

## Future Improvements
- Extend to handle punctuation and spaces for general text encryption.
- Implement a user-configurable cipher grid for added security.

## Authors
- Davis Carson
- Matthew Ray
