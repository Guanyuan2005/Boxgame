#include <stdio.h>
#include <graphics.h>
#include <easyx.h>
#include <stdlib.h>
#include <conio.h>
#include <stdbool.h>
#include <windows.h>
#include <time.h>
#include <string.h>
#include <iostream>
#include <process.h>
#include <shellapi.h>
#pragma comment(lib,"winmm.lib")
/*
�յ�           0
ǽ��           1
Ŀ�ĵ�         2
����           3
���           4
����+Ŀ�ĵ�    5
���+Ŀ�ĵ�    6
������         7
����           8
����+����      11
���+����      12
������         20
������+����    23
������+���    24
�����ذ�       30
����+�����ذ�  33
���+�����ذ�  34
ը��           40
ը��+Ŀ�ĵ�    42
ը��+����      48
ը��+�����ذ�  70
*/
#define SPACE 0
#define M 1
#define a 2
#define O 3
#define ROW 15
#define COL 15
#define LEVEL 18
int flag=0;
int cleardoor = 0;
int existdoor = 1;
int level = 0;
int counter = 0;
int pushcounter = 0;
char blank1;
int singal = 0;
int key = -2;
int label1 = 0;
int label2 = 0;
int label3 = 0;
int exi = 0;
int sign = -1;
int symbol = 0;
int times = 0;   //����
int time2 = 0;
int time3 = 0;
int time4 = 0;
int time5 = 0;
int time6 = 0;
int sendsth = 0;
int stopsend = 0;
int senddoornum = 0;
int count = 0;
int score = 0;
int memcounter = 0;
int mempushcounter = 0;
int lct1 = 0;
int lct2 = 0 ;
int lct3 = 1;
int lcttime = 0;
int showtips1 = 1, showtips3 = 1, showtips4 = 1, showtips5 = 1, showtips6 = 1, showtips7 = 1;
IMAGE Box;
IMAGE dot1;
IMAGE dot2;
IMAGE dot3;
IMAGE dot4;
IMAGE dot5;
IMAGE dot6;
IMAGE ground1;
IMAGE ground2;
IMAGE ground3;
IMAGE ground4;
IMAGE ground5;
IMAGE ground6;
IMAGE player1;
IMAGE player2;
IMAGE player3;
IMAGE player4;
IMAGE player5;
IMAGE player6;
IMAGE Wall1;
IMAGE Wall2;
IMAGE Wall3;
IMAGE Wall4;
IMAGE Wall5;
IMAGE Wall6;
IMAGE Boxpro;
IMAGE Door;
IMAGE gouba;
IMAGE gouba_player3;
IMAGE gouba_player4;
IMAGE gouba_player5;
IMAGE gouba_player6;
IMAGE Box_gouba;
IMAGE powerbox;
IMAGE powerground;
IMAGE powerplayer4;
IMAGE powerplayer5;
IMAGE powerplayer6;
IMAGE senddoor5;
IMAGE senddoor6;
IMAGE bomb;
IMAGE bomb_gouba;
IMAGE powerbomb;
IMAGE rulephoto1_1;
IMAGE rulephoto1_2;
IMAGE rulephoto1_3;
IMAGE rulephoto2_1;
IMAGE rulephoto2_2;
IMAGE rulephoto2_3;
IMAGE rulephoto2_4;
IMAGE rulephoto2_5;
IMAGE rulephoto2_6;
IMAGE rulephoto2_7;
IMAGE rulephoto2_8;
IMAGE rulephoto2_9;
IMAGE rulephoto2_10;
IMAGE rulephoto2_11;
IMAGE rulephoto2_12;
IMAGE rulephoto2_13;
IMAGE rulephoto2_14;
IMAGE rulephoto3_1;
IMAGE rulephoto3_2;
IMAGE rulephoto3_3;
IMAGE rulephoto3_4;
IMAGE rulephoto3_5;
IMAGE rulephoto3_6;
IMAGE rulephoto3_7;
IMAGE rulephoto3_8;
IMAGE rulephoto3_9;
IMAGE rulephoto3_10;
IMAGE rulephoto3_11;
IMAGE rulephoto3_12;
IMAGE rulephoto3_13;
IMAGE rulephoto3_14;
IMAGE rulephoto3_15;
IMAGE rulephoto3_16;
IMAGE rulephoto3_17;
IMAGE rulephoto4_1;
IMAGE rulephoto4_2;
IMAGE rulephoto4_3;
IMAGE rulephoto4_4;
IMAGE rulephoto4_5;
IMAGE rulephoto4_6;
IMAGE rulephoto4_7;
IMAGE rulephoto4_8;
IMAGE rulephoto4_9;
IMAGE rulephoto4_10;
IMAGE rulephoto4_11;
IMAGE rulephoto5_1;
IMAGE rulephoto5_2;
IMAGE rulephoto5_3;
IMAGE rulephoto6_1;
IMAGE rulephoto6_2;
IMAGE rulephoto6_3;
IMAGE rulephoto6_4;
IMAGE rulephoto7_1;
IMAGE rulephoto7_2;
IMAGE rulephoto7_3;
IMAGE rulephoto7_4;
ExMessage msg;
int leastscore[18][2] =
{
    {10,4}, {89,29},{78,26},{115,33},{107,24},{169,31},        {78,23},{107,42},{182,62},{40,21},{60,25},{287,62},           {28,13},{125,42},{74,276},{78,23},{39,138},{116,33}
};
void countscore()  //�����û��÷�
{
    int x = leastscore[level][0];
    int y = leastscore[level][1];
    score = 200000 * x / counter + 500000 * y / pushcounter + 50000 * (6 - lcttime);
    if (score < 0)
        score = 0;
    else if (score > 1000000)
        score = 1000000;
}
int origin[LEVEL][ROW][COL] =           //����ԭ��ͼ
{
    {
        //�ؿ�1
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,M,M,M,0,0,0,0,0,0,0,0},
        {0,0,0,0,M,a,M,0,0,0,0,0,0,0,0},
        {0,0,0,0,M,O,M,M,M,M,0,0,0,0,0},
        {0,0,M,M,M,0,0,O,a,M,0,0,0,0,0},
        {0,0,M,a,O,4,0,M,M,M,0,0,0,0,0},
        {0,0,M,M,M,M,O,M,0,0,0,0,0,0,0},
        {0,0,0,0,0,M,a,M,0,0,0,0,0,0,0},
        {0,0,0,0,0,M,M,M,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    },
    {
        //�ؿ�2
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,M,M,M,M,M,0,0,0,0,0,0,0},
        {0,0,0,M,0,0,0,M,0,0,0,0,0,0,0},
        {0,0,0,M,0,O,0,M,0,M,M,M,0,0,0},
        {0,0,0,M,0,O,4,M,0,M,a,M,0,0,0},
        {0,0,0,M,M,M,O,M,M,M,a,M,0,0,0},
        {0,0,0,0,M,M,0,0,0,0,a,M,0,0,0},
        {0,0,0,0,M,0,0,0,M,0,0,M,0,0,0},
        {0,0,0,0,M,0,0,0,M,M,M,M,0,0,0},
        {0,0,0,0,M,M,M,M,M,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    },
    {
        //�ؿ�3
       {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,M,M,M,M,M,M,M,0,0,0,0},
        {0,0,0,0,M,0,0,a,a,a,M,0,0,0,0},
        {0,0,0,0,M,0,0,0,M,M,M,M,0,0,0},
        {0,0,0,M,M,M,O,0,0,0,0,M,0,0,0},
        {0,0,0,M,0,0,0,M,O,M,0,M,0,0,0},
        {0,0,0,M,0,O,0,M,4,0,0,M,0,0,0},
        {0,0,0,M,0,0,0,M,M,M,M,M,0,0,0},
        {0,0,0,M,M,M,M,M,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    },
    {
        //�ؿ�4
         {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,M,M,M,M,M,M,M,M,0,0,0,0},
        {0,0,0,M,0,0,0,M,0,0,M,0,0,0,0},
        {0,0,0,M,0,M,0,M,O,a,M,0,0,0,0},
        {0,0,0,M,0,0,0,0,O,a,M,0,0,0,0},
        {0,0,0,M,0,M,0,M,O,a,M,0,0,0,0},
        {0,0,0,M,0,0,0,M,0,4,M,0,0,0,0},
        {0,0,0,M,M,M,M,M,0,0,M,0,0,0,0},
        {0,0,0,0,0,0,0,M,M,M,M,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    },
    {
        //�ؿ�5
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,M,M,M,M,0,0,0,0,0,0,0},
        {0,0,0,0,M,0,0,M,M,M,M,M,0,0,0},
        {0,0,M,M,M,0,a,M,0,0,0,M,0,0,0},
        {0,0,M,4,0,0,O,0,0,0,0,M,0,0,0},
        {0,0,M,0,M,M,5,M,M,M,M,M,0,0,0},
        {0,0,M,0,0,0,O,0,0,M,0,0,0,0,0},
        {0,0,M,M,M,0,a,0,0,M,0,0,0,0,0},
        {0,0,0,0,M,0,0,M,M,M,0,0,0,0,0},
        {0,0,0,0,M,M,M,M,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    },
    {
        //�ؿ�6
         {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
         {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
         {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
         {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
         {0,0,0,0,M,M,M,M,M,M,0,0,0,0,0},
         {0,0,0,M,M,0,0,0,0,M,M,0,0,0,0},
         {0,0,0,M,0,3,0,3,3,0,M,0,0,0,0},
         {0,0,0,M,2,2,2,2,2,2,M,0,0,0,0},
         {0,0,0,M,0,3,3,0,3,0,M,0,0,0,0},
         {0,0,0,M,M,M,0,4,M,M,M,0,0,0,0},
         {0,0,0,0,0,M,M,M,M,0,0,0,0,0,0},
         {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
         {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
         {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
         {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    },
     {
         //�ؿ�7
         {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
         {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
         {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
         {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
         {0,0,0,M,M,M,M,M,M,M,M,M,0,0,0},
         {0,0,0,M,0,0,0,4,0,0,0,M,0,0,0},
         {0,0,0,M,0,0,0,8,0,0,0,M,0,0,0},
         {0,0,0,M,0,O,0,O,0,O,0,M,0,0,0},
         {0,0,0,M,0,O,0,a,0,O,0,M,0,0,0},
         {0,0,0,M,M,M,7,7,7,M,M,M,0,0,0},
         {0,0,0,0,M,a,0,0,0,a,M,0,0,0,0},
         {0,0,0,0,M,a,0,0,0,a,M,0,0,0,0},
         {0,0,0,0,M,M,M,M,M,M,M,0,0,0,0},
         {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
         {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
     },
     {
         //�ؿ�8
         {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
         {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
         {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
         {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
         {0,0,0,0,M,M,M,M,M,M,M,M,0,0,0},
         {0,0,0,M,M,0,0,M,M,0,0,M,0,0,0},
         {0,0,0,M,0,O,0,M,M,O,0,M,0,0,0},
         {0,0,0,M,7,7,0,0,M,7,7,M,M,M,0},
         {0,0,0,M,0,0,0,O,0,0,0,8,0,M,0},
         {0,0,0,M,0,0,O,M,M,0,4,0,0,M,0},
         {0,0,0,M,0,0,O,0,M,0,0,0,M,M,0},
         {0,M,M,M,0,0,0,0,0,0,M,M,M,0,0},
         {0,M,a,a,a,a,a,0,M,M,M,0,0,0,0},
         {0,M,M,M,M,M,M,M,M,0,0,0,0,0,0},
         {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
     },
     {
         //�ؿ�9
         {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
         {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
         {0,0,0,0,M,M,M,M,M,M,M,M,M,0,0},
         {0,0,0,0,M,0,0,0,0,0,0,0,M,0,0},
         {0,0,0,M,M,O,M,M,M,M,M,0,M,0,0},
         {0,0,0,M,0,O,0,0,8,0,M,0,M,0,0},
         {0,0,0,M,0,0,0,0,0,0,M,0,M,0,0},
         {0,0,0,M,M,M,O,0,0,0,M,0,M,0,0},
         {0,0,0,0,0,M,0,0,0,0,M,0,M,0,0},
         {0,0,0,0,0,M,0,0,0,0,M,0,M,0,0},
         {0,0,M,M,M,M,M,M,M,0,M,0,M,0,0},
         {0,0,M,7,a,M,M,M,M,0,0,0,M,0,0},
         {0,0,M,7,a,0,0,0,0,0,4,0,M,0,0},
         {0,0,M,7,a,0,0,0,0,0,M,M,M,0,0},
         {0,0,M,M,M,M,M,M,M,M,M,0,0,0,0},
     },
     {
         //�ؿ�10
         {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
         {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
         {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
         {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
         {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
         {0,0,1,1,1,1,1,1,1,1,1,1,1,0,0},
         {0,0,1,0,2,2,7,33,33,30,0,0,1,0,0},
         {0,0,1,0,2,0,0,3,8,4,0,0,1,0,0},
         {0,0,1,0,2,2,7,33,33,30,0,0,1,0,0},
         {0,0,1,1,1,1,1,1,1,1,1,1,1,0,0},
         {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
         {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
         {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
         {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
         {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},

     },
     {
         //�ؿ�11
         {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
         {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
         {0,0,0,0,0,0,M,M,M,M,M,0,0,0,0},
         {0,0,0,0,0,0,M,0,0,6,M,0,0,0,0},
         {0,0,0,0,0,0,M,0,M,5,M,M,M,M,0},
         {0,M,M,M,M,M,M,33,M,O,0,0,0,M,0},
         {0,M,a,5,a,7,30,30,33,30,33,30,30,M,0},
         {0,M,M,M,M,M,M,33,M,M,M,M,M,M,0},
         {0,0,0,M,M,M,M,0,0,a,M,0,0,0,0},
         {0,0,0,M,0,0,0,0,O,a,M,0,0,0,0},
         {0,0,0,M,0,0,0,0,8,a,M,0,0,0,0},
         {0,0,0,M,M,M,M,M,M,M,M,0,0,0,0},
         {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
         {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
         {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
     },
     {
         //�ؿ�12
         {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
         {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
         {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
         {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
         {0,0,M,M,M,M,M,M,M,M,M,M,0,0,0},
         {0,0,M,0,2,2,0,3,0,0,0,M,0,0,0},
         {0,0,M,3,2,0,30,2,3,0,0,M,0,0,0},
         {0,0,M,2,0,M,M,M,M,5,0,M,0,0,0},
         {0,0,M,3,3,0,3,30,0,3,5,M,0,0,0},
         {0,0,M,6,5,0,0,0,0,2,0,M,0,0,0},
         {0,0,M,M,M,M,M,M,M,M,M,M,0,0,0},
         {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
         {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
         {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
         {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
     },
     {
         //�ؿ�13
         {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
         {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
         {0,0,0,0,0,M,M,M,0,0,0,0,0,0,0},
         {0,0,0,0,0,M,2,M,0,0,0,0,0,0,0},
         {0,0,0,0,0,M,20,M,0,0,0,0,0,0,0},
         {0,0,0,0,0,M,0,M,M,M,M,M,M,0,0},
         {0,0,0,0,0,M,0,7,7,M,M,M,M,0,0},
         {0,0,M,M,M,M,33,3,0,0,20,2,M,0,0},
         {0,0,M,2,8,3,33,M,M,M,M,M,M,0,0},
         {0,0,M,M,M,M,30,M,0,0,0,0,0,0,0},
         {0,0,0,0,0,M,4,M,0,0,0,0,0,0,0},
         {0,0,0,0,0,M,2,M,0,0,0,0,0,0,0},
         {0,0,0,0,0,M,M,M,0,0,0,0,0,0,0},
         {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
         {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
     },
     {
         //�ؿ�14
         {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
         {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
         {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
         {0,0,M,M,M,M,M,M,M,M,M,M,M,0,0},
         {0,0,M,0,20,a,7,a,7,a,7,a,M,0,0},
         {0,0,M,0,M,M,M,M,M,M,M,M,M,0,0},
         {0,0,M,0,M,M,M,0,0,0,0,M,M,0,0},
         {0,0,M,0,0,0,0,0,3,3,4,0,M,0,0},
         {0,0,M,M,20,0,0,3,3,0,8,0,M,0,0},
         {0,0,M,M,M,M,M,0,0,0,0,0,M,0,0},
         {0,0,M,M,M,M,M,M,M,M,M,M,M,0,0},
         {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
         {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
         {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
         {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},

     },
     {
         //�ؿ�15
         {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
         {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
         {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
         {0,0,0,0,0,M,M,M,M,0,0,0,0,0,0},
         {0,0,0,0,0,M,0,20,M,0,0,0,0,0,0},
         {0,0,0,M,M,M,3,0,M,0,0,0,0,0,0},
         {0,0,0,M,0,2,2,3,M,M,M,0,0,0,0},
         {0,0,0,M,0,0,2,2,0,0,M,0,0,0,0},
         {0,0,0,M,0,3,2,3,0,0,M,0,0,0,0},
         {0,0,0,M,M,0,20,3,M,M,M,0,0,0,0},
         {0,0,0,0,M,4,0,0,M,0,0,0,0,0,0},
         {0,0,0,0,M,M,M,M,M,0,0,0,0,0,0},
         {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
         {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
         {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
     },
     {
         //�ؿ�16
         {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
         {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
         {0,0,M,M,M,M,M,M,M,M,M,M,M,0,0},
         {0,0,M,M,M,M,M,M,M,M,M,M,M,0,0},
         {0,0,M,M,7,7,7,0,0,0,a,M,M,0,0},
         {0,0,M,M,7,20,7,0,40,M,4,M,M,0,0},
         {0,0,M,M,7,7,7,0,40,a,0,M,M,0,0},
         {0,0,M,M,M,M,M,M,M,M,M,M,M,0,0},
         {0,0,M,M,M,M,M,M,M,M,M,M,M,0,0},
         {0,0,0,0,M,M,a,8,20,0,0,M,M,0,0},
         {0,0,0,0,M,M,0,O,O,O,0,M,M,0,0},
         {0,0,0,0,M,M,0,0,0,0,0,M,M,0,0},
         {0,0,0,0,M,M,M,M,M,M,M,M,M,0,0},
         {0,0,0,0,M,M,M,M,M,M,M,M,M,0,0},
         {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
     },
     {
         //�ؿ�17
         {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
         {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
         {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
         {0,0,0,0,0,M,M,M,M,M,M,M,0,0,0},
         {0,0,0,0,M,M,0,0,0,0,0,M,0,0,0},
         {0,0,0,M,M,M,0,M,M,M,0,M,0,0,0},
         {0,0,0,M,M,42,2,42,M,3,0,M,0,0,0},
         {0,0,0,M,0,2,3,7,3,M,M,M,0,0,0},
         {0,0,0,M,0,0,0,0,3,4,M,0,0,0,0},
         {0,0,0,M,M,0,0,M,M,M,M,0,0,0,0},
         {0,0,0,0,M,0,0,M,0,0,0,0,0,0,0},
         {0,0,0,0,M,M,M,M,0,0,0,0,0,0,0},
         {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
         {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
         {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
     },
     {
         //�ؿ�18
         {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
         {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
         {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
         {0,0,M,M,M,M,0,0,0,0,0,0,0,0,0},
         {0,M,M,0,0,M,M,M,M,M,M,M,M,0,0},
         {0,M,0,2,3,0,20,M,M,M,40,0,M,0,0},
         {0,M,0,3,2,3,2,4,M,40,40,20,M,0,0},
         {0,M,0,2,3,2,3,0,M,M,M,M,M,0,0},
         {0,M,0,3,2,3,2,3,0,M,M,0,0,0,0},
         {0,M,0,2,3,2,3,2,0,M,0,0,0,0,0},
         {0,M,M,0,0,0,0,0,M,M,0,0,0,0,0},
         {0,0,M,M,M,M,M,M,M,0,0,0,0,0,0},
         {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
         {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
         {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
     },
};
int remap[ROW][COL] = { 0 };           //�ȶԵ�ͼ
int memory[ROW][COL] = { 0 };        //�浵
int map[ROW][COL];   //��ǰ��ͼ
void copymemorymap()  //�洢�û���ǰ��ͼ״̬
{
    for (int i = 0; i < 15; i++)
    {
        for (int j = 0; j < 15; j++)
        {
            memory[i][j] = map[i][j];
        }
    }
}
void readmemorymap()  //�ָ��浵�����浵ʱ��¼�ĵ�ͼ״̬�������ڵĵ�ͼ
{
    for (int i = 0; i < 15; i++)
    {
        for (int j = 0; j < 15; j++)
        {
            map[i][j] = memory[i][j];
        }
    }
}
void clearmemorymap()  //���浵��ͼ����
{
    for (int i = 0; i < 15; i++)
    {
        for (int j = 0; j < 15; j++)
        {
            memory[i][j] = 0;
        }
    }
}
void copymap()   //������ĵ�ͼ���Ƹ���ǰ�ĵ�ͼ
{
        for (int i = 0; i < 15; i++)
        {
            for (int j = 0; j < 15; j++)
            {
                map[i][j] = origin[level][i][j];
            }
        }
}                //               //
void clearmap()               //��remap��ͼ����
{
    for (int i = 0; i < 15; i++)
    {
        for (int j = 0; j < 15; j++)
        {
            remap[i][j] = 0;
        }
    }
}
void showphotos()  //�ֹؿ����յ��µ�ͼ�����ӡ��ͼ
{
    if (level >= 0 && level < 3)
    {
        for (int i = 0; i < 15; i++)
        {
            for (int j = 0; j < 15; j++)
            {
                if (map[i][j] == 0&& ((count==0)||(i>=2)))
                {
                    loadimage(&ground1, "res\\ground1.jpg", 60, 60);
                    putimage(60 * j, 60 * i, &ground1);
                }
                else if (map[i][j] == 1)
                {
                    loadimage(&Wall1, "res\\Wall1.jpg", 60, 60);
                    putimage(60 * j, 60 * i, &Wall1);
                }
                else if (map[i][j] == 2)
                {
                    loadimage(&dot1, "res\\dot1.jpg", 60, 60);
                    putimage(60 * j, 60 * i, &dot1);
                }
                else if (map[i][j] == 3)// && remap[i][j] != map[i][j]
                {
                    loadimage(&Box, "res\\Box.jpg", 60, 60);
                    putimage(60 * j, 60 * i, &Box);
                }
                else if (map[i][j] == 4 )//&& remap[i][j] != map[i][j]
                {
                    loadimage(&player1, "res\\player1.jpg", 60, 60);
                    putimage(60 * j, 60 * i, &player1);
                }
                else if (map[i][j] == 5 && remap[i][j] != map[i][j])
                {
                    loadimage(&Boxpro, "res\\Box+Project.jpg", 60, 60);
                    putimage(60 * j, 60 * i, &Boxpro);
                }
                else if (map[i][j] == 6)
                {
                    loadimage(&player1, "res\\player1.jpg", 60, 60);
                    putimage(60 * j, 60 * i, &player1);
                }
            }
        }
    }
    else if (level >= 3 && level < 6)
    {
        for (int i = 0; i < 15; i++)
        {
            for (int j = 0; j < 15; j++)
            {
                if (map[i][j] == 0&&((count == 0) || (i >= 2 && i < 14)))
                {
                    loadimage(&ground2, "res\\ground2.jpg", 60, 60);
                    putimage(60 * j, 60 * i, &ground2);
                }
                else if (map[i][j] == 1)
                {
                    loadimage(&Wall2, "res\\Wall2.jpg", 60, 60);
                    putimage(60 * j, 60 * i, &Wall2);
                }
                else if (map[i][j] == 2)
                {
                    loadimage(&dot2, "res\\dot2.jpg", 60, 60);
                    putimage(60 * j, 60 * i, &dot2);
                }
                else if (map[i][j] == 3 && remap[i][j] != map[i][j])
                {
                    loadimage(&Box, "res\\Box.jpg", 60, 60);
                    putimage(60 * j, 60 * i, &Box);
                }
                else if (map[i][j] == 4 && remap[i][j] != map[i][j])
                {
                    loadimage(&player2, "res\\player2.jpg", 60, 60);
                    putimage(60 * j, 60 * i, &player2);
                }
                else if (map[i][j] == 5 && remap[i][j] != map[i][j])
                {
                    loadimage(&Boxpro, "res\\Box+Project.jpg", 60, 60);
                    putimage(60 * j, 60 * i, &Boxpro);
                }
                else if (map[i][j] == 6)
                {
                    loadimage(&player2, "res\\player2.jpg", 60, 60);
                    putimage(60 * j, 60 * i, &player2);
                }
            }
        }
    }

    else if (level >= 6 && level < 9)
    {
        for (int i = 0; i < 15; i++)
        {
            for (int j = 0; j < 15; j++)
            {
                if (map[i][j] == 0&&((count == 0) || (i >= 2 )))
                {
                    loadimage(&ground3, "res\\ground3.jpg", 60, 60);
                    putimage(60 * j, 60 * i, &ground3);
                }
                else if (map[i][j] == 1)
                {
                    loadimage(&Wall3, "res\\Wall3.jpg", 60, 60);
                    putimage(60 * j, 60 * i, &Wall3);
                }
                else if (map[i][j] == 2)
                {
                    loadimage(&dot3, "res\\dot3.jpg", 60, 60);
                    putimage(60 * j, 60 * i, &dot3);
                }
                else if (map[i][j] == 3 && remap[i][j] != map[i][j])
                {
                    loadimage(&Box, "res\\Box.jpg", 60, 60);
                    putimage(60 * j, 60 * i, &Box);
                }
                else if (map[i][j] == 4 && remap[i][j] != map[i][j])
                {
                    loadimage(&player3, "res\\player3.jpg", 60, 60);
                    putimage(60 * j, 60 * i, &player3);
                }
                else if (map[i][j] == 5 && remap[i][j] != map[i][j])
                {
                    loadimage(&Boxpro, "res\\Box+Project.jpg", 60, 60);
                    putimage(60 * j, 60 * i, &Boxpro);
                }
                else if (map[i][j] == 6)
                {
                    loadimage(&player3, "res\\player3.jpg", 60, 60);
                    putimage(60 * j, 60 * i, &player3);
                }
                else if (map[i][j] == 7 || map[i][j] == 37)
                {
                    loadimage(&Door, "res\\Door.jpg", 60, 60);
                    putimage(60 * j, 60 * i, &Door);
                }
                else if (map[i][j] == 8)
                {
                    loadimage(&gouba, "res\\gouba.jpg", 60, 60);
                    putimage(60 * j, 60 * i, &gouba);
                }
                else if (map[i][j] == 11)
                {
                    loadimage(&Box_gouba, "res\\Box+gouba.jpg", 60, 60);
                    putimage(60 * j, 60 * i, &Box_gouba);
                }
                else if (map[i][j] == 12)
                {
                    loadimage(&gouba_player3, "res\\gouba+player3.jpg", 60, 60);
                    putimage(60 * j, 60 * i, &gouba_player3);
                }
            }
        }
    }
    else if (level >= 9 && level < 12)
    {
        for (int i = 0; i < 15; i++)
        {
            for (int j = 0; j < 15; j++)
            {
                if (map[i][j] == 0&&((count == 0) || (i >= 2 )))
                {
                    loadimage(&ground4, "res\\ground4.jpg", 60, 60);
                    putimage(60 * j, 60 * i, &ground4);
                }
                else if (map[i][j] == 1)
                {
                    loadimage(&Wall4, "res\\Wall4.jpg", 60, 60);
                    putimage(60 * j, 60 * i, &Wall4);
                }
                else if (map[i][j] == 2)
                {
                    loadimage(&dot4, "res\\dot4.jpg", 60, 60);
                    putimage(60 * j, 60 * i, &dot4);
                }
                else if (map[i][j] == 3 && remap[i][j] != map[i][j])
                {
                    loadimage(&Box, "res\\Box.jpg", 60, 60);
                    putimage(60 * j, 60 * i, &Box);
                }
                else if (map[i][j] == 4 && remap[i][j] != map[i][j])
                {
                    loadimage(&player4, "res\\player4.jpg", 60, 60);
                    putimage(60 * j, 60 * i, &player4);
                }
                else if (map[i][j] == 5 && remap[i][j] != map[i][j])
                {
                    loadimage(&Boxpro, "res\\Box+Project.jpg", 60, 60);
                    putimage(60 * j, 60 * i, &Boxpro);
                }
                else if (map[i][j] == 6)
                {
                    loadimage(&player4, "res\\player4.jpg", 60, 60);
                    putimage(60 * j, 60 * i, &player4);
                }
                else if (map[i][j] == 7 || map[i][j] == 37)
                {
                    loadimage(&Door, "res\\Door.jpg", 60, 60);
                    putimage(60 * j, 60 * i, &Door);
                }
                else if (map[i][j] == 8)
                {
                    loadimage(&gouba, "res\\gouba.jpg", 60, 60);
                    putimage(60 * j, 60 * i, &gouba);
                }
                else if (map[i][j] == 11)
                {
                    loadimage(&Box_gouba, "res\\Box+gouba.jpg", 60, 60);
                    putimage(60 * j, 60 * i, &Box_gouba);
                }
                else if (map[i][j] == 12)
                {
                    loadimage(&gouba_player4, "res\\gouba+player4.jpg", 60, 60);
                    putimage(60 * j, 60 * i, &gouba_player4);
                }
                else if (map[i][j] == 30)
                {
                    loadimage(&powerground, "res\\powerground.jpg", 60, 60);
                    putimage(60 * j, 60 * i, &powerground);
                }
                else if (map[i][j] == 33)
                {
                    loadimage(&powerbox, "res\\powerbox.jpg", 60, 60);
                    putimage(60 * j, 60 * i, &powerbox);
                }
                else if (map[i][j] == 34)
                {
                    loadimage(&powerplayer4, "res\\powerplayer4.jpg", 60, 60);
                    putimage(60 * j, 60 * i, &powerplayer4);
                }
            }
        }
    }
    else if (level >= 12 && level < 15)
    {
        for (int i = 0; i < 15; i++)
        {
            for (int j = 0; j < 15; j++)
            {
                if (map[i][j] == 0&&((count == 0) || (i >= 2 )))
                {
                    loadimage(&ground5, "res\\ground5.jpg", 60, 60);
                    putimage(60 * j, 60 * i, &ground5);
                }
                else if (map[i][j] == 1)
                {
                    loadimage(&Wall5, "res\\Wall5.jpg", 60, 60);
                    putimage(60 * j, 60 * i, &Wall5);
                }
                else if (map[i][j] == 2)
                {
                    loadimage(&dot5, "res\\dot5.jpg", 60, 60);
                    putimage(60 * j, 60 * i, &dot5);
                }
                else if (map[i][j] == 3 && remap[i][j] != map[i][j])
                {
                    loadimage(&Box, "res\\Box.jpg", 60, 60);
                    putimage(60 * j, 60 * i, &Box);
                }
                else if (map[i][j] == 4 && remap[i][j] != map[i][j])
                {
                    loadimage(&player5, "res\\player5.jpg", 60, 60);
                    putimage(60 * j, 60 * i, &player5);
                }
                else if (map[i][j] == 5 && remap[i][j] != map[i][j])
                {
                    loadimage(&Boxpro, "res\\Box+Project.jpg", 60, 60);
                    putimage(60 * j, 60 * i, &Boxpro);
                }
                else if (map[i][j] == 6)
                {
                    loadimage(&player5, "res\\player5.jpg", 60, 60);
                    putimage(60 * j, 60 * i, &player5);
                }

                else if (map[i][j] == 7 || map[i][j] == 37)
                {
                    loadimage(&Door, "res\\Door.jpg", 60, 60);
                    putimage(60 * j, 60 * i, &Door);
                }
                else if (map[i][j] == 8)
                {
                    loadimage(&gouba, "res\\gouba.jpg", 60, 60);
                    putimage(60 * j, 60 * i, &gouba);
                }
                else if (map[i][j] == 11)
                {
                    loadimage(&Box_gouba, "res\\Box+gouba.jpg", 60, 60);
                    putimage(60 * j, 60 * i, &Box_gouba);
                }
                else if (map[i][j] == 12)
                {
                    loadimage(&gouba_player5, "res\\gouba+player5.jpg", 60, 60);
                    putimage(60 * j, 60 * i, &gouba_player5);
                }
                else if (map[i][j] == 30)
                {
                    loadimage(&powerground, "res\\powerground.jpg", 60, 60);
                    putimage(60 * j, 60 * i, &powerground);
                }
                else if (map[i][j] == 33)
                {
                    loadimage(&powerbox, "res\\powerbox.jpg", 60, 60);
                    putimage(60 * j, 60 * i, &powerbox);
                }
                else if (map[i][j] == 34)
                {
                    loadimage(&powerplayer5, "res\\powerplayer5.jpg", 60, 60);
                    putimage(60 * j, 60 * i, &powerplayer5);
                }
                else if (map[i][j] == 20)
                {
                    loadimage(&senddoor5, "res\\senddoor5.jpg", 60, 60);
                    putimage(60 * j, 60 * i, &senddoor5);
                }
                else if (map[i][j] == 23 && remap[i][j] != map[i][j])
                {
                    loadimage(&Box, "res\\Box.jpg", 60, 60);
                    putimage(60 * j, 60 * i, &Box);
                }
                else if (map[i][j] == 24 && remap[i][j] != map[i][j])
                {
                    loadimage(&player5, "res\\player5.jpg", 60, 60);
                    putimage(60 * j, 60 * i, &player5);
                }
            }
        }
    }

    else if (level >= 15 && level < 18)
    {
        for (int i = 0; i < 15; i++)
        {
            for (int j = 0; j < 15; j++)
            {
                if (map[i][j] == 0&&((count == 0) || (i >= 2 )))
                {
                    loadimage(&ground6, "res\\ground6.jpg", 60, 60);
                    putimage(60 * j, 60 * i, &ground6);
                }
                else if (map[i][j] == 1)
                {
                    loadimage(&Wall6, "res\\Wall6.jpg", 60, 60);
                    putimage(60 * j, 60 * i, &Wall6);
                }
                else if (map[i][j] == 2)
                {
                    loadimage(&dot6, "res\\dot6.jpg", 60, 60);
                    putimage(60 * j, 60 * i, &dot6);
                }
                else if (map[i][j] == 3 && remap[i][j] != map[i][j])
                {
                    loadimage(&Box, "res\\Box.jpg", 60, 60);
                    putimage(60 * j, 60 * i, &Box);
                }
                else if (map[i][j] == 4 && remap[i][j] != map[i][j])
                {
                    loadimage(&player6, "res\\player6.jpg", 60, 60);
                    putimage(60 * j, 60 * i, &player6);
                }
                else if (map[i][j] == 5 && remap[i][j] != map[i][j])
                {
                    loadimage(&Boxpro, "res\\Box+Project.jpg", 60, 60);
                    putimage(60 * j, 60 * i, &Boxpro);
                }
                else if (map[i][j] == 6)
                {
                    loadimage(&player6, "res\\player6.jpg", 60, 60);
                    putimage(60 * j, 60 * i, &player6);
                }

                else if (map[i][j] == 7 || map[i][j] == 37)
                {
                    loadimage(&Door, "res\\Door.jpg", 60, 60);
                    putimage(60 * j, 60 * i, &Door);
                }
                else if (map[i][j] == 8)
                {
                    loadimage(&gouba, "res\\gouba.jpg", 60, 60);
                    putimage(60 * j, 60 * i, &gouba);
                }
                else if (map[i][j] == 11)
                {
                    loadimage(&Box_gouba, "res\\Box+gouba.jpg", 60, 60);
                    putimage(60 * j, 60 * i, &Box_gouba);
                }
                else if (map[i][j] == 12)
                {
                    loadimage(&gouba_player6, "res\\gouba+player6.jpg", 60, 60);
                    putimage(60 * j, 60 * i, &gouba_player6);
                }
                else if (map[i][j] == 30)
                {
                    loadimage(&powerground, "res\\powerground.jpg", 60, 60);
                    putimage(60 * j, 60 * i, &powerground);
                }
                else if (map[i][j] == 33)
                {
                    loadimage(&powerbox, "res\\powerbox.jpg", 60, 60);
                    putimage(60 * j, 60 * i, &powerbox);
                }
                else if (map[i][j] == 34)
                {
                    loadimage(&powerplayer6, "res\\powerplayer6.jpg", 60, 60);
                    putimage(60 * j, 60 * i, &powerplayer6);
                }
                else if (map[i][j] == 20)
                {
                    loadimage(&senddoor6, "res\\senddoor6.jpg", 60, 60);
                    putimage(60 * j, 60 * i, &senddoor6);
                }
                else if (map[i][j] == 23 && remap[i][j] != map[i][j])
                {
                    loadimage(&Box, "res\\Box.jpg", 60, 60);
                    putimage(60 * j, 60 * i, &Box);
                }
                else if (map[i][j] == 24 && remap[i][j] != map[i][j])
                {
                    loadimage(&player6, "res\\player6.jpg", 60, 60);
                    putimage(60 * j, 60 * i, &player6);
                }
                else if (map[i][j] == 40|| map[i][j] == 42)
                {
                    loadimage(&bomb, "res\\bomb.jpg", 60, 60);
                    putimage(60 * j, 60 * i, &bomb);
                }
            }
        }
    }
}
void showrulephotos()  //����ͼƬ��ӳ����
{
        if (level==0&&showtips1 == 1)
        {
        loadimage(&rulephoto1_1, "res\\rulephoto1.1.jpg", 900, 900);
        putimage(0, 0, &rulephoto1_1);
        Sleep(3000);
        loadimage(&rulephoto1_2, "res\\rulephoto1.2.jpg", 900, 900);
        putimage(0, 0, &rulephoto1_2);
        Sleep(1500);
        loadimage(&rulephoto1_3, "res\\rulephoto1.3.jpg", 900, 900);
        putimage(0, 0, &rulephoto1_3);
        Sleep(2500);
        showtips1 = 0;
        }
        else if (level == 1 && showtips3 == 1)
        {
            loadimage(&rulephoto2_1, "res\\rulephoto2.1.jpg", 900, 900);
            putimage(0, 0, &rulephoto2_1);
            Sleep(2500);
            loadimage(&rulephoto2_2, "res\\rulephoto2.2.jpg", 900, 900);
            putimage(0, 0, &rulephoto2_2);
            Sleep(700);
            loadimage(&rulephoto2_3, "res\\rulephoto2.3.jpg", 900, 900);
            putimage(0, 0, &rulephoto2_3);
            Sleep(2500);
            loadimage(&rulephoto2_4, "res\\rulephoto2.4.jpg", 900, 900);
            putimage(0, 0, &rulephoto2_4);
            Sleep(700);
            loadimage(&rulephoto2_5, "res\\rulephoto2.5.jpg", 900, 900);
            putimage(0, 0, &rulephoto2_5);
            Sleep(700);
            loadimage(&rulephoto2_6, "res\\rulephoto2.6.jpg", 900, 900);
            putimage(0, 0, &rulephoto2_6);
            Sleep(700);
            loadimage(&rulephoto2_7, "res\\rulephoto2.7.jpg", 900, 900);
            putimage(0, 0, &rulephoto2_7);
            Sleep(700);
            loadimage(&rulephoto2_8, "res\\rulephoto2.8.jpg", 900, 900);
            putimage(0, 0, &rulephoto2_8);
            Sleep(700);
            loadimage(&rulephoto2_9, "res\\rulephoto2.9.jpg", 900, 900);
            putimage(0, 0, &rulephoto2_9);
            Sleep(700);
            loadimage(&rulephoto2_10, "res\\rulephoto2.10.jpg", 900, 900);
            putimage(0, 0, &rulephoto2_10);
            Sleep(700);
            loadimage(&rulephoto2_11, "res\\rulephoto2.11.jpg", 900, 900);
            putimage(0, 0, &rulephoto2_11);
            Sleep(700);
            loadimage(&rulephoto2_12, "res\\rulephoto2.12.jpg", 900, 900);
            putimage(0, 0, &rulephoto2_12);
            Sleep(700);
            loadimage(&rulephoto2_13, "res\\rulephoto2.13.jpg", 900, 900);
            putimage(0, 0, &rulephoto2_13);
            Sleep(700);
            loadimage(&rulephoto2_14, "res\\rulephoto2.14.jpg", 900, 900);
            putimage(0, 0, &rulephoto2_14);
            Sleep(2500);
            loadimage(&rulephoto3_1, "res\\rulephoto3.1.jpg", 900, 900);
            putimage(0, 0, &rulephoto3_1);
            Sleep(2500);
            loadimage(&rulephoto3_2, "res\\rulephoto3.2.jpg", 900, 900);
            putimage(0, 0, &rulephoto3_2);
            Sleep(2500);
            loadimage(&rulephoto3_3, "res\\rulephoto3.3.jpg", 900, 900);
            putimage(0, 0, &rulephoto3_3);
            Sleep(700);
            loadimage(&rulephoto3_4, "res\\rulephoto3.4.jpg", 900, 900);
            putimage(0, 0, &rulephoto3_4);
            Sleep(700);
            loadimage(&rulephoto3_5, "res\\rulephoto3.5.jpg", 900, 900);
            putimage(0, 0, &rulephoto3_5);
            Sleep(700);
            loadimage(&rulephoto3_6, "res\\rulephoto3.6.jpg", 900, 900);
            putimage(0, 0, &rulephoto3_6);
            Sleep(700);
            loadimage(&rulephoto3_7, "res\\rulephoto3.7.jpg", 900, 900);
            putimage(0, 0, &rulephoto3_7);
            Sleep(2500);
            loadimage(&rulephoto3_8, "res\\rulephoto3.8.jpg", 900, 900);
            putimage(0, 0, &rulephoto3_8);
            Sleep(700);
            loadimage(&rulephoto3_9, "res\\rulephoto3.9.jpg", 900, 900);
            putimage(0, 0, &rulephoto3_9);
            Sleep(700);
            loadimage(&rulephoto3_10, "res\\rulephoto3.10.jpg", 900, 900);
            putimage(0, 0, &rulephoto3_10);
            Sleep(700);
            loadimage(&rulephoto3_11, "res\\rulephoto3.11.jpg", 900, 900);
            putimage(0, 0, &rulephoto3_11);
            Sleep(2500);
            loadimage(&rulephoto3_12, "res\\rulephoto3.12.jpg", 900, 900);
            putimage(0, 0, &rulephoto3_12);
            Sleep(700);
            loadimage(&rulephoto3_13, "res\\rulephoto3.13.jpg", 900, 900);
            putimage(0, 0, &rulephoto3_13);
            Sleep(700);
            loadimage(&rulephoto3_14, "res\\rulephoto3.14.jpg", 900, 900);
            putimage(0, 0, &rulephoto3_14);
            Sleep(700);
            loadimage(&rulephoto3_15, "res\\rulephoto3.15.jpg", 900, 900);
            putimage(0, 0, &rulephoto3_15);
            Sleep(700);
            loadimage(&rulephoto3_16, "res\\rulephoto3.16.jpg", 900, 900);
            putimage(0, 0, &rulephoto3_16);
            Sleep(700);
            loadimage(&rulephoto3_17, "res\\rulephoto3.17.jpg", 900, 900);
            putimage(0, 0, &rulephoto3_17);
            Sleep(1500);
            showtips3 = 0;
        }
        else if (level == 6 && showtips4 == 1)
        {
            loadimage(&rulephoto4_1, "res\\rulephoto4.1.jpg", 900, 900);
            putimage(0, 0, &rulephoto4_1);
            Sleep(2500);
            loadimage(&rulephoto4_2, "res\\rulephoto4.2.jpg", 900, 900);
            putimage(0, 0, &rulephoto4_2);
            Sleep(2500);
            loadimage(&rulephoto4_3, "res\\rulephoto4.3.jpg", 900, 900);
            putimage(0, 0, &rulephoto4_3);
            Sleep(700);
            loadimage(&rulephoto4_4, "res\\rulephoto4.4.jpg", 900, 900);
            putimage(0, 0, &rulephoto4_4);
            Sleep(700);
            loadimage(&rulephoto4_5, "res\\rulephoto4.5.jpg", 900, 900);
            putimage(0, 0, &rulephoto4_5);
            Sleep(700);
            loadimage(&rulephoto4_6, "res\\rulephoto4.6.jpg", 900, 900);
            putimage(0, 0, &rulephoto4_6);
            Sleep(700);
            loadimage(&rulephoto4_7, "res\\rulephoto4.7.jpg", 900, 900);
            putimage(0, 0, &rulephoto4_7);
            Sleep(700);
            loadimage(&rulephoto4_8, "res\\rulephoto4.8.jpg", 900, 900);
            putimage(0, 0, &rulephoto4_8);
            Sleep(700);
            loadimage(&rulephoto4_9, "res\\rulephoto4.9.jpg", 900, 900);
            putimage(0, 0, &rulephoto4_9);
            Sleep(700);
            loadimage(&rulephoto4_10, "res\\rulephoto4.10.jpg", 900, 900);
            putimage(0, 0, &rulephoto4_10);
            Sleep(700);
            loadimage(&rulephoto4_11, "res\\rulephoto4.11.jpg", 900, 900);
            putimage(0, 0, &rulephoto4_11);
            Sleep(1500);
            showtips4 = 0;
            }
        else if (level == 9 && showtips5 == 1)
        {
            loadimage(&rulephoto5_1, "res\\rulephoto5.1.jpg", 900, 900);
            putimage(0, 0, &rulephoto5_1);
            Sleep(2500);
            loadimage(&rulephoto5_2, "res\\rulephoto5.2.jpg", 900, 900);
            putimage(0, 0, &rulephoto5_2);
            Sleep(700);
            loadimage(&rulephoto5_3, "res\\rulephoto5.3.jpg", 900, 900);
            putimage(0, 0, &rulephoto5_3);
            Sleep(1500);
            showtips5 = 0;
            }
        else if (level == 12 && showtips6 == 1)
        {
            loadimage(&rulephoto6_1, "res\\rulephoto6.1.jpg", 900, 900);
            putimage(0, 0, &rulephoto6_1);
            Sleep(2500);
            loadimage(&rulephoto6_2, "res\\rulephoto6.2.jpg", 900, 900);
            putimage(0, 0, &rulephoto6_2);
            Sleep(700);
            loadimage(&rulephoto6_3, "res\\rulephoto6.3.jpg", 900, 900);
            putimage(0, 0, &rulephoto6_3);
            Sleep(700);
            loadimage(&rulephoto6_4, "res\\rulephoto6.4.jpg", 900, 900);
            putimage(0, 0, &rulephoto6_4);
            Sleep(1500);
            showtips6 = 0;
            }
        else if (level == 15 && showtips7 == 1)
        {
            loadimage(&rulephoto7_1, "res\\rulephoto7.1.jpg", 900, 900);
            putimage(0, 0, &rulephoto7_1);
            Sleep(2500);
            loadimage(&rulephoto7_2, "res\\rulephoto7.2.jpg", 900, 900);
            putimage(0, 0, &rulephoto7_2);
            Sleep(500);
            loadimage(&rulephoto7_3, "res\\rulephoto7.3.jpg", 900, 900);
            putimage(0, 0, &rulephoto7_3);
            Sleep(500);
            loadimage(&rulephoto7_4, "res\\rulephoto7.4.jpg", 900, 900);
            putimage(0, 0, &rulephoto7_4);
            Sleep(1500);
            showtips7 = 0;
            }
    }
void showmap()            //��ͼƬ��ӡ���µ�ͼ
{
    int  len1 = 0, width1 = 0;
    char  str[30][20] = { "LEVEL:1","LEVEL:2","LEVEL:3","LEVEL:4","LEVEL:5","LEVEL:6","LEVEL:7","LEVEL:8","LEVEL:9","LEVEL:10","LEVEL:11","LEVEL:12","LEVEL:13","LEVEL:14","LEVEL:15","LEVEL:16","LEVEL:17","LEVEL:18","����ʱ��:" };
    char represnttime[100] = { 0 }, sig[2] = {':','\0'}, min[3] = {0}, sec[3] = {0};
    showphotos();
    if (level != -1&&count==0)
    {
        setfillcolor(RGB(161, 161, 161));
        fillrectangle(0, 0, 900, 100);
        setbkmode(TRANSPARENT);
        settextcolor(RGB(237, 28, 36));
        settextstyle(23, 14, "����");
        len1 = textwidth(str[level]);
        width1 = textheight(str[level]);
        outtextxy(200 - len1 / 2, 50 - width1 / 2, str[level]);
        count = 1;
    }
}
void copyremap()                  //���Ƶ��µ�ͼ���Ա���һ�ֲ���������бȶԣ����Ƶ������
{
    for (int i = 0; i < 15; i++)
    {
        for (int j = 0; j < 15; j++)
        {
            remap[i][j] = map[i][j];
        }
    }
}
int FindKeymap(int x, int y)       //�ڹؿ������ж���갴����������ذ���ֵ
{
    if (x > 980 && x < 1120)
    {
        for (int i = 0; i < 5; i++)
        {
            if (y > 100 + 150 * i && y < 150 + 150 * i)
            {
                return i;
            }
        }
        return 7;
    }
    else
    {
        return 7;
    }
}
void keypush(int i, int j)            //���ݻ�ȡ�ļ�����Ϣ�Ե�ͼ�����޸�
{
    if (GetAsyncKeyState(VK_UP))
    {
        counter++;
        if (map[i - 1][j] == SPACE || map[i-1][j]==8 || map[i - 1][j] == 2|| map[i - 1][j] == 30 || map[i - 1][j] == 20)
        {
            map[i - 1][j] += 4;
            map[i][j] -= 4;
        }
        else if (map[i - 1][j] == 3 || map[i - 1][j] == 5||map[i-1][j]==11||map[i-1][j]==33 || map[i - 1][j] == 23)
        {
            if (map[i - 2][j] == 2 || map[i - 2][j] == SPACE || map[i - 2][j] == 8 || map[i - 2][j] == 30 || map[i - 2][j] == 20)
            {
                pushcounter++;
                map[i - 2][j] += 3;
                map[i - 1][j] -= 3;
                map[i - 1][j] += 4;
                map[i][j] -= 4;
            }
        }
        else if (map[i - 1][j] == 40 || map[i - 1][j] == 42 || map[i - 1][j] == 48 || map[i - 1][j] == 70)
        {
            if (map[i - 2][j] == 2 || map[i - 2][j] == SPACE || map[i - 2][j] == 8 || map[i - 2][j] == 30 || map[i - 2][j] == 20||map[i - 2][j] == 1)
            {
                pushcounter++;
                map[i - 2][j] += 40;
                map[i - 1][j] -= 40;
                map[i - 1][j] += 4;
                map[i][j] -= 4;
            }
        }
     
        if (map[i][j]==34)
        {
            if ((map[i - 1][j] == 33 || map[i - 1][j] == 3 || map[i - 1][j] == 5) && (map[i - 2][j] == 33 || map[i - 2][j] == 3 || map[i - 2][j] == 5))//��������
            {
                if (map[i - 3][j] == SPACE || map[i - 3][j] == 2 || map[i - 3][j] == 8 || map[i - 3][j] == 30 || map[i - 3][j] == 20)
                {
                    pushcounter++;
                    map[i - 3][j] += 3;
                    map[i - 1][j] -= 3;
                    map[i - 1][j] += 4;
                    map[i][j] -= 4;
                } 
            }
        }
    }
    else if (GetAsyncKeyState(VK_DOWN))
    {
        counter++;
        if (map[i + 1][j] == SPACE || map[i + 1][j] == 8 || map[i + 1][j] == 2 || map[i + 1][j] == 30 || map[i + 1][j] == 20)
        {
            map[i + 1][j] += 4;
            map[i][j] -= 4;
        }
        else if (map[i + 1][j] == 3 || map[i + 1][j] == 5 || map[i + 1][j] == 11 || map[i + 1][j] == 33 || map[i + 1][j] == 23)
        {
            if (map[i + 2][j] == 2 || map[i + 2][j] == SPACE || map[i + 2][j] == 8 || map[i + 2][j] == 30 || map[i + 2][j] == 20)
            {
                pushcounter++;
                map[i + 2][j] += 3;
                map[i + 1][j] -= 3;
                map[i + 1][j] += 4;
                map[i][j] -= 4;
            }
        }
        else if (map[i + 1][j] == 40 || map[i + 1][j] == 42 || map[i + 1][j] == 48 || map[i + 1][j] == 70)
        {
            if (map[i + 2][j] == 2 || map[i + 2][j] == SPACE || map[i + 2][j] == 8 || map[i + 2][j] == 30 || map[i + 2][j] == 20 || map[i + 2][j] == 1)
            {
                pushcounter++;
                map[i + 2][j] += 40;
                map[i + 1][j] -= 40;
                map[i + 1][j] += 4;
                map[i][j] -= 4;
            }
        }

        if (map[i][j] == 34)
        {
            if ((map[i + 1][j] == 33 || map[i + 1][j] == 3 || map[i + 1][j] == 5) && (map[i + 2][j] == 33 || map[i + 2][j] == 3 || map[i + 2][j] == 5))//��������
            {
                if (map[i + 3][j] == SPACE || map[i + 3][j] == 2 || map[i + 3][j] == 8 || map[i + 3][j] == 30 || map[i + 3][j] == 20)
                {
                    pushcounter++;
                    map[i + 3][j] += 3;
                    map[i + 1][j] -= 3;
                    map[i + 1][j] += 4;
                    map[i][j] -= 4;
                }
            }
        }
    }
    else if (GetAsyncKeyState(VK_LEFT))
    {
        counter++;
        if (map[i][j-1] == SPACE || map[i][j-1] == 8 || map[i][j-1] == 2 || map[i][j-1] == 30 || map[i][j-1] == 20)
        {
            map[i][j-1] += 4;
            map[i][j] -= 4;
        }
        else if (map[i][j-1] == 3 || map[i][j-1] == 5 || map[i][j-1] == 11 || map[i][j-1] == 33 || map[i][j-1] == 23)
        {
            if (map[i][j-2] == 2 || map[i][j-2] == SPACE || map[i][j-2] == 8 || map[i][j-2] == 30 || map[i][j-2] == 20)
            {
                pushcounter++;
                map[i][j-2] += 3;
                map[i][j-1] -= 3;
                map[i][j-1] += 4;
                map[i][j] -= 4;
            }
        }
        else if (map[i][j-1] == 40 || map[i][j-1] == 42 || map[i][j-1] == 48 || map[i][j-1] == 70)
        {
            if (map[i][j-2] == 2 || map[i][j-2] == SPACE || map[i][j-2] == 8 || map[i][j-2] == 30 || map[i][j-2] == 20 || map[i][j-2] == 1)
            {
                pushcounter++;
                map[i][j-2] += 40;
                map[i][j-1] -= 40;
                map[i][j-1] += 4;
                map[i][j] -= 4;
            }
        }

        if (map[i][j] == 34)
        {
            if ((map[i][j-1] == 33 || map[i][j-1] == 3 || map[i][j-1] == 5) && (map[i][j-2] == 33 || map[i][j-2] == 3 || map[i][j-2] == 5))//��������
            {
                if (map[i][j-3] == SPACE || map[i][j-3] == 2 || map[i][j-3] == 8 || map[i][j-3] == 30 || map[i][j -3] == 20)
                {
                    pushcounter++;
                    map[i][j-3] += 3;
                    map[i][j-1] -= 3;
                    map[i][j-1] += 4;
                    map[i][j] -= 4;
                }
            }
        }
    }
    else if (GetAsyncKeyState(VK_RIGHT))
    {
        counter++;
        if (map[i][j +1] == SPACE || map[i][j +1] == 8 || map[i][j +1] == 2 || map[i][j +1] == 30 || map[i][j +1] == 20)
        {
            map[i][j +1] += 4;
            map[i][j] -= 4;
        }
        else if (map[i][j +1] == 3 || map[i][j +1] == 5 || map[i][j +1] == 11 || map[i][j +1] == 33 || map[i][j +1] == 23)
        {
            if (map[i][j +2] == 2 || map[i][j +2] == SPACE || map[i][j +2] == 8 || map[i][j +2] == 30 || map[i][j +2] == 20)
            {
                pushcounter++;
                map[i][j +2] += 3;
                map[i][j +1] -= 3;
                map[i][j +1] += 4;
                map[i][j] -= 4;
            }
        }
        else if (map[i][j +1] == 40 || map[i][j +1] == 42 || map[i][j +1] == 48 || map[i][j +1] == 70)
        {
            if (map[i][j +2] == 2 || map[i][j +2] == SPACE || map[i][j +2] == 8 || map[i][j +2] == 30 || map[i][j +2] == 20 || map[i][j +2] == 1)
            {
                pushcounter++;
                map[i][j +2] += 40;
                map[i][j +1] -= 40;
                map[i][j +1] += 4;
                map[i][j] -= 4;
            }
        }

        if (map[i][j] == 34)
        {
            if ((map[i][j +1] == 33 || map[i][j +1] == 3 || map[i][j +1] == 5) && (map[i][j +2] == 33 || map[i][j +2] == 3 || map[i][j +2] == 5))//��������
            {
                if (map[i][j +3] == SPACE || map[i][j +3] == 2 || map[i][j +3] == 8 || map[i][j + 3] == 30 || map[i][j + 3] == 20)
                {
                    pushcounter++;
                    map[i][j +3] += 3;
                    map[i][j +1] -= 3;
                    map[i][j +1] += 4;
                    map[i][j] -= 4;
                }
            }
        }
        }
  
}
void pushbox()             //��¼�����Ӷ���
{
    int i = 0, j = 0;
    Sleep(80);
    //Ѱ������±�
    int findplayer = 0;
    for (i = 0; i < 15; i++)
    {
        findplayer = 0;
        for (j = 0; j < 15; j++)
        {
            if (map[i][j] == 4 || map[i][j] == 6 || map[i][j] == 12||map[i][j]==34||map[i][j]==24)
            {
                findplayer = 1;
                break;
            }
        }
        if (findplayer == 1)
        {
            break;
        }
    }
    //��ȡ����
    if (label1 == 0)
    {
        keypush(i, j);
    }
    int i1 = -1, i2 = -1, i3 = -1, j1 = -1, j2 = -1, j3 = -1, temp;
    senddoornum = 0;
    for (int i = 0; i < 15; i++)
    {
        for (int j = 0; j < 15; j++)
        {
            if (map[i][j] == 20)
            {
                senddoornum++;
            }
            if (senddoornum == 2)
            {
                stopsend = 0;
            }
        }
        }
    for (int i = 0; i < 15; i++)
    {
        for (int j = 0; j < 15; j++)
        {
            if (map[i][j] == 20)
            {
                i1 = i;
                j1 = j;
            }
            else if (map[i][j] == 23 && stopsend == 0)
            {
                sendsth = 1;
                i2 = i;
                j2 = j;
                
            }
            else if (map[i][j] == 24 && stopsend == 0)
            {
                sendsth = 2;
                i3 = i;
                j3 = j;
            }
        }
    }
    if (sendsth == 1 &&stopsend == 0)
    {
        temp = map[i1][j1];
        map[i1][j1] = map[i2][j2];
        map[i2][j2] = temp;
        sendsth = 0;
        stopsend = 1;
    }
    else if (sendsth == 2 && stopsend == 0)
    {
        temp = map[i3][j3];
        map[i3][j3] = map[i1][j1];
        map[i1][j1] = temp;
        sendsth = 0;
        stopsend = 1;
    }
}
bool judge()          //�ж�����״̬��ͳ��ʣ��������
{
    int boxnum = 0,len=0,width=0,destnum=0;

    char str[100] = "ʣ����������", Num[15][10] = {"0","1","2","3","4","5","6","7","8","9","10","11","12","13","14"};
    char count[20] = "�ж�������", numcount[100];
    char pushcount[20] = "�ƶ�������",numpushcount[100] ;
    itoa(counter, numcount, 10);
    itoa(pushcounter,numpushcount,10);
    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COL; j++)
        {
            if (map[i][j] == 3|| map[i][j] == 33||map[i][j] == 11||map[i][j]==23)
            {
                boxnum++;
            }
        }
    }
    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COL; j++)
        {
            if (map[i][j] ==2)
            {
                destnum++;
            }
        }
    }
    setfillcolor(RGB(195, 195, 195));
    fillroundrect(950,800,1150,850,10,10);
    setbkmode(TRANSPARENT);
    settextcolor(RGB(199, 29, 247));
    settextstyle(20, 12, "����");
    strcat_s(str, Num[boxnum]);
    len = textwidth(str);
    width = textheight(str); count;
    outtextxy(1050-len/2,825-width/2,str);
    setfillcolor(RGB(161, 161, 161));
    fillrectangle(300,0, 900, 100);
    settextcolor(RGB(199, 29, 247));
    settextstyle(20, 12, "����");
    strcat_s(count, numcount);
    len = textwidth(count);
    width = textheight(count);
    outtextxy(500 - len / 2, 50 - width / 2, count);
    strcat_s(pushcount, numpushcount);
    len = textwidth(pushcount);
    width = textheight(pushcount);
    outtextxy(750 - len / 2, 50 - width / 2, pushcount);

    if (destnum == 0&&boxnum==0)
        return true;
    else
        return false;
}
void stopmusic()  //ֹͣ�������ڲ��ŵ�����
{

    mciSendString("stop res\\HolyLand.mp3", NULL, 0, NULL);
    mciSendString("close res\\HolyLand.mp3", NULL, 0, NULL);
    mciSendString("stop res\\ANocturneforAll.mp3", NULL, 0, NULL);
    mciSendString("close res\\ANocturneforAll.mp3", NULL, 0, NULL);
    mciSendString("stop res\\Grudge.mp3", NULL, 0, NULL);
    mciSendString("close res\\Grudge.mp3", NULL, 0, NULL);
    mciSendString("stop res\\North.mp3", NULL, 0, NULL);
    mciSendString("close res\\North.mp3", NULL, 0, NULL);
    mciSendString("stop res\\Compounding.mp3", NULL, 0, NULL);
    mciSendString("close res\\Compounding.mp3", NULL, 0, NULL);
    mciSendString("stop res\\TheSun.mp3", NULL, 0, NULL);
    mciSendString("close res\\TheSun.mp3", NULL, 0, NULL);

}
int FindKeyMenu(int x, int y)    //�жϲ˵�ʱ���״̬
{
    int sign = 0;
        if ((y > 270 && y < 350) && (x > 550 && x < 690))
        {
            sign = 18;
        }
        else if (y > 380 && y < 460)
        {
            int j = 0;
            for (int i = 40; i < 1100; i = i + 200)
            {
                if (x > i && x < i + 140)
                {
                    sign = j;

                    break;
                }
                j++;
            }
        }
        else if (y > 580 && y < 660)
        {
            int j = 0;
            for (int i = 40; i < 1100; i = i + 200)
            {
                if (x > i && x < i + 140)
                {
                    sign = j+6;
                    break;
                }
                j++;
            }
        }
        else if (y > 780 && y < 860)
        {
            int j = 0;
            for (int i = 40; i < 1100; i = i + 200)
            {
                if (x > i && x < i + 140)
                {
                    sign = j+12;
                    break;
                }
                j++;
            }
        }
        else
        {
            sign = -1;
        }
    return sign;
}
void Print6(void)     //��ӡ�˵�
{
    int  len = 0, hight = 0, lenkey = 80, lenkeyx = 140, keyx[8] = { 40,240,440,640,840,1040,550 }, keyy[4] = {380,580,780,270},count=0,sign = -1;
    char str[20][100] = { "�ؿ�1","�ؿ�2","�ؿ�3","�ؿ�4","�ؿ�5","�ؿ�6","�ؿ�7","�ؿ�8","�ؿ�9","�ؿ�10","�ؿ�11","�ؿ�12","�ؿ�13","�ؿ�14","�ؿ�15","�ؿ�16","�ؿ�17","�ؿ�18","�˳�" };
    setbkcolor(RGB(110, 226, 229));
    cleardevice();
    loadimage(&Box, "res\\Box.jpg", 60, 60);
    putimage(550, 150, &Box);
    settextcolor(RGB(255, 248, 71));
    settextstyle(90, 60, "����");
    len = textwidth("������");
    outtextxy((1200 - len) / 2, 20, "������");
    setfillcolor(RGB(240, 190, 20));
    setbkmode(TRANSPARENT);
    settextstyle(30, 23, "����");
    count = 0;
    for (int j = 0; j < 3; j++)
    {
        for (int i = 0; i < 6; i++)
        {
            len = textwidth(str[count]);
            hight = textheight(str[count]);
            fillroundrect(keyx[i], keyy[j], keyx[i] + lenkeyx, keyy[j] + lenkey, 10, 10);
            outtextxy(keyx[i] + (lenkeyx - len) / 2, keyy[j] + (lenkey - hight) / 2, str[count]);
            count++;
        }
   }
    len = textwidth(str[18]);
    hight = textheight(str[18]);
    fillroundrect(keyx[6], keyy[3], keyx[6] + lenkeyx, keyy[3] + lenkey, 10, 10);
    outtextxy(keyx[6] + (lenkeyx - len) / 2, keyy[3] + (lenkey - hight) / 2, str[18]);
}
int Determin(void)      //�����Ϣ�ж�
{
    sign = -1;
    while (sign == -1)
    {
        if (peekmessage(&msg, EM_MOUSE))
        {
            switch (msg.message)
            {
            case WM_LBUTTONDOWN:
            {
                sign = FindKeyMenu(msg.x, msg.y);
                printf("%d", sign);
                break;
            }
            default:
                break;
            }
        }
    }
    return sign;
}
void showtips()  //��ʾ��Ϣ����
{
    int len = 0, width = 0,num=0;
    srand(time(NULL));
    char tips[15][100] = { "Tip: You can input Q to restart directly!" ,
        "Tip: Two boxes next to each other cannot be pushed." ,
        "Tip: Have you encountered any difficulties? Try the next level!",
        "Tip: Guess what the next tip will be.",
        "Tip: If you accidentally make a mistake, you can only......"
        "Tip: Try other modes!",
        "Tip: Someone come to push the box.",
        "Tip: You're reading the tips again and again!",
        "Tip: Don't push the boxes into dead corners, they won't come out!",
        "Tip: I heard that people with an IQ of 210 can pass just by playing once."
    };
    int magic = rand() % 10 + 1;
    num = magic;
    setfillcolor(RGB(161, 161, 161));
    fillrectangle(100, 400, 800, 500);
    setbkmode(TRANSPARENT);
    settextcolor(RGB(237, 28, 36));
    settextstyle(15, 9, "����");
     len = textwidth(tips[num]);
     width = textheight(tips[num]);
     outtextxy(450 - len / 2, 450 - width / 2, tips[num]);
}
void PrintMap(int lev)    //��ӡ���н���
{
    int len = 0, width = 0, len1 = 0, len2 = 0, width1 = 0, width2 = 0, lenkey = 80, lenkeyx = 140, keyx[8] = { 40,240,440,640,840,1040,550 }, keyy[4] = { 380,580,780,270 };
    char Keys[8][50] = { "���ز˵�","���¿�ʼ","��ʾ","�浵","�ָ�","Tip:ÿһ��ֻ����ʾһ��"};
    char str[20][100] = { "�ؿ�1","�ؿ�2","�ؿ�3","�ؿ�4","�ؿ�5","�ؿ�6","�ؿ�7","�ؿ�8","�ؿ�9","�ؿ�10","�ؿ�11","�ؿ�12","�ؿ�13","�ؿ�14","�ؿ�15","�ؿ�16","�ؿ�17","�ؿ�18","�˳�" };
    switch (lev)
    {
    case -1:
    {
        Print6();
        level = Determin();
        if (level >= 0 && level != 18)               //��Ⱦ���Ч��
        {
            len = textwidth(str[level]);
            width = textheight(str[level]);
            setfillcolor(RGB(217, 172, 161));
            setbkmode(TRANSPARENT);
            settextstyle(30, 23, "����");
            fillroundrect(keyx[level % 6], keyy[level / 6], keyx[level % 6] + lenkeyx, keyy[level / 6] + lenkey, 10, 10);
            outtextxy(keyx[level % 6] + (lenkeyx - len) / 2, keyy[level / 6] + (lenkey - width) / 2, str[level]);
        }
        else if (level == 18)
        {
            len = textwidth(str[18]);
            width = textheight(str[18]);
            setfillcolor(RGB(217, 172, 161));
            setbkmode(TRANSPARENT);
            settextstyle(30, 23, "����");
            fillroundrect(keyx[6], keyy[3], keyx[6] + lenkeyx, keyy[3] + lenkey, 10, 10);
            outtextxy(keyx[6] + (lenkeyx - len) / 2, keyy[3] + (lenkey - width) / 2, str[18]);
        }
        Sleep(250);
        break;
    }
    case 18:
    {
        closegraph();
        exi = 1;
        stopmusic();
        break;
    }
    default:
    {
        showrulephotos();
        showmap();
        setfillcolor(RGB(195, 195, 195));
        for (int i = 0; i < 5; i++)
        {
            setbkmode(TRANSPARENT);
            settextcolor(RGB(199, 29, 247));
            settextstyle(20, 12, "����");
            len = textwidth(Keys[i]);
            width = textheight(Keys[i]);
            fillroundrect(980, 100 + 150 * i, 1120, 150 + 150 * i, 10, 10);
            outtextxy(1050 - len / 2, 125 + 150 * i - width / 2, Keys[i]);
        }
        setfillcolor(RGB(255, 125, 164));
        setbkmode(TRANSPARENT);
        settextcolor(RGB(199, 29, 247));
        settextstyle(20, 12, "����");
        if (key == 0 || key == 1 || key == 2||key==3||key==4)
        {
            len = textwidth(Keys[key]);
            width = textheight(Keys[key]);
            fillroundrect(980, 100 + 150 * key, 1120, 150 + 150 * key, 10, 10);
            outtextxy(1050 - len / 2, 125 + 150* key - width / 2, Keys[key]);
            key=7;
        }
    }
    }
}
void Loading(void)  //���ؽ���
{
    int len = 0, width = 0;
    char load[100] = { "Loading����" };
    setfillcolor(RGB(115, 251, 253));
    fillrectangle(0, 0, 1200, 900);
    setbkmode(TRANSPARENT);
    settextcolor(RGB(237, 28, 36));
    settextstyle(100, 70, "����");
    len = textwidth(load);
    width = textheight(load);
    outtextxy(520 - len / 2, 450 - width / 2, load);
}
DWORD WINAPI ThreadProc(PVOID lp)  //�����Ϣ����
{
    int back=  0 , forth =  0 ,len=0,width=0;
    while (1)
    {
        ExMessage mouse;
        if (peekmessage(&mouse, EM_MOUSE))
        {
            switch (mouse.message)
            {
                case WM_LBUTTONDOWN:
                {
                    key = FindKeymap(mouse.x, mouse.y);
                    break;
                }
                default:
                    break;
            }
            switch (key)
            {
                case 0:
                {
                    label1 = 1;
                    label3 = 0;
                    level = -1;
                    Loading();
                    break;
                }
                case 1:
                {
                    time5=1;
                    break;
                }
                case 2:
                {
                    label1 = 0;
                    if (times < 2)
                    {
                        times++;
                        Sleep(100);
                        showtips();
                    }
                    break;
                }
                case 3:
                {
                    if (counter - memcounter >= 1)
                    {
                        lct1 = 0;
                    }
                    if (lct1 == 0)
                    {
                        copymemorymap();
                        memcounter = counter;
                        mempushcounter = pushcounter;
                        label1 = 0;
                        lct1 = 1;
                        lct3 = 0;
                    }
                    break;
                }
                case 4:
                {
                    if (counter - memcounter >= 1)
                    {
                        label1 = 0;
                        counter = memcounter;
                        pushcounter = mempushcounter;
                        lct1 = 0;
                        lct2 = 1;
                        lcttime++;
                   }
                    break;
                }
                case 7:
                {
                    label1 = 0;
                    break;
                }
                default:
                {
                    label1 = 0;
                    time5 = 0;
                    break;
                }
            }
        }
    }
    return 0;
}
/*DWORD WINAPI ThreadProb(PVOID lp)
{
    int len1 = 0, len2 = 0, width1 = 0, width2 = 0;
    char  change[2][20] = { 0 }, str[7][20] = {"LEVEL:1","LEVEL:2","LEVEL:3","LEVEL:4","LEVEL:5","LEVEL:6","����ʱ��:"};
    start = clock();
    while (1)
    {
        setfillcolor(RGB(161, 161, 161));
        fillrectangle(0, 0, 900, 100);
        setbkmode(TRANSPARENT);
        settextcolor(RGB(237, 28, 36));
        settextstyle(23, 14, "����");
        len1 = textwidth(str[0]);
        width1 = textheight(str[0]);
        outtextxy(200 - len1 / 2, 50 - width1 / 2, str[0]);
        end = clock();
        gcvt((float)(end - start) / CLOCKS_PER_SEC, 5, change[1]);
        strcat(str[1], change[1]);
        len2 = textwidth(str[1]);
        width2 = textheight(str[1]);
        outtextxy(650 - len2 / 2, 50 - width2 / 2, str[1]);
    }
    return 0;
}*/
void search()  //Ѱ�Ҵ�����
{
   
    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COL; j++)
        {
            if (map[i][j] == 11)
            {
                cleardoor = 1;
                break;
            }
        }
    }
    if (cleardoor == 1)
    {
        for (int i = 0; i < ROW; i++)
        {
            for (int j = 0; j < COL; j++)
            {
                if (map[i][j] == 7)
                {
                    map[i][j] = 0;
                }
            }
        }
    }
}
void doorback()  
{
    existdoor = 1;
    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COL; j++)
        {
            if (map[i][j] == 11)
            {
                existdoor = 0;
                break;
            }
        }
    }
    if (existdoor == 1)
    {
        for (int i = 0; i < ROW; i++)
        {
            for (int j = 0; j < COL; j++)
            {
                if (origin[level][i][j] == 7)
                {
                    if (map[i][j] == 0)
                        map[i][j] = 7;
                    else if (map[i][j] == 30)
                        map[i][j] = 37;
                    
                }
            }
        }
    }
}
void startmusic()  //��������
{
    mciSendString("open res\\playSound.mp3", NULL, 0, NULL);
    mciSendString("play res\\playSound.mp3", NULL, 0, NULL);
    Sleep(600);
    mciSendString("stop res\\playSound.mp3", NULL, 0, NULL);
    mciSendString("close res\\playSound.mp3", NULL, 0, NULL);
    if (level >= 0 && level < 3)
    {
        stopmusic();
        mciSendString("open res\\HolyLand.mp3", NULL, 0, NULL);
        mciSendString("play res\\HolyLand.mp3", NULL, 0, NULL);
    }
    else if (level >= 3 && level < 6)
    {
        stopmusic();
        mciSendString("open res\\ANocturneforAll.mp3", NULL, 0, NULL);
        mciSendString("play res\\ANocturneforAll.mp3", NULL, 0, NULL); 
    }
    else if (level >= 6 && level < 9)
    {
        stopmusic();
        mciSendString("open res\\Grudge.mp3", NULL, 0, NULL);
        mciSendString("play res\\Grudge.mp3", NULL, 0, NULL);
    }
    else if (level >= 9 && level < 12)
    {
        stopmusic();
        mciSendString("open res\\North.mp3", NULL, 0, NULL);
        mciSendString("play res\\North.mp3", NULL, 0, NULL);
    }
    else if (level >= 12 && level < 15)
    {
        stopmusic();
        mciSendString("open res\\Compounding.mp3", NULL, 0, NULL);
        mciSendString("play res\\Compounding.mp3", NULL, 0, NULL);
    }
    else if (level >= 15 && level < 18)
    {
        stopmusic();
        mciSendString("open res\\TheSun.mp3", NULL, 0, NULL);
        mciSendString("play res\\TheSun.mp3", NULL, 0, NULL);
    }
}
/*void startvideo1()
{
    switch (level)
    {
    case 0:
        const char* videoFilePath = "testvideo.mp4";
        HINSTANCE hInst = ShellExecute(NULL, "open", videoFilePath, NULL, NULL, SW_SHOWNORMAL);
        break;
    }
}*/
void bombdoor()    //�޸���Ϊ�յ�
{
    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COL; j++)
        {
            if (map[i][j] == 41)
            {
                map[i][j] = 0;
            }
        }
    }
}
int main(void) 
{
	int len=0,width=0,mark=0;
     mciSendString("open res\\happy.mp3", NULL, 0, NULL);
    mciSendString("play res\\happy.mp3", NULL, 0, NULL);
    HANDLE h=CreateThread(NULL, 0, ThreadProc, 0, CREATE_SUSPENDED, 0);
    //HANDLE e= CreateThread(NULL, 0, ThreadProb, 0, CREATE_SUSPENDED, 0);
    char remind[5][50] = { "�ɹ����أ�" ,"���Ѿ�������йؿ���","����ɹ���" };
    initgraph(1200, 900, 0);
    //BeginBatchDraw();
    while (TRUE)
    {
        counter = 0;
        pushcounter = 0;
        memcounter = 0;
        mempushcounter = 0;
        stopmusic();
        mciSendString("open res\\happy.mp3", NULL, 0, NULL);
        mciSendString("play res\\happy.mp3", NULL, 0, NULL);
        cleardevice();
        key = -2;
        level = -1;
        time2 = 0;
        setbkcolor(RGB(222, 197, 36));
        cleardevice();
        PrintMap(level);
        if (level == 18)
        {
            PrintMap(level);
        }
        if (exi == 1)
        {
            exit(0);
        }
        cleardevice();
        PrintMap(level);
        //EndBatchDraw();
        if (h!= 0)
        {
            ResumeThread(h);
        }
        while (level < LEVEL&&level>=0)
        {
            count = 0;
            memcounter = 0;
            mempushcounter = 0;
            mciSendString("stop res\\happy.mp3", NULL, 0, NULL);
            mciSendString("close res\\happy.mp3", NULL, 0, NULL);
            Loading();
            startmusic();
            //ResumeThread(e);
            copymap();
            clearmap();
            singal = 0;
            flag = 0;
            label2 = 0;
            time5 = 0;               
            //time6 = 0;
            lcttime = 0;
            while (!flag)
            {
                if (time5 == 1)//&&time6==0
                {
                    copymap();
                    clearmap();
                    for (int i = 0; i < 15; i++)
                    {
                        for (int j = 0; j < 15; j++)
                        {
                            memory[i][j] = origin[level][i][j];
                        }
                    }
                    singal = 0;
                    time5 = 0;
                    //time6 = 1;
                    lcttime = 0;
                    counter = 0;
                    pushcounter = 0;
                    memcounter = 0;
                    mempushcounter = 0;
                }
                else if (lct2== 1)
                {
                    readmemorymap();
                    lct2 = 0;
                }

                flag = 0;
                label2 = 0;
                if (times != 0 && time2 == 0)
                {
                    Sleep(2000);
                    time2 = 1;
                }
                PrintMap(level);
                copyremap();
                singal = 1;
                if ( lct3 == 0)
                {
                    setfillcolor(RGB(255, 242, 0));
                    fillrectangle(300, 0, 900, 100);
                    setbkmode(TRANSPARENT);
                    settextcolor(RGB(237, 28, 36));
                    settextstyle(25, 14, "����");
                    len = textwidth(remind[2]);
                    width = textheight(remind[2]);
                    outtextxy(600 - len / 2, 50 - width / 2, remind[2]);
                    Sleep(500);
                    lct3 = 1;
                }
                if (judge())
                { 
                    countscore();
                char txtscore[20] = "������", totalscore[100];
                sprintf(totalscore, "%f", ((double)score) / 10000);
                strcat_s(txtscore, totalscore);
                    flag = 0;
                    setfillcolor(RGB(161, 161, 161));
                    fillrectangle(200, 325, 700, 575);
                    setbkmode(TRANSPARENT);
                    settextcolor(RGB(237, 28, 36));
                    settextstyle(25, 14, "����");
                    len = textwidth(remind[0]);
                    width = textheight(remind[0]);
                    outtextxy(450 - len / 2, 375 - width / 2, remind[0]);
                    len = textwidth(txtscore);
                    width = textheight(txtscore);
                    outtextxy(450 - len / 2, 525 - width / 2, txtscore);
                    while (!mark)
                    {
                        if (GetAsyncKeyState(VK_RETURN))
                        {
                            mark = 1;
                        }
                    }
                    mark = 0;
                    level++;
                    flag = 1;
                    counter = 0;
                    pushcounter = 0;
                    score = 0;
                    if (level > (LEVEL - 1))
                    {
                        setfillcolor(RGB(161, 161, 161));
                        fillrectangle(200, 325, 700, 575);
                        setbkmode(TRANSPARENT);
                        settextcolor(RGB(237, 28, 36));
                        settextstyle(25, 14, "����");
                        len = textwidth(remind[1]);
                        width = textheight(remind[1]);
                        outtextxy(450 - len / 2, 375 - width / 2, remind[1]);
                        len = textwidth(txtscore);
                        width = textheight(txtscore);
                        outtextxy(450 - len / 2, 650 - width / 2, txtscore);
                    }
                   }
                pushbox();
                if (label1)
                {
                    label2 = 1;
                    break;
                }
                search();
                doorback();
                bombdoor();
            }
            if (label2 == 1&&label3!=1)
            {
                Sleep(1000);
                break;
            }
            counter = 0;
            pushcounter = 0;
            //ResumeThread(e);
        }
        if (h != 0)
        {
            SuspendThread(h);
        }
    }
    //EndBatchDraw();
	return 0;
}