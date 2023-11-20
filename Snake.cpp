#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#define NORMAL "\x1b[m"
#define BHBLK "\e[1;90m"
#define BHRED "\e[1;91m"
#define BHGRN "\e[1;92m"
#define BHYEL "\e[1;93m"
#define BHBLU "\e[1;94m"
#define BHMAG "\e[1;95m"
#define BHCYN "\e[1;96m"
#define BHWHT "\e[1;97m"
#define BLKHB "\e[0;100m"
#define REDHB "\e[0;101m"
#define GRNHB "\e[0;102m"
#define YELHB "\e[0;103m"
#define BLUHB "\e[0;104m"
#define MAGHB "\e[0;105m"
#define CYNHB "\e[0;106m"
#define WHTHB "\e[0;107m"

using namespace std;
class game
{
public:
    int value;
    int player;
    game *next;
    void insert(int data);
    void show_game();
   game(int data)
    {
        next = NULL;
        value=data;
    }
};
void draw_line(int n, char ch);
void board(int, int);
void gamescore(char name1[], char name2[], int p1, int p2);
void play_dice(int &score);

int main()
{
    game *p1 =new game(0);
    game *p2 =new game(0);
    p1->player=1;
    p2->player=2;
    int player1 = 0, player2 = 0, lastpos;
    char p1name[80], p2name[80];
    system("cls");

    srand((unsigned)time(NULL));

    draw_line(50, '=');
    cout << "\n";
    draw_line(50, '=');
    cout << "\n";
    draw_line(50, '=');
    cout << "\n\t\tSNAKE LADDER GAME\n";
    draw_line(50, '=');
    cout << "\n";
    draw_line(50, '=');
    cout << "\n";
    draw_line(50, '=');

    cout << "\n\n\nEnter Name of player 1 :";
    cin >> (p1name);
    cout << "\nEnter Name of player 2 :";
    cin >> (p2name);

    while (player1 < 100 && player2 < 100)
    {
        board(player1, player2);
        gamescore(p1name, p2name, player1, player2);
        cout << "\n\n >>> " << p1name << " Now your Turn >> Press any key to play ";
        getch();
        lastpos = player1;
        play_dice(player1);
        p1->insert(player1);
        if (player1 < lastpos)
            cout << "\n\aOops!! Snake found !! You are at postion " << player1 << "\n";
        else if (player1 > lastpos + 6)
            cout << "\nGreat!! you got a ladder !! You are at position " << player1;
        else if (player2 == lastpos)
            cout << "Cannot move" << endl;

        cout << "\n\n >>> " << p2name << " Now your Turn >> Press any key to play ";
        getch();
        lastpos = player2;

        play_dice(player2);
        p2->insert(player2);
        if (player2 < lastpos)
            cout << "\n\n\aOops!! Snake found !! You are at position " << player2 << "\n";
        else if (player2 > lastpos + 6)
            cout << "\n\nGreat!! you got a ladder !! You are at position " << player2 << "\n";
        else if (player2 == lastpos)
            cout << "Cannot move" << endl;
        getch();
    }
    system("cls");
    cout << "\n\n\n";
    draw_line(100, '#');
    cout << "\n\t\tRESULT\n\n";
    draw_line(100, '#');
    cout << endl;
    gamescore(p1name, p2name, player1, player2);
    cout << "\n\n\n";
    if (player1 >= player2)
        cout << "Congratulations !!! " << p1name << ", You won the game\n\n";
    else
        cout << "Congratulations !!! " << p2name << ", You won the game\n\n";
    draw_line(52, '#');
    cout<<"\n\t\t\t\tMatch history=>\n";
    cout<<"\033[5";
    p1->show_game();
    cout<<endl;
    p2->show_game();
    getch();
    return 0;
}
void draw_line(int n, char ch)
{
    for (int i = 0; i < n; i++)
        cout << ch;
}

void board(int player1, int player2)
{
    system("cls");
    int size = 10;
    int board[10][10];
    int i, j, count = 1;
    int flag = 1;

    for (i = size - 1; i >= 0; i--)
    {
        if (flag)
        {
            for (j = 0; j < size; j++)
            {
                board[i][j] = count++;
            }
            flag = 0;
        }
        else
        {
            for (j = size - 1; j >= 0; j--)
            {
                board[i][j] = count++;
            }
            flag = 1;
        }
    }

    // Print the board
    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
        {
            if(player1 == board[i][j] || player2 == board[i][j]){
                printf("\033[5m");
            }

            switch (board[i][j])
            {
            case 98:
            case 55:
                printf("%s%3d%s", BHRED, board[i][j], NORMAL);
                break;
            case 92:
            case 75:
                printf("%s%3d%s", BHYEL, board[i][j], NORMAL);
                break;
            case 82:
            case 42:
                printf("%s%3d%s", BHBLU, board[i][j], NORMAL);
                break;
            case 73:
            case 51:
                printf("%s%3d%s", BHWHT, board[i][j], NORMAL);
                break;
            case 56:
            case 19:
                printf("%s%3d%s", BHMAG, board[i][j], NORMAL);
                break;
            case 47:
            case 15:
                printf("%s%3d%s", BHCYN, board[i][j], NORMAL);
                break;
            case 30:
            case 7:
                printf("%s%3d%s", BHGRN, board[i][j], NORMAL);
                break;
            case 89:
            case 71:
                printf("%s%3d%s", REDHB, board[i][j], NORMAL);
                break;
            case 80:
            case 63:
                printf("%s%3d%s", GRNHB, board[i][j], NORMAL);
                break;
            case 76:
            case 43:
                printf("%s%3d%s", YELHB, board[i][j], NORMAL);
                break;
            case 74:
            case 29:
                printf("%s%3d%s", BLUHB, board[i][j], NORMAL);
                break;
            case 39:
            case 21:
                printf("%s%3d%s", MAGHB, board[i][j], NORMAL);
                break;
            case 25:
            case 4:
                printf("%s%3d%s", CYNHB, board[i][j], NORMAL);
                break;

            default:
                printf("%3d", board[i][j]);
            }
            if(player1 == board[i][j] && player2 == board[i][j])
                printf("%sX%sO%s ",BHMAG, BHGRN, NORMAL);
            else if(player1 == board[i][j])
                printf("%sX%s  ",BHMAG,  NORMAL);
            else if(player2 == board[i][j])
                printf("%sO%s  ",BHGRN,  NORMAL);
            else
                printf("\t");
        }
        printf("\n\n");
    }
    printf("\n\nBOLD COLORED NUMBERS ARE INDICATING SNAKES\n\nBACKGROUND COLORED NUMBERS ARE INDIACTING LADDERS\n");
}

void gamescore(char name1[], char name2[], int p1, int p2)
{
    cout << "\n";
    draw_line(52, '-');
    cout << "\n\t\tGAME STATUS\n";
    draw_line(52, '-');
    cout << "\n > " << BHMAG << "X " << NORMAL << name1 << " is at position " << p1 << endl;
    cout << " > " << BHGRN << "O " << NORMAL << name2 << " is at position " << p2 << endl;
    draw_line(52, '_');
    cout << endl;
}

void play_dice(int &score)
{
    int dice;
    dice = 1 + rand() % 6;
    cout << "\nYou got " << dice << " Point !! ";
    if (score + dice <= 100)
        score = score + dice;
    cout << "Now you are at position " << score;
    switch (score)
    {
    case 4:
        score = 25;
        break;
    case 29:
        score = 74;
        break;
    case 21:
        score = 39;
        break;
    case 43:
        score = 76;
        break;
    case 63:
        score = 80;
        break;
    case 71:
        score = 89;
        break;
    case 98:
        score = 55;
        break;
    case 92:
        score = 75;
        break;
    case 82:
        score = 42;
        break;
    case 56:
        score = 19;
        break;
    case 30:
        score = 7;
        break;
    case 47:
        score = 15;
        break;
    }
}
void game::insert(int data)
{
    game *n=new game(data);
   
    if(next==NULL){
        next=n;
        return;
    }else if(next!=NULL){
         
        game *tr=next;
        while(tr->next!=NULL)
        {
            tr=tr->next;
        }
         tr->next=n;
    }
       
}


void game::show_game()
{
    game *tr=next;
    cout<<"Move of player "<<player<<":";
    cout<<value;
    while(tr!=NULL)
    {
        
        cout<<"->"<<tr->value;
        tr=tr->next;
    }
}