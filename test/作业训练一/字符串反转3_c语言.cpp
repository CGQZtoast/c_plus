#include <stdio.h>
#include <string.h>

char str[105];
char word[15];

int main()
{
    int n;
    scanf("%d\n", &n);
    memset(str, 0, sizeof(str));
    memset(word, 0, sizeof(word));

    while (n--)
    {
        char tmp;
        char *ptr_word = word;
        char *ptr_str = str;
        while (tmp = getchar())
        {
            if (tmp != '\n' && tmp != ' ')
                *(ptr_word++) = tmp;
            else
            {
                ptr_str += (ptr_word - word - 1);
                ptr_word = word;
                while (*ptr_word != '\0')
                    *(ptr_str--) = *(ptr_word++);
                ptr_str += (ptr_word - word);
                *(++ptr_str) = ' ';
                ptr_str++;
                ptr_word = word;
                memset(word, 0, sizeof(word));
                if (tmp == '\n')
                    break;
            }
        }
        printf("%s\n", str);
        memset(str, 0, sizeof(str));
    }
}