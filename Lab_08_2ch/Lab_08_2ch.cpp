// Програма за допомогою стандартних функцій мови C (strchr, strspn, strncat)
// вилучає пробіли між словами та знаками пунктуації.
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

using namespace std;

char* RemoveSpaces(char* dest, const char* str)
{
    const char punct[] = ".,!?;:-()\"'";
    dest[0] = '\0';
    int i = 0;

    while (str[i] != '\0')
    {
        if (str[i] == ' ')
        {
            size_t count = strspn(str + i, " ");
            size_t dLen = strlen(dest);

            bool afterWord = (dLen > 0 && dest[dLen - 1] != ' ' && strchr(punct, dest[dLen - 1]) == nullptr);
            bool beforePunct = (str[i + count] != '\0' && strchr(punct, str[i + count]) != nullptr);

            if (!afterWord || !beforePunct)
                strncat(dest, str + i, count);

            i += count;
        }
        else
        {
            strncat(dest, str + i, 1);
            i++;
        }
    }
    return dest;
}

int main()
{
    char str[151];
    cout << "Enter string:" << endl;
    cin.getline(str, 150);

    char dest[151];
    RemoveSpaces(dest, str);
    cout << "Modified string: " << dest << endl;

    return 0;
}