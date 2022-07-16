#include <iostream>
using namespace std;

// Complete Tokenisation function
// Remove the cout sum in compare functions

char* myStrCopy(char* s1Ptr, const char* s2Ptr)           // Working
{
    for(int i = 0; i < 50; i++)
    {
        s1Ptr[i] = s2Ptr[i];
    } 

    return s1Ptr;
}

char* myStrNumCopy(char* s1Ptr, const char* s2Ptr, int n) // Working
{
    for (int i = 0; i < n; i++)
    {
        s1Ptr[i] = s2Ptr[i];
    }

    return s1Ptr;
}

char* myStrCat(char* s1Ptr, const char* s2Ptr)            // Working 
{
    int i = 0;
    char arr[100];

    while (s1Ptr[i] != '\0')
    {
        arr[i] = s1Ptr[i];
        i++;
    }

    int k = i;
    i = 0;

    while (s2Ptr[i] != '\0')
    {
        arr[k] = s2Ptr[i];
        i++;
        k++;
    }
    
    arr[k] = '\0';

    // s1Ptr = arr;             // Check why doesn't this work
    
    i = 0;
    
    while (arr[i] != '\0')
    {
        s1Ptr[i] = arr[i];
        i++;
    }

    s1Ptr[i] = '\0';

    return s1Ptr;
}

char* myStrNumCat(char* s1Ptr, const char* s2Ptr, int n)  // Working 
{
    int i = 0;
    char arr[100];

    while (s1Ptr[i] != '\0')
    {
        arr[i] = s1Ptr[i];
        i++;
    }

    int k = i;
    i = 0;

    while (i != n)
    {
        arr[k] = s2Ptr[i];
        i++;
        k++;
    }
    
    arr[k] = '\0';

    // s1Ptr = arr;             // Check why doesn't this work
    
    i = 0;
    
    while (arr[i] != '\0')
    {
        s1Ptr[i] = arr[i];
        i++;
    }

    s1Ptr[i] = '\0';

    return s1Ptr;
}

int myStrComp(const char* s1Ptr, const char* s2Ptr)       // Working 
{
    int sumS1 = 0, sumS2 = 0;

    for (int i = 0; s1Ptr[i] != '\0'; i++)
    {
        sumS1 += int(s1Ptr[i]);
    }
        cout << "Sum s1: " << sumS1 << endl;       // Remove in the end

    for (int i = 0; s2Ptr[i] != '\0'; i++)
    {
        sumS2 += int(s2Ptr[i]);
    }
        cout << "Sum s2: " << sumS2 << endl;        // Remove in the end

    if (sumS1 == sumS2)
        return 0;

    else if (sumS1 > sumS2)
        return 1;

    else
        return -1;
    
}

int myStrNumComp(const char* s1Ptr, const char* s2Ptr, int n)   // Working
{
    int sumS1 = 0, sumS2 = 0;

    for (int i = 0; i < n; i++)
    {
        sumS1 += int(s1Ptr[i]);
    }
        cout << "Sum s1: " << sumS1 << endl;        // Remove in the end

    for (int i = 0; s2Ptr[i] != '\0'; i++)
    {
        sumS2 += int(s2Ptr[i]);
    }
        cout << "Sum s2: " << sumS2 << endl;        // Remove in the end

    if (sumS1 == sumS2)
        return 0;

    else if (sumS1 > sumS2)
        return 1;

    else
        return -1;
}

void myStrTok(string s1, string s2)     // Not Working
{
    int i = 0;

    while (s1[i] != ' ' && s1[i] != '\0')
    {
        s2 += s1[i];
        i++;
    }
        cout << s2 << endl;
}

int myStrLen(const char* sPtr)    // Working
{
    int counter = 0;

    while ( sPtr[counter] != '\0')
    {
        counter++;
    }

    return counter;
}

int main()
{
    char s3[6] = {'h', 'e', 'l', 'l', 'o', '\0'};
    char s4[6] = {'w', 'o', 'r', 'l', 'd', '\0'};

    char s1[50];
    char s2[50];
    
    cout << "Enter First String: ";
    cin.getline(s1, 50);
    cout << "Enter Second String: ";
    cin.getline(s2, 50);

    // int lim;
    // cout << "Enter the limit: ";
    // cin >> lim;

    // cout << myStrCopy(s1, s2);
    // cout << myStrNumCopy(s1, s2, lim);
    // cout << myStrCat(s1, s2);
    // cout << myStrNumCat(s1, s2, lim);
    // cout << myStrComp(s1, s2);
    // cout << myStrNumComp(s1, s2, lim);
    // cout << myStrTok(s1, s2);
    // cout << myStrLen(s1);

    return 0;
}