#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<windows.h>
#include<conio.h>
#define M 22 // 18 22  25
#define N  3 //  8  3   0
int G[M][M]={0};
 
using namespace std;
 
//�]�w��Ц�m
void gotoxy(int xpos, int ypos)
{
  COORD scrn;
  HANDLE hOuput = GetStdHandle(STD_OUTPUT_HANDLE);
  scrn.X = xpos; scrn.Y = ypos;
  SetConsoleCursorPosition(hOuput,scrn); //�]�w��Ц�m
}
 
//�]�w�C��
void SetColor(int f=7,int b=0)
{
    unsigned short ForeColor=f+16*b;
    HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);//���o�ثe��r��������XHandle
    SetConsoleTextAttribute(hCon,ForeColor);
}
 
//�ѽL�Ϥ�&�u��
void dir(int x,int y){
 
        gotoxy(x*2,y);
             if(G[x][y]==1)      {printf("��");}
        else if(G[x][y]==2)      {printf("��");}
        else {
             if(x==N   && y==N  ){printf("�z");}
        else if(x==N   && y==M-1){printf("�|");}
        else if(x==M-1 && y==N  ){printf("�{");}
        else if(x==M-1 && y==M-1){printf("�}");}
        else if(x==N  )          {printf("�u");}
        else if(x==M-1)          {printf("�t");}
        else if(y==N  )          {printf("�s");}
        else if(y==M-1)          {printf("�r");}
        else                     {printf("�q");}
             }
     return ;
}
 
 
//�p���v��
int sc(int s,int x,int y){
        int i,j,l;
        int snc[6]={0,1,10,50,1000,10000}; //1 2 20 50
        int n,ns,nn,t;
        n=0;
 
        for(j=1;j<=8;j++){
        for(l=-1;l<1;l++){
          ns=nn=1;
          for(i=l;i<l+5;i++)      //��
          {if(j==1)t=G[ x ][y-i]; //�W
           if(j==2)t=G[x+i][y-i]; //�k�W
           if(j==3)t=G[x+i][ y ]; //�k
           if(j==4)t=G[x+i][y+i]; //�k�U
           if(j==5)t=G[ x ][y+i]; //�U
           if(j==6)t=G[x-i][y+i]; //���U
           if(j==7)t=G[x-i][ y ]; //��
           if(j==8)t=G[x-i][y-i]; //���W
 
           if     (t==s)nn++;
           else if(t!=0)ns=0;
 
          if(nn>5 && G[x][y]==s)
          {SetColor(0,8);
           dir(x,y);
           SetColor(15,0);
           gotoxy(56,5);
           if(s==1)printf("�� �a ���!!");
           if(s==2)printf("�q �� ���!!");
           n=-1;return n;}
 
          if(ns)n+=snc[nn];       }}}
       if(G[x][y])n=0;
       return n;
      }
 
 
//�Ʀr�����
void nc(int n){
    char s1[10][5]={"  ","�@","�G","�T","�|","��","��","�C","�K","�E"};
 
    if(n>99)printf("%s��",s1[n/100]);
    n%=100;
    if(n>19)printf("%s",s1[n/10]);
    if(n>9)printf("�Q");
    n%=10;
    printf("%s",s1[n]);
 
    return ;
    }
 
 
 
// �P�_�U���I
int mg(int s){
    int i,j;
    int cM;     //���a�̤j��+�q���̤j��
    int cN,iN;  //�q���o��m����+ ���a��
    int cMx,cMy;//�U���Ix+y
    int rrM;    //�p�H�����t
 
    srand(time(NULL));
                                               //�P�_�q������
    cM=0;
    for(i=N;i<M;i++)
    for(j=N;j<M;j++){
    cN=sc(2,i,j);iN=sc(1,i,j);                //�D�q���P���a���ӪŮ����
    if(iN>cN)cN=iN;                           //����j�̩��cN
    rrM=0;
    if(cN==cM)rrM=rand()%3-1;                //�Y�۵��h�H��
    if(cN>cM+rrM){cM=cN;cMx=i;cMy=j;}
    }
 
    G[cMx][cMy]=s;
    dir(cMx,cMy);
 
    return cMx*100+cMy;
 
}
 
 
int main(){
Start:
    gotoxy(56,5);
    printf("               ");
    int i,j,l;
    int cMg;
    int nt=1;
                  //�e�ѽL
    for(i=N;i<M;i++)
    {
        for(j=N;j<M;j++)
        {
            G[i][j]=0;
            SetColor(0,15);
            dir(i,j);
        }
 
        SetColor(15,0);
        gotoxy(i*2,M);
        printf("%02d",i-N+1);
        gotoxy(M*2+1,i);
        printf("%c",'A'+i-N);
    }
 
    int key;
    int xi,yi;
    xi=yi=(M+N)/2;
 
    while(1)
    {
        SetColor(15,0);
        gotoxy(6,N-2);
        printf("���l�ѹ�@");
        SetColor(15,0);
        gotoxy(55,N);
        printf("��");nc(nt);printf("�^�X    ");
 
        if(nt>=((M-N)*(M-N))/2)
        {
           SetColor(15,0);
           gotoxy(56,5);
           printf("��  �� !!");
        }
 
        nt++;
 
        do{
 
            SetColor(0,8);dir(xi,yi);
            key=getch();
 
            SetColor(0,15);dir(xi,yi);
 
                    //��J
            if(key==72){if(yi>N)yi--;   else yi=M-1; }   //�W
            else if(key==80){if(yi<M-1)yi++; else yi=N;   }   //�U
            else if(key==75){if(xi>N)xi--;   else xi=M-1; }   //��
            else if(key==77){if(xi<M-1)xi++; else xi=N;   }   //�k
        }while(key!=13 || G[xi][yi]!=0); // ��ܲ��� */
 
        SetColor(0,15);
        G[xi][yi]=1;
        dir(xi,yi);
 
        if(sc(1,xi,yi)<0)break;
 
        cMg=mg(2);
        if(sc(2,cMg/100,cMg%100)<0)break;
 
        Sleep(10);
    }//while(1)
 
    while(1)
    {
        SetColor(15,0);
        gotoxy(56,7);
        printf("�O�_�~��?!(Y/N)");
        key=getch();
        gotoxy(56,7);
        printf("               ");
        if(key=='n')break;
        else if(key=='y')goto Start;
    }
    return 0;
}
