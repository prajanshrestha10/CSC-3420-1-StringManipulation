#include "StringManipulation.h"

int StringManipulation::compareStrings(const char* str1, const char* str2) {
    return strcmp(str1, str2);
}

int StringManipulation::compareNStrings(const char* str1, const char* str2, size_t n) {
    return strncmp(str1, str2, n);
}

char* StringManipulation::copyString(const char* src) {
    size_t len = strlen(src);
    char* dest = new char[len + 1];
    strcpy(dest, src);
    return dest;
}

char* StringManipulation::appendString(const char* str1, const char* str2) {
    size_t len1 = strlen(str1);
    size_t len2 = strlen(str2);
    char* result = new char[len1 + len2 + 1];
    strcpy(result, str1);
    strcat(result, str2);
    return result;
}

size_t StringManipulation::getLength(const char* str) {
    return strlen(str);
}

char* StringManipulation::reverseWords(const char* str) {
    size_t len = strlen(str);
    if (len == 0) {
        char* emptyStr = new char[1];
        emptyStr[0] = '\0';
        return emptyStr;
    }

    // Work on a dynamically allocated copy since strtok modifies the string
    char* tempCopy = new char[len + 1];
    strcpy(tempCopy, str);

    // Array of pointers to hold individual tokens
    char** tokens = new char*[len + 1];
    int count = 0;

    char* token = strtok(tempCopy, " \t\n\r");
    while (token != nullptr) {
        tokens[count++] = token;
        token = strtok(nullptr, " \t\n\r");
    }

    // Allocate buffer for the result string
    char* result = new char[len + 1];
    result[0] = '\0';

    // Build the reversed word string
    for (int i = count - 1; i >= 0; --i) {
        strcat(result, tokens[i]);
        if (i > 0) {
            strcat(result, " ");
        }
    }

    // Clean up temporary dynamically allocated buffers
    delete[] tokens;
    delete[] tempCopy;

    return result;
}