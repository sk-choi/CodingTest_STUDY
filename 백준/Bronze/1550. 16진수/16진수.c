//#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

int check_index(char hex)
{
    char arr[17] = "0123456789ABCDEF";
    int j = 0;
    while (j < strlen(arr))
    {
        if (hex == arr[j])
            return j;
        else
            j++;
    }
}

int hex_to_dec(char *hex)
{
    int i = 0;
    int result = 0;
    while (i < strlen(hex))
    {
        result *= 16;
        result += check_index(hex[i]);
        i++;
    }
    return result;
}

int main() {
    char hex[7];
    scanf("%s", hex);
    printf("%d", hex_to_dec(hex));
    return 0;
}