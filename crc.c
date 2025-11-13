#include <stdio.h>
#include <string.h>

// Function to calculate CRC
unsigned int crc(char *data, unsigned int polynomial, int bits) {
    unsigned int crc = 0;
    int i, j;

    // Iterate over each byte in data
    for (i = 0; i < strlen(data); i++) {
        crc ^= (unsigned int)data[i] << (bits - 8);
        for (j = 0; j < 8; j++) {
            if (crc & (1 << (bits - 1))) {
                crc = (crc << 1) ^ polynomial;
            } else {
                crc <<= 1;
            }
        }
    }

    return crc;
}

int main() {
    // Define polynomials
    unsigned int crc12_poly = 0x180F;  // x^12 + x^11 + x^3 + x^2 + x + 1
    unsigned int crc16_poly = 0x8005;  // x^16 + x^15 + x^2 + 1
    unsigned int crc_ccip_poly = 0x1021;  // x^16 + x^12 + x^5 + 1

    // Test data
    char data[] = "Hello, World!";

    // Calculate CRCs
    unsigned int crc12 = crc(data, crc12_poly, 12);
    unsigned int crc16 = crc(data, crc16_poly, 16);
    unsigned int crc_ccip = crc(data, crc_ccip_poly, 16);

    printf("CRC-12: 0x%03X\n", crc12);
    printf("CRC-16: 0x%04X\n", crc16);
    printf("CRC-CCIP: 0x%04X\n", crc_ccip);

    return 0;
}
