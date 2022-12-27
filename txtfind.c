#include "stdio.h"
#include <string.h>
#include <stdlib.h>
#define LINE 256
#define WORD 30
#define MAXLINES 250

int getline2(char s[])
{
    char c;
    for (size_t i = 0; i < 256; i++)
    {
        scanf("%c",&c);
        if(c!='\r')
        {
            s[i]=c;
        }
        if(c=='\n')
        {
            s[i]='\0';
            break;
        }
    }
    return strlen(s); 
}
int getword(char w[])
{
    int count = 0;
    for(int i =0; i < WORD; i++)
    {
        scanf("%c",&w[i]);
        count++;
        if(w[i] == '\n' || w[i] == '\t' || w[i] == ' ' || w[i]=='\r')
        {
            w[i]='\0';
            break;
        }
    }
    return count; 

}
int substring( char * str1, char * str2)
{
    int count = 0;
    int ans = 0;
    int n = strlen(str1);
    int m = strlen(str2);
    for(int i = 0; i <= n - m; i++)
    {
        count = 0;
        for(int j = 0; j < m; j++)
        {
            if(*(str1 + i + j) == *(str2 + j))
                count++;
        }
        if(count == m)
            ans = 1;
    }
    return ans;
}
int similar (char *s, char *t, int n)
{
    if(strlen(s) - strlen(t) != n)
        return 0;
    int len1 = strlen(s);
    int len2 = strlen(t);
    int i, j;
    for (i = 0, j = 0; i < len1 && j < len2; i++)
    {
        if (*(s+i) == *(t + j))
        {
            j++;
        }
    }
    return (j == len2);

}
void print_lines(char * str)
{
    char *text[MAXLINES];
    int mallocated = 0;
    for(int i = 0; i < 250; i++)
    {
        text[i] = (char*)malloc(LINE * sizeof(char));
        mallocated++;
        getline2(text[i]);
        if(substring(text[i],str) == 1)
            printf("%s\n",text[i]);
    }
    for(int i = 0; i < mallocated; i++)
    {
        free(text[i]);
    }
}
void print_similar_words(char * str)
{
    char word[WORD];
    for(int i=0;i<MAXLINES*LINE;i++)
    {
        getword(word);
        if(*word == '\n')
            break;
        if(similar(word,str,0) == 1 || similar(word,str,1) == 1)
        {
            printf("%s\n",word);
        }
        
    }
}
int main()
{
    char s[WORD];
    char w[WORD];
    getword(w);
    getword(s); 
    if(s[0] == 'a')
        print_lines(w);
    if(s[0] == 'b')
        print_similar_words(w);
    return 0;
}