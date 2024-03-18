#include <bits/stdc++.h>
using namespace std;

int len(const char arr[]) {
    int length = 0;
    while (arr[length] != '\0') {
        length++;
    }
    return length;
}

void mystrcat(char arr1[], const char arr2[]) {
    int i = 0, j = 0;
    while (arr1[i] != '\0') {
        i++;
    }
    while (arr2[j] != '\0') {
        arr1[i++] = arr2[j++];
    }
    arr1[i] = '\0';
}

void mystrcpy(char arr1[], const char arr2[]) {
    int i = 0;
    while (arr2[i] != '\0') {
        arr1[i] = arr2[i];
        i++;
    }
    arr1[i] = '\0';
}

int mystrcmp(const char arr1[], const char arr2[]) {
    int i = 0;
    while (arr1[i] == arr2[i]) {
        if (arr1[i] == '\0')
            return 0;
        i++;
    }
    return arr1[i] - arr2[i];
}

int main() {
    char arr1[1000], arr2[1000];
    
    cout << "Enter the first string: ";
    cin >> arr1;
    cout << "Enter the second string: ";
    cin >> arr2;
    
    int length1 = len(arr1);
    cout << "Length of first string: " << length1 << endl;
    
    char concatenated[2000];
    mystrcat(concatenated, arr1);
    mystrcat(concatenated, arr2);
    cout << "Concatenated string: " << concatenated << endl;
    
    char copied[1000];
    mystrcpy(copied, arr1);
    cout << "Copied string: " << copied << endl;
    
    int comparison = mystrcmp(arr1, arr2);
    if (comparison == 0)
        cout << "Strings are equal" << endl;
    else if (comparison > 0)
        cout << arr1 << " is less than " << arr2 << endl;
    else
        cout << arr1 << " is greater than " << arr2 << endl;

    return 0;
}
