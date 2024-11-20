#include "_Play.h"
#include <vector>
#include <Windows.h>
#include <mmsystem.h>
#include <iostream>
using namespace std;
int d1, d2, d3;
struct Name{
    char data[30];
};
vector <Name> ch;

void Textcolor(int color)
{
    HANDLE hConsoleColor;
    hConsoleColor = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsoleColor, color);
}
void AnTroChuot()
{
    CONSOLE_CURSOR_INFO Info;
    Info.bVisible = FALSE;
    Info.dwSize = 20;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &Info);
}
void HienTroChuot()
{
    CONSOLE_CURSOR_INFO Info;
    Info.bVisible = TRUE;
    Info.dwSize = 20;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &Info);
}
int ReadChedo(char a[30])
{
    int chedo;
    system("cls");
    ifstream f;
    f.open(a, ios::in);
    if (!f){
        _Common::gotoXY(35, 46);
        cout << "\n FILE KHONG TON TAI!" << endl;
        Sleep(1000);
        ScreenStartGame(99);
    }
    else
        f >> d1>> d2 >> d3 >> chedo;
    f.close();
    return chedo;
}
void ReadNameFile()
{
    int a, b, c;
    Textcolor(Cyan);
    _Common::gotoXY(60, 18);
    cout << "LIST FILE NAME";
    int i = 19;
    ifstream f;
    f.open("Name.txt", ios::in);
    while (!f.eof())
    {
        char s[30];
        f >> s >> a >> b >> c;
        _Common::gotoXY(50, i);
        cout << s;
        i++;
    }
    f.close();
}
void PrintCaro()
{
    int x = 25;
    Textcolor(rand()%15+1);
    _Common::gotoXY(x+20, 7);
    cout << "XXX   XXX     OOOOOOO";
    _Common::gotoXY(x + 20, 8);
    cout << " XXX XXX     OOO   OOO";
    _Common::gotoXY(x + 20, 9);
    cout << "  XXXXX      OOO   OOO ";
    _Common::gotoXY(x + 20, 10);
    cout << " XXX XXX     OOO   OOO";
    _Common::gotoXY(x + 20, 11);
    cout << "XXX   XXX     OOOOOOO";
}
void PrintCaro2()
{
    int x= 25;
    Textcolor(defaultColor);
    _Common::gotoXY(x+20, 7);
    cout << "XXX   XXX     OOOOOOO";
    _Common::gotoXY(x + 20, 8);
    cout << " XXX XXX     OOO   OOO";
    _Common::gotoXY(x + 20, 9);
    cout << "  XXXXX      OOO   OOO ";
    _Common::gotoXY(x + 20, 10);
    cout << " XXX XXX     OOO   OOO";
    _Common::gotoXY(x + 20, 11);
    cout << "XXX   XXX     OOOOOOO";
}

void About()
{
    system("cls");
    PrintCaro2();
    Textcolor(Cyan);
    _Common::gotoXY(60, 18);
    cout << "ABOUT";
    _Common::gotoXY(50, 21);
    cout << "GAME CARO";
    _Common::gotoXY(50, 22);
    cout << "THUC HIEN: LINHTQ23" << endl;
    _Common::gotoXY(50, 23);
    cout << "CHOI GAME VUI VE!";
    _Common::gotoXY(60, 30);
    cout << "BACK";
    char command = ' ';
    command = _getch();
    system("cls");
}
void Help()
{
    system("cls");
    PrintCaro2();
    Textcolor(Cyan);
    _Common::gotoXY(60, 18);
    cout << "HELP";
    _Common::gotoXY(50, 21);
    cout << "HUONG DAN" << endl;
    _Common::gotoXY(50, 22);
    cout << "1. Ban co gom " << SIZE << "x" << SIZE << " o vuong." << endl;
    _Common::gotoXY(50, 23);
    cout << "2. Su dung cac phim W A S D de di chuyen va Enter de danh." << endl;
    _Common::gotoXY(50, 24);
    cout << "3. Luat choi cu du 5 quan co X hoac O theo hang ngang, doc, cheo se chien thang." << endl;
    _Common::gotoXY(50, 25);
    cout << "4. Luat choi tuan theo quy dinh chan 2 dau " << endl;

    _Common::gotoXY(50, 26);
    cout << "-> Chuc moi nguoi choi game vui ve !!" << endl;
    _Common::gotoXY(60, 30);
    cout << "BACK";
    char command = ' ';
    command = _getch();
    system("cls");
}
void LoadLoad()
{
    int n = 100;
    system("cls");
    PrintCaro2();
    ReadNameFile();
    char data[30];
    _Common::gotoXY(50, 32);
    HienTroChuot();
    cout << "ENTER FILE NAME: ";
    cin.getline(data, 30);
    int chedo = ReadChedo(data);
    if (chedo == -30 || chedo == -31)
    {
        Diem a;
        a.score1 = d1;
        a.score2 = d2;
        a.score3 = d3;
        int t = PlayerVsPlayer(a, chedo, data);
        if (t == 27)
        {
            system("cls");
            ScreenStartGame(n - 1);
        }
    }
    if (chedo == -4)
    {
        Diem a;
        a.score1 = d1;
        a.score2 = d2;
        a.score3 = d3;
        int t = PlayerVsCom2(a, -4, data);
        if (t == 27)
        {
            system("cls");
            ScreenStartGame(n - 1);
        }
    }
    if (chedo == -5)
    {
        Diem a;
        a.score1 = d1;
        a.score2 = d2;
        a.score3 = d3;
        int t = PlayerVsCom(a, -5, data);
        if (t == 27)
        {
            system("cls");
            ScreenStartGame(n - 1);
        }
    }
}

void searchInformation() {
    system("cls");
    PrintCaro2();
    vector<string> name;
    vector<int> win;
    vector<int> draw;
    vector<int> lose;
    char data[30];
    ifstream f;
    f.open("Name.txt", ios::in);
    while (!f.eof())
    {
        char s[30];
        int a, b, c;
        f >> s >> a >> b >> c;
        name.push_back(s);
        win.push_back(a);
        lose.push_back(b);
        draw.push_back(c);
    }
    f.close();

    // sắp xếp
    for (size_t i=0; i<win.size(); i++) {
        for (size_t j=i+1; j<win.size(); j++){
            if (win[j]*3 + draw[j] > win[j+1]*3 + draw[j+1]) {
                std::swap(name[j], name[j+1]);
                std::swap(win[j], win[j+1]);
                std::swap(draw[j], draw[j+1]);
                std::swap(lose[j], lose[j+1]);
            }
        }
    }
    bool c = true;
    int k =20;
    _Common::gotoXY(40, 19);
    cout << "ENTER PLAYER NAME: ";
    cin.getline(data, 30);
    for (size_t i=0; i<win.size(); i++) {
        if (name[i] == string(data)) {
            _Common::gotoXY(50, k);
            cout <<"Thong tin nguoi choi: ";
            _Common::gotoXY(50, k++);
            cout << "Name: " << name[i] << "- Win: " << win[i] << "- Lose: " << lose[i] <<"- Draw: " << draw[i];
            _Common::gotoXY(50, k++);
            cout << "Thong tin nguoi choi cung cap do: ";
            if (i>=1){
                _Common::gotoXY(50, k++);
                cout << "Name: " << name[i-1] << "- Win: " << win[i-1] << "- Lose: " << lose[i-1] <<"- Draw: " << draw[i-1];
            }
            if (i>=2){
                _Common::gotoXY(50, k++);
                cout << "Name: " << name[i-2] << "- Win: " << win[i-2] << "- Lose: " << lose[i-2] <<"- Draw: " << draw[i-2];
            }
            if (i<sizeof(win)-1){
                _Common::gotoXY(50, k++);
                cout << "Name: " << name[i+1] << "- Win: " << win[i+1] << "- Lose: " << lose[i+1] <<"- Draw: " << draw[i+1];
            }
            if (i<sizeof(win)-2) {
                _Common::gotoXY(50, k++);
                cout << "Name: " << name[i] << "- Win: " << win[i] << "- Lose: " << lose[i] <<"- Draw: " << draw[i];
            }
            c=false;
        }
    }
    if (c == true) {
        _Common::gotoXY(50, k);
        cout <<"Khon co thong tin nguoi choi";
    }
    char command =' ';
    command = _getch();
    system("cls");
}

void ScreenStartGame(int n)
{

    AnTroChuot();
    int x = 50, y = 20;
    //int i;
    char s[30] = " ";
    int check = 1;
    Textcolor(Red);
    _Common::gotoXY(50, 20); cout << "Player Vs Player";
    Textcolor(7);
    _Common::gotoXY(50, 21); cout << "Player Vs Computer (Easy)";
    _Common::gotoXY(50, 22); cout << "Player Vs Computer (Hard)";
    _Common::gotoXY(50, 23); cout << "Load Game";
    _Common::gotoXY(50, 24); cout << "Help";
    _Common::gotoXY(50, 25); cout << "About";
    _Common::gotoXY(50, 26); cout << "Exit";
    _Common::gotoXY(50, 27); cout << "Search Information";
    _Common::gotoXY(50, 32); cout << "....... W - S : Move";
    _Common::gotoXY(50, 33); cout << "....... Enter : Select ";
    if (n == 100)
    {
        Screen();
        PrintCaro();
    }
    else
        PrintCaro2();

    while (check)
    {
        if (_kbhit())
        {
            switch (_getch())
            {
            case 'w': case 72:
                if (y > 20)
                {
                    y--;
                    _Common::gotoXY(x, y);
                }
                if (y == 20)
                {
                    Textcolor(Red);
                    _Common::gotoXY(50, 20); cout << "Player Vs Player";
                    Textcolor(7);
                    _Common::gotoXY(50, 21); cout << "Player Vs Computer (Easy)";
                    _Common::gotoXY(50, 22); cout << "Player Vs Computer (Hard)";
                    _Common::gotoXY(50, 23); cout << "Load Game";
                    _Common::gotoXY(50, 24); cout << "Help";
                    _Common::gotoXY(50, 25); cout << "About";
                    _Common::gotoXY(50, 26); cout << "Exit";
                    _Common::gotoXY(50, 27); cout << "Search Information";
                }
                if (y == 21)
                {
                    Textcolor(7);
                    _Common::gotoXY(50, 20); cout << "Player Vs Player";
                    Textcolor(Red);
                    _Common::gotoXY(50, 21); cout << "Player Vs Computer (Easy)";
                    Textcolor(7);
                    _Common::gotoXY(50, 22); cout << "Player Vs Computer (Hard)";
                    _Common::gotoXY(50, 23); cout << "Load Game";
                    _Common::gotoXY(50, 24); cout << "Help";
                    _Common::gotoXY(50, 25); cout << "About";
                    _Common::gotoXY(50, 26); cout << "Exit";
                    _Common::gotoXY(50, 27); cout << "Search Information";
                }
                if (y == 22)
                {
                    Textcolor(7);
                    _Common::gotoXY(50, 20); cout << "Player Vs Player";
                    _Common::gotoXY(50, 21); cout << "Player Vs Computer (Easy)";
                    Textcolor(Red);
                    _Common::gotoXY(50, 22); cout << "Player Vs Computer (Hard)";
                    Textcolor(7);
                    _Common::gotoXY(50, 23); cout << "Load Game";
                    _Common::gotoXY(50, 24); cout << "Help";
                    _Common::gotoXY(50, 25); cout << "About";
                    _Common::gotoXY(50, 26); cout << "Exit";
                    _Common::gotoXY(50, 27); cout << "Search Information";
                }
                if (y == 23)
                {
                    Textcolor(7);
                    _Common::gotoXY(50, 20); cout << "Player Vs Player";
                    _Common::gotoXY(50, 21); cout << "Player Vs Computer (Easy)";
                    _Common::gotoXY(50, 22); cout << "Player Vs Computer (Hard)";
                    Textcolor(Red);
                    _Common::gotoXY(50, 23); cout << "Load Game";
                    Textcolor(7);
                    _Common::gotoXY(50, 24); cout << "Help";
                    _Common::gotoXY(50, 25); cout << "About";
                    _Common::gotoXY(50, 26); cout << "Exit";
                    _Common::gotoXY(50, 27); cout << "Search Information";
                }
                if (y == 24)
                {
                    Textcolor(7);
                    _Common::gotoXY(50, 20); cout << "Player Vs Player";
                    _Common::gotoXY(50, 21); cout << "Player Vs Computer (Easy)";
                    _Common::gotoXY(50, 22); cout << "Player Vs Computer (Hard)";
                    _Common::gotoXY(50, 23); cout << "Load Game";
                    Textcolor(Red);
                    _Common::gotoXY(50, 24); cout << "Help";
                    Textcolor(7);
                    _Common::gotoXY(50, 25); cout << "About";
                    _Common::gotoXY(50, 26); cout << "Exit";
                    _Common::gotoXY(50, 27); cout << "Search Information";
                }
                if (y == 25)
                {
                    Textcolor(7);
                    _Common::gotoXY(50, 20); cout << "Player Vs Player";
                    _Common::gotoXY(50, 21); cout << "Player Vs Computer (Easy)";
                    _Common::gotoXY(50, 22); cout << "Player Vs Computer (Hard)";
                    _Common::gotoXY(50, 23); cout << "Load Game";
                    _Common::gotoXY(50, 24); cout << "Help";
                    Textcolor(Red);
                    _Common::gotoXY(50, 25); cout << "About";
                    Textcolor(7);
                    _Common::gotoXY(50, 26); cout << "Exit";
                    _Common::gotoXY(50, 27); cout << "Search Information";
                }
                if (y == 26)
                {
                    Textcolor(7);
                    _Common::gotoXY(50, 20); cout << "Player Vs Player";
                    _Common::gotoXY(50, 21); cout << "Player Vs Computer (Easy)";
                    _Common::gotoXY(50, 22); cout << "Player Vs Computer (Hard)";
                    _Common::gotoXY(50, 23); cout << "Load Game";
                    _Common::gotoXY(50, 24); cout << "Help";
                    _Common::gotoXY(50, 25); cout << "About";
                    Textcolor(Red);
                    _Common::gotoXY(50, 26); cout << "Exit";
                    Textcolor(7);
                    _Common::gotoXY(50, 27); cout << "Search Information";
                }
                if (y == 27)
                {
                    Textcolor(7);
                    _Common::gotoXY(50, 20); cout << "Player Vs Player";
                    _Common::gotoXY(50, 21); cout << "Player Vs Computer (Easy)";
                    _Common::gotoXY(50, 22); cout << "Player Vs Computer (Hard)";
                    _Common::gotoXY(50, 23); cout << "Load Game";
                    _Common::gotoXY(50, 24); cout << "Help";
                    _Common::gotoXY(50, 25); cout << "About";
                    _Common::gotoXY(50, 26); cout << "Exit";
                    Textcolor(Red);
                    _Common::gotoXY(50, 27); cout << "Search Information";
                }
                break;
            case 's': case 80:
                if (y<27)
                {
                    y++;
                    _Common::gotoXY(x, y);
                }
                if (y == 20)
                {
                    Textcolor(Red);
                    _Common::gotoXY(50, 20); cout << "Player Vs Player";
                    Textcolor(7);
                    _Common::gotoXY(50, 21); cout << "Player Vs Computer (Easy)";
                    _Common::gotoXY(50, 22); cout << "Player Vs Computer (Hard)";
                    _Common::gotoXY(50, 23); cout << "Load Game";
                    _Common::gotoXY(50, 24); cout << "Help";
                    _Common::gotoXY(50, 25); cout << "About";
                    _Common::gotoXY(50, 26); cout << "Exit";
                    _Common::gotoXY(50, 27); cout << "Search Information";
                }
                if (y == 21)
                {
                    Textcolor(7);
                    _Common::gotoXY(50, 20); cout << "Player Vs Player";
                    Textcolor(Red);
                    _Common::gotoXY(50, 21); cout << "Player Vs Computer (Easy)";
                    Textcolor(7);
                    _Common::gotoXY(50, 22); cout << "Player Vs Computer (Hard)";
                    _Common::gotoXY(50, 23); cout << "Load Game";
                    _Common::gotoXY(50, 24); cout << "Help";
                    _Common::gotoXY(50, 25); cout << "About";
                    _Common::gotoXY(50, 26); cout << "Exit";
                    _Common::gotoXY(50, 27); cout << "Search Information";
                }
                if (y == 22)
                {
                    Textcolor(7);
                    _Common::gotoXY(50, 20); cout << "Player Vs Player";
                    _Common::gotoXY(50, 21); cout << "Player Vs Computer (Easy)";
                    Textcolor(Red);
                    _Common::gotoXY(50, 22); cout << "Player Vs Computer (Hard)";
                    Textcolor(7);
                    _Common::gotoXY(50, 23); cout << "Load Game";
                    _Common::gotoXY(50, 24); cout << "Help";
                    _Common::gotoXY(50, 25); cout << "About";
                    _Common::gotoXY(50, 26); cout << "Exit";
                    _Common::gotoXY(50, 27); cout << "Search Information";
                }
                if (y == 23)
                {
                    Textcolor(7);
                    _Common::gotoXY(50, 20); cout << "Player Vs Player";
                    _Common::gotoXY(50, 21); cout << "Player Vs Computer (Easy)";
                    _Common::gotoXY(50, 22); cout << "Player Vs Computer (Hard)";
                    Textcolor(Red);
                    _Common::gotoXY(50, 23); cout << "Load Game";
                    Textcolor(7);
                    _Common::gotoXY(50, 24); cout << "Help";
                    _Common::gotoXY(50, 25); cout << "About";
                    _Common::gotoXY(50, 26); cout << "Exit";
                    _Common::gotoXY(50, 27); cout << "Search Information";
                }
                if (y == 24)
                {
                    Textcolor(7);
                    _Common::gotoXY(50, 20); cout << "Player Vs Player";
                    _Common::gotoXY(50, 21); cout << "Player Vs Computer (Easy)";
                    _Common::gotoXY(50, 22); cout << "Player Vs Computer (Hard)";
                    _Common::gotoXY(50, 23); cout << "Load Game";
                    Textcolor(Red);
                    _Common::gotoXY(50, 24); cout << "Help";
                    Textcolor(7);
                    _Common::gotoXY(50, 25); cout << "About";
                    _Common::gotoXY(50, 26); cout << "Exit";
                    _Common::gotoXY(50, 27); cout << "Search Information";
                }
                if (y == 25)
                {
                    Textcolor(7);
                    _Common::gotoXY(50, 20); cout << "Player Vs Player";
                    _Common::gotoXY(50, 21); cout << "Player Vs Computer (Easy)";
                    _Common::gotoXY(50, 22); cout << "Player Vs Computer (Hard)";
                    _Common::gotoXY(50, 23); cout << "Load Game";
                    _Common::gotoXY(50, 24); cout << "Help";
                    Textcolor(Red);
                    _Common::gotoXY(50, 25); cout << "About";
                    Textcolor(7);
                    _Common::gotoXY(50, 26); cout << "Exit";
                    _Common::gotoXY(50, 27); cout << "Search Information";
                }
                if (y == 26)
                {
                    Textcolor(7);
                    _Common::gotoXY(50, 20); cout << "Player Vs Player";
                    _Common::gotoXY(50, 21); cout << "Player Vs Computer (Easy)";
                    _Common::gotoXY(50, 22); cout << "Player Vs Computer (Hard)";
                    _Common::gotoXY(50, 23); cout << "Load Game";
                    _Common::gotoXY(50, 24); cout << "Help";
                    _Common::gotoXY(50, 25); cout << "About";
                    Textcolor(Red);
                    _Common::gotoXY(50, 26); cout << "Exit";
                    Textcolor(7);
                    _Common::gotoXY(50, 27); cout << "Search Information";
                }
                if (y == 27)
                {
                    Textcolor(7);
                    _Common::gotoXY(50, 20); cout << "Player Vs Player";
                    _Common::gotoXY(50, 21); cout << "Player Vs Computer (Easy)";
                    _Common::gotoXY(50, 22); cout << "Player Vs Computer (Hard)";
                    _Common::gotoXY(50, 23); cout << "Load Game";
                    _Common::gotoXY(50, 24); cout << "Help";
                    _Common::gotoXY(50, 25); cout << "About";
                    _Common::gotoXY(50, 26); cout << "Exit";
                    Textcolor(Red);
                    _Common::gotoXY(50, 27); cout << "Search Information";
                }
                break;
            case 13:
                if (y == 20)
                {
                    Diem a;
                    a.score1 = 0;
                    a.score2 = 0;
                    a.score3 = 0;
                    int t = PlayerVsPlayer(a,0,s);
                    //cout<<s;
                    if (t == 27)
                    {
                        system("cls");
                        ScreenStartGame(99);
                    }
                }
                if (y == 21)
                {
                    Diem a;
                    a.score1 = 0;
                    a.score2 = 0;
                    a.score3 = 0;
                    int t = PlayerVsCom2(a,0,s);
                    if (t == 27)
                    {
                        system("cls");
                        ScreenStartGame(99);
                    }
                }
                if (y == 22)
                {
                    Diem a;
                    a.score1 = 0;
                    a.score2 = 0;
                    a.score3 = 0;
                    int t = PlayerVsCom(a,0,s);
                    if (t == 27)
                    {
                        system("cls");
                        ScreenStartGame(99);
                    }
                }
                if (y == 23)
                {
                    LoadLoad();

                }
                if (y == 24)
                {
                    Help();
                    ScreenStartGame(99);
                }
                if (y == 25)
                {
                    About();
                    ScreenStartGame(99);
                }
                if (y == 26)
                {
                    exit(0);
                }
                if (y == 27)
                {
                    searchInformation();
                    ScreenStartGame(99);
                }
                break;
            }
        }
    }
}
void PrintScoreBoard()
{
    Textcolor(White);
    _Common::gotoXY(SIZE * 4 + 40, 2);
    cout << "PLAYER 1";
    _Common::gotoXY(SIZE * 4 + 30, 4);
    cout << "So quan X : ";
    _Common::gotoXY(SIZE * 4 + 30, 5);
    cout << "So tran da thang : ";
    _Common::gotoXY(SIZE * 4 + 30, 6);
    cout << "So tran da thua : ";
    _Common::gotoXY(SIZE * 4 + 30, 7);
    cout << "So tran hoa : ";


    _Common::gotoXY(SIZE * 4 + 40, 12);
    cout << "PLAYER 2";
    _Common::gotoXY(SIZE * 4 + 30, 14);
    cout << "So quan O : ";
    _Common::gotoXY(SIZE * 4 + 30, 15);
    cout << "So tran da thang : ";
    _Common::gotoXY(SIZE * 4 + 30, 16);
    cout << "So tran da thua : ";
    _Common::gotoXY(SIZE * 4 + 30, 17);
    cout << "So tran hoa : ";


    _Common::gotoXY(SIZE * 4 + 30, 25);
    cout << "-----------------------";
    _Common::gotoXY(SIZE * 4 + 30, 26);
    cout << " W A S D : Move ";
    _Common::gotoXY(SIZE * 4 + 30, 27);
    cout << " U : Undo ";
    _Common::gotoXY(SIZE * 4 + 30, 28);
    cout << " R : Redo ";
    _Common::gotoXY(SIZE * 4 + 30, 29);
    cout << " L : Save Game ";
    _Common::gotoXY(SIZE * 4 + 30, 30);
    cout << " T : Load Game ";
    _Common::gotoXY(SIZE * 4 + 30, 31);
    cout << " ESC : Exit ";

    _Common::gotoXY(2,1);
} // IN BANG DIEM
void Screen()
{
    int check = 1;
    while (check<20)
    {
        PrintCaro();
        Sleep(100);
        check++;
    }
}
int PlayerVsCom(Diem &a, int load , char data[30])
{
    int k = 1, n = 100;
    int *xAt = new int[SIZE*SIZE];
    int *yAt = new int[SIZE*SIZE];
    int *check = new int[SIZE*SIZE];
    for (int i = 0; i < SIZE*SIZE; i++)
    {
        xAt[i] = -1;
        yAt[i] = -1;
        check[i] = 0;
    }
    int i = 0;
    HienTroChuot();
    _Game g(SIZE, 0, 0);
    g.setCountXY();
    if (load == -5)
    {
        g.LoadGame(data);
    }
    else
    {
        g.startGame();
        g.setTurn();
    }
    PrintScoreBoard();
    Textcolor(Cyan);
    _Common::gotoXY(SIZE * 4 + 32, 22);
    cout << " PLAYER VS BOT (HARD) ";
    Textcolor(Blue);
    _Common::gotoXY(SIZE * 4 + 30 + 18, 5);
    cout << a.score1;
    _Common::gotoXY(SIZE * 4 + 30 + 18, 6);
    cout << a.score2;
    _Common::gotoXY(SIZE * 4 + 30 + 18, 7);
    cout << a.score3;
    //cout << g.getScore1();
    Textcolor(Red);
    _Common::gotoXY(SIZE * 4 + 30 + 18, 15);
    cout << a.score2;
    _Common::gotoXY(SIZE * 4 + 30 + 18, 16);
    cout << a.score1;
    _Common::gotoXY(SIZE * 4 + 30 + 18, 17);
    cout << a.score3;
    //cout << g.getScore2();
    _Common::gotoXY(2, 1);
    while (g.isContinue())
    {
        if (!g.getTurn())
        {
            if (g.DemNuocCoDaDi() == 0)
            {
                g.setX((SIZE * 4 / 2)-2);
                g.setY((SIZE * 2 / 2)-1);
                _Common::gotoXY((SIZE * 4 / 2) - 2, (SIZE * 2 / 2) - 1);
                g.setCommand(13);
            }
            else
            {
                g.TimKiemNuocDi2();
                int x = g.getXatEnter();
                int y = g.getYatEnter();
                _Common::gotoXY(x, y);
                Sleep(300);
                g.setCommand(13);
            }
        }
        else
            g.waitKeyBoard();
        if (g.getCommand() == 27)
        {
            return 27;
        }
        else
        {
            switch (g.getCommand())
            {
            case 'A': case 75:
                g.moveLeft();
                break;
            case 'D': case 77:
                g.moveRight();
                break;
            case 'W': case 72:
                g.moveUp();
                break;
            case 'S': case 80:
                g.moveDown();
                break;
            case 'L':
                g.SaveGame(-5, a.score1, a.score2, a.score3);
                break;
            case 'T':
                LoadLoad();
                break;
            case 'U':
                if (i > 0 && xAt[i-1] >= 0 && yAt[i-1] >= 0){
                    g.Undo(xAt[i-1], yAt[i-1]);
                    i--;
                }
                if (i > 0 && xAt[i-1] >= 0 && yAt[i-1] >= 0){
                    g.Undo(xAt[i-1], yAt[i-1]);
                    i--;
                }
                _Common::gotoXY(xAt[i-1], yAt[i-1]);
                break;
            case 'R':
                if (i >= 0 && xAt[i] >= 0 && yAt[i] >= 0){
                    g.Redo(xAt[i], yAt[i], check[i]);
                    i++;
                }
                if (i >= 0 && xAt[i] >= 0 && yAt[i] >= 0){
                    g.Redo(xAt[i], yAt[i], check[i]);
                    i++;
                }
                break;
            case 13:
                int x = g.getXatEnter();
                int y = g.getYatEnter();
                xAt[i] = x;
                yAt[i] = y;
                if (g.getTurn() == 1){
                    check[i] = -1;
                }
                if (g.getTurn() == 0){
                    check[i] = 1;
                }
                i++;
                if (g.processCheckBoard()){
                    switch (g.processFinish(x, y)){
                    case -1:
                        a.score1++;
                        while (k)
                        {
                            if (_kbhit())
                            {
                                switch (_getch())
                                {
                                case 'y':
                                    load = 0;
                                    return PlayerVsCom(a,load,data);
                                    break;
                                case 27:
                                    system("cls");
                                    ScreenStartGame(n-1);
                                    break;
                                }
                            }
                        }
                        break;
                    case 1:
                        a.score2++;
                        while (k)
                        {
                            if (_kbhit())
                            {
                                switch (_getch())
                                {
                                case 'y':
                                    load = 0;
                                    return PlayerVsCom(a, load, data);
                                    break;
                                case 27:
                                    system("cls");
                                    ScreenStartGame(n-1);
                                    break;
                                }
                            }
                        }

                        break;
                    case 0:
                        a.score3++;
                        while (k)
                        {
                            if (_kbhit())
                            {
                                switch (_getch())
                                {
                                case 'y':
                                    load = 0;
                                    return PlayerVsCom(a, load, data);
                                    break;
                                case 27:
                                    system("cls");
                                    ScreenStartGame(n-1);
                                    break;
                                }
                            }
                        }
                        break;
                    }
                }
            }
        }

    }
}
int PlayerVsCom2(Diem &a, int load, char data[30])
{
    int n = 99;
    int k = 1;
    int *xAt = new int[SIZE*SIZE];
    int *yAt = new int[SIZE*SIZE];
    int *check = new int[SIZE*SIZE];
    for (int i = 0; i < SIZE*SIZE; i++)
    {
        xAt[i] = -1;
        yAt[i] = -1;
        check[i] = 0;
    }
    int i = 0;
    HienTroChuot();
    _Game g(SIZE, 0, 0);
    g.setCountXY();
    if (load == -4)
    {
        g.LoadGame(data);
    }
    else
    {
        g.startGame();
        g.setTurn();
    }
    PrintScoreBoard();
    Textcolor(Cyan);
    _Common::gotoXY(SIZE * 4 + 32, 22);
    cout << " PLAYER VS BOT (EASY) ";
    Textcolor(Blue);
    _Common::gotoXY(SIZE * 4 + 30 + 18, 5);
    cout << a.score1;
    _Common::gotoXY(SIZE * 4 + 30 + 18, 6);
    cout << a.score2;
    _Common::gotoXY(SIZE * 4 + 30 + 18, 7);
    cout << a.score3;
    //cout << g.getScore1();
    Textcolor(Red);
    _Common::gotoXY(SIZE * 4 + 30 + 18, 15);
    cout << a.score2;
    _Common::gotoXY(SIZE * 4 + 30 + 18, 16);
    cout << a.score1;
    _Common::gotoXY(SIZE * 4 + 30 + 18, 17);
    cout << a.score3;
    //cout << g.getScore1();
    _Common::gotoXY(2, 1);
    while (g.isContinue())
    {
        if (!g.getTurn())
        {
            if (g.DemNuocCoDaDi() == 0)
            {
                g.setX((SIZE * 4 / 2) - 2);
                g.setY((SIZE * 2 / 2) - 1);
                _Common::gotoXY((SIZE * 4 / 2) - 2, (SIZE * 2 / 2) - 1);
                g.setCommand(13);
            }
            else
            {
                g.TimKiemNuocDi1();
                //g.TimKiemNuocDiDe();
                int x = g.getXatEnter();
                int y = g.getYatEnter();
                _Common::gotoXY(x, y);
                Sleep(300);
                g.setCommand(13);
            }
        }
        else
            g.waitKeyBoard();
        if (g.getCommand() == 27){
            return 27;
        }
        else
        {
            switch (g.getCommand())
            {
            case 'A': case 75:
                g.moveLeft();
                break;
            case 'D' : case 77:
                g.moveRight();
                break;
            case 'W': case 72:
                g.moveUp();
                break;
            case 'S': case 80:
                g.moveDown();
                break;
            case 'L':
                g.SaveGame(-4, a.score1, a.score2, a.score3);
                break;
            case 'T':
                LoadLoad();
                break;
            case 'U':
                if (i > 0 && xAt[i-1] >= 0 && yAt[i-1] >= 0){
                    g.Undo(xAt[i-1], yAt[i-1]);
                    i--;
                }
                if (i > 0 && xAt[i-1] >= 0 && yAt[i-1] >= 0){
                    g.Undo(xAt[i-1], yAt[i-1]);
                    i--;
                }
                _Common::gotoXY(xAt[i-1], yAt[i-1]);
                break;
            case 'R':
                if (i >= 0 && xAt[i] >= 0 && yAt[i] >= 0){
                    g.Redo(xAt[i], yAt[i], check[i]);
                    i++;
                }
                if (i >= 0 && xAt[i] >= 0 && yAt[i] >= 0){
                    g.Redo(xAt[i], yAt[i], check[i]);
                    i++;
                }
                break;
            case 13:
                int x = g.getXatEnter();
                int y = g.getYatEnter();
                xAt[i] = x;
                yAt[i] = y;
                if (g.getTurn() == 1){
                    check[i] = -1;
                }
                if (g.getTurn() == 0){
                    check[i] = 1;
                }
                i++;
                if (g.processCheckBoard()){
                    switch (g.processFinish(x, y)){
                    case -1:
                        a.score1++;
                        while (k)
                        {
                            if (_kbhit())
                            {
                                switch (_getch())
                                {
                                case 'y':
                                    load = 0;
                                    return PlayerVsCom2(a,load,data);
                                    break;
                                case 27:
                                    system("cls");
                                    ScreenStartGame(n);
                                    break;
                                }
                            }
                        }

                        break;
                    case 1:
                        a.score2++;
                        while (k)
                        {
                            if (_kbhit())
                            {
                                switch (_getch())
                                {
                                case 'y':
                                    load = 0;
                                    return PlayerVsCom2(a,load,data);
                                    break;
                                case 27:
                                    system("cls");
                                    ScreenStartGame(n);
                                    break;
                                }
                            }
                        }

                        break;
                    case 0:
                        a.score3++;
                        while (k)
                        {
                            if (_kbhit())
                            {
                                switch (_getch())
                                {
                                case 'y':
                                    load = 0;
                                    return PlayerVsCom2(a,load,data);
                                    break;
                                case 27:
                                    system("cls");
                                    ScreenStartGame(n);
                                    break;
                                }
                            }
                        }
                        break;
                    }
                }
            }
        }

    }
}
int PlayerVsPlayer(Diem &a, int load, char data[30])
{
    int k = 1;
    int n = 99;
    cout << data;
    int *xAt = new int[SIZE*SIZE];
    int *yAt = new int[SIZE*SIZE];
    int *check = new int[SIZE*SIZE];
    for (int i = 0; i < SIZE*SIZE; i++)
    {
        xAt[i] = -1;
        yAt[i] = -1;
        check[i] = 0;
    }
    int i = 0;
    HienTroChuot();
    _Game g(SIZE, 0, 0);
    g.setCountXY();
    if (load == -30)
    {
        g.setTurn();
        g.LoadGame(data);
    }
    else if (load == -31)
    {
        g.LoadGame(data);
    }
    else {
        //g.setTurn();
        g.startGame();
    }
    PrintScoreBoard();
    Textcolor(Cyan);
    _Common::gotoXY(SIZE * 4 + 32, 22);
    cout << " PLAYER VS PLAYER ";
    Textcolor(Blue);
    _Common::gotoXY(SIZE * 4 + 30 + 18, 5);
    cout << a.score1;
    _Common::gotoXY(SIZE * 4 + 30 + 18, 6);
    cout << a.score2;
    _Common::gotoXY(SIZE * 4 + 30 + 18, 7);
    cout << a.score3;
    //cout << g.getScore1();
    Textcolor(Red);
    _Common::gotoXY(SIZE * 4 + 30 + 18, 15);
    cout << a.score2;
    _Common::gotoXY(SIZE * 4 + 30 + 18, 16);
    cout << a.score1;
    _Common::gotoXY(SIZE * 4 + 30 + 18, 17);
    cout << a.score3;
    //cout << g.getScore2();
    _Common::gotoXY(2, 1);
    while (g.isContinue())
    {
        g.waitKeyBoard();
        if (g.getCommand() == 27){
            return 27;
        }
        // if (!g.getTurn())
        // {
        //     if (g.DemNuocCoDaDi() == 0)
        //     {
        //         g.setX((SIZE * 4 / 2) - 2);
        //         g.setY((SIZE * 2 / 2) - 1);
        //         _Common::gotoXY((SIZE * 4 / 2) - 2, (SIZE * 2 / 2) - 1);
        //         g.setCommand(13);
        //     }
        //     else
        //     {
        //         g.TimKiemNuocDi1();
        //         //g.TimKiemNuocDiDe();
        //         int x = g.getXatEnter();
        //         int y = g.getYatEnter();
        //         _Common::gotoXY(x, y);
        //         Sleep(300);
        //         g.setCommand(13);
        //     }
        // }
        // else{
        //     g.TimKiemNuocDi2();
        //     //g.TimKiemNuocDiDe();
        //     int x = g.getXatEnter();
        //     int y = g.getYatEnter();
        //     _Common::gotoXY(x, y);
        //     Sleep(300);
        //     g.setCommand(13);
        // }
        // if (g.getCommand() == 27){
        //     return 27;
        // }
        else
        {
            switch (g.getCommand())
            {
            case 'A': case 75:
                g.moveLeft();
                break;
            case 'D': case 77:
                g.moveRight();
                break;
            case 'W': case 72:
                g.moveUp();
                break;
            case 'S': case 80:
                g.moveDown();
                break;
            case 'L':
                if (g.getTurn() == 1)
                    g.SaveGame(-31, a.score1, a.score2, a.score3);
                else
                    g.SaveGame(-30, a.score1, a.score2, a.score3);
                break;
            case 'T':
                LoadLoad();
                break;
            case 'U':
                if (i > 0 && xAt[i-1] >= 0 && yAt[i-1] >= 0){
                    g.Undo(xAt[i-1], yAt[i-1]);
                    i--;
                }
                _Common::gotoXY(xAt[i-1], yAt[i-1]);
                break;
            case 'R':
                if (i >= 0 && xAt[i] >= 0 && yAt[i] >= 0){
                    g.Redo(xAt[i], yAt[i], check[i]);
                    i++;
                }
                break;
            case 13:
                int x = g.getXatEnter();
                int y = g.getYatEnter();
                // _Common::gotoXY(x, y);
                // cout << x;
                xAt[i] = x;
                yAt[i] = y;
                if (g.getTurn() == 1){
                    check[i] = -1;
                }
                if (g.getTurn() == 0){
                    check[i] = 1;
                }
                i++;
                if (g.processCheckBoard()){
                    switch (g.processFinish(x, y)){
                    case -1:
                        a.score1++;
                        while (k)
                        {
                            if (_kbhit())
                            {
                                switch (_getch())
                                {
                                case 'y':
                                    load = 0;
                                    return PlayerVsPlayer(a,load,data);
                                    break;
                                case 27:
                                    system("cls");
                                    ScreenStartGame(n);
                                    break;
                                }
                            }
                        }
                        break;
                    case 1:
                        a.score2++;
                        while (k)
                        {
                            if (_kbhit())
                            {
                                switch (_getch())
                                {
                                case 'y':
                                    load = 0;
                                    return PlayerVsPlayer(a, load, data);
                                    break;
                                case 27:
                                    system("cls");
                                    ScreenStartGame(n);
                                    break;
                                }
                            }
                        }
                        break;
                    case 0:
                        a.score3++;
                        while (k)
                        {
                            if (_kbhit())
                            {
                                switch (_getch())
                                {
                                case 'y':
                                    load = 0;
                                    return PlayerVsPlayer(a, load, data);
                                    break;
                                case 27:
                                    system("cls");
                                    ScreenStartGame(n);
                                    break;
                                }
                            }
                        }
                        break;

                    }
                }
            }
        }
    }
}


