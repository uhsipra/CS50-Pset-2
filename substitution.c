#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    string alpha[2]; // Stores the alphabet in an array
    alpha[0] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"; // Array of uppercase alphabetical letters
    alpha [1] = "abcdefghijklmnopqrstuvwxyz"; // Array of lowercase alphabetical letters
    string key[2]; // Will convert argv into 2 strings, one that is all capitals of the key and one that is all lower
    key[0] = alpha[0]; // Intializing key[0]
    key[1] = alpha[1]; // Intializing key[1]

    if (argc == 2)
    {
        if (strlen(argv[1]) != 26)
        {
            printf("Key is not valid: length is not 26\n");
            return 1;
        }

        for (int i = 0, n = strlen(argv[1]); i < n; i++)
        {
            if (argv[1][i] >= 'a' && argv[1][i] <= 'z') // Checks if any lowercase letters in the key
            {
                argv[1][i] = argv[1][i] - 32; // Converts any lowercase letter to uppercase

                if (argv[1][i] < 'A' ||  argv[1][i] > 'Z') // Checks to see if the key has any characters that are not letters of the alphabet
                {
                    printf("Key is not valid: Contains a non alphabetical character\n");
                    return 1;
                }
            }
            else if (argv[1][i] < 'A' ||  argv[1][i] > 'Z') // Checks to see if the key has any characters that are not letters of the alphabet
            {
                printf("Key is not valid: Contains a non alphabetical character\n");
                return 1;
            }
        }

        int checks = 0;
        for (int j = 0, m = strlen(argv[1]); j < m; j++) // Iterates once for every letter in the key array
        {
            for (int r = 0, k = strlen(argv[1]); r < k; r++) // Iterates onces for every letter in they key array again
            {
                if (argv[1][j] == argv[1][r]) // Comapres every letter in the key array to itself
                {
                    checks ++; // If there are duplicate letters in the key array then checks will be greater than the
                }              // length of the key array, if there are no duplicate letters then checks will be eqaul
            }                  // to the length of they key array. Since the length of they key array should be same as
        }                      // the alphabet, we can say if checks != 26 then there are duplicate letters in the key
        if (checks == 26)      // array.
        {
            printf("Success\n");
            printf("Alpha: %s\n", alpha[0]);
            printf("Key:   %s\n", argv[1]);
        }
        else
        {
            printf("The key does not contain every letter of the alphabet exactly once\n");
            printf("Letters of alphabet: %i\n", checks);
            return 1;
        }
    }
    else
    {
        printf("Key is not valid: More than 1 input\n");
        return 1;
    }

    string plntxt = get_string("plaintext: ");
    string cphrtxt = plntxt;

    for (int u = 0, w = strlen(plntxt); u < w; u++)
    {
        for (int k = 0, f = strlen(alpha[0]); k < f; k++)
        {
            if (plntxt[u] == alpha[0][k]) // Checks if any letters in plntxt are equal to any letters in capital alpha
            {
                cphrtxt[u] = argv[1][k]; // Switches the letter in the plntxt array to the corresponding letter in the "key" array
                k = 26; // Will make the second for loop stop and restart from the first for loop
            }
            else if (plntxt[u] == alpha[1][k]) // Checks if any letters in key are equal to any letters in lower alpha
            {
                argv[1][k] = argv[1][k] + 32; // Converts uppercase letters to lower case
                cphrtxt[u] = argv[1][k]; // Switches the letter in the plntxt array to the corresponding letter in the "key" array
                argv[1][k] = argv[1][k] - 32; // Converts any lowercase letter to uppercase
                k = 26;
            }
        }
    }

    printf("ciphertext: %s\n", cphrtxt);
    return 0;
}
