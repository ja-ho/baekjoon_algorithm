#include <cstdio>
#include <utility>
using namespace std;

char map[51][51];

int BFS();


int main() {
	int R, C;
	pair<int, int> position; 	//Todo: renaming
	pair<int, int> location;
	scanf("%d %d", &R, &C);
	for(int i = 0; i < R; i++) {
		for(int j = 0; j < C; j++) {
			scanf("%c", &map[i][j]);
		}
	}
	printf("------------------\n");
	
	for(int i = 0; i < R; i++) {
		printf("%s", map[i]);
		printf("\n");
	}



	return 0;
}

int BFS() 
{
	
}
