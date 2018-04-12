#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

int Answer;

void go(int **room, bool **visits, int *x, int *y, int *dir)
{
	if (*dir == 1) {
		if (room[*y][*x] == 0) {
			*x+=1;
		}
		else if (room[*y][*x] == 1) {
			*dir = 4;
			if (visits[*y][*x] == false) {
				Answer++;
				visits[*y][*x] = true;
			}
			*y-=1;
		}
		else {
			*dir = 3;
			if (visits[*y][*x] == false) {
				Answer++;
				visits[*y][*x] = true;
			}
			*y+=1;
		}
	}
	else if (*dir == 2) {
		if (room[*y][*x] == 0) {
			*x-=1;
		}
		else if (room[*y][*x] == 1) {
			*dir = 3;
			if (visits[*y][*x] == false) {
				Answer++;
				visits[*y][*x] = true;
			}
			*y+=1;
		}
		else {
			*dir = 4;
			if (visits[*y][*x] == false) {
				Answer++;
				visits[*y][*x] = true;
			}
			*y-=1;
		}
	}
	else if (*dir == 3) {
		if (room[*y][*x] == 0) {
			*y+=1;
		}
		else if (room[*y][*x] == 1) {
			*dir = 2;
			if (visits[*y][*x] == false) {
				Answer++;
				visits[*y][*x] = true;
			}
			*x-=1;
		}
		else {
			*dir = 1;
			if (visits[*y][*x] == false) {
				Answer++;
				visits[*y][*x] = true;
			}
			*x+=1;
		}
	}
	else {
		if (room[*y][*x] == 0) {
			*y-=1;
		}
		else if (room[*y][*x] == 1) {
			*dir = 1;
			if (visits[*y][*x] == false) {
				Answer++;
				visits[*y][*x] = true;
			}
			*x+=1;
		}
		else {
			*dir = 2;
			if (visits[*y][*x] == false) {
				Answer++;
				visits[*y][*x] = true;
			}
			*x-=1;
		}
	}
	return;
}

int main(int argc, char** argv)
{
	int T, test_case;
	/*
	The freopen function below opens input.txt file in read only mode, and afterward,
	the program will read from input.txt file instead of standard(keyboard) input.
	To test your program, you may save input data in input.txt file,
	and use freopen function to read from the file when using cin function.
	You may remove the comment symbols(//) in the below statement and use it.
	Use #include<cstdio> or #include <stdio.h> to use the function in your program.
	But before submission, you must remove the freopen function or rewrite comment symbols(//).
	*/

	// freopen("input.txt", "r", stdin);

	cin >> T;
	for (test_case = 0; test_case < T; test_case++)
	{

		Answer = 0;
		/////////////////////////////////////////////////////////////////////////////////////////////
		/*
		Implement your algorithm here.
		The answer to the case will be stored in variable Answer.
		*/
		/////////////////////////////////////////////////////////////////////////////////////////////

		// Print the answer to standard output(screen).
		int N;	//length
		int **rooms;
		bool **visit;
		int x_position, y_position;
		int dir;	//go right =1, left = 2, down = 3, up = 4;
		cin >> N;
		rooms = (int **)malloc(sizeof(int *)*(N + 1));
		visit = (bool **)malloc(sizeof(bool *)*(N + 1));
		for (int i = 0; i <= N; i++) {
			rooms[i] = (int *)malloc(sizeof(int)*(N + 1));
			visit[i] = (bool *)malloc(sizeof(bool)*(N + 1));
		}

		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				scanf("%1d", &rooms[i][j]);
				visit[i][j] = false;
			}
		}

		x_position = 1; y_position = 1;
		dir = 1;
		while (true) {
			if (x_position <= 0 || x_position > N || y_position <= 0 || y_position > N) {
				break;
			}
			go(rooms, visit, &x_position, &y_position, &dir);
		}
		
		cout << "Case #" << test_case + 1 << endl;
		cout << Answer << endl;

		for (int i = 0; i < N + 1; i++) {
			free(rooms[i]);
			free(visit[i]);
		}
		free(rooms);
		free(visit);
	}

	return 0;//Your program should return 0 on normal termination.
}