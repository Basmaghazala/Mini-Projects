#include <iostream>
using namespace std;

const int MAX_SIZE = 100;
char arr[MAX_SIZE][MAX_SIZE];


void initBoard(int n) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            arr[i][j] = '.';
}


void printBoard(int n) {
    for (int r = 0; r < n; r++) {
        for (int c = 0; c < n; c++) {
            cout << arr[r][c] << " ";
        }
        cout << "\n";
    }
}


bool checkRowsCols(int n) {
    for (int r = 0; r < n; r++) {
        int rowCount = 1, colCount = 1;
        for (int c = 0; c < n - 1; c++) {
            
            if (arr[r][c] != '.' && arr[r][c] == arr[r][c + 1])
                rowCount++;
            else
                rowCount = 1;

            
            if (arr[c][r] != '.' && arr[c][r] == arr[c + 1][r])
                colCount++;
            else
                colCount = 1;

            if (rowCount == n) {
                cout << "player " << arr[r][c] << " is winner\n";
                return true;
            }
            if (colCount == n) {
                cout << "player " << arr[c][r] << " is winner\n";
                return true;
            }
        }
    }
    return false;
}

bool checkMainDiagonal(int n) {
    int mainDiagCount = 1;
    for (int d = 0; d < n - 1; d++) {
        if (arr[d][d] != '.' && arr[d][d] == arr[d + 1][d + 1])
            mainDiagCount++;
        else
            mainDiagCount = 1;

        if (mainDiagCount == n) {
            cout << "player " << arr[d][d] << " is winner\n";
            return true;
        }
    }
    return false;
}

bool checkAntiDiagonal(int n) {
    int antiDiagCount = 1;
    for (int d = 0; d < n - 1; d++) {
        if (arr[d][n - 1 - d] != '.' && arr[d][n - 1 - d] == arr[d + 1][n - 2 - d])
            antiDiagCount++;
        else
            antiDiagCount = 1;

        if (antiDiagCount == n) {
            cout << "player " << arr[d][n - 1 - d] << " is winner\n";
            return true;
        }
    }
    return false;
}

bool checkWinner(int n) {
    return checkRowsCols(n) || checkMainDiagonal(n) || checkAntiDiagonal(n);
}

int main() {
    int n, m = 0;
    cin >> n;
    initBoard(n);

    while (m < n * n) {
        int i, j;
        cin >> i >> j;
        i--; j--; 

        if (i >= n || j >= n || arr[i][j] != '.') {
            cout << "invalid input, enter another number again.\n";
            continue;
        }

        if (m % 2 == 1) {
            cout << "player o turn enter empty location\n";
            arr[i][j] = 'o';
        }
        else {
            cout << "player x turn enter empty location\n";
            arr[i][j] = 'x';
        }

        printBoard(n);

        if (checkWinner(n))
            return 0;

        m++;
    }
    cout << "tie, no one won.\n";
    return 0;
}


