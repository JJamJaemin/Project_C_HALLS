#include <stdio.h>
#include <time.h>
#include <windows.h>
#include <mmsystem.h>
#include <conio.h>


#define UP 0 
#define DOWN 1
#define LEFT 2
#define RIGHT 3
#define SUBMIT 4 //���� �ϴ� Ű (�����̽���) 
#define __COLOR_LIST_

enum 
{
    black,
    blue,
    green,
    cyan,
    red,
    purple,
    brown,
    lightgray,
    darkgray,
    lightblue,
    lightgreen,
    lightcyan,
    lightred,
    lightpurple,
    yellow,
    white
};
void mms();
void returnMenu();
void ending();
void endingMap();
int keyControlDALDAL(); 
void move(int* , int* , int , int);
void moveCOM();
void gLoop(int); //���� ���� 
int keyControl(); 
void init();
void titleDraw();
int menuDraw();
void gotoxy(int, int);
void infoDraw();
int maplistDraw();
void drawMap(int*, int*);
void setColor(int forground, int background);
void main()
{
    init(); // �ܼ�ũ�� ����
    while(1)
    {
        titleDraw();
        int menuCode = menuDraw();
        if(menuCode == 0)
        {
            //���� ���� 
            int n = maplistDraw(); 
            
            if(n==0)//���� ���� 
            {
                system("cls");
                setColor(yellow,black); 
                printf("\n\n   [���丮���]\n\n\n");
                setColor(white,black);
                printf("                      vBBBBBBB\n");
            printf("                    JBBBBBQBBZ\n");
            printf("      iJJr:     iBBBBBBBBBBBB.\n");
            printf("  BBBBBBBBBBBBBBBBBBBBQBK SBBu\n");
            printf(" QBQBBBQBBBQBBBQBQBBBBBB   BBB\n");
            printf("QBBBBBBBBBBBBBBBBBBBQBBB   .P.\n");
            printf("BQBBBQBQBBBBBBBQBBBBBQBB\n");
            printf(" BBBBBBBQBQBBBBBBBBBQBg     ���̸�\n");
            printf("  KBB:.BB.  :vJLviBBBBg��   ȣ�ý�\n");
            printf("   Bg  BB         QB qB5    ���ָ���\n"); 
            printf("  LB  MB7         BB  :B:\n");
            printf("  qB  LB          QB  JB\n");
            printf("  Bi   B.         R7 ZB\n");
            printf("  Bi   BB         BvBB\n");
            printf("  BB   :BB        BQB\n");
            Sleep(4500);
            system("cls");
            
            setColor(yellow,black);
            printf("\n\n   ��...? �̰Թ���?\n\n");
            setColor(white,black);
            printf("��������������������������������������������������������\n");
               printf("��    �ٰ渶��ȸ ���� ��    ��\n");
             printf("��                          ��\n");
               printf("��   ��»�ǰ: ��ǰ ���߱�  ��\n");
               printf("��                          ��\n");
               printf("��  �ؿ��±� ��ɲ� ���ɡ�  ��\n");
               printf("��                          ��\n");
               printf("��                          ��\n");
               printf("��                          ��\n");
               printf("��                          ��\n");
               printf("��������������������������������������������������������\n");
               Sleep(4500);
               system("cls");
               
               printf("\n\n                      vBBBBBBB\n");
            printf("                    JBBBBBQBBZ\n");
            printf("      iJJr:     iBBBBBBBBBBBB.\n");
            printf("  BBBBBBBBBBBBBBBBBBBBQBK SBBu\n");
            printf(" QBQBBBQBBBQBBBQBQBBBBBB   BBB\n");
            printf("QBBBBBBBBBBBBBBBBBBBQBBB   .P.\n");
            printf("BQBBBQBQBBBBBBBQBBBBBQBB\n"); 
            printf(" BBBBBBBQBQBBBBBBBBBQBg    ��ħ ���߱���\n");
            printf("  KBB:.BB.  :vJLviBBBBg     ��Ҵµ� \n");
            printf("   Bg  BB         QB qB5    ��ȸ�� ������\n");
            printf("  LB  MB7         BB  :B:   ���߱��̳� ����\n"); 
            printf("  qB  LB          QB  JB\n"); 
            printf("  Bi   B.         R7 ZB\n");
            printf("  Bi   BB         BvBB\n");
            printf("  BB   :BB        BQB\n");
            
            Sleep(4500);
            system("cls");
            
                setColor(yellow,black); 
                printf("\n\n\n\n\n������� �������� ���� ã�ƺ���");
                Sleep(2000);
                gLoop(0);
                
            }
            else if (n==1)//�ʺ��� 
            {
                gLoop(1);
                
            }
             else if (n==2)//�޼������� 
            {
                gLoop(2);
                
            }
        }
        else if (menuCode == 1)
        {
            infoDraw();//���� ���� 
        }
        else if (menuCode == 2)
        {
            return 0; //���� 
        } 
        system("cls");
    }
    
}
void setColor(int forground, int background)
{
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    int code = forground + background * 16;
    SetConsoleTextAttribute(consoleHandle, code);
}
void init()
{
    system("mode con cols=56 lines=28 | title HALLS");//�������� �ܼ� ũ�� ����
} 

void titleDraw()
{
    printf("\n\n\n\n");
    setColor(yellow,black);
    printf("          #   #     #     #      #       ####  \n  " );
    printf("        #   #    # #    #      #      #      \n  ");
    printf("        #####   # # #   #      #       ####  \n  ");
    printf("        #   #  #     #  #      #           # \n  ");
    printf("        #   # #       # ###### ######  ####  \n \n ");
    setColor(lightred,black);
    printf("        ���ֿ� ������ ���� ȣ�ý��� ������ ���۵ȴ�.. \n\n\n\n\n");
      setColor(red,black);
      printf ("             s   \n        :JOMRBB  \n     cBBBBBBBBBB \n   cBBBBBBBBB");
      setColor(black,black);
      printf("O");
      setColor(red,black);
      printf("BBJ \nBBBBBBBQBBBBBBBBB\nBBBBQBBBBBB  sBBQB  \nBBBBBBBBBQB    QBB  \nBBBBBBBBQBB    \n");
      setColor(white,black);
    
    setColor(white,black);
}

void gotoxy(int x, int y)
{
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos;
    pos.X = x;
    pos.Y = y;
    SetConsoleCursorPosition(consoleHandle, pos);
}

int menuDraw() //�ʱ� ȭ�� �Լ� 
{
    int x = 24;
    int y = 12; 
    gotoxy(x-2 ,y);
    printf("> ���ӽ���");
    gotoxy(x,y+1);
    printf("���� ����");
    gotoxy(x,y+2);
    printf("���� "); 
    while(1)
    {
        int n = keyControl();
        switch(n)
        {
            case UP:
                {
                    if (y>12){ //12 ���ӽ��� ��ư 
                        gotoxy(x-2, y);
                        printf(" ");
                        gotoxy(x-2, --y);
                        printf(">");
                    }
                    break;
                }
            case DOWN:
                {
                    if (y<14){ // 14 �����ư 
                        gotoxy(x-2 , y);
                        printf(" ");
                        gotoxy(x-2 , ++y);
                        printf(">");
                    }
                    break;
                }
            case SUBMIT:
                {
                    return y-12;
                }
        }
    }
}

int keyControl() // ����Ű �� ���� ���� 
{
    char temp =getch();
    
    if(temp == 'w' || temp == 'W')
    {
        return UP;
    }
    else if(temp == 's' || temp == 'S')
    {
        return DOWN;
    }
    else if(temp == 'a' || temp == 'A')
    {
        return LEFT;
    }
    else if(temp == 'd' || temp == 'D')
    {
        return RIGHT;
    }
    if(temp == ' ')
    {
        return SUBMIT;
    }
    
}
int keyControlDALDAL() // ����Ű �� ���� ���� 
{
    char temp =getch();
    int a,b,c;
    int d; //�������� 
    if(temp == 'j' || temp == 'J')
    {
        a=1;
        char temp =getch();
        if(temp == 'k' || temp == 'K')
        {
           b=1;
           char temp = getch();
           if(temp == 'l' || temp == 'L')
           {
              c=1;
         }
      }
    }
    if(temp == ' ')
    {
        return SUBMIT;
    }
    if(temp == 't' || temp == 'T')
    {
        d = 1;
        
    } 
    if(temp == 'f' || temp == 'F')
    {
        d = 2;
        
    } 
    if(temp == 'g' || temp == 'G')
    {
        d = 3;
        
    } 
    if(temp == 'h' || temp == 'H')
    {
        d = 4;
        
    } 
    if(a==1&&b==1&&c==1&&d==1)
    {
       a=0;
       b=0;
       c=0;
       return UP;
       
   }
    if(a==1&&b==1&&c==1&&d==2)
    {
       a=0;
       b=0;
       c=0;
       return LEFT;
       
   }
    if(a==1&&b==1&&c==1&&d==3)
    {
       a=0;
       b=0;
       c=0;
       return DOWN;
       
   }
    if(a==1&&b==1&&c==1&&d==4)
    {
       a=0;
       b=0;
       c=0;
       return RIGHT;
       
   }
   
    
}

void infoDraw() //  ���� ���� ȭ�� �Լ� 
{
    system("cls");
    printf("\n\n");
    setColor(lightred,black);
    printf("               [ �� �� ��]\n\n");
    setColor(white,black);
    printf("              �޴� �̵� :  W A S D\n");
    printf("              ���� : �����̽� ��\n");
    printf("              ������ �ڷΰ���: �����̽��� \n");
   printf("              �÷��̾� �̵�Ű: T F G H �� ���⼳��\n ");
    printf("                     JKL ������� �Է½� �̵�\n\n\n");
    setColor(lightred,black);
    printf("         ������ 2���� �Դϴ�!!\n\n");
    setColor(white,black);
       
    printf("          �����̽��ٸ� ������ ����ȭ������ ���ư��ϴ�.\n");
      setColor(red,black);
      printf ("             s   \n        :JOMRBB  \n     cBBBBBBBBBB \n   cBBBBBBBBB");
      setColor(black,black);
      printf("O");
      setColor(red,black);
      printf("BBJ \nBBBBBBBQBBBBBBBBB\nBBBBQBBBBBB  sBBQB  \nBBBBBBBBBQB    QBB  \nBBBBBBBBQBB    \n");
      setColor(white,black);
    
    while(1)
    {
        if(keyControl()== SUBMIT)
        {
            break;
        }
      }  
}


int maplistDraw() // ���̵� ���� 
{
    int x = 24;
    int y = 6;
    system("cls");
    
    printf("\n\n");
    setColor(yellow,black);
    printf("                [ȣ�ý��� ������ �����ұ�?]\n\n");
    setColor(white,black);
    gotoxy(x-2 , y);
    printf("> ���丮 ��� ����");
    gotoxy(x, y+1);
    printf("����� ����");
    gotoxy(x, y+2);
    printf("�ڷ�");
    
    while(1)
    {
        int n = keyControl();
        switch(n)
        {
            case UP:
                {
                    if (y>6)
                    {
                        gotoxy(x-2, y);
                        printf(" ");
                        gotoxy(x-2 , --y);
                        printf(">");
                    }
                    break;
                }
            case DOWN:
                {
                    if(y < 9)
                    {
                        gotoxy(x-2 , y);
                        printf(" ");
                        gotoxy(x-2, ++y);
                        printf(">");
                    }
                    break;
                }
            case SUBMIT:
                {
                    return y-6;
                }
        }   
     } 
}



 
char tempMap[25][56] ; //�� �ӽ����� 



char map1[25][56] = //���̵� ���� 
{
  {"7777777777777777777777777777777777777777"},
  {"11q3111111111111111115511111111111111111"},
  {"1133113333333333111133333333331133333311"},
  {"1133113311331133339333113311331133113311"},
  {"1133113311331111111111113311111133111111"},
  {"1133113311111111333333113333333333333311"},
  {"1133113333113333331111111133111111113311"},
  {"1133113311111111331133331133113333113311"},
  {"1133113333333311331111331133113311113311"},
  {"1133113311113333333311331133113333333311"},
  {"1133111111111111113311331133113311111111"},
  {"1133113333333333333311331133113333333311"},
  {"1133111111113311111111331111111133113336"},
  {"1133113311333333333333331133111111113311"},
  {"1133113311331111111133111133113333113311"},
  {"1133333311331133331133113333333311111111"},
  {"1133113311111133111133113311113311113311"},
  {"1133113333333333331133333333113311333311"},
  {"1133111111111111111111111133113311331111"},
  {"1133333333333333333333333333333333331111"},
  {"1111111111111111111111111111111111111111"},
      
}; 
char map3[25][56] = //���̵� ���� 
{
  {"7777777777777777777777777777777777777777"},
  {"1133111111111111111115511111111111111111"},
  {"1133113333333333111133333333331133333311"},
  {"113311331133113333q333113311331133113311"},
  {"1133113311331111111111113311111133111111"},
  {"1133113311111111333333113333333333333311"},
  {"1133113333113333331111111133111111113311"},
  {"1133113311111111331133331133113333113311"},
  {"1133113333333311331111331133113311113311"},
  {"1133113311113333333311331133113333333311"},
  {"1133111111111111113311331133113311111111"},
  {"1133113333333333333311331133113333333311"},
  {"1133111111113311111111331111111133113336"},
  {"1133113311333333333333331133111111113311"},
  {"1133113311331111111133111133113333113311"},
  {"1133333311331133331133113333333311111111"},
  {"1133113311111133111133113311113311113311"},
  {"1133113333333333331133333333113311333311"},
  {"1133111111111111111111111133113311331111"},
  {"1133333333333333333333333333333333331111"},
  {"1111111111111111111111111111111111111111"},
      
}; 


char map2[25][56] = //���̵� ����� 
{
    {"3333111111111111111111111111111111111113333"},
    {"3311333333333333333333333333333333333331133"},
    {"1133333333333333333333333333333333333333311"},
    {"1333333333333333333333333333333333333333331"},
    {"1333333222222222222222222222222222223333331"},
    {"1333332333333333333333333333333333332333331"},
    {"1333323333333333333333333333333333333233331"},
    {"1333323333333333333333333333333333333233331"},
    {"1333323333333333333333333333333333333233331"},      
    {"1333323333333333333333333333333333333233331"},
    {"1333323333333333333333333333333333333233331"},
    {"1333323333333333333333333333333333333233331"},
    {"1333323333333333333333333333333333333233331"},
    {"1333323333333333333333333333333333333233331"},
    {"1333332333333333333333333333333333332333331"},
    {"1333333222222222222222222222222222223333331"},
    {"1333333333q33333333333333333333333333333331"},
    {"1133333333333333333333333333333333333333311"},
    {"3311333333333333333333333333333333333331133"},
    {"3333111111111111111111111111111111111113333"},
      
};


void drawMap(int *x, int*y)
{
    system("cls");
    int h, w ; //���� ���� 
    int i;
    char temp1;
    for (h=0; h <25 ; h ++) 
    {
        for(w= 0 ; w<56; w++)
        {
           
            char temp = tempMap[h][w];  
            if(temp == '3')//����� 
            {
                setColor(black, black); 
                printf(" ");
            } 
            if(temp == '9')//�޼��� 
            {
                setColor(black, black); 
                printf(" ");
                
            } 
            if(temp == '7')//����� 
            {
                setColor(black, black); 
                printf(" ");
            }
            if(temp == '5')
            {
                setColor(black,black);
                printf(" ");
                void ending(); 
                
            }
             if(temp == '6')
            {
                setColor(black,black);
                printf(" ");
                void ending(); 
                
            }
            else if (temp == '1') // �� 
            {
                setColor(green, green);
                printf("#"); 
            }
            
            else if(temp == 'q')//�÷��̾� 
            {
                *x = w;
                *y = h;
                setColor (brown, black);
                printf("$");
            }
                  
            
            else if (temp == '2')
            {
                setColor(red,red);
                printf("|");
            }
            else if (temp == '0')
            {
                setColor(green,green);
                printf("-");
            }
        }
        printf("\n");
    }
    setColor(white, black);
    
}

void gLoop(int mapCode)
{
    int x, y; // �÷��̾� ��ǥ���� ���� 
    
    int playing = 1; // 1�̸� ������ 0�̸� �������� 
    
    //mapNumber 0 �̸� �����  1�̸� ������ 
    if (mapCode == 0)
    {
        memcpy(tempMap, map1 , sizeof(tempMap));
        
    } 
    else if (mapCode == 1)
    {
        memcpy (tempMap, map2 , sizeof(tempMap));
    }
    else if (mapCode == 2)
    {
        memcpy (tempMap, map3 , sizeof(tempMap));
    }
    
    drawMap(&x, &y);
    
    while(playing)
    {
        switch (keyControlDALDAL())
        {
            case UP:
                move(&x,&y,0,-1);
                break;
            case DOWN:
                move(&x,&y,0,1);
                break;
            case RIGHT:
                move(&x,&y,1,0);
                break;
            case LEFT:
                move(&x,&y,-1,0);
                break;
            case SUBMIT:
               playing = 0 ;
               break;
        }
        
        
    }
}

void move(int* x , int* y , int _x, int _y) // �÷��̾� �̵� �Լ�  
{
   char mapObject = tempMap[*y + _y][*x + _x];
    setColor(white, black);
   
    if (mapObject == '3') 
    {
    gotoxy(*x, *y);
    printf(" ");
    
    setColor(brown, black);
    gotoxy(*x + _x, *y + _y);
    printf("$");
    
    *x += _x;
    *y += _y;
   }
   if(mapObject == '5')
   {
        ending();
   }
   if(mapObject == '6')
   {
        endingMap();
   }
   
   
   if(mapObject == '9')
   {
         
         
      
        mms();
        Sleep(3000);
        gLoop(2);
        
            
      
      
      
   }
   
}

void ending()
{
    system("cls");
    setColor(lightred,black);
    printf(" \n��忣��\n\n\n\n\n\n");
    setColor(white,black);
    printf("          .gBQ5r7XBJ\n        iBBJ      vBQ.\n       BBi  DBB2  7BBBL        ���� �߸���     \n     :QB  BBr BB  BBQBBX\n    .BP .Bj  BB  BBBBBBB5      ��ɲۿ��� ���� \n    BB  BQ QBv  QBQBBBQBBi\n   QB   RBQi  IBBBBQBBBBBB     ��� �Ǿ����ϴ�.\n   BB       uBBBBBBBBBBBBBs\n    ZBgYUZBBBBBBBQBBBBBBBBB\n     rBBBBBBBBBBBBQBBBQBBBB\n       :BBBBBBBBBBBBBBBBBB7\n          2BBBBBBBBBBBBBBBB.\n            .YQBBBBQBBBBP vBB .     �����̽��� �Է½�  \n                 .:i:. 7QD  BBBBQ   ���� ȭ������...  \n                         RBr   .B\n                          Bu BBBv\n                         Bq7BU\n");
    returnMenu();
}


void endingMap()
{
    system("cls");
    printf("                SJ\n");                     
   printf("              UBBBB:\n");                    
   printf("           7BQBBBBBB7\n");                   
   printf("           sBU7rQBBBR   �ٸ� ģ������ �̷θ�\n");             
   printf("                BBBBB.  Ż������  ����\n");                
   printf("               BBBQBB:  ��ȥ�� �����߳�!\n");                
   printf("             5BBBBBBB   ���߱� ���ƿ�~\n");                
   printf("        QQJ::BBBQBBBBg\n");                  
   printf("       Bq.BBBBBBBQBBBBQ\n");                  
   printf("      iB B77XgBBBBBBBBBBY\n");                
   printf("      7BLB     iBBBBBBBBBBE\n");              
   printf("        B7       YBBBBBBBBBB\n");             
   printf("        g          .rBBBBBBBB\n");            
   printf("                     BBBBBQBBBr\n");          
   printf("                     BBB2vBBiBBQB7. .\n");    
   printf("                     .BB  7B. IBBBBBr.\n");   
   printf("                       QB  :Br    :.\n");     
   printf("                       BB   BS\n");           
   printf("                      BB    B.\n");           
   printf("                    .BQ    sB\n");
   setColor(yellow, black);
   printf("\n ���ο� ���߱����� �ų��� �޷�����!\n");
   setColor(white , black); 
    Sleep(5000);
    
    gLoop(1); 
}

void returnMenu()
{
    int n = keyControl();
        switch(n)
        {
            
            case SUBMIT:
                {
                    system("cls");
                    main();
            
                    
                }
     
     
        }
}

void mms()
{

   system("cls");
   setColor(lightred,black);
   printf("\n\n\n                       [WARNING]\n\n\n") ;
   printf("       �ֺ����� �ѼҸ��� �鸰��. �����ϵ��� ����");
   setColor(white,black);
   
   
}
