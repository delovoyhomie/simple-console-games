// minesweeper by delovoyhomie 
#include <iostream>
#include <ctime>
using namespace std;
int main()
{
    int mass[100][100], nmk[100];
    char field[100][100];
    int n, m, k;
    int row, col;
    int bomb_row, bomb_col;

    srand(time(NULL));//время в секундах с 1 января 1970 года

    cout << "Enter the playing field size and number of bombs (row, col, numb): ";
    cin >> n >> m >> k; // n - кол-во строк, m - кол-во столбцов, k - кол-во бомб
    for (int i = 0; i < n; i++) {// заполняю массив нулями
        for (int j = 0; j < m; j++) {
            mass[i][j] = 0;
        }
    }
    for (int i = 0; i < k; i++) {// рандомно спавнятся бомбы
        bomb_row = rand() % n;
        bomb_col = rand() % m;
        while(bomb_row == bomb_col){// проверка на одинаковые значения рандома        
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
