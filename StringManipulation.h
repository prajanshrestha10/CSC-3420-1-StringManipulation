/*
Name: Prajan Shrestha
Instructor Name: Dr. Visvasuresh Govindaswamy
Course: Data Structures and Algorithms - CSC-3420-1
Due Date: November 9, 2026
Description: It is a menu-driven C++ console application designed to introduce C-style 
            string manipulation using char* and the <cstring> library. 
            The program allows users to dynamically allocate memory (new[] and delete[]) 
            and perform various string operations—including comparing strings, 
            comparing up to $N$ characters, copying, appending, finding length, 
            and tokenizing/reversing word order—using standard library functions 
            like strcmp, strncmp, strcpy, strcat, strlen, and strtok.        
*/

#ifndef STRINGMANIPULATION_H
#define STRINGMANIPULATION_H

#include <iostream>
#include <string>
#include <cstring>
#include <limits>
using namespace std;

class StringManipulation {
    public:
        // Menu option functions
        int compareStrings(const char* str1, const char* str2);
        int compareNStrings(const char* str1, const char* str2, size_t n);
        char* copyString(const char* src);
        char* appendString(const char* str1, const char* str2);
        size_t getLength(const char* str);
        char* reverseWords(const char* str);
};

#endif