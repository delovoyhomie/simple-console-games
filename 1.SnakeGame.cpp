#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include <random>
#include <windows.h>
#include <stdio.h>
#include <conio.h>
#include <cstdlib>
#include <cmath>
#include <queue>
#include <map>
#include <algorithm>
#include <set>
#define fastIO() {ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);}
#define all(x) x.begin(), x.end()
#define el '\n'
typedef long long ll;
using namespace std;

/*
 HEADER END
*/

struct snake {
    int x, y;
};
int main() {
    fastIO();
    srand(time(0));
    setlocale(LC_ALL, "RUSSIAN");
    system("color A");
    char pole[20][20];
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 20; j++) {
            pole[i][j] = ' ';
        }
    }
    ofstream fout; ifstream fin;
    snake apple;
    bool flag = false, flag2 = false, lose = false, tc = false, dc = false, sc = true, pac = false, flag3 = true;
    vector<snake> zm;
    snake temp;
    vector<snake> poisoned_apple(5);
    temp.x = 8;
    temp.y = 9;
    zm.push_back(temp);
    temp.x = 9;
    temp.y = 9;
    zm.push_back(temp);
    char e = 'w', sym = '^';
    int slp, sw, score = 0, best_score = NULL;
    fin.open("Best_score.txt");
    fin >> best_score;
    fin.close();
    if (best_score == NULL) best_score = 0;
    while (dc == false)
    {
        system("CLS");
        cout << "1. Продолжить" << endl << "2. Сбросить лучший результат" << endl << "3. Настройки звукового сигнала" << endl;
        sw = _getch();
        switch (sw)
        {
        case 49:
            system("CLS");
            cout << "Выберите уровень сложности:" << endl << "1. Легкий" << endl << "2. Средний" << endl << "3. Сложный" << endl << "4. Очень сложный" << endl;
            sw = _getch();
            while (dc == false) {
                system("CLS");
                cout << "Выберите уровень сложности:" << endl << "1. Легкий" << endl << "2. Средний" << endl << "3. Сложный" << endl << "4. Очень сложный" << endl;;
                switch (sw) {
                case 49:
                    slp = 300;
                    dc = !dc;
                    break;

                case 50:
                    slp = 200;
                    dc = !dc;
                    break;

                case 51:
                    slp = 50;
                    dc = !dc;
                    break;
                case 52:
                    slp = 50;
                    dc = !dc;
                    pac = true;
                    break;
                default:
                    cout << "\033[31mВыберите сложность игры!!!\033[38;2;0;205;0m";
                    sw = _getch();
                    break;
                }
            }
            break;
        case 50:
            while (dc == false) {
                system("CLS");
                cout << "Вы уверены?" << endl << "1. Да" << endl << "2. Нет" << endl;
                sw = _getch();
                switch (sw) {
                case 49:
                    best_score = 0;
                    dc = !dc;
                    break;
                case 50:
                    dc = !dc;
                    break;
                default:
                    break;
                }
            }
            dc = !dc;
            break;

        case 51:
            while (dc == false) {
                system("CLS");
                if (sc == true) cout << "Звуковой сигнал включен \n";
                else cout << "Звуковой сигнал выключен \n";
                cout << "1. Включить(По умолчанию)" << endl << "2. Выключить" << endl << "3. Назад" << endl;
                sw = _getch();
                switch (sw) {
                case 49:
                    sc = true;
                    break;
                case 50:
                    sc = false;
                    break;
                case 51:
                    dc = !dc;
                    break;
                default:
                    break;
                }
            }
            dc = !dc;
            break;
        default:
            break;
        }
    }
    system("CLS");
    cout << "Инструкция: \n 1.1 Цель игры - набрать как можно больше очков! \n Получить их вы можете съедая яблоки (\033[31m@\033[38;2;0;205;0m). \n При столкновении со своим хвостом вы проигрываете! \n \n 1.2 На очень сложном уровне сложности появляются гнилые/отравленные яблоки(@). \n При съедании такого вы сразу проигрываете! \n \n 2. Управление осуществляется клавишами WASD. \n \n 3. Чтобы поставить игру на паузу нажмите P";
    _getch();
    while (true) {
        system("CLS");
        if (flag == false) {
            while (flag2 == false) {
                flag2 = true;

                apple.x = rand() % 20;
                apple.y = rand() % 20;
                for (int i = 0; i < zm.size(); i++) {
                    if (apple.x == zm[i].x && apple.y == zm[i].y) {
                        flag2 = false;
                    }
                }
            }
            flag = true;
            flag2 = false;
        }
        if (flag3 && pac) {
            for (int i = 0; i < 5; i++) {
                while (!flag2) {
                    flag2 = true;
                    poisoned_apple[i].x = rand() % 20;
                    poisoned_apple[i].y = rand() % 20;
                    for (int j = 0; j < zm.size(); j++) {
                        if ((poisoned_apple[i].x == apple.x && poisoned_apple[i].y == apple.y)) {
                            flag2 = false;
                        }
                        if (((poisoned_apple[i].x - zm[0].x < 3 && poisoned_apple[i].x - zm[0].x > -3) && (poisoned_apple[i].y - zm[0].y < 3 && poisoned_apple[i].y - zm[0].y > -3))) {
                            flag2 = false;
                        }
                        if ((poisoned_apple[i].x == zm[j].x && poisoned_apple[i].y == zm[j].y)) {
                            flag2 = false;
                        }
                    }
                }
                flag2 = false;
            }
            flag3 = false;
        }
        pole[apple.x][apple.y] = '@';
        if (pac) {
            for (int i = 0; i < 5; i++) {
                pole[poisoned_apple[i].x][poisoned_apple[i].y] = '@';
            }
        }
        for (int i = 0; i < zm.size(); i++) {
            pole[zm[i].x][zm[i].y] = '*';
        }
        pole[zm[0].x][zm[0].y] = sym;
        cout << "______________________" << endl;
        for (int i = 0; i < 20; i++) {
            cout << "|";
            for (int j = 0; j < 20; j++) {
                if (i == apple.x && j == apple.y) {
                    cout << "\033[31m" << pole[i][j] << "\033[38;2;0;205;0m";
                }
                else cout << pole[i][j];
            }
            cout << "|";
            if (i == 0) {
                cout << "\t \t Лучший результат: " << best_score;
            }
            if (i == 2) {
                cout << "\t \t Текущий счёт: " << score;
            }
            cout << endl;
        }
        cout << "______________________" << endl;
        switch (e) {
        case 's':
            Sleep(slp);
            if (_kbhit() && tc == false) {
                e = _getch();
                if (e == 'p' || e == 'P' || e == -89 || e == -121) system("PAUSE");
                if (e == -28 || e == -108 || e == 'A') e = 'a';
                if (e == -94 || e == -126 || e == 'D') e = 'd';
                tc = true;
                if (e != 'a' && e != 'd') e = 's';
                else break;
            }
            for (int i = zm.size() - 1; i > 0; i--) {
                zm[i] = zm[i - 1];
            }
            zm[0].x++;
            if (zm[0].x > 19)zm[0].x = 0;
            for (int i = 1; i < zm.size(); i++) {
                if (zm[0].x == zm[i].x && zm[0].y == zm[i].y) {
                    lose = true;
                    break;
                }
            }
            if (pac) {
                for (int i = 0; i < 5; i++) {
                    if (zm[0].x == poisoned_apple[i].x && zm[0].y == poisoned_apple[i].y) {
                        lose = true;
                        break;
                    }
                }
            }
            if (apple.x == zm[0].x && apple.y == zm[0].y) {
                if (sc) cout << "\a";
                score++;
                zm.push_back(zm[zm.size() - 1]);
                flag3 = true;
                flag = false;

            }
            sym = 'v';
            tc = false;
            break;

        case 'w':
            Sleep(slp);
            if (_kbhit() && tc == false) {
                e = _getch();
                if (e == 'p' || e == 'P' || e == -89 || e == -121) system("PAUSE");
                if (e == -28 || e == -108 || e == 'A') e = 'a';
                if (e == -94 || e == -126 || e == 'D') e = 'd';
                tc = true;
                if (e != 'a' && e != 'd') e = 'w';
                else break;
            }
            for (int i = zm.size() - 1; i > 0; i--) {
                zm[i] = zm[i - 1];
            }
            zm[0].x--;
            if (zm[0].x < 0)zm[0].x = 19;
            for (int i = 1; i < zm.size(); i++) {
                if (zm[0].x == zm[i].x && zm[0].y == zm[i].y) {
                    lose = true;
                    break;
                }
            }
            if (pac) {
                for (int i = 0; i < 5; i++) {
                    if (zm[0].x == poisoned_apple[i].x && zm[0].y == poisoned_apple[i].y) {
                        lose = true;
                        break;
                    }
                }
            }
            if (apple.x == zm[0].x && apple.y == zm[0].y) {
                score++;
                if (sc) cout << "\a";
                zm.push_back(zm[zm.size() - 1]);
                flag = false;
                flag3 = true;
            }
            sym = '^';
            tc = false;
            break;
        case 'd':
            Sleep(slp);
            if (_kbhit() && tc == false) {
                e = _getch();
                if (e == 'p' || e == 'P' || e == -89 || e == -121) system("PAUSE");
                if (e == -26 || e == -106 || e == 'W') e = 'w';
                if (e == -21 || e == -101 || e == 'S') e = 's';
                tc = true;
                if (e != 'w' && e != 's') e = 'd';
                else break;
            }
            for (int i = zm.size() - 1; i > 0; i--) {
                zm[i] = zm[i - 1];
            }
            zm[0].y++;
            if (zm[0].y > 19)zm[0].y = 0;
            for (int i = 1; i < zm.size(); i++) {
                if (zm[0].x == zm[i].x && zm[0].y == zm[i].y) {
                    lose = true;
                    break;
                }
            }
            if (pac) {
                for (int i = 0; i < 5; i++) {
                    if (zm[0].x == poisoned_apple[i].x && zm[0].y == poisoned_apple[i].y) {
                        lose = true;
                        break;
                    }
                }
            }
            if (apple.x == zm[0].x && apple.y == zm[0].y) {
                score++;
                if (sc) cout << "\a";
                zm.push_back(zm[zm.size() - 1]);
                flag = false;
                flag3 = true;
            }
            sym = '>';
            tc = false;
            break;
        case 'a':
            Sleep(slp);
            if (_kbhit() && tc == false) {
                e = _getch();
                if (e == 'p' || e == 'P' || e == -89 || e == -121) system("PAUSE");
                if (e == -26 || e == -106 || e == 'W') e = 'w';
                if (e == -21 || e == -101 || e == 'S') e = 's';
                tc = true;
                if (e != 'w' && e != 's') e = 'a';
                else break;
            }
            for (int i = zm.size() - 1; i > 0; i--) {
                zm[i] = zm[i - 1];
            }

            zm[0].y--;
            if (pole[zm[0].x][zm[0].y] == '*') {
                lose = true;
                break;
            }
            if (zm[0].y < 0)zm[0].y = 19;
            for (int i = 1; i < zm.size(); i++) {
                if (zm[0].x == zm[i].x && zm[0].y == zm[i].y) {
                    lose = true;
                    break;
                }
            }
            if (pac) {
                for (int i = 0; i < 5; i++) {
                    if (zm[0].x == poisoned_apple[i].x && zm[0].y == poisoned_apple[i].y) {
                        lose = true;
                        break;
                    }
                }
            }
            if (apple.x == zm[0].x && apple.y == zm[0].y) {
                score++;
                zm.push_back(zm[zm.size() - 1]);
                if (sc) cout << "\a";
                flag = false;
                flag3 = true;
            }
            sym = '<';
            tc = false;
            break;
        }

        if (lose == true) {
            fout.open("Best_score.txt");
            if (score > best_score) best_score = score;
            fout << best_score;
            fout.close();
            system("CLS");
            cout << "Game Over" << endl;
            system("PAUSE");
            break;
        }
        for (int i = 0; i < 20; i++) {
            for (int j = 0; j < 20; j++) {
                pole[i][j] = ' ';
            }
        }
    }
    return 0;
}
