using namespace std;
int solution(int n)
{
	int x;
	int answer = 0;

	while (n != 0) {   
		answer += n % 10;
		n /= 10;
	}

	return answer;
}