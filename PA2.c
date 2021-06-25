
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <Windows.h>
#include <time.h>
#define NONE_MARK  "  "
#define LONG_NONE_MARK  "                                                       "
#define PLAYER_MARK1  "◆"
#define PLAYER_MARK2  "○"
#define PLAYER_MARK3  "☆"
#define WALL_MARK2  "■"
#define GUARD_MARK  "▣"
#define TOP_MARK  "▶"
#define WALL_MARK "▦"
#define TREASURE_MARK "▦"
#define TRAP_HOLE "＠"
#define TRAP_STOP "※"
#define TRUE_EYE "◎"
#define TRUE_LOVE "♥"
#define MAX_X 20
#define MAX_Y 30
#define TIME_LIMIT 15
#define TIME_LIMIT_S2 30
#define TIME_LIMIT_S3 60

//게임 구현을 위한 함수들
void display_rule1(void);
void display_rule2(void);
void display_rule3(void);
void make_hidden_and_top1(int topx[], int topy[], int topCnt, int stage1x, int stage1y);
void move_arrow_key(char key, int* x1, int* y1, int x_b, int y_b);
void display_map(int matrix[][15], int topx[], int topy[], int stagex, int stagey);
void display_map2(int matrix[][20], int topx[], int topy[], int stagex, int stagey);
void display_map3(int matrix[][25], int topx[], int topy[], int stagex, int stagey);
void stage_game_control(int topx[], int topy[], clock_t start, double* pst, int stagex, int stagey);
void stage_game_control2(int topx[], int topy[], clock_t start, double* pst, int stagex, int stagey);
void stage_game_control3(int topx[], int topy[], clock_t start, double* pst, int stagex, int stagey);
void gotoxy(int x, int y);
void stop_trap();
void stop_trap_up();
void True_eye(int matrix[][20], int topx[], int topy[]);
void True_eye2(int matrix[][25], int topx[], int topy[]);
void True_eye3(int matrix[][25], int topx[], int topy[]);

//스토리 구성을 위한 함수들
void menu();
void stage1();
void stage2();
void stage3();
int story1();
void story2();
void story3();
int story4();
int story5();
int storyEND();
void textcolor(int color_number);



/*
       main 함수
*/
int main(void)

{
    int num;
    char ch;
    int end_flag = 0;


    while (1)
    {
        system("cls");
        menu();
        printf("번호를 선택하세요: ");
        scanf("%d", &num);


        switch (num)
        {
        case 1:
            stage1();
            break;

        case 2:
            stage2();
            break;

        case 3:
            stage3();
            break;

        case 4:
            printf("프로그램이 종료됩니다.");
            end_flag = 1;
            break;
        default:
            break;

        }
        if (end_flag = 1)
        {
            break;
        }

    }
    return 0;
}


/*
        게임 menu에 대한 함수
*/
void menu()
{
    textcolor(11);
    puts("┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓");
    puts("┃                                       ┃");
    puts("┃       ◆○   도형 왕국   ○◆         ┃");
    puts("┃                                       ┃");
    puts("┃          1. Stage1[초급]              ┃");
    puts("┃                                       ┃");
    puts("┃          2. Stage2[중급]              ┃");
    puts("┃                                       ┃");
    puts("┃          3. Stage3[고급]              ┃");
    puts("┃                                       ┃");
    puts("┃          0. 종     료                 ┃");
    puts("┃                                       ┃");
    puts("┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛");
}



/*
        게임 stage에 대한 함수
*/
void stage1()
{

    int topCnt = 8;
    int stage1x = 10;
    int stage1y = 15;
    int topx[10], topy[10];
    story1();
    story2();
    story3();



    system("cls");

    clock_t start, end;



    double pst;
    display_rule1();
    srand((unsigned)time(NULL));

    //make_treasure(topx, topy);
    make_hidden_and_top1(topx, topy, topCnt, stage1x, stage1y);
    start = clock();

    system("cls");

    stage_game_control(topx, topy, start, &pst, stage1x, stage1y);



    return 0;

}

void stage2()
{

    int flag = 0;
    int topCnt = 15;
    int s_time;
    int stage2x = 15;
    int stage2y = 20;
    int topx[15], topy[15];
    double pst;
    flag = story4();
    if (flag == 1)
    {
        system("cls");
        display_rule2();
        clock_t start, end;

        srand((unsigned)time(NULL));

        //make_treasure(topx, topy);
        make_hidden_and_top1(topx, topy, topCnt, stage2x, stage2y);

        system("cls");
        start = clock();

        stage_game_control2(topx, topy, start, &pst, stage2x, stage2y);


    }
    return 0;

}

void stage3()
{
    int flag = 0;
    int topCnt = 20;
    int s_time;
    int stage3x = 20;
    int stage3y = 25;
    int topx[20], topy[20];
    double pst;

    flag = story5();
    while (flag == 1)
    {

        system("cls");
        display_rule3();
        clock_t start, end;


        srand((unsigned)time(NULL));

        //make_treasure(topx, topy);
        make_hidden_and_top1(topx, topy, topCnt, stage3x, stage3y);

        system("cls");
        start = clock();

        stage_game_control3(topx, topy, start, &pst, stage3x, stage3y);

        flag = storyEND();
        if (flag == 2)
        {
            break;
        }
    }
    return 0;
}


/*
        게임 story에 대한 함수
*/
int story1()
{

    system("cls");
    textcolor(11);
    puts("┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓");
    puts("┃                                                                              ┃");
    puts("┃   도형 왕국에 사는 마름모에게는 사랑하는 사람인 동그라미 공주가 있다.        ┃");
    puts("┃  군데 군데 각진 그에게 있어서 공주의 아름다운 원형은 눈이부시게 아름다웠다.  ┃");
    puts("┃  물론 처음에는 별 감흥이 없었다.시작은 처음으로 연중 행사로 열리는 도형축제  ┃");
    puts("┃  에 나갔을때다.여러 도형들은 각이 져있는 마름모에게 다가오려 하지 않았다.    ┃");
    puts("┃  그렇게 우울해 하고있는 마름모에게 동그라미 공주는 먼저 다가와주었다.        ┃");
    puts("┃  뿐만아니라, 그녀는 축제에 있는 동그라미, 세모, 정사각형등 그 누구도         ┃");
    puts("┃  차별하지 않았다. 그저 도형 그자체로 사랑해줄뿐..                            ┃");
    puts("┃                                                                              ┃");
    puts("┃                                                                              ┃");
    puts("┃                                                                              ┃");
    puts("┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛");


    printf("아무키나 누르세요");
    _getch();


}



void story2()
{
    char skip;
    system("cls");
    textcolor(11);
    puts("┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓");
    puts("┃                                                                              ┃");
    puts("┃   마름모는 그런 공주를 보면서 힘이 났다. 자신의 각진 모습도 어쩌면 가치가    ┃");
    puts("┃  있는 일이라는 생각이 들었다. 그래서 마름모는 더 이상 자신의 각진 모습을     ┃");
    puts("┃  미워하지 않기로 했다. 오히려 그런 단점을 사랑하고, 또 자신감을 가지고 주변  ┃");
    puts("┃  도형들에게 다가갔다. 그 후로 마름모는 자신을 사랑하고, 의미있는 일을 하기  ┃");
    puts("┃  위해 노력했고 그런 모습에 공주도 마름모를 눈여겨 보게 되었다. 몇 년이 흐르고┃");
    puts("┃  결국 마름모와 공주는 사랑하는 사이가 되었고 마름모는 다가오는 도형축제날,   ┃");
    puts("┃  그녀에게 고백하기로 마음 먹었다.                                            ┃");
    puts("┃                                                                              ┃");
    puts("┃                                                                              ┃");
    puts("┃                                                                              ┃");
    puts("┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛");


    printf("아무키나 누르세요");

    _getch();
    _getch();

}

void story3()
{
    char skip;
    system("cls");
    textcolor(11);
    puts("┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓");
    puts("┃                                                                              ┃");
    puts("┃   그렇게 도형축제가 열리고 마름모가 용기를 내려고 할 때였다. 갑자기 스산한   ┃");
    puts("┃  안개가 왕국안을 가득 찾고 누가 누군지 분간을 할 수가 없었다. '꺄악!!'       ┃");
    puts("┃  공주의 목소리였다. 마름모는 본능적으로 공주를 구하기 위해 달렸지만 @        ┃");
    puts("┃  마법사가 이미 공주를 붙잡고 있었다. 마침내 공주에게 다가온 마름모는 @       ┃");
    puts("┃  마법사를 향해 각진 모서리로 돌격했지만 미리 발동해둔 마법으로 마법사는 사라 ┃");
    puts("┃  졌다. “공주를 찾고 싶으면 탑으로 와라, 시간이 지나면 공주는 영영 볼        ┃");
    puts("┃  없을거야!!”라는 말과 함께.. 마름모는 망설일 시간이 없다! 어서 공주를       ┃");
    puts("┃  구하러 탑으로 가자!!                                                        ┃");
    puts("┃                                                                              ┃");
    puts("┃                                                                              ┃");
    puts("┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛");


    printf("아무키나 누르세요");

    _getch();
    _getch();

}


int story4()
{
    char num;
    int flag = 1;
    do {

        system("cls");
        textcolor(11);
        puts("┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓");
        puts("┃                                                                              ┃");
        puts("┃   공주를 구했다! 마름모는 공주의 상태를 확인했다. 다행히 공주는 괜찮아 보    ┃");
        puts("┃  였다. “이럴 때가 아니야” 마름모는 공주를 데리고 탑을 벗어나 서둘러 왕국   ┃");
        puts("┃  으로 향하려 했다. “이렇게 놓칠 순 없지!!” 그런데 그때 @마법사의 음성이    ┃");
        puts("┃  들렸고다시 한번 궁전에서 본 봉인 마법이 공주를 향해 다가왔다. 공주에게      ┃");
        puts("┃  다시 마법이 가해지려는 순간, 마름모는 힘을 다해 막아섰고 사라지고 말았다.   ┃");
        puts("┃  공주는 잠시 당황했지만 이내 침착해졌다. “내가 구하면 되.”                 ┃");
        puts("┃  이번에는 공주 차례다, 탑에 봉인되고 있는 마름모를 구하자!!                  ┃");
        puts("┃                                                                              ┃");
        puts("┃                                                                              ┃");
        puts("┃                                                                              ┃");
        puts("┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛");

        printf("Start to S");
        scanf("%c", &num);

    } while (num != 'S');

    return flag;

}



int story5()
{
    char num;
    int flag = 1;
    do {

        system("cls");
        textcolor(11);
        puts("┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓");
        puts("┃                                                                              ┃");
        puts("┃   마름모를 구했다! 이제는 마법사도 힘이 꽤 빠진 듯하다. 그렇게 마름모와      ┃");
        puts("┃  공주는 탈출을 하려고 했지만.. 이대로 가면 언젠가 마법사가 다시 올지 모른다.  ┃");
        puts("┃  마름모는 공주를 바라보았고 공주역시 같은 생각인 듯 했다.  '내 모서리가 힘을 ┃");
        puts("┃  발휘할때군' 그렇게 마법사에게 돌진하려 할 때, 공주는 마름모를 잡으며 품안   ┃");
        puts("┃  에서 별빛 보석을 꺼냈다. 그것은 도형 왕국에서 내려오는 보물이였다. 두명이서만 ┃");
        puts("┃  사용이 가능한 보물로, 서로 마음이 맞지 않거나 자신을 다루지 못하는 약한     ┃");
        puts("┃  도형은 사용할 수가 없었다. 다행히 보물은 효과를 발휘했고 별의 마법이 둘을   ┃");
        puts("┃  감쌌다. 이제 남은건 @마법사이다! 마법사를 처리하러 가자!                    ┃");
        puts("┃                                                                              ┃");
        puts("┃                                                                              ┃");
        puts("┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛");

        printf("Start to S");
        scanf("%c", &num);

    } while (num != 'S');

    return flag;

}

int storyEND()
{
    char num;
    int flag = 2;
    do {
        system("cls");
        textcolor(11);
        puts("┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓");
        puts("┃                                                                              ┃");
        puts("┃   @마법사를 물리쳤다! 마름모와 공주는 지친몸을 이끌고 왕국으로 향했다.       ┃");
        puts("┃  휴식을 취하고 마름모는 용기를 내서 못다한 고백을 했고 공주는 받아들         ┃");
        puts("┃  였다. 공주를 구해온 용기에 감격한 왕도 둘 사이를 허락했고 마름모와          ┃");
        puts("┃  공주의 결혼식이 열리게 되었다. 하지만 마름모도, 공주도 헤피엔딩이라고       ┃");
        puts("┃  생각하지 않았다. 그들에게는 해야할 일들이 있었고 언제 또 @마법사 같은       ┃");
        puts("┃  도형들이 왕국을 쳐들어 올지 모르는 일이였으니까. 마름모는 항상 노력했고     ┃");
        puts("┃  각진 모서리들로 고통받는 도형 들을 위로했다. 자신의 각진 모습을 자랑        ┃");
        puts("┃  하면서 말이다. 공주도 늘 하던 것처럼 다른 도형들을 격려했고 마름모를 아껴   ┃");
        puts("┃  주었다. 자, 이제 우리들 차례입니다! 우리들의 모험을 하고 우리들의           ┃");
        puts("┃              Story를 들려줍시다! 또다른 누군가에게!                          ┃");
        puts("┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛");

        printf("END to E");
        scanf("%c", &num);

    } while (num != 'E');

    return flag;

}







/*

게임 규칙을 출력하는 함수 display_rule

*/

void display_rule1(void)

{
    gotoxy(1, 1);

    printf("◆○   도형 왕국   ○◆");

    gotoxy(1, 3);

    printf("탑에 갇힌 공주를 구해야 합니다. ");

    gotoxy(1, 5);

    printf("탑안에는 공주 또는 마법사가 준비한 함정 마법이 있습니다. \n");

    gotoxy(1, 7);

    printf("제한된 시간(30초)가 지나면 탑의 봉인은 완성이 되고\n");

    gotoxy(1, 9);

    printf("공주를 영영 볼수가 없습니다.\n");

    gotoxy(1, 11);

    printf("자, 힘을 내세요!!\n");

    gotoxy(1, 12);
    printf("------------------------------------------------\n");

    gotoxy(1, 14);
    printf("8개의 (▶)탑이 있습니다.\n");

    gotoxy(1, 16);
    printf("※마법에 걸리면 2초간 움직일 수가 없습니다.\n");

    _getch();
    _getch();
}
void display_rule2(void)

{

    gotoxy(1, 1);

    printf("◆○   도형 왕국   ○◆");

    gotoxy(1, 3);

    printf("탑안에는 마름모 또는 마법사가 준비한 마법이 기다리고 있습니다. \n");

    gotoxy(1, 5);

    printf("제한된 시간(45초)가 지나면 탑의 봉인은 완성이 되고\n");

    gotoxy(1, 7);

    printf("마름모는 영영 볼수가 없습니다.\n");

    gotoxy(1, 9);

    printf("분한 @마법사는 더 다양한 마법을 부립니다.\n");

    gotoxy(1, 11);

    printf("하지만 공주는 특정 탑에서 진실의 눈(◎) 마법을 사용할 수 있습니다. 힘내세요!\n");

    gotoxy(1, 12);
    printf("------------------------------------------------\n");

    gotoxy(1, 14);
    printf("15개의 (▶)탑이 있습니다.\n");

    gotoxy(1, 16);
    printf("(※)STOP마법에 걸리면 2초간 움직일 수가 없습니다. x 2\n");

    gotoxy(1, 18);
    printf("(＠)웜홀 마법에 걸리면 탑에서 방출되고 초기 위치로 이동됩니다. x 2 \n");

    gotoxy(1, 20);
    printf("(◎)진실의 눈은 허상의 탑 하나를 가려냅니다. x 1\n");


    _getch();
    _getch();
}


void display_rule3(void)

{

    gotoxy(1, 1);

    printf("◆○   도형 왕국   ○◆");

    gotoxy(1, 3);

    printf("탑안에는 지친 @마법사가 숨어 있습니다. \n");

    gotoxy(1, 5);

    printf("제한된 시간(60초)이 지나면 도망 마법진이 완성이 되고\n");

    gotoxy(1, 7);

    printf("@마법사는 사라질겁니다.\n");

    gotoxy(1, 9);

    printf("@마법사는 강력히 저항하겠지만 별의 힘이 두 도형을 감싸고 있습니다.\n");

    gotoxy(1, 11);

    printf("무엇보다 당신은 혼자가 아닙니다, 자 힘내세요!!\n");

    gotoxy(1, 12);
    printf("------------------------------------------------\n");

    gotoxy(1, 14);
    printf("20개의 (▶)탑이 있습니다.\n");

    gotoxy(1, 16);
    printf("(※)STOP마법에 걸리면 2초간 움직일 수가 없습니다. x 3\n");

    gotoxy(1, 18);
    printf("강력한 (※)STOP마법에 걸리면 4초간 움직일 수가 없습니다. x 2\n");

    gotoxy(1, 20);
    printf("(＠)웜홀 마법에 걸리면 탑에서 방출되고 초기 위치로 이동됩니다. x 5\n");

    gotoxy(1, 22);
    printf("(◎)진실의 눈은 허상의 탑 하나를 가려냅니다. x 2 \n");

    _getch();
    _getch();

}





/*

    탑의 위치 들이 만들어지는 함수

*/

void make_hidden_and_top1(int topx[], int topy[], int topCnt, int stagex, int stagey)

{
    int i;

    for (i = 0; i < topCnt; i++) //top, hidden 좌표 만들기

    {
        do
        {
            topx[i] = rand() % stagex - 1; //hidden의 x 좌표
            topy[i] = rand() % stagey - 1; //hidden의 y 좌표

        } while ((topx[i] < 2) || (topy[i] < 2));
    }
}






/*

    색깔 입히는 함수

*/

void textcolor(int color_number)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color_number);
}




/*

    사용자 입력에 따라 커서 지정하기 위한 함수

*/
void gotoxy(int x, int y)

{

    COORD Pos = { x  , y };

    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);

}



/*

    함수 move_arrow_key 방향키에 따라 움직이기 위한 함수

*/
void move_arrow_key(char key, int* x1, int* y1, int x_b, int y_b)

{

    switch (key)

    {

    case 72:
        gotoxy(*x1, *y1);
        printf(NONE_MARK);
        *y1 = *y1 - 1; //위쪽 방향의 화살표 키 입력

        if (*y1 < 1)

            *y1 = 1;

        break;

    case 75:

        gotoxy(*x1, *y1);
        printf(NONE_MARK);
        *x1 = *x1 - 2; //왼쪽 방향의 화살표 키 입력

        if (*x1 < 2)

            *x1 = 2;

        break;

    case 77:

        gotoxy(*x1, *y1);
        printf(NONE_MARK);
        *x1 = *x1 + 2; //오른쪽 방향의 화살표 키 입력

        if (*x1 > x_b - 2)

            *x1 = x_b - 2;

        break;

    case 80:

        gotoxy(*x1, *y1);
        printf(NONE_MARK);
        *y1 = *y1 + 1; //아래쪽 방향의 화살표 키 입력

        if (*y1 > y_b - 1)

            *y1 = y_b - 1;

        break;

    default:

        return;

    }

}





/*

    도형왕국 게임에서 구현되는 마법들을 위한 함수

*/
void wormhole_trap(int* x, int* y)
{
    gotoxy(1, 28);
    textcolor(4);
    printf("웜홀 마법에 당했습니다. 초기위치로 돌아갑니다");
    Sleep(1000); // 웜홀 빠지는 중
    gotoxy(1, 30);
    printf(LONG_NONE_MARK);
    *x = 2; *y = 2; //초기위치

}

void stop_trap()
{
    gotoxy(1, 28);
    printf(LONG_NONE_MARK);
    textcolor(8);
    printf("마법사의 마법에 걸렸습니다. 2초간 멈춥니다.");
    Sleep(2000);
}

void stop_trap_up()
{

    gotoxy(1, 28);
    printf(LONG_NONE_MARK);
    textcolor(12);
    printf("마법사의 강력한 마법에 걸렸습니다. 4초간 멈춥니다.");
    Sleep(4000);
}
void True_eye(int matrix[][20], int topx[], int topy[])
{
    int i;
    gotoxy(1, 28);
    printf(LONG_NONE_MARK);
    textcolor(1);
    printf("진실의 눈이 탑의 허상을 가려냅니다.\n");
    matrix[topx[9]][topy[9]] = 2;
    
}

void True_eye2(int matrix[][25], int topx[], int topy[])
{
    int i;
    gotoxy(1, 28);
    printf(LONG_NONE_MARK);
    textcolor(1);
    printf("진실의 눈이 탑의 허상을 가려냅니다.\n");
    matrix[topx[13]][topy[13]] = 2;
   
}
void True_eye3(int matrix[][25], int topx[], int topy[])
{
    int i;
    gotoxy(1, 28);
    printf(LONG_NONE_MARK);
    textcolor(1);
    printf("진실의 눈이 탑의 허상을 가려냅니다.\n");
    matrix[topx[14]][topy[14]] = 2;
}


/*

    게임 control에따라 바뀌는 맵을 적용하기 위한 함수

*/

void display_map(int matrix[][15], int topx[], int topy[], int stagex, int stagey)
{
    int i, j;

    for (i = 0; i < stagex; i++)
    {
        for (j = 0; j < stagey; j++)
        {
            if (matrix[i][j] >= 2)

            {
                gotoxy(2 * i, j);
                textcolor(5);
                printf(TOP_MARK);

                if (matrix[i][j] == 6)
                {
                    gotoxy(2 * i, j);
                    textcolor(3);
                    printf(PLAYER_MARK2);
                }
                else if (matrix[i][j] == 4)
                {
                    textcolor(8);
                    gotoxy(2 * i, j);
                    printf(TRAP_STOP);
                }
            }

            else if (matrix[i][j] == 1)
            {
                textcolor(10);
                gotoxy(2 * i, j);
                printf(WALL_MARK);

            }
            else if (matrix[i][j] == -1)
            {
                gotoxy(2 * i, j);
                printf(NONE_MARK);

            }

        }

    }

}

void display_map2(int matrix[][20], int topx[], int topy[], int stagex, int stagey)
{
    int i, j;

    for (i = 0; i < stagex; i++)
    {
        for (j = 0; j < stagey; j++)
        {
            if (matrix[i][j] >= 2)

            {
                gotoxy(2 * i, j);
                textcolor(5);
                printf(TOP_MARK);

                if (matrix[i][j] == 6)
                {
                    gotoxy(2 * i, j);
                    printf(PLAYER_MARK1);
                }
                else if (matrix[i][j] == 4)
                {
                    gotoxy(2 * i, j);
                    textcolor(8);
                    printf(TRAP_STOP);
                }
                else if (matrix[i][j] == 5)
                {
                    gotoxy(2 * i, j);
                    textcolor(4);
                    printf(TRAP_HOLE);
                }
                else if (matrix[i][j] == 2)
                {
                    gotoxy(2 * i, j);
                    textcolor(1);
                    printf(TRUE_EYE);
                }
            }

            else if (matrix[i][j] == 1)
            {
                gotoxy(2 * i, j);
                textcolor(11);
                printf(WALL_MARK);

            }
            else if (matrix[i][j] == -1)
            {
                gotoxy(2 * i, j);
                printf(NONE_MARK);

            }

        }

    }

}

void display_map3(int matrix[][25], int topx[], int topy[], int stagex, int stagey)
{
    int i, j;

    for (i = 0; i < stagex; i++)
    {
        for (j = 0; j < stagey; j++)
        {
            if (matrix[i][j] >= 2)

            {
                gotoxy(2 * i, j);
                textcolor(5);
                printf(TOP_MARK);

                if (matrix[i][j] == 6)
                {
                    gotoxy(2 * i, j);
                    textcolor(4);
                    printf(TRUE_LOVE);
                }
                else if (matrix[i][j] == 4 || matrix[i][j] == 7)
                {
                    gotoxy(2 * i, j);
                    textcolor(8);
                    printf(TRAP_STOP);
                }
                else if (matrix[i][j] == 5)
                {
                    gotoxy(2 * i, j);
                    textcolor(12);
                    printf(TRAP_HOLE);
                }

                else if (matrix[i][j] == 2)
                {
                    textcolor(1);
                    gotoxy(2 * i, j);
                    printf(TRUE_EYE);
                }
            }

            else if (matrix[i][j] == 1)
            {
                textcolor(4);
                gotoxy(2 * i, j);
                printf(WALL_MARK);

            }
            else if (matrix[i][j] == -1)
            {
                gotoxy(2 * i, j);
                printf(NONE_MARK);

            }

        }

    }

}

/*
    stage별 게임 control을 위한 함수
*/


void stage_game_control(int topx[], int topy[], clock_t start, double* pst, int stagex, int stagey)

{
    char key, restart;
    int i, j, count = 0;
    int x = 2, y = 2;

    int s_time = time(NULL);
    clock_t end;

    int matrix[10][15] =
    {
        {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
    };


    for (i = 0; i < 8; i++)
    {
        matrix[topx[i]][topy[i]] = 9;
    }

    do
    {
        gotoxy(x, y);
        textcolor(3);
        printf(PLAYER_MARK1);
        //matrix[(x + 1) / 2][y] = 0;// 지나간 것을 표시.

        for (i = 0; i < 15; i++)
        {
            if (((x) / 2 == topx[i]) && (y == topy[i]))
                matrix[topx[i]][topy[i]] = -1;
        }

        if (((x) / 2 == topx[0]) && (y == topy[0]))
            matrix[(x) / 2][y] = 6;  //공주 구하기


        else if (x / 2 == topx[4] && (y == topy[4]))
        {
            matrix[(x + 1) / 2][y] = 4; // 멈추기 마법 표시
            stop_trap();
            gotoxy(x, y);
        }

        for (i = 0; i < 10; i++)
        {
            for (j = 0; j < 15; j++)
                if (matrix[i][j] == 6)
                {
                    count = count + 1;
                }

        }

        gotoxy(2, 2);

        display_map(matrix, topx, topy, stagex, stagey); //지도를 바꾼다

        key = _getch();

        move_arrow_key(key, &x, &y, 18, 14);
        end = clock();

        *pst = (double)(end - start) / CLK_TCK;
        gotoxy(1, 17);

        printf("경과시간:%.1f초", *pst);

        if (*pst > TIME_LIMIT)
        {
            gotoxy(1, 19);
            printf("탑의 봉인이 완성 되었습니다. \n");
            Sleep(1000);
            *pst = 0;
            stage1();
            
        }


    } while (count < 1);
    {
        printf("공주를 구했습니다!!\n");
        Sleep(2000);
        stage2(); }

}

void stage_game_control2(int topx[], int topy[], clock_t start, double* pst, int stagex, int stagey)
{
    char key, restart;
    int i, j, count = 0;
    int x = 2, y = 2;

    int s_time = time(NULL);
    clock_t end;

    int matrix[15][20] =
    {
        {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    };

    for (i = 0; i < 15; i++)
    {
        matrix[topx[i]][topy[i]] = 9;
    }

    do
    {
        gotoxy(x, y);

        printf(PLAYER_MARK2);

        //matrix[(x + 1) / 2][y] = 0;// 지나간 것을 표시.

        for (i = 0; i < 15; i++)
        {
            if (((x) / 2 == topx[i]) && (y == topy[i]))
                matrix[topx[i]][topy[i]] = -1;
        }

        if (((x) / 2 == topx[0]) && (y == topy[0]))
            matrix[(x) / 2][y] = 6;  //마름모 구하기


        else if (x / 2 == topx[4] && (y == topy[4]))
        {
            matrix[(x + 1) / 2][y] = 4; // 멈추기 마법 표시
            stop_trap();
            gotoxy(x, y);
        }
        else if (x / 2 == topx[5] && (y == topy[5]))
        {
            matrix[(x + 1) / 2][y] = 4; // 멈추기 마법 표시
            stop_trap();
            gotoxy(x, y);
        }

        else if (x / 2 == topx[6] && (y == topy[6]))
        {
            matrix[(x + 1) / 2][y] = 5; // 웜홀 마법 표시
            wormhole_trap(&x, &y);
            gotoxy(x, y);
        }
        else if (x / 2 == topx[7] && (y == topy[7]))
        {
            matrix[(x + 1) / 2][y] = 5; // 웜홀 마법 표시
            wormhole_trap(&x, &y);
            gotoxy(x, y);
        }
        else if (x / 2 == topx[8] && (y == topy[8]))
        {
            matrix[(x + 1) / 2][y] = 2; // 진실의 눈 표시(기능 도움)
            True_eye(matrix, topx, topy);


        }


        for (i = 1; i < 15; i++)
        {
            for (j = 1; j < 20; j++)
                if (matrix[i][j] == 6)
                {
                    count = count + 1;
                }

        }

        gotoxy(2, 2);
        display_map2(matrix, topx, topy, stagex, stagey); //지도를 바꾼다

        key = _getch();

        move_arrow_key(key, &x, &y, 28, 19);
        end = clock();

        *pst = (double)(end - start) / CLK_TCK;
        gotoxy(1, 22);

        printf("경과시간:%.1f초", *pst);

        if (*pst > TIME_LIMIT_S2)
        {
            gotoxy(1, 23);
            printf("탑의 봉인이 완성 되었습니다. \n");
            Sleep(1000);
            *pst = 0;
            stage2();
        }



    } while (count < 1);
    {

        gotoxy(1, 22);
        printf("마름모를 구했습니다!!\n");
        Sleep(2000);
        stage3(); }

}


void stage_game_control3(int topx[], int topy[], clock_t start, double* pst, int stagex, int stagey)
{
    char key, restart;
    int i, j, count = 0;
    int x = 2, y = 2;

    int s_time = time(NULL);
    clock_t end;

    int matrix[20][25] =
    {
        {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
    };

    for (i = 0; i < 20; i++)
    {
        matrix[topx[i]][topy[i]] = 9;
    }

    do
    {
        gotoxy(x, y);
        textcolor(6);
        printf(PLAYER_MARK3);

        //matrix[(x + 1) / 2][y] = 0;// 지나간 것을 표시.

        for (i = 0; i < 20; i++)
        {
            if (((x) / 2 == topx[i]) && (y == topy[i]))
                matrix[topx[i]][topy[i]] = -1;
        }

        if (((x) / 2 == topx[0]) && (y == topy[0]))
        {
            matrix[(x) / 2][y] = 6;
            gotoxy(1, 27);
            printf("마법사를 무찌르기에 아직 부족합니다, 좀더 힘을 내주세요!");//  @마법사 처치하기
        }

        else if (x / 2 == topx[4] && (y == topy[4]))
        {
            matrix[(x + 1) / 2][y] = 4; // 멈추기 마법 표시
            stop_trap();
            gotoxy(x, y);
        }
        else if (x / 2 == topx[5] && (y == topy[5]))
        {
            matrix[(x + 1) / 2][y] = 4; // 멈추기 마법 표시
            stop_trap();
            gotoxy(x, y);
        }
        else if (x / 2 == topx[6] && (y == topy[6]))
        {
            matrix[(x + 1) / 2][y] = 4; // 멈추기 마법 표시
            stop_trap();
            gotoxy(x, y);
        }
        else if (x / 2 == topx[7] && (y == topy[7]))
        {
            matrix[(x + 1) / 2][y] = 7; // 강력한 멈추기 마법 표시
            stop_trap_up();
            gotoxy(x, y);
        }
        else if (x / 2 == topx[8] && (y == topy[8]))
        {
            matrix[(x + 1) / 2][y] = 7; // 강력한 멈추기 마법 표시
            stop_trap_up();
            gotoxy(x, y);
        }

        else if (x / 2 == topx[9] && (y == topy[9]))
        {
            matrix[(x + 1) / 2][y] = 5; // 웜홀 마법 표시
            wormhole_trap(&x, &y);
            gotoxy(x, y);
        }
        else if (x / 2 == topx[10] && (y == topy[10]))
        {
            matrix[(x + 1) / 2][y] = 5; // 웜홀 마법 표시
            wormhole_trap(&x, &y);
            gotoxy(x, y);
        }
        else if (x / 2 == topx[10] && (y == topy[10]))
        {
            matrix[(x + 1) / 2][y] = 5; // 웜홀 마법 표시
            wormhole_trap(&x, &y);
            gotoxy(x, y);
        }
        else if (x / 2 == topx[11] && (y == topy[11]))
        {
            matrix[(x + 1) / 2][y] = 2; // 진실의 눈 표시(기능 도움)
            True_eye2(matrix, topx, topy);
        }
        else if (x / 2 == topx[12] && (y == topy[12]))
        {
            matrix[(x + 1) / 2][y] = 2; // 진실의 눈 표시(기능 도움)
            True_eye3(matrix, topx, topy);
        }
        else if (x / 2 == topx[15] && (y == topy[15]))
        {
            matrix[(x + 1) / 2][y] = 6; // @마법사 처치2

        }

        count = 0;
        for (i = 0; i < 20; i++)
        {
            for (j = 0; j < 25; j++)
            {
                if (matrix[i][j] == 6)
                {
                    count = count + 1;
                }
            }

        }

        gotoxy(2, 2);
        display_map3(matrix, topx, topy, stagex, stagey); //지도를 바꾼다

        key = _getch();

        move_arrow_key(key, &x, &y, 38, 24);
        end = clock();

        *pst = (double)(end - start) / CLK_TCK;
        gotoxy(1, 26);

        printf("경과시간:%.1f초", *pst);

        if (*pst > TIME_LIMIT_S3)
        {
            gotoxy(1, 30);
            printf("@마법사가 도망갔습니다. 후에 더 강력해져서 돌아올 수 있습니다.\n");
            Sleep(1000);
            *pst = 0;
            stage3();
        }
    } while (count < 2);

    gotoxy(1, 30);
    printf("@마법사를 무찔렀습니다!! 왕국에는 과연 평화가 왔을까요..?\n");
    Sleep(2000);
    storyEND();


}


