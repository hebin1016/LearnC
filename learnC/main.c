//
//  main.c
//  learnC
//
//  Created by hebin on 2017/1/14.
//  Copyright © 2017年 hebin. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//读取文本文件
//int main()
//{
//    char *path="/Users/hebin/note.txt";
//    FILE *fp=fopen(path,"r");
//    if(fp==NULL){
//        printf("打开失败");
//        return 0;
//    }
//    char buff[50];//缓冲
//    while(fgets(buff,50,fp)){
//        printf("%s", buff);
//    }
//    //关闭流
//    fclose(fp);
//
//    return 0;
//}

//写入文本文件
//int main()
//{
//    char *path="/Users/hebin/note_new.txt";
//    //打开
//    FILE *fp=fopen(path,"w");
//    char *text="这是一个新的笔记,\n新的开始";
//    fputs(text, fp);
//
//    fclose(fp);
//    return 0;
//}

//操作二进制文件，计算机的文件存储在物理上都是二进制
//文本文件和二进制之分，其实是一个逻辑之分
//c读写文本文件与二进制文件的差别仅仅体现在回车换行符
//写文本时，每遇到一个'\n',会将其转换成'\r\n'(回车换行)
//读文本时，每遇到一个'\r\n',会将其转换成'\n'

//文件复制
//int main()
//{
//    char *read_path="/Users/hebin/Downloads/a2cc7cd98d1001e9460fd63bbd0e7bec54e797d7.jpg";
//    char *write_path="/Users/hebin/Downloads/meinv.jpg";
//    
//    //读的文件
//    FILE *read_p=fopen(read_path,"rb");
//    //写的文件
//    FILE *write_p=fopen(write_path,"wb");
//    
//    //复制
//    int buff[50];//缓冲区域
//    int len=0;//每次读到的数据长度
//    while ((len=fread(buff,sizeof(int),50,read_p))!=0) {
//        fwrite(buff, sizeof(int), len,write_p);
//    }
//    
//    fclose(write_p);
//    fclose(read_p);
//    
//    return 0;
//}

//获取文件大小
/*
int main()
{
    char *read_path="/Users/hebin/Downloads/AdsSdkSample.zip";
    //读的文件
    FILE *read_p=fopen(read_path,"r");
    
    long init=ftell(read_p);

    
    //重新定位文件指针，0代表和文件末尾的偏移量
    fseek(read_p, 0, SEEK_END);
    //返回当前的文件指针，相当于显示当前位置和文件开头的偏移量
    long size=ftell(read_p);

    printf("%d,%d\n",init,size);
    
    fclose(read_p);
    return 0;
}
*/

/*
//练习：文本文件加解密
//异或
//规则：1^1=0,0^0=0,1^0=1,0^1=1 同为0 不同为1

//加密函数
void crpypt(char normal_path[],char crypt_path[])
{
    //打开文件
    FILE *normal_fp=fopen(normal_path, "r");
    FILE *crypt_fp=fopen(crypt_path, "w");
    //文本文件加解密一次读取一个字符
    int ch;
    while ((ch=fgetc(normal_fp))!=EOF) { //end of file
        //写入
        fputc(ch^9, crypt_fp);
    }
    fclose(crypt_fp);
    fclose(normal_fp);
}

//解密函数
void decrpypt(char crypt_path[],char decrypt_path[])
{
    //打开文件
    FILE *crypt_fp=fopen(crypt_path, "r");
    FILE *decrypt_fp=fopen(decrypt_path, "w");
    //文本文件加解密一次读取一个字符
    int ch;
    while ((ch=fgetc(crypt_fp))!=EOF) { //end of file
        //写入
        fputc(ch^9, decrypt_fp);
    }
    fclose(crypt_fp);
    fclose(decrypt_fp);
}



int main()
{
    char *normal_path="/Users/hebin/note.txt";
    char *crpypt_path="/Users/hebin/note_crpty.txt";
    
    char *decrpypt_path="/Users/hebin/note_decrpty.txt";

    
    //crpypt(normal_path,crpypt_path);
    
    decrpypt(crpypt_path, decrpypt_path);
    return 0;
}
 */

/*
//练习：二进制文件加解密
//读取二进制文件中的数据时，一个一个字符读取
//加密函数
void crpypt(char normal_path[],char crypt_path[],char password[])
{
    //打开文件
    FILE *normal_fp=fopen(normal_path, "rb");
    FILE *crypt_fp=fopen(crypt_path, "wb");
    //一次读取一个字符
    int ch;
    int i=0;
    int pwd_len=strlen(password);
    while ((ch=fgetc(normal_fp))!=EOF) { //end of file
        //循环password的每个字符和当前字符异或
        fputc(ch^password[i%pwd_len], crypt_fp);
        i++;
    }
    fclose(crypt_fp);
    fclose(normal_fp);
}

//解密函数
void decrpypt(char crypt_path[],char decrypt_path[],char password[])
{
    //打开文件
    FILE *crypt_fp=fopen(crypt_path, "r");
    FILE *decrypt_fp=fopen(decrypt_path, "w");
    //文本文件加解密一次读取一个字符
    int ch;
    int i=0;
    int pwd_len=strlen(password);
    while ((ch=fgetc(crypt_fp))!=EOF) { //end of file
        //写入
        fputc(ch^password[i%pwd_len], decrypt_fp);
        i++;
    }
    fclose(crypt_fp);
    fclose(decrypt_fp);
}



int main()
{
    char *normal_path="/Users/hebin/Downloads/meinv.jpg";
    char *crpypt_path="/Users/hebin/Downloads/meinv_crpypt.jpg";
    
    char *decrpypt_path="/Users/hebin/Downloads/meinv_decrpypt.jpg";
    
    crpypt(normal_path,crpypt_path,"hank");
    
    decrpypt(crpypt_path, decrpypt_path,"hank");
    return 0;
}
 */

