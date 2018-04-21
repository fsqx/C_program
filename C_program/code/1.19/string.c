#include <stdio.h>
#include <string.h>

int my_strcmp(char *str1, char *str2);          //比较两个字符串是否相等
int my_strlen(char *str);                       //计算字符串长度
int my_strlen_space(char *str);                 //计算字符串长度，遇到空格停止
char *my_strcpy(char *str1, char *str2);        //复制字符串
char *my_strncpy(char *str1, char *str2, int n);//按给定字符个数复制字符串
char *reverse(char *str);                       //反转字符串
char *reverse_words(char *str);                 //按单词反转字符串
int *my_atoi(char *str);
double my_atof(char *str);

int main()
{
    char m[] = "I am from China";
    char n[] = "  -4521.365";
//    printf("%s\n",reverse_words(m));
    printf("%lf\n",my_atof(n));
//    char n[] = "12345abc";
//    char p[30];
//    printf("%d,%d\n",strlen(m),my_strlen(m));
//    char *p = reverse(m);
//    printf("%s\n",strncpy(p,m,6));
//    printf("%d\n",my_strlen(m));
//    printf("%s\n",reverse(m));        
//    printf("%s\n",reverse_words(m));
//    printf("%d\n",my_strlen_space(reverse(m)));
    return 0;
}

/*strcmp 比较两个字符串是否相等*/
int my_strcmp(char *str1, char *str2)
{
    while(*str1 != '\0')
    {
        if(!(*str1 - *str2))
            break;
        str1++;
        str2++;
    }
    if(*str1 == *str2)
    {
        return 0;
    }else if(*str1 > *str2)
    {
        return 1;
    }
    else
    {
        return -1;
    }
}

/*strlen 计算字符串长度*/
int my_strlen(char *str)
{
    int len = 0;
    char *strcopy = str;
    while(*strcopy != '\0')
    {
        len++;
        strcopy++;
    }
    return len;
}

/*strlen 计算字符串中单词长度，遇到空格停止计数*/
int my_strlen_space(char *str)
{
    int len = 0;
    char *strcopy = str;
    while(*strcopy != ' ' && *strcopy != '\0')
    {
        len++;
        strcopy++;
    }
    return len;
}

/*strcpy 复制字符串*/
char *my_strcpy(char *str1, char *str2)
{   
    char *str1copy = str1;
    while(*str1copy != '\0')
    {
        *str1copy++ = *str2++;
   //     str1copy++;
   //     str2++;
    }
    return str1;
}

/*strncpy 按指定个数复制字符串*/
char *my_strncpy(char *str1, char *str2, int number)
{
    char *str1copy = str1;
    int i = 0;
    while(i++ < number)
    {
        *str1copy ++ = *str2++;
    }
    *(str1 + i - 1) = '\0';
    return str1;
}

/*reverse 反转字符串*/
char *reverse(char *str)
{
    char *strcopy = str;
    char temp;
    int i, len_of_str;
    len_of_str = strlen(str);
    for(i = 0; i < len_of_str / 2; i++)
    {
        temp = *(strcopy + i);
        *(strcopy + i) = *(strcopy + len_of_str - i - 1);
        *(strcopy + len_of_str - i - 1) = temp;
    }
    return str;
}

/*reverse_words 按单词反转句子*/
char *reverse_words(char *str)
{
    char *strcopy = reverse(str);
    char temp;
    int i;
    int number;
    int n = 0;

    while(*strcopy != '\0')
    { 
        if(n++) //第一个单词前没有空格
        {
            strcopy++;
        }
        number = my_strlen_space(strcopy);  //获取空格前单词个数
        for(i = 0; i < number / 2; i++)
        {
            temp = *(strcopy + i);
            *(strcopy + i) = *(strcopy + number - i - 1);
            *(strcopy + number - i - 1) = temp;
        }
        strcopy += number;  //配合if(n++)移动指针指向单词首字母
    }
    
    return str;
}

/*
char *reverse_words(char *str)
{
    char *strcopy = str;
    char *strcopy_old = str;
    char temp_str[10];
    char *temp_str_old = temp_str;
    reverse(strcopy);
    while(*strcopy_old != '\0')
    {

        my_strncpy(temp_str_old,strcopy_old,my_strlen_space(strcopy_old));
        printf("%s",reverse(temp_str));
        strcopy_old++;
        

    }
    
    //my_strncpy(temp_str_old,strcopy_old,my_strlen_space(strcopy_old));
    return str;
}*/

int my_atoi(char *str)
{
    int total = 0;
    int sign = 1;

    while(*strcopy == ' ')
    {
        strcopy++;

    }
    if(*str == '-')
    {
        sign = -1;
    }
    
}

double my_atof(char *str)
{
    int cnt = 0;
    int i = 0;
    double total = 0.0;
    int sign = 1;
    char *strcopy = str;

    while(*strcopy == ' ')
    {
        strcopy++;
    }

    if(*strcopy == '-')
    {
        sign = -1;
        strcopy++;
    }

    while(*strcopy >= '0' && *strcopy <= '9')
    {
        total = total * 10 + *strcopy - '0';
        strcopy++;
    }
        
    if(*strcopy == '.')
    {
        strcopy++;
        while(*strcopy >= '0' && *strcopy <= '9')
        {
        total = total * 10 + *strcopy - '0';
        strcopy++;
        cnt++;
        }
    }
    for(; i < cnt; i++)
    {
        total = total / 10;
    }

    return total * sign;
}
