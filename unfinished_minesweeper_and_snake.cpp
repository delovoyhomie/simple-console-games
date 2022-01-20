// готовый проект по c++
#include <iostream>
#include <windows.h>
#include <conio.h>
#include <ctime>
using namespace std;
void minesweeper()
{
    int mass[100][100];
    char field[100][100];
    int n, m, k;
    int row, col;
    int bomb_row, bomb_col;

    srand(time(NULL));//время в секундах с 1 января 1970 года

    cout << "Enter the playing field size and number of bombs (row, col, numb): ";
    cin >> n >> m >> k;
    system("CLS");
    for (int i = 0; i < n; i++) {// заполняю массив нулями
        for (int j = 0; j < m; j++) {
            mass[i][j] = 0;
        }
    }
    for (int i = 0; i < k; i++) {// рандомно спавнятся бомбы
        bomb_row = rand() % n;
        bomb_col = rand() % m;
        if (bomb_row == bomb_col) {// проверка на одинаковые значения рандома
            bomb_col = rand() % m;
        }
        for (int i = 0; i < k; i++) {
            mass[bomb_row][bomb_col] = -9;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {// метки кол-во бомб
            if (mass[i][j] < 0) {// 1 1       
                mass[i - 1][j - 1]++;// 0 0
                mass[i - 1][j]++;    // 0 1
                mass[i - 1][j + 1]++;// 0 2
                mass[i][j - 1]++;    // 1 0
                mass[i][j + 1]++;    // 1 2
                mass[i + 1][j - 1]++;// 2 0
                mass[i + 1][j]++;    // 2 1
                mass[i + 1][j + 1]++;// 2 2                               
            }
        }
    }

    while (true) {
        for (int i = 0; i < n; i++) {// вывод поля
            for (int j = 0; j < m; j++) {
                if (mass[i][j] < 0) {//бомба
                    if (field[i][j] == 70) {//флаг
                        cout << "F" << " ";
                    }
                    else {
                        cout << "." << " ";
                    }
                }
                else if (mass[i][j] == 0) {
                    cout << "." << " "; //пустые клетки
                }
                else {
                    cout << mass[i][j] << " "; // пробелы между значениями
                }
            }
            cout << endl;
        }

        cout << "Enter coordinate: "; // обрабатыватель исхода событий
        cin >> row >> col; //флаг
        field[row][col] = 70;
        if (mass[row][col] < 0) {
            k--;
        }
        else {
            cout << "GAME OVER!" << endl;
            break;
        }
        if (k == 0) {
            cout << "Congratulations, you was won!" << endl;
            break;
        }
        system("cls");
    }
    cout << "you spent on solving this puzzle: " << clock() / 3600000 << " hours" << " " << clock() % 3600000 / 60000 << " minutes" << " " << clock() % 60000 / 1000 << " seconds"; // время в милисекундах, затраченных на выполнение программы
}
void snake()
{
    // змейка 
    int mass[100][100];
    int n, m, snake_row, snake_col, pin_row, pin_col, score = 0;
    bool game = true;



    srand(time(NULL));//время в секундах с 1 января 1970 года

    cout << "Enter the playing field size (row, col): ";
    cin >> n >> m; // n - кол-во строк, m - кол-во столбцов, k - кол-во бомб
    for (int i = 0; i < n; i++) {// заполняю массив нулями
        for (int j = 0; j < m; j++) {
            mass[i][j] = 0;
        }
    }

    for (int i = 0; i < n; i++) {// 1 - граница поля    
        mass[i][0] = 1;
        mass[i][m - 1] = 1;
        for (int j = 0; j < m; j++) {
            mass[0][j] = 1;
            mass[n - 1][j] = 1;
        }
    }
    snake_row = rand() % n;//начальная координата строки змейки
    snake_col = rand() % m;//начальная координата столбца змейки
    pin_row = rand() % n;//начальная координата строки pin                       //    СДЕЛАТЬ НОРМАЛЬНЫЙ СПАВН ЕДЫ (PIN) ПРОБЛЕМА В УСЛОВИЯХ
    pin_col = rand() % m;//начальная координата столбца pin
    while (true) {//проверка на координату в границе поля(#)
        if (mass[snake_row][snake_col] == 1) {// 1 - граница
            snake_row = rand() % n;
            snake_col = rand() % m;
        }
        else {
            mass[snake_row][snake_col] = 2;// 2 - змея
            break;
        }
    }


    while (game) {
        while (true) {//проверка на координату в границе поля(#)
            if (mass[pin_row][pin_col] == 1 || mass[pin_row][pin_col] == mass[snake_row][snake_col]) {
                pin_row = rand() % n;
                pin_col = rand() % m;
            }
            else {
                mass[pin_row][pin_col] = 3;// 3 - pin(еда)
                break;
            }
        }
        for (int i = 0; i < n; i++) {//вывод поля
            for (int j = 0; j < m; j++) {
                if (mass[i][j] == 2) {
                    cout << ">";
                }
                if (mass[i][j] == 1) {
                    cout << "#";
                }
                if (mass[i][j] == 0) {
                    cout << ".";
                }
                if (mass[i][j] == 3) {
                    cout << "*";
                }
            }
            cout << endl;
        }
        cout << "score: " << score << endl;
        cout << "you played: " << clock() / 3600000 << " hours" << " " << clock() % 3600000 / 60000 << " minutes" << " " << clock() % 60000 / 1000 << " seconds"; // время в милисекундах, затраченных на выполнение программы
        Sleep(100);
        if (_kbhit()) {
            switch (_getch())
            {
            case'w':
                if (mass[snake_row - 1][snake_col] == 1) {
                    game = false;
                }
                if (mass[snake_row - 1][snake_col] == 3) {
                    score++;
                }
                mass[snake_row - 1][snake_col] = mass[snake_row][snake_col];
                mass[snake_row][snake_col] = 0;
                snake_row--;
                break;
            case'a':
                if (mass[snake_row][snake_col - 1] == 1) {
                    game = false;
                }
                if (mass[snake_row][snake_col - 1] == 3) {
                    score++;
                }
                mass[snake_row][snake_col - 1] = mass[snake_row][snake_col];
                mass[snake_row][snake_col] = 0;
                snake_col--;
                break;
            case's':
                if (mass[snake_row + 1][snake_col] == 1) {
                    game = false;
                }
                if (mass[snake_row + 1][snake_col] == 3) {
                    score++;
                }
                mass[snake_row + 1][snake_col] = mass[snake_row][snake_col];
                mass[snake_row][snake_col] = 0;
                snake_row++;
                break;
            case'd':
                if (mass[snake_row][snake_col + 1] == 1) {
                    game = false;
                }
                if (mass[snake_row][snake_col + 1] == 3) {
                    score++;
                }
                mass[snake_row][snake_col + 1] = mass[snake_row][snake_col];
                mass[snake_row][snake_col] = 0;
                snake_col++;
                break;
            }
        }
        system("CLS");
    }
    cout << "Game Over" << endl;
    cout << "you played: " << clock() / 3600000 << " hours" << " " << clock() % 3600000 / 60000 << " minutes" << " " << clock() % 60000 / 1000 << " seconds"; // время в милисекундах, затраченных на выполнение программы

}
int main()
{
    int select_game;
    cout << "select game:" << endl;
    cout << "1. minesweeper" << endl << "2. snake" << endl;
    cin >> select_game;
    if (select_game == 1) {
        system("CLS");
        minesweeper();        
    }
    else {
        system("CLS");
        snake();       
    }    
}


