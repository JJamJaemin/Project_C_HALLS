#include <stdio.h>
#include <time.h>
#include <windows.h>
#include <mmsystem.h>
#include <conio.h>


#define UP 0 
#define DOWN 1
#define LEFT 2
#define RIGHT 3
#define SUBMIT 4 //선택 하는 키 (스페이스바) 
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
void gLoop(int); //게임 루프 
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
    init(); // 콘솔크기 조정
    while(1)
    {
        titleDraw();
        int menuCode = menuDraw();
        if(menuCode == 0)
        {
            //게임 시작 
            int n = maplistDraw(); 
            
            if(n==0)//쉬움 선택 
            {
                system("cls");
                setColor(yellow,black); 
                printf("\n\n   [스토리모드]\n\n\n");
                setColor(white,black);
                printf("                      vBBBBBBB\n");
            printf("                    JBBBBBQBBZ\n");
            printf("      iJJr:     iBBBBBBBBBBBB.\n");
            printf("  BBBBBBBBBBBBBBBBBBBBQBK SBBu\n");
            printf(" QBQBBBQBBBQBBBQBQBBBBBB   BBB\n");
            printf("QBBBBBBBBBBBBBBBBBBBQBBB   .P.\n");
            printf("BQBBBQBQBBBBBBBQBBBBBQBB\n");
            printf(" BBBBBBBQBQBBBBBBBBBQBg     내이름\n");
            printf("  KBB:.BB.  :vJLviBBBBg은   호올스\n");
            printf("   Bg  BB         QB qB5    경주마죠\n"); 
            printf("  LB  MB7         BB  :B:\n");
            printf("  qB  LB          QB  JB\n");
            printf("  Bi   B.         R7 ZB\n");
            printf("  Bi   BB         BvBB\n");
            printf("  BB   :BB        BQB\n");
            Sleep(4500);
            system("cls");
            
            setColor(yellow,black);
            printf("\n\n   음...? 이게뭐지?\n\n");
            setColor(white,black);
            printf("┌━━━━━━━━━━━━━━━━━━━━━━━━━━┐\n");
               printf("│    ☆경마대회 개최 ☆    │\n");
             printf("│                          │\n");
               printf("│   우승상품: 명품 말발굽  │\n");
               printf("│                          │\n");
               printf("│  ※오는길 사냥꾼 조심※  │\n");
               printf("│                          │\n");
               printf("│                          │\n");
               printf("│                          │\n");
               printf("│                          │\n");
               printf("└━━━━━━━━━━━━━━━━━━━━━━━━━━┘\n");
               Sleep(4500);
               system("cls");
               
               printf("\n\n                      vBBBBBBB\n");
            printf("                    JBBBBBQBBZ\n");
            printf("      iJJr:     iBBBBBBBBBBBB.\n");
            printf("  BBBBBBBBBBBBBBBBBBBBQBK SBBu\n");
            printf(" QBQBBBQBBBQBBBQBQBBBBBB   BBB\n");
            printf("QBBBBBBBBBBBBBBBBBBBQBBB   .P.\n");
            printf("BQBBBQBQBBBBBBBQBBBBBQBB\n"); 
            printf(" BBBBBBBQBQBBBBBBBBBQBg    마침 말발굽이\n");
            printf("  KBB:.BB.  :vJLviBBBBg     닳았는데 \n");
            printf("   Bg  BB         QB qB5    대회에 나가서\n");
            printf("  LB  MB7         BB  :B:   말발굽이나 얻자\n"); 
            printf("  qB  LB          QB  JB\n"); 
            printf("  Bi   B.         R7 ZB\n");
            printf("  Bi   BB         BvBB\n");
            printf("  BB   :BB        BQB\n");
            
            Sleep(4500);
            system("cls");
            
                setColor(yellow,black); 
                printf("\n\n\n\n\n경기장을 가기위해 길을 찾아보자");
                Sleep(2000);
                gLoop(0);
                
            }
            else if (n==1)//맵보기 
            {
                gLoop(1);
                
            }
             else if (n==2)//메세지뜬후 
            {
                gLoop(2);
                
            }
        }
        else if (menuCode == 1)
        {
            infoDraw();//게임 도움말 
        }
        else if (menuCode == 2)
        {
            return 0; //종료 
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
    system("mode con cols=56 lines=28 | title HALLS");//게임제목 콘솔 크기 변경
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
    printf("        경주에 나가기 위한 호올스의 여정이 시작된다.. \n\n\n\n\n");
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

int menuDraw() //초기 화면 함수 
{
    int x = 24;
    int y = 12; 
    gotoxy(x-2 ,y);
    printf("> 게임시작");
    gotoxy(x,y+1);
    printf("게임 도움말");
    gotoxy(x,y+2);
    printf("종료 "); 
    while(1)
    {
        int n = keyControl();
        switch(n)
        {
            case UP:
                {
                    if (y>12){ //12 게임시작 버튼 
                        gotoxy(x-2, y);
                        printf(" ");
                        gotoxy(x-2, --y);
                        printf(">");
                    }
                    break;
                }
            case DOWN:
                {
                    if (y<14){ // 14 종료버튼 
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

int keyControl() // 방향키 및 선택 세팅 
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
int keyControlDALDAL() // 방향키 및 선택 세팅 
{
    char temp =getch();
    int a,b,c;
    int d; //방향제어 
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

void infoDraw() //  게임 도움말 화면 함수 
{
    system("cls");
    printf("\n\n");
    setColor(lightred,black);
    printf("               [ 조 작 법]\n\n");
    setColor(white,black);
    printf("              메뉴 이동 :  W A S D\n");
    printf("              선택 : 스페이스 바\n");
    printf("              게임중 뒤로가기: 스페이스바 \n");
   printf("              플레이어 이동키: T F G H 로 방향설정\n ");
    printf("                     JKL 순서대로 입력시 이동\n\n\n");
    setColor(lightred,black);
    printf("         엔딩은 2가지 입니다!!\n\n");
    setColor(white,black);
       
    printf("          스페이스바를 누르면 메인화면으로 돌아갑니다.\n");
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


int maplistDraw() // 난이도 설정 
{
    int x = 24;
    int y = 6;
    system("cls");
    
    printf("\n\n");
    setColor(yellow,black);
    printf("                [호올스는 무엇을 선택할까?]\n\n");
    setColor(white,black);
    gotoxy(x-2 , y);
    printf("> 스토리 모드 시작");
    gotoxy(x, y+1);
    printf("경기장 보기");
    gotoxy(x, y+2);
    printf("뒤로");
    
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



 
char tempMap[25][56] ; //맵 임시저장 



char map1[25][56] = //난이도 쉬움 
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
char map3[25][56] = //난이도 쉬움 
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


char map2[25][56] = //난이도 어려움 
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
    int h, w ; //세로 가로 
    int i;
    char temp1;
    for (h=0; h <25 ; h ++) 
    {
        for(w= 0 ; w<56; w++)
        {
           
            char temp = tempMap[h][w];  
            if(temp == '3')//빈공간 
            {
                setColor(black, black); 
                printf(" ");
            } 
            if(temp == '9')//메세지 
            {
                setColor(black, black); 
                printf(" ");
                
            } 
            if(temp == '7')//빈공간 
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
            else if (temp == '1') // 벽 
            {
                setColor(green, green);
                printf("#"); 
            }
            
            else if(temp == 'q')//플레이어 
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
    int x, y; // 플레이어 좌표저장 변수 
    
    int playing = 1; // 1이면 게임중 0이면 게임종료 
    
    //mapNumber 0 이면 쉬운맵  1이면 어려운맵 
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

void move(int* x , int* y , int _x, int _y) // 플레이어 이동 함수  
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
    printf(" \n배드엔딩\n\n\n\n\n\n");
    setColor(white,black);
    printf("          .gBQ5r7XBJ\n        iBBJ      vBQ.\n       BBi  DBB2  7BBBL        길을 잘못들어서     \n     :QB  BBr BB  BBQBBX\n    .BP .Bj  BB  BBBBBBB5      사냥꾼에게 잡혀 \n    BB  BQ QBv  QBQBBBQBBi\n   QB   RBQi  IBBBBQBBBBBB     고기 되었습니다.\n   BB       uBBBBBBBBBBBBBs\n    ZBgYUZBBBBBBBQBBBBBBBBB\n     rBBBBBBBBBBBBQBBBQBBBB\n       :BBBBBBBBBBBBBBBBBB7\n          2BBBBBBBBBBBBBBBB.\n            .YQBBBBQBBBBP vBB .     스페이스바 입력시  \n                 .:i:. 7QD  BBBBQ   메인 화면으로...  \n                         RBr   .B\n                          Bu BBBv\n                         Bq7BU\n");
    returnMenu();
}


void endingMap()
{
    system("cls");
    printf("                SJ\n");                     
   printf("              UBBBB:\n");                    
   printf("           7BQBBBBBB7\n");                   
   printf("           sBU7rQBBBR   다른 친구들은 미로를\n");             
   printf("                BBBBB.  탈출하지  못해\n");                
   printf("               BBBQBB:  나혼자 출전했네!\n");                
   printf("             5BBBBBBB   말발굽 좋아요~\n");                
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
   printf("\n 새로운 말발굽으로 신나게 달려보자!\n");
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
   printf("       주변에서 총소리가 들린다. 조심하도록 하자");
   setColor(white,black);
   
   
}
