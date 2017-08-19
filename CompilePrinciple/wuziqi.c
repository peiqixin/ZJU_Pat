#include <stdio.h>
#include <stdlib.h>

#define N 15
int chessboard[N + 1][N + 1] = {0};
int whoseTurn;

void InitGame(void);
void PrintChessBoard(void);
void PlayChess(void);
int Judge(int x, int y);

int main(int argc, char const *argv[])
{
	
	PrintChessBoard();

	while(1){
		PlayChess();
		whoseTurn++;
	}

	return 0;
}

void InitGame(void)
{
	char c;
	printf("Welcome to WuZiQi, enter y or Y start game!\n");

	c = getchar();
	if('y' != c && 'Y' != c)
		exit(0);
	system("cls");

	PrintChessBoard();
}

void PrintChessBoard(void)
{
	int i, j;
	for(i = 0; i <= N * 2; i++){
		for(j = 0; j < N; j++){
			if(i % 2 == 0){
				if(i == 0){
					printf("%3d", j);
				}else if(j == 0){
					printf("%3d", i / 2);
				}else if(chessboard[i][j] == 1){
					printf("| X ");
				}else if(chessboard[i][j] == 2){
					printf("| O ");
				}else{
					printf("| * ");
				}
			}else{
				if(j != N)
					printf("---|");
				else
					printf("---");
			}
		}
		printf("\n");
	}
}
// 0 | 2 | 3 | 4 | 5
//---|---|---|---|---
// 1 | 2 | 3 | 3 | 5
//---|---|---|---|---

void PlayChess(void)
{
	int x, y, winner;
	if(whoseTurn % 2 == 0){
		printf("Now is player1's turn, please enter 'x y')\n");
		scanf("%d %d", &x, &y);
		chessboard[x][y] = 1;
	}else{
		printf("Now is player2's turn, please enter 'x y')\n");
		scanf("%d %d", &x, &y);
		chessboard[x][y] = 2;
	}

	system("cls");
	PrintChessBoard();

	winner = Judge(x, y);
	if(winner){
		if(whoseTurn % 2 == 0){
			printf("Player1 is win\n");
		}else{
			printf("Player2 is win\n");
		}
	}

}

int Judge(int x, int y)
{
	int i, j;
    int t = 2 - whoseTurn % 2;

    for (i = x - 4, j = y; i <= x; i++)
    {
        if (i >= 1 && i <= N - 4 && t == chessboard[i][j] && t == chessboard[i + 1][j] && t == chessboard[i + 2][j] && t == chessboard[i + 3][j] && t == chessboard[i + 4][j])
            return 1;
    }
    for (i = x, j = y - 4; j <= y; j++)
    {
        if (j >= 1 && j <= N - 4 && t == chessboard[i][j] && t == chessboard[i][j + 1] && t == chessboard[i][j + 2] && t == chessboard[i][j + 3] && t == chessboard[i][j + 4])
            return 1;
    }
    for (i = x - 4, j = y - 4; i <= x, j <= y; i++, j++)
    {
        if (i >= 1 && i <= N - 4 && j >= 1 && j <= N - 4 && t == chessboard[i][j] && t == chessboard[i + 1][j + 1] && t == chessboard[i + 2][j + 2] && t == chessboard[i + 3][j + 3] && t == chessboard[i + 4][j + 4])
            return 1;
    }
    for (i = x + 4, j = y - 4; i >= 1, j <= y; i--, j++)
    {
        if (i >= 1 && i <= N - 4 && j >= 1 && j <= N - 4 && t == chessboard[i][j] && t == chessboard[i - 1][j + 1] && t == chessboard[i - 2][j + 2] && t == chessboard[i - 3][j + 3] && t == chessboard[i - 4][j + 4])
            return 1;
    }

    return 0;
}