#include "_Game.h"
#include <vector>
_Game::_Game(int pSize, int pLeft, int  pTop)
{
    _b = new _Board(pSize, pLeft, pTop);
    _loop = _turn = true;
    _command = -1;
    _x = pLeft;
    _y = pTop;
}
int _Game::getCommand(){ return _command; }
bool _Game::isContinue(){ return _loop; }
char _Game::waitKeyBoard()
{
    _command = toupper(_getch());
    return _command;
}
char _Game::askContinue()
{
    _Common::gotoXY(0, _b->getYAt(_b->getSize() - 1, _b->getSize() - 1) + 4);
    return waitKeyBoard();
}
void _Game::startGame()
{
    system("cls");
    _b->resetData();
    _b->drawBoard();
    _x = _b->getXAt(0, 0);
    _y = _b->getYAt(0, 0);
    if (_turn == 1)
    {
        Textcolor(Blue);
        _Common::gotoXY(SIZE * 4 + 32, 24);
        cout << " Den luot PLAYER 1 ";
    }
    else
    {
        Textcolor(Red);
        _Common::gotoXY(SIZE * 4 + 32, 24);
        cout << " Den luot PLAYER 2 ";
    }
    Textcolor(Blue);
    _Common::gotoXY(SIZE * 4 + 30 + 11, 4);
    cout << _b->CountX;
    Textcolor(Red);
    _Common::gotoXY(SIZE * 4 + 30 + 11, 14);
    cout << _b->CountO;
}
void _Game::exitGame()
{
    _loop = false;
}

void _Game::Undo(int pX, int pY) {
    Textcolor(defaultColor);
    _Common::gotoXY(pX, pY);
    switch(_b->Undo(pX, pY)){
    case -1:
        cout << " ";
        _b->CountX--;
        _turn = !_turn;
        break;
    case 1:
        cout << " ";
        _b->CountO--;
        _turn = !_turn;
        break;
    case 0:
        cout << " ";
        break;
    }
}

void _Game::Redo(int pX, int pY, int check) {
    _Common::gotoXY(pX, pY);
    _b->Redo(pX, pY, check);
    switch(check){
    case -1:
        Textcolor(Blue);
        cout << "X";
        _b->CountX++;
        _turn = !_turn;
        break;
    case 1:
        Textcolor(Red);
        cout << "O";
        _b->CountO++;
        _turn = !_turn;
        break;
    case 0:
        cout << " ";
        break;
    }
}

void _Game::moveRight()
{
    if (_x<_b->getXAt(_b->getSize() - 1, _b->getSize() - 1))
    {
        _x += 4;
        _Common::gotoXY(_x, _y);
    }
}

void _Game::moveLeft(){
    if (_x>_b->getXAt(0,0))
    {
        _x -= 4;
        _Common::gotoXY(_x, _y);
    }
}
void P1WIN()
{
    AnTroChuot();
    int check = 1;
    Textcolor(Cyan);
    _Common::gotoXY(50, 26);
    cout << "Y   : Play Again";
    _Common::gotoXY(50, 27);
    cout << "ESC : BACK";
    while (check<30)
    {
        P1();
        Sleep(200);
        check++;
    }
}
void P2WIN()
{
    AnTroChuot();
    int check = 1;
    Textcolor(Cyan);
    _Common::gotoXY(50, 26);
    cout << "Y   : Play Again";
    _Common::gotoXY(50, 27);
    cout << "ESC : BACK";
    while (check<30)
    {
        P2();
        Sleep(200);
        check++;
    }
}
void PDraw()
{
    AnTroChuot();
    int check = 1;
    Textcolor(Cyan);
    _Common::gotoXY(50, 26);
    cout << "Y   : Play Again";
    _Common::gotoXY(50, 27);
    cout << "ESC : BACK";
    while (check<30)
    {
        Draw();
        Sleep(200);
        check++;
    }
}
void _Game::moveDown() {
    if (_y<_b->getYAt(_b->getSize() - 1, _b->getSize() - 1))
    {
        _y += 2;
        _Common::gotoXY(_x, _y);
    }
}
void _Game::moveUp() {
    if (_y>_b->getYAt(0,0))
    {
        _y -= 2;
        _Common::gotoXY(_x, _y);
    }
}
bool _Game::processCheckBoard()
{
    switch (_b->checkBoard(_x, _y, _turn))
    {
    case -1:
        Textcolor(Blue);
        cout << "X";
        _Common::gotoXY(SIZE * 4 + 30+12, 4);
        cout << _b->CountX;
        Textcolor(Red);
        _Common::gotoXY(SIZE * 4 + 30+12, 14);
        cout << _b->CountO;
        _Common::gotoXY(SIZE * 4 + 32, 24);
        cout << " Den luot PLAYER 2 ";

        _Common::gotoXY(_x, _y);
        break;
    case 1:
        Textcolor(Red);
        cout << "O";
        Textcolor(Blue);
        _Common::gotoXY(SIZE * 4 + 30 + 12, 4);
        cout << _b->CountX;
        _Common::gotoXY(SIZE * 4 + 32, 24);
        cout << " Den luot PLAYER 1 ";
        Textcolor(Red);
        _Common::gotoXY(SIZE * 4 + 30 + 12, 14);
        cout << _b->CountO;

        break;
    case 0:
        return false;
        break;
    }
    return true;
}
int _Game::DemNuocCoDaDi()
{
    return _b->CountX + _b->CountO;
}
void P1()
{
    int i = 50, j = 10;
    Textcolor(rand() % 15 + 1);
    _Common::gotoXY(i, j + 2); cout << "P1 chien thang";
}
void P2()
{
    int i = 50, j = 10;
    Textcolor(rand() % 15 + 1);
    _Common::gotoXY(i, j + 2); cout << "P2 chien thang";
}
void Draw()
{
    int i = 50, j = 10;
    Textcolor(rand() % 15 + 1);
    _Common::gotoXY(i, j + 2); cout << "Draw";
}

int _Game::processFinish(int x,int y)
{
    _Common::gotoXY(0, _b->getYAt(_b->getSize() - 1, _b->getSize() - 1) + 2);
    int pWhoWin = _b->checkWin(x,y);
    switch (pWhoWin)
    {
    case -1:
        _b->printWin();
        system("cls");
        P1WIN();
        break;
    case 1:
        _b->printWin();
        system("cls");
        P2WIN();
        break;
    case 0:
        system("cls");
        PDraw();
        break;
    case 2:
        _turn = !_turn;
    }
    _Common::gotoXY(_x, _y);// Trả về vị trí hiện hành của con trỏ màn hình bàn cờ
    return pWhoWin;
}
int _Game::getXatEnter()
{
    return _x;
}
int _Game::getYatEnter()
{
    return _y;
}
void _Game::TimKiemNuocDi2()//tb
{
    _x = _b->Tim_Kiem_NuocDi_2().getX();
    _y = _b->Tim_Kiem_NuocDi_2().getY();
}
void _Game::TimKiemNuocDi1()//de
{
    _x = _b->Tim_Kiem_NuocDi_1().getX();
    _y = _b->Tim_Kiem_NuocDi_1().getY();
}

// void _Game::TimKiemNuocDiDe(){
//     _x = _b->easyBot().getX();
//     _y = _b->easyBot().getY();
// }

void _Game::TimKiemNuocDi3() {
    _x = _b->findBestMove().getX();
    _y = _b->findBestMove().getY();
}
_Game::~_Game()
{
    delete _b;
}

void _Game::SaveGame(int n, int scoreP1, int scoreP2, int scoreP3)
{
    vector<string> lines;
    int a, b, c;
    char data[30];
    _Common::gotoXY(35, SIZE*2+1);
    cout << "ENTER FILE NAME: ";
    Textcolor(Cyan);
    cin.getline(data, 30);
    ofstream f1;
    ofstream f2;
    f1.open(data, ios::out);
    f2.open("Name.txt", ios::app);
    f2 << data << " " << scoreP1 << " " << scoreP2 << " " << scoreP3<< endl;
    //thong tin
    f1 << scoreP1 << " " << scoreP2 << " " << scoreP3 << " " << n << endl;
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            f1 << _b->get_Check(i, j) << " ";
        }
        f1 << endl;
    }
    f1.close();
    f2.close();
    _Common::gotoXY(35, SIZE * 2 + 2);
    cout << "ESC : BACK";
    int t = 1;
    while (t)
    {
        if (_kbhit())
        {
            switch (_getch())
            {
            case 27:
                t = 0;
                system("cls");
                ScreenStartGame(99);
                break;
            }
        }
    }
}
void _Game::LoadGame(char data[30])
{

    //NHAP FILE
    ifstream f;
    f.open(data, ios::in);
    if (!f){
        _Common::gotoXY(35, 46);
        cout << "\n FILE KHONG TON TAI!" << endl;
    }
    else
    {
        f >> scorep1 >> scorep2 >> scorep3 >> chedo;
        system("cls");
        //thong tin
        //ban co
        int k;
        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j < SIZE; j++)
            {
                f >> k;
                _b->loadData(i, j, k);
            }
        }
        _x = _b->getXAt(0, 0);
        _y = _b->getYAt(0, 0);
        _b->drawBoard();
        f.close();
    }
    Textcolor(Blue);
    _Common::gotoXY(SIZE * 4 + 30 + 12, 4);
    cout << _b->CountX;
    Textcolor(Red);
    _Common::gotoXY(SIZE * 4 + 30 + 12, 14);
    cout << _b->CountO;
    if (_turn == 1)
    {
        Textcolor(Blue);
        _Common::gotoXY(SIZE * 4 + 32, 24);
        cout << " Den luot PLAYER 1 ";
    }
    else
    {
        Textcolor(Red);
        _Common::gotoXY(SIZE * 4 + 32, 24);
        cout << " Den luot PLAYER 2 ";
    }

}
