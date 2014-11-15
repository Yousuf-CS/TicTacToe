#include<stdio.h>
#include<windows.h>

int game_board(char board[4][4]);
int winner(char board[4][4]);
int start(void);


int main(void) {
	system("color f3");
	start();
	int row, col, win = 0;
	char p1[10], p2[10];
	printf("\nEnter player 1's name : ");scanf("%s", &p1);
	printf("\nEnter player 2's name : ");scanf("%s", &p2);
	Sleep(300);
	system("cls");
	char board1[4][4] = {{'_','_','_','_'},{'_','_','_','_'},{'_','_','_','_'},{'_','_','_','_'}};
	game_board(board1);
	while (win == 0) {
		system("color f3");
		printf("\n%s's turn ...\n\n", p1);
		printf("\nChoose a row : ");scanf("%d", &row);
		row--;
		printf("\nChoose a col : ");scanf("%d", &col);
		col--;
		board1[row][col] = 'X';
		printf("\n");
		game_board(board1);
        win = winner(board1);
		if (win == 1) {
			break;
		}

        // tie condition
        if (win == 3) {
            break;
        }

		system("color f0");
		printf("\n%s's turn : \n\n", p2);
		printf("\nChoose a row : ");scanf("%d", &row);
		row--;
		printf("\nChoose a col : ");scanf("%d", &col);
		col--;
		board1[row][col] = '0';
		printf("\n");
		game_board(board1);
        win = winner(board1);
	}

	if (win == 1) {
		printf("\n%s wins!!\n", p1);
	} // p1 win condition
	if (win == 2) {
		printf("\n%s wins!!!\n", p2);
	} //p2 win condition
    if (win == 3) {
        printf("\nIt's a TIE!!!!\n\n");
    } //p3 win condition

    getchar();
	getchar();
	return 0;
}

int game_board(char a[4][4]) {
	int i, j;
	for (i = 0; i<4; i++) {
		for (j = 0; j<4; j++) {
			printf("%c  ", a[i][j]);
		}
		printf("\n");
	}
	return 0;
}

int winner(char board[4][4]) {
	int win = 0;
	if ((board[0][0] == 'X' && board[0][1] == 'X' && board[0][2] == 'X' && board[0][3] == 'X') || // first row
		(board[1][0] == 'X' && board[1][1] == 'X' && board[1][2] == 'X' && board[1][3] == 'X') || // second row
		(board[2][0] == 'X' && board[2][1] == 'X' && board[2][2] == 'X' && board[2][3] == 'X') || // third row
		(board[3][0] == 'X' && board[3][1] == 'X' && board[3][2] == 'X' && board[3][3] == 'X') || // fourth row
		(board[0][0] == 'X' && board[1][0] == 'X' && board[2][0] == 'X' && board[3][0] == 'X') || // first col
		(board[0][1] == 'X' && board[1][1] == 'X' && board[2][1] == 'X' && board[3][1] == 'X') || // second col
		(board[0][2] == 'X' && board[1][2] == 'X' && board[2][2] == 'X' && board[3][2] == 'X') || // third col
		(board[0][3] == 'X' && board[1][3] == 'X' && board[2][3] == 'X' && board[3][3] == 'X') || // fourth col
		(board[0][0] == 'X' && board[1][1] == 'X' && board[2][2] == 'X' && board[3][3] == 'X') || // first diagonal
		(board[0][3] == 'X' && board[1][2] == 'X' && board[2][1] == 'X' && board[3][0] == 'X'))   // second diagonal
		{
			win = 1;
		}
	else if ((board[0][0] == '0' && board[0][1] == '0' && board[0][2] == '0' && board[0][3] == '0') || // first row
		(board[1][0] == '0' && board[1][1] == '0' && board[1][2] == '0' && board[1][3] == '0') || // second row
		(board[2][0] == '0' && board[2][1] == '0' && board[2][2] == '0' && board[2][3] == '0') || // third row
		(board[3][0] == '0' && board[3][1] == '0' && board[3][2] == '0' && board[3][3] == '0') || // fourth row
		(board[0][0] == '0' && board[1][0] == '0' && board[2][0] == '0' && board[3][0] == '0') || // first col
		(board[0][1] == '0' && board[1][1] == '0' && board[2][1] == '0' && board[3][1] == '0') || // second col
		(board[0][2] == '0' && board[1][2] == '0' && board[2][2] == '0' && board[3][2] == '0') || // third col
		(board[0][3] == '0' && board[1][3] == '0' && board[2][3] == '0' && board[3][3] == '0') || // fourth col
		(board[0][0] == '0' && board[1][1] == '0' && board[2][2] == '0' && board[3][3] == '0') || // first diagonal
		(board[0][3] == '0' && board[1][2] == '0' && board[2][1] == '0' && board[3][0] == '0'))   // second diagonal
		{
			win = 2;
		}
	else if ((board[0][0] != '_' && board[0][1] != '_' && board[0][2] != '_' && board[0][3] != '_') && // first row
		(board[1][0] != '_' && board[1][1] != '_' && board[1][2] != '_' && board[1][3] != '_') && // second row
		(board[2][0] != '_' && board[2][1] != '_' && board[2][2] != '_' && board[2][3] != '_') && // third row
		(board[3][0] != '_' && board[3][1] != '_' && board[3][2] != '_' && board[3][3] != '_') && // fourth row
		(board[0][0] != '_' && board[1][0] != '_' && board[2][0] != '_' && board[3][0] != '_') && // first col
		(board[0][1] != '_' && board[1][1] != '_' && board[2][1] != '_' && board[3][1] != '_') && // second col
		(board[0][2] != '_' && board[1][2] != '_' && board[2][2] != '_' && board[3][2] != '_') && // third col
		(board[0][3] != '_' && board[1][3] != '_' && board[2][3] != '_' && board[3][3] != '_') && // fourth col
		(board[0][0] != '_' && board[1][1] != '_' && board[2][2] != '_' && board[3][3] != '_') && // first diagonal
		(board[0][3] != '_' && board[1][2] != '_' && board[2][1] != '_' && board[3][0] != '_')) // second diagonal
		{
		    win = 3;
		}
		return win;
}

int start(void) {
	int z;
	printf("LOADING");
	for (z=0; z<30;z++) {
		Sleep(100);
		printf(".");
	}
	system("cls");
	return 0;

}










