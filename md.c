#include<stdio.h>
#include<ctype.h>
// #include "test.h"

/**
 * 
 * 加密与解密文件
 * 
*/

// 声明加密函数
void encode(char *input, char *output, char key);

// 声明解密函数
void decode(char *input, char *output, char key);

void onemain()
{
    /* code */
    unsigned char s[80], in_file[80], out_file[80], key;
    for (;;)
    {
        // 提示解密或加密
        printf("encode,decode,quit\n");
        gets(s);
        *s = toupper(*s);
        switch (*s)
        {
        case /* constant-expression */'E':
            /* code */
            printf("enter input filename:\n");
            gets(in_file);// 得到加密源文件
            printf("enter output filename:\n");
            gets(out_file);// 得到加密后的密码文件
            printf("enter key:");
            scanf("%d",&key); // 输入密码
            encode(in_file,out_file,key);//加密
            break;
        case 'D':
            printf("enter input filename:\n");
            gets(in_file);// 得到加密源文件
            printf("enter output filename:\n");
            gets(out_file);// 得到加密后的密码文件
            printf("enter key:");
            scanf("%d",&key); // 输入密码
            decode(in_file,out_file,key);//去密
            break;
        default:
            break;
        }
    }
}

void encode(char *input, char *output, char key){
    int ch;
    FILE *fp, *fp1;
    if ((fp = fopen(input, "r")) != NULL)
    {
        printf("coan not open the output file\n");
        // exit(0);
    }
    if ((fp1 = fopen(input, "r")) != NULL)
    {
        printf("coan not open the output file\n");
        // exit(0);
    }
    do
    {
        ch=getc(fp);
        if (ch == EOF) // eof文件尾部
        {
            /* code */
            break;
        }
        ch = ch^key; // 进行按位亦或运算
        // if (ch==e)
        // {
        //     /* code */
        // }
        ch++;
        putc(ch, fp1);// 加密后字节输出到fp1
    } while (1);
    
    fclose(fp);
    fclose(fp1);
 
}

void decode(char *input, char *output, char key) {
    int ch;
    FILE *fp, *fp1;
    if ((fp = fopen(input, "r")) != NULL)
    {
        printf("coan not open the output file\n");
        // exit(0);
    }
    if ((fp1 = fopen(input, "w")) != NULL)
    {
        printf("coan not open the output file\n");
        // exit(0);
    }
    do
    {
        ch=getc(fp);
        if (ch == EOF) // eof文件尾部
        {
            /* code */
            break;
        }
        ch = ch^key; // 进行按位亦或运算
        if (ch == EOF + 1)
        {
            /* code */
             ch--;
            putc(ch, fp1);// 解密后字节输出到fp1
        }
    } while (1);
    
    fclose(fp);
    fclose(fp1);
}

int main(int argc, char const *argv[])
{
    onemain();
    unsigned char a,b,c;
    a = 0x3;
    b = a | 0xb;
    c = b << 1; // 二进制左移1位
    return 0;
}
