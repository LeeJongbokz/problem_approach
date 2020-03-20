// 최초 풀이: 50분 디버깅: 40분 = 총 90분
// 4번 조건에 대해서 명확하게 이해하지 못했음 
// dfs에서 return을 하는 것과 동작을 멈추는 것의 차이점을 이해하지 못했음
// 시간을 제한하고 푸는데 더 익숙해져야 함 

// 잘한 점
- 최대한 간단한 테스트 케이스를 만들어 디버깅하려고 한 점
- 디버깅에 있어서 적절한 for문이나 함수를 넣어서 풀이한 점
- 문제가 무엇인지 인지하고, 그에 대해 해결해낸 점

// 단순히 디버깅을 시도하는 것보다,
   내가 모르는 것이 무엇이고, 문제의 원인이 무엇인지 깊이 생각해보는 것이
   더 빠른 문제 해결로 이어질 수 있다. 

#include <iostream>
#include <cstring>

using namespace std;

int N, M;
int r, c, d;
int map[60][60];
bool check[60][60];
int total = 0; 


int leftx[4] = { 0, -1, 0, 1 };
int lefty[4] = { -1, 0, 1, 0 };

int backx[4] = { 1, 0, -1, 0 };
int backy[4] = { 0, -1, 0, 1 };

int cleaned = 0; 


bool isRange(int x, int y) {

	if (1 <= x && x <= N && 1 <= y && y <= M) {
		return true;
	}
	else {
		return false; 
	}
}

void checkMap() {

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (check[i][j] == true) {
				cleaned += 1;
			}

		}
	}
}




void dfs(int x, int y, int d) {

	check[x][y] = true;
	int cnt = 0; 


	while (1) {

		if (cnt == 4) {
			break;
		}

		int nx = x + leftx[d];
		int ny = y + lefty[d];
		

		if (isRange(nx,ny) && map[nx][ny] == 0 && check[nx][ny] == false) {
			int nd;
			if (d == 0) {
				nd = 3;
			}
			else {
				nd = d - 1;
			}

			dfs(nx, ny, nd);

		}
		else{

			if (d == 0) {
				d = 3;
			}
			else {
				d = d - 1;
			}
			cnt += 1;

		}


	}

	int bx = x + backx[d];
	int by = y + backy[d];


	if (isRange(bx,by) && map[bx][by] == 0) {
		dfs(bx, by, d);
	}
	else if(isRange(bx, by) && map[bx][by] == 1) {
		if (total == 0) {
			checkMap();
			total += 1;
		}
		return; 
	}


}






int main() {


	cin >> N >> M;

	cin >> r >> c >> d;

	memset(check, false, sizeof(check));

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> map[i][j]; 
		}
	}


	dfs(r+1, c+1, d);
     

	cout << cleaned;


}
