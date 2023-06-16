#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
 * main - Generate a key based on a username for crackme5
 * @argc: Number of arguments
 * @argv: Arguments
 * Return: 0 on success, 1 on error
 */
int main(int argc, char *argv[])
{
    unsigned int i, sum, prod, rands, sum_sqr;
    size_t len;
    char *charset = "A-CHRDw87lNS0E9B2TibgpnMVys5XzvtOGJcYLU+4mjW6fxqZeF3Qa1rPhdKIouk";
    char key[7] = "      ";
    unsigned char m_char;

    if (argc != 2)
    {
        printf("Correct usage: ./keygen5 username\n");
        return (1);
    }

    len = strlen(argv[1]);

    key[0] = charset[(len ^ 59) & 63];

    for (i = 0, sum = 0; i < len; i++)
        sum += argv[1][i];

    key[1] = charset[(sum ^ 79) & 63];

    for (i = 0, prod = 1; i < len; i++)
        prod *= argv[1][i];

    key[2] = charset[(prod ^ 85) & 63];

    m_char = (unsigned char)argv[1][0];
    for (i = 0; i < len; i++)
        if ((unsigned char)argv[1][i] >= m_char)
            m_char = (unsigned char)argv[1][i]; 

    srand(m_char ^ 14);
    key[3] = charset[rand() & 63];

    for (i = 0, sum_sqr = 0; i < len; i++)
        sum_sqr += argv[1][i] * argv[1][i];

    key[4] = charset[(sum_sqr ^ 239) & 63];

    for (i = 0, rands = 0; (char)i < argv[1][0]; i++)
        rands = rand();

    key[5] = charset[(rands ^ 229) & 63];

    printf("%s\n", key);

    return (0);
}

