#include <stdlib.h>
#include <string.h>

char* convert(char* s, int numRows) {
    if (numRows == 1 || numRows >= strlen(s))
        return s;

    int len = strlen(s);
    char* result = (char*)malloc((len + 1) * sizeof(char));
    int index = 0;
    int cycleLen = 2 * numRows - 2;

    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j + i < len; j += cycleLen) {
            result[index++] = s[j + i];
            if (i != 0 && i != numRows - 1 && j + cycleLen - i < len)
                result[index++] = s[j + cycleLen - i];
        }
    }

    result[index] = '\0';
    return result;
}
