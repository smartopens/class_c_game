
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <Windows.h>
#include <time.h>
#define NONE_MARK  "  "
#define LONG_NONE_MARK  "                                                       "
#define PLAYER_MARK1  "﹣"
#define PLAYER_MARK2  "∞"
#define PLAYER_MARK3  "≧"
#define WALL_MARK2  "﹥"
#define GUARD_MARK  "〡"
#define TOP_MARK  "Ⅱ"
#define WALL_MARK "〩"
#define TREASURE_MARK "〩"
#define TRAP_HOLE "��"
#define TRAP_STOP "≦"
#define TRUE_EYE "≡"
#define TRUE_LOVE "Ⅵ"
#define MAX_X 20
#define MAX_Y 30
#define TIME_LIMIT 15
#define TIME_LIMIT_S2 30
#define TIME_LIMIT_S3 60

//啪歜 掘⑷擊 嬪и л熱菟
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

//蝶饜葬 掘撩擊 嬪и л熱菟
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
       main л熱
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
        printf("廓�ㄧ� 摹鷗ж撮蹂: ");
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
            printf("Щ煎斜極檜 謙猿腌棲棻.");
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
        啪歜 menu縑 渠и л熱
*/
void menu()
{
    textcolor(11);
    puts("旨收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旬");
    puts("早                                       早");
    puts("早       ﹣∞   紫⑽ 諾措   ∞﹣         早");
    puts("早                                       早");
    puts("早          1. Stage1[蟾晝]              早");
    puts("早                                       早");
    puts("早          2. Stage2[醞晝]              早");
    puts("早                                       早");
    puts("早          3. Stage3[堅晝]              早");
    puts("早                                       早");
    puts("早          0. 謙     猿                 早");
    puts("早                                       早");
    puts("曲收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旭");
}



/*
        啪歜 stage縑 渠и л熱
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
        啪歜 story縑 渠и л熱
*/
int story1()
{

    system("cls");
    textcolor(11);
    puts("旨收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旬");
    puts("早                                                                              早");
    puts("早   紫⑽ 諾措縑 餌朝 葆葷賅縑啪朝 餌嫌ж朝 餌塋檣 翕斜塭嘐 奢輿陛 氈棻.        早");
    puts("早  捱等 捱等 陝霞 斜縑啪 氈橫憮 奢輿曖 嬴葷棻遴 錳⑽擎 換檜睡衛啪 嬴葷棻錫棻.  早");
    puts("早  僭煩 籀擠縑朝 滌 馬�奰� 橈歷棻.衛濛擎 籀擠戲煎 翱醞 ч餌煎 翮葬朝 紫⑽蹴薯  早");
    puts("早  縑 釭鬲擊陽棻.罹楝 紫⑽菟擎 陝檜 螳氈朝 葆葷賅縑啪 棻陛螃溥 ж雖 彊懊棻.    早");
    puts("早  斜溢啪 辦選п ж堅氈朝 葆葷賅縑啪 翕斜塭嘐 奢輿朝 試盪 棻陛諦輿歷棻.        早");
    puts("早  閨虜嬴棲塭, 斜喪朝 蹴薯縑 氈朝 翕斜塭嘐, 撮賅, 薑餌陝⑽蛔 斜 援掘紫         早");
    puts("早  離滌ж雖 彊懊棻. 斜盪 紫⑽ 斜濠羹煎 餌嫌п還閨..                            早");
    puts("早                                                                              早");
    puts("早                                                                              早");
    puts("早                                                                              早");
    puts("曲收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旭");


    printf("嬴鼠酈釭 援腦撮蹂");
    _getch();


}



void story2()
{
    char skip;
    system("cls");
    textcolor(11);
    puts("旨收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旬");
    puts("早                                                                              早");
    puts("早   葆葷賅朝 斜楛 奢輿蒂 爾賊憮 ��檜 陬棻. 濠褐曖 陝霞 賅蝗紫 橫翹賊 陛纂陛    早");
    puts("早  氈朝 橾檜塭朝 儅陝檜 菟歷棻. 斜楚憮 葆葷賅朝 渦 檜鼻 濠褐曖 陝霞 賅蝗擊     早");
    puts("早  嘐錶ж雖 彊晦煎 ц棻. 螃�鷛� 斜楛 欽薄擊 餌嫌ж堅, 傳 濠褐馬擊 陛雖堅 輿滲  早");
    puts("早  紫⑽菟縑啪 棻陛鬲棻. 斜 �譟� 葆葷賅朝 濠褐擊 餌嫌ж堅, 曖嘐氈朝 橾擊 ж晦  早");
    puts("早  嬪п 喻溘ц堅 斜楛 賅蝗縑 奢輿紫 葆葷賅蒂 換罹啖 爾啪 腎歷棻. 賃 喇檜 �撣ㄟ磽�");
    puts("早  唸措 葆葷賅諦 奢輿朝 餌嫌ж朝 餌檜陛 腎歷堅 葆葷賅朝 棻陛螃朝 紫⑽蹴薯陳,   早");
    puts("早  斜喪縑啪 堅寥ж晦煎 葆擠 詳歷棻.                                            早");
    puts("早                                                                              早");
    puts("早                                                                              早");
    puts("早                                                                              早");
    puts("曲收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旭");


    printf("嬴鼠酈釭 援腦撮蹂");

    _getch();
    _getch();

}

void story3()
{
    char skip;
    system("cls");
    textcolor(11);
    puts("旨收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旬");
    puts("早                                                                              早");
    puts("早   斜溢啪 紫⑽蹴薯陛 翮葬堅 葆葷賅陛 辨晦蒂 頂溥堅 й 陽艘棻. 骨濠晦 蝶骯и   早");
    puts("早  寰偃陛 諾措寰擊 陛菜 瓊堅 援陛 援捱雖 碟除擊 й 熱陛 橈歷棻. '畦學!!'       早");
    puts("早  奢輿曖 跡模葬艘棻. 葆葷賅朝 獄棟瞳戲煎 奢輿蒂 掘ж晦 嬪п 殖溜雖虜 @        早");
    puts("早  葆徹餌陛 檜嘐 奢輿蒂 稱濩堅 氈歷棻. 葆藹頂 奢輿縑啪 棻陛螞 葆葷賅朝 @       早");
    puts("早  葆徹餌蒂 щп 陝霞 賅憮葬煎 給問ц雖虜 嘐葬 嫦翕п菩 葆徹戲煎 葆徹餌朝 餌塭 早");
    puts("早  螺棻. ※奢輿蒂 瓊堅 談戲賊 鱉戲煎 諦塭, 衛除檜 雖釭賊 奢輿朝 艙艙 獐        早");
    puts("早  橈擊剪撿!!§塭朝 蜓婁 л眷.. 葆葷賅朝 蜂撲橾 衛除檜 橈棻! 橫憮 奢輿蒂       早");
    puts("早  掘ж楝 鱉戲煎 陛濠!!                                                        早");
    puts("早                                                                              早");
    puts("早                                                                              早");
    puts("曲收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旭");


    printf("嬴鼠酈釭 援腦撮蹂");

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
        puts("旨收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旬");
        puts("早                                                                              早");
        puts("早   奢輿蒂 掘ц棻! 葆葷賅朝 奢輿曖 鼻鷓蒂 �挫恉葧�. 棻ч�� 奢輿朝 惘雛嬴 爾    早");
        puts("早  艘棻. ※檜歇 陽陛 嬴棲撿§ 葆葷賅朝 奢輿蒂 等葬堅 鱉擊 慇橫釭 憮萃楝 諾措   早");
        puts("早  戲煎 щж溥 ц棻. ※檜溢啪 場艦 牖 橈雖!!§ 斜楛等 斜陽 @葆徹餌曖 擠撩檜    早");
        puts("早  菟溜堅棻衛 и廓 掙瞪縑憮 獄 瑰檣 葆徹檜 奢輿蒂 щп 棻陛諮棻. 奢輿縑啪      早");
        puts("早  棻衛 葆徹檜 陛п雖溥朝 牖除, 葆葷賅朝 ��擊 棻п 虞嬴撕堅 餌塭雖堅 蜓懊棻.   早");
        puts("早  奢輿朝 濡衛 渡�笞萴鷏� 檜頂 藹雜п螺棻. ※頂陛 掘ж賊 腎.§                 早");
        puts("早  檜廓縑朝 奢輿 離滔棻, 鱉縑 瑰檣腎堅 氈朝 葆葷賅蒂 掘ж濠!!                  早");
        puts("早                                                                              早");
        puts("早                                                                              早");
        puts("早                                                                              早");
        puts("曲收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旭");

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
        puts("旨收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旬");
        puts("早                                                                              早");
        puts("早   葆葷賅蒂 掘ц棻! 檜薯朝 葆徹餌紫 ��檜 紮 緒霞 蛭ж棻. 斜溢啪 葆葷賅諦      早");
        puts("早  奢輿朝 驍轎擊 ж溥堅 ц雖虜.. 檜渠煎 陛賊 樹薇陛 葆徹餌陛 棻衛 螢雖 賅艇棻.  早");
        puts("早  葆葷賅朝 奢輿蒂 夥塭爾懊堅 奢輿羲衛 偽擎 儅陝檣 蛭 ц棻.  '頂 賅憮葬陛 ��擊 早");
        puts("早  嫦�秷珔妤�' 斜溢啪 葆徹餌縑啪 給霞ж溥 й 陽, 奢輿朝 葆葷賅蒂 濩戲貊 ヶ寰   早");
        puts("早  縑憮 滌維 爾戮擊 疏麻棻. 斜匙擎 紫⑽ 諾措縑憮 頂溥螃朝 爾僭檜艘棻. 舒貲檜憮虜 早");
        puts("早  餌辨檜 陛棟и 爾僭煎, 憮煎 葆擠檜 蜃雖 彊剪釭 濠褐擊 棻瑞雖 跤ж朝 擒и     早");
        puts("早  紫⑽擎 餌辨й 熱陛 橈歷棻. 棻ч�� 爾僭擎 �膩�蒂 嫦�秷葥� 滌曖 葆徹檜 萃擊   早");
        puts("早  馬調棻. 檜薯 陴擎勒 @葆徹餌檜棻! 葆徹餌蒂 籀葬ж楝 陛濠!                    早");
        puts("早                                                                              早");
        puts("早                                                                              早");
        puts("曲收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旭");

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
        puts("旨收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旬");
        puts("早                                                                              早");
        puts("早   @葆徹餌蒂 僭葬蟻棻! 葆葷賅諦 奢輿朝 雖耀跺擊 檜莊堅 諾措戲煎 щц棻.       早");
        puts("早  �瑍釋� 鏃ж堅 葆葷賅朝 辨晦蒂 頂憮 跤棻и 堅寥擊 ц堅 奢輿朝 嫡嬴菟         早");
        puts("早  艘棻. 奢輿蒂 掘п螞 辨晦縑 馬問и 諾紫 萃 餌檜蒂 ъ塊ц堅 葆葷賅諦          早");
        puts("早  奢輿曖 唸�末釋� 翮葬啪 腎歷棻. ж雖虜 葆葷賅紫, 奢輿紫 ④Я縛註檜塭堅       早");
        puts("早  儅陝ж雖 彊懊棻. 斜菟縑啪朝 п撿й 橾菟檜 氈歷堅 樹薯 傳 @葆徹餌 偽擎       早");
        puts("早  紫⑽菟檜 諾措擊 藥菟橫 螢雖 賅腦朝 橾檜艘戲棲梱. 葆葷賅朝 о鼻 喻溘ц堅     早");
        puts("早  陝霞 賅憮葬菟煎 堅鱔嫡朝 紫⑽ 菟擊 嬪煎ц棻. 濠褐曖 陝霞 賅蝗擊 濠嫌        早");
        puts("早  ж賊憮 蜓檜棻. 奢輿紫 棺 ж湍 匙籀歲 棻艇 紫⑽菟擊 問溥ц堅 葆葷賅蒂 嬴硫   早");
        puts("早  輿歷棻. 濠, 檜薯 辦葬菟 離滔殮棲棻! 辦葬菟曖 賅я擊 ж堅 辦葬菟曖           早");
        puts("早              Story蒂 菟溥鄹衛棻! 傳棻艇 援捱陛縑啪!                          早");
        puts("曲收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旭");

        printf("END to E");
        scanf("%c", &num);

    } while (num != 'E');

    return flag;

}







/*

啪歜 敘罌擊 轎溘ж朝 л熱 display_rule

*/

void display_rule1(void)

{
    gotoxy(1, 1);

    printf("﹣∞   紫⑽ 諾措   ∞﹣");

    gotoxy(1, 3);

    printf("鱉縑 陘�� 奢輿蒂 掘п撿 м棲棻. ");

    gotoxy(1, 5);

    printf("鱉寰縑朝 奢輿 傳朝 葆徹餌陛 遽綠и л薑 葆徹檜 氈蝗棲棻. \n");

    gotoxy(1, 7);

    printf("薯и脹 衛除(30蟾)陛 雖釭賊 鱉曖 瑰檣擎 諫撩檜 腎堅\n");

    gotoxy(1, 9);

    printf("奢輿蒂 艙艙 獐熱陛 橈蝗棲棻.\n");

    gotoxy(1, 11);

    printf("濠, ��擊 頂撮蹂!!\n");

    gotoxy(1, 12);
    printf("------------------------------------------------\n");

    gotoxy(1, 14);
    printf("8偃曖 (Ⅱ)鱉檜 氈蝗棲棻.\n");

    gotoxy(1, 16);
    printf("≦葆徹縑 勘葬賊 2蟾除 遺霜橾 熱陛 橈蝗棲棻.\n");

    _getch();
    _getch();
}
void display_rule2(void)

{

    gotoxy(1, 1);

    printf("﹣∞   紫⑽ 諾措   ∞﹣");

    gotoxy(1, 3);

    printf("鱉寰縑朝 葆葷賅 傳朝 葆徹餌陛 遽綠и 葆徹檜 晦棻葬堅 氈蝗棲棻. \n");

    gotoxy(1, 5);

    printf("薯и脹 衛除(45蟾)陛 雖釭賊 鱉曖 瑰檣擎 諫撩檜 腎堅\n");

    gotoxy(1, 7);

    printf("葆葷賅朝 艙艙 獐熱陛 橈蝗棲棻.\n");

    gotoxy(1, 9);

    printf("碟и @葆徹餌朝 渦 棻曄и 葆徹擊 睡董棲棻.\n");

    gotoxy(1, 11);

    printf("ж雖虜 奢輿朝 か薑 鱉縑憮 霞褒曖 換(≡) 葆徹擊 餌辨й 熱 氈蝗棲棻. ��頂撮蹂!\n");

    gotoxy(1, 12);
    printf("------------------------------------------------\n");

    gotoxy(1, 14);
    printf("15偃曖 (Ⅱ)鱉檜 氈蝗棲棻.\n");

    gotoxy(1, 16);
    printf("(≦)STOP葆徹縑 勘葬賊 2蟾除 遺霜橾 熱陛 橈蝗棲棻. x 2\n");

    gotoxy(1, 18);
    printf("(��)錢�� 葆徹縑 勘葬賊 鱉縑憮 寞轎腎堅 蟾晦 嬪纂煎 檜翕腌棲棻. x 2 \n");

    gotoxy(1, 20);
    printf("(≡)霞褒曖 換擎 ъ鼻曖 鱉 ж釭蒂 陛溥鹿棲棻. x 1\n");


    _getch();
    _getch();
}


void display_rule3(void)

{

    gotoxy(1, 1);

    printf("﹣∞   紫⑽ 諾措   ∞﹣");

    gotoxy(1, 3);

    printf("鱉寰縑朝 雖耀 @葆徹餌陛 獗橫 氈蝗棲棻. \n");

    gotoxy(1, 5);

    printf("薯и脹 衛除(60蟾)檜 雖釭賊 紫蜂 葆徹霞檜 諫撩檜 腎堅\n");

    gotoxy(1, 7);

    printf("@葆徹餌朝 餌塭韓匏棲棻.\n");

    gotoxy(1, 9);

    printf("@葆徹餌朝 鬼溘�� 盪ож啊雖虜 滌曖 ��檜 舒 紫⑽擊 馬諄堅 氈蝗棲棻.\n");

    gotoxy(1, 11);

    printf("鼠歙爾棻 渡褐擎 �母痚� 嬴椎棲棻, 濠 ��頂撮蹂!!\n");

    gotoxy(1, 12);
    printf("------------------------------------------------\n");

    gotoxy(1, 14);
    printf("20偃曖 (Ⅱ)鱉檜 氈蝗棲棻.\n");

    gotoxy(1, 16);
    printf("(≦)STOP葆徹縑 勘葬賊 2蟾除 遺霜橾 熱陛 橈蝗棲棻. x 3\n");

    gotoxy(1, 18);
    printf("鬼溘и (≦)STOP葆徹縑 勘葬賊 4蟾除 遺霜橾 熱陛 橈蝗棲棻. x 2\n");

    gotoxy(1, 20);
    printf("(��)錢�� 葆徹縑 勘葬賊 鱉縑憮 寞轎腎堅 蟾晦 嬪纂煎 檜翕腌棲棻. x 5\n");

    gotoxy(1, 22);
    printf("(≡)霞褒曖 換擎 ъ鼻曖 鱉 ж釭蒂 陛溥鹿棲棻. x 2 \n");

    _getch();
    _getch();

}





/*

    鱉曖 嬪纂 菟檜 虜菟橫雖朝 л熱

*/

void make_hidden_and_top1(int topx[], int topy[], int topCnt, int stagex, int stagey)

{
    int i;

    for (i = 0; i < topCnt; i++) //top, hidden 謝ル 虜菟晦

    {
        do
        {
            topx[i] = rand() % stagex - 1; //hidden曖 x 謝ル
            topy[i] = rand() % stagey - 1; //hidden曖 y 謝ル

        } while ((topx[i] < 2) || (topy[i] < 2));
    }
}






/*

    儀梃 殮�鰲� л熱

*/

void textcolor(int color_number)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color_number);
}




/*

    餌辨濠 殮溘縑 評塭 醴憮 雖薑ж晦 嬪и л熱

*/
void gotoxy(int x, int y)

{

    COORD Pos = { x  , y };

    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);

}



/*

    л熱 move_arrow_key 寞щ酈縑 評塭 遺霜檜晦 嬪и л熱

*/
void move_arrow_key(char key, int* x1, int* y1, int x_b, int y_b)

{

    switch (key)

    {

    case 72:
        gotoxy(*x1, *y1);
        printf(NONE_MARK);
        *y1 = *y1 - 1; //嬪薹 寞щ曖 �香嚂� 酈 殮溘

        if (*y1 < 1)

            *y1 = 1;

        break;

    case 75:

        gotoxy(*x1, *y1);
        printf(NONE_MARK);
        *x1 = *x1 - 2; //豭薹 寞щ曖 �香嚂� 酈 殮溘

        if (*x1 < 2)

            *x1 = 2;

        break;

    case 77:

        gotoxy(*x1, *y1);
        printf(NONE_MARK);
        *x1 = *x1 + 2; //螃艇薹 寞щ曖 �香嚂� 酈 殮溘

        if (*x1 > x_b - 2)

            *x1 = x_b - 2;

        break;

    case 80:

        gotoxy(*x1, *y1);
        printf(NONE_MARK);
        *y1 = *y1 + 1; //嬴楚薹 寞щ曖 �香嚂� 酈 殮溘

        if (*y1 > y_b - 1)

            *y1 = y_b - 1;

        break;

    default:

        return;

    }

}





/*

    紫⑽諾措 啪歜縑憮 掘⑷腎朝 葆徹菟擊 嬪и л熱

*/
void wormhole_trap(int* x, int* y)
{
    gotoxy(1, 28);
    textcolor(4);
    printf("錢�� 葆徹縑 渡ц蝗棲棻. 蟾晦嬪纂煎 給嬴骨棲棻");
    Sleep(1000); // 錢�� 緒雖朝 醞
    gotoxy(1, 30);
    printf(LONG_NONE_MARK);
    *x = 2; *y = 2; //蟾晦嬪纂

}

void stop_trap()
{
    gotoxy(1, 28);
    printf(LONG_NONE_MARK);
    textcolor(8);
    printf("葆徹餌曖 葆徹縑 勘溜蝗棲棻. 2蟾除 誇邊棲棻.");
    Sleep(2000);
}

void stop_trap_up()
{

    gotoxy(1, 28);
    printf(LONG_NONE_MARK);
    textcolor(12);
    printf("葆徹餌曖 鬼溘и 葆徹縑 勘溜蝗棲棻. 4蟾除 誇邊棲棻.");
    Sleep(4000);
}
void True_eye(int matrix[][20], int topx[], int topy[])
{
    int i;
    gotoxy(1, 28);
    printf(LONG_NONE_MARK);
    textcolor(1);
    printf("霞褒曖 換檜 鱉曖 ъ鼻擊 陛溥鹿棲棻.\n");
    matrix[topx[9]][topy[9]] = 2;
    
}

void True_eye2(int matrix[][25], int topx[], int topy[])
{
    int i;
    gotoxy(1, 28);
    printf(LONG_NONE_MARK);
    textcolor(1);
    printf("霞褒曖 換檜 鱉曖 ъ鼻擊 陛溥鹿棲棻.\n");
    matrix[topx[13]][topy[13]] = 2;
   
}
void True_eye3(int matrix[][25], int topx[], int topy[])
{
    int i;
    gotoxy(1, 28);
    printf(LONG_NONE_MARK);
    textcolor(1);
    printf("霞褒曖 換檜 鱉曖 ъ鼻擊 陛溥鹿棲棻.\n");
    matrix[topx[14]][topy[14]] = 2;
}


/*

    啪歜 control縑評塭 夥船朝 裘擊 瞳辨ж晦 嬪и л熱

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
    stage滌 啪歜 control擊 嬪и л熱
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
        //matrix[(x + 1) / 2][y] = 0;// 雖釭除 匙擊 ル衛.

        for (i = 0; i < 15; i++)
        {
            if (((x) / 2 == topx[i]) && (y == topy[i]))
                matrix[topx[i]][topy[i]] = -1;
        }

        if (((x) / 2 == topx[0]) && (y == topy[0]))
            matrix[(x) / 2][y] = 6;  //奢輿 掘ж晦


        else if (x / 2 == topx[4] && (y == topy[4]))
        {
            matrix[(x + 1) / 2][y] = 4; // 誇蹺晦 葆徹 ル衛
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

        display_map(matrix, topx, topy, stagex, stagey); //雖紫蒂 夥羞棻

        key = _getch();

        move_arrow_key(key, &x, &y, 18, 14);
        end = clock();

        *pst = (double)(end - start) / CLK_TCK;
        gotoxy(1, 17);

        printf("唳婁衛除:%.1f蟾", *pst);

        if (*pst > TIME_LIMIT)
        {
            gotoxy(1, 19);
            printf("鱉曖 瑰檣檜 諫撩 腎歷蝗棲棻. \n");
            Sleep(1000);
            *pst = 0;
            stage1();
            
        }


    } while (count < 1);
    {
        printf("奢輿蒂 掘ц蝗棲棻!!\n");
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

        //matrix[(x + 1) / 2][y] = 0;// 雖釭除 匙擊 ル衛.

        for (i = 0; i < 15; i++)
        {
            if (((x) / 2 == topx[i]) && (y == topy[i]))
                matrix[topx[i]][topy[i]] = -1;
        }

        if (((x) / 2 == topx[0]) && (y == topy[0]))
            matrix[(x) / 2][y] = 6;  //葆葷賅 掘ж晦


        else if (x / 2 == topx[4] && (y == topy[4]))
        {
            matrix[(x + 1) / 2][y] = 4; // 誇蹺晦 葆徹 ル衛
            stop_trap();
            gotoxy(x, y);
        }
        else if (x / 2 == topx[5] && (y == topy[5]))
        {
            matrix[(x + 1) / 2][y] = 4; // 誇蹺晦 葆徹 ル衛
            stop_trap();
            gotoxy(x, y);
        }

        else if (x / 2 == topx[6] && (y == topy[6]))
        {
            matrix[(x + 1) / 2][y] = 5; // 錢�� 葆徹 ル衛
            wormhole_trap(&x, &y);
            gotoxy(x, y);
        }
        else if (x / 2 == topx[7] && (y == topy[7]))
        {
            matrix[(x + 1) / 2][y] = 5; // 錢�� 葆徹 ル衛
            wormhole_trap(&x, &y);
            gotoxy(x, y);
        }
        else if (x / 2 == topx[8] && (y == topy[8]))
        {
            matrix[(x + 1) / 2][y] = 2; // 霞褒曖 換 ル衛(晦棟 紫遺)
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
        display_map2(matrix, topx, topy, stagex, stagey); //雖紫蒂 夥羞棻

        key = _getch();

        move_arrow_key(key, &x, &y, 28, 19);
        end = clock();

        *pst = (double)(end - start) / CLK_TCK;
        gotoxy(1, 22);

        printf("唳婁衛除:%.1f蟾", *pst);

        if (*pst > TIME_LIMIT_S2)
        {
            gotoxy(1, 23);
            printf("鱉曖 瑰檣檜 諫撩 腎歷蝗棲棻. \n");
            Sleep(1000);
            *pst = 0;
            stage2();
        }



    } while (count < 1);
    {

        gotoxy(1, 22);
        printf("葆葷賅蒂 掘ц蝗棲棻!!\n");
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

        //matrix[(x + 1) / 2][y] = 0;// 雖釭除 匙擊 ル衛.

        for (i = 0; i < 20; i++)
        {
            if (((x) / 2 == topx[i]) && (y == topy[i]))
                matrix[topx[i]][topy[i]] = -1;
        }

        if (((x) / 2 == topx[0]) && (y == topy[0]))
        {
            matrix[(x) / 2][y] = 6;
            gotoxy(1, 27);
            printf("葆徹餌蒂 鼠鎬腦晦縑 嬴霜 睡褶м棲棻, 覬渦 ��擊 頂輿撮蹂!");//  @葆徹餌 籀纂ж晦
        }

        else if (x / 2 == topx[4] && (y == topy[4]))
        {
            matrix[(x + 1) / 2][y] = 4; // 誇蹺晦 葆徹 ル衛
            stop_trap();
            gotoxy(x, y);
        }
        else if (x / 2 == topx[5] && (y == topy[5]))
        {
            matrix[(x + 1) / 2][y] = 4; // 誇蹺晦 葆徹 ル衛
            stop_trap();
            gotoxy(x, y);
        }
        else if (x / 2 == topx[6] && (y == topy[6]))
        {
            matrix[(x + 1) / 2][y] = 4; // 誇蹺晦 葆徹 ル衛
            stop_trap();
            gotoxy(x, y);
        }
        else if (x / 2 == topx[7] && (y == topy[7]))
        {
            matrix[(x + 1) / 2][y] = 7; // 鬼溘и 誇蹺晦 葆徹 ル衛
            stop_trap_up();
            gotoxy(x, y);
        }
        else if (x / 2 == topx[8] && (y == topy[8]))
        {
            matrix[(x + 1) / 2][y] = 7; // 鬼溘и 誇蹺晦 葆徹 ル衛
            stop_trap_up();
            gotoxy(x, y);
        }

        else if (x / 2 == topx[9] && (y == topy[9]))
        {
            matrix[(x + 1) / 2][y] = 5; // 錢�� 葆徹 ル衛
            wormhole_trap(&x, &y);
            gotoxy(x, y);
        }
        else if (x / 2 == topx[10] && (y == topy[10]))
        {
            matrix[(x + 1) / 2][y] = 5; // 錢�� 葆徹 ル衛
            wormhole_trap(&x, &y);
            gotoxy(x, y);
        }
        else if (x / 2 == topx[10] && (y == topy[10]))
        {
            matrix[(x + 1) / 2][y] = 5; // 錢�� 葆徹 ル衛
            wormhole_trap(&x, &y);
            gotoxy(x, y);
        }
        else if (x / 2 == topx[11] && (y == topy[11]))
        {
            matrix[(x + 1) / 2][y] = 2; // 霞褒曖 換 ル衛(晦棟 紫遺)
            True_eye2(matrix, topx, topy);
        }
        else if (x / 2 == topx[12] && (y == topy[12]))
        {
            matrix[(x + 1) / 2][y] = 2; // 霞褒曖 換 ル衛(晦棟 紫遺)
            True_eye3(matrix, topx, topy);
        }
        else if (x / 2 == topx[15] && (y == topy[15]))
        {
            matrix[(x + 1) / 2][y] = 6; // @葆徹餌 籀纂2

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
        display_map3(matrix, topx, topy, stagex, stagey); //雖紫蒂 夥羞棻

        key = _getch();

        move_arrow_key(key, &x, &y, 38, 24);
        end = clock();

        *pst = (double)(end - start) / CLK_TCK;
        gotoxy(1, 26);

        printf("唳婁衛除:%.1f蟾", *pst);

        if (*pst > TIME_LIMIT_S3)
        {
            gotoxy(1, 30);
            printf("@葆徹餌陛 紫蜂鬲蝗棲棻. �醴� 渦 鬼溘п螳憮 給嬴螢 熱 氈蝗棲棻.\n");
            Sleep(1000);
            *pst = 0;
            stage3();
        }
    } while (count < 2);

    gotoxy(1, 30);
    printf("@葆徹餌蒂 鼠鎚毓蝗棲棻!! 諾措縑朝 婁翱 ゎ�降� 諮擊梱蹂..?\n");
    Sleep(2000);
    storyEND();


}


