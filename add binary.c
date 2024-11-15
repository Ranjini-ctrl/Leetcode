char* addBinary(char* a, char* b)
{
    int lenA = strlen(a);
    int lenB = strlen(b);
    int maxLen = lenA > lenB ? lenA : lenB;
    int carry = 0;
    char* result = (char*)malloc(maxLen + 2);
    if (!result) {
        perror("malloc failed");
        return NULL;
         }

    result[maxLen + 1] = '\0'; 
    int i = lenA - 1;
    int j = lenB - 1;
    int k = maxLen;

    while (i >= 0 || j >= 0 || carry > 0) {
        int bitA = (i >= 0) ? a[i] - '0' : 0;
        int bitB = (j >= 0) ? b[j] - '0' : 0;
        int sum = bitA + bitB + carry;

        result[k] = (sum % 2) + '0'; 
        carry = sum / 2;            

        i--;
        j--;
        k--;
    }
    if (k >= 0) {
        memmove(result, result + 1, maxLen + 1);
    }
    return result;
}
