/*
 * Simple utility to control the brightness on linux system
 *
 *Copyright (c) 2021 Prakersh Arya  <prakersh009@gmail.com>
 *Copyright (c) 2021 Shivam Sharma  <shivamsharmaskp94@gmail.com>
 *for license and copyright information, see the LICENSE file distributed with this source
 *
 */

#include<stdlib.h>
#include<stdio.h>
#include<dirent.h>          //this header files helps to open directories.
#include<string.h>
#include <limits.h>
#define path  "/sys/class/backlight/"       //path to backlight modifier

int main(int argc,char *argv[])
{
    
    if(argc!=2)
    {
        exit(1);
    }
    DIR* folder=opendir(path);
    struct dirent * rd;
    char *pathb;
    if(folder==NULL)
    printf("can't open");
    else
    {
        while(rd=readdir(folder))           //reads each content name in directory.
            pathb=rd->d_name;
    }
    closedir(folder);
    char arr[100];
    strcat(arr,path);strcat(arr,pathb);strcat(arr,"/");         //builds the path name
    int n =strlen(arr);
    strcat(arr,"max_brightness");
    int maxi;
    FILE *fp=fopen(arr,"r");
    fscanf(fp,"%d",&maxi);
    fclose(fp);
    arr[n]='\0';
    strcat(arr,"brightness");

    fp=fopen(arr,"w");
    int value=atoi(argv[1]);

    if(value>100)
    {
        value=100;
        printf("\e[31;1mNahi thik hai , Gaand hi maar lo na mere system ka!!!engineer ke chodee, 100 tak ki value hi daalna agli bar\e[0;0m\n");

    }
    fprintf(fp,"%d",value*(maxi/100));

    fclose(fp);
    return 0;
}
