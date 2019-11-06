#include <iostream>
#include <cstdio>

using namespace std;

int N;
int map[21][21];
int max1;

void go(int dir) {
   int i, j;
   int temp;
   int check[21][21] = { 0 };

   if (dir == 0) { // 북쪽으로 땡기기
      for (i = 0; i < N; i++) {
         for (j = 0; j < N; j++) {
            temp = j;
            while (1) {  // 쭉 미는 와일문
               if (temp - 1 == -1) //맵 넘어가면 break;
                  break;
               if (map[temp - 1][i] != 0)
                  break;
               map[temp - 1][i] = map[temp][i];
               map[temp][i] = 0;
               temp--;
            }
            if (temp - 1 == -1)
               continue;
            if (map[temp - 1][i] == map[temp][i] && check[temp - 1][i] != 1) { //밀었는데 앞에 같은숫자일때
               map[temp][i] = 0;
               map[temp - 1][i] = 2 * map[temp - 1][i];
               check[temp - 1][i] = 1;
            }

         }
      }
   }
   else if (dir == 1) {
      for (i = 0; i < N; i++) {
         for (j = N - 1; j >= 0; j--) {
            temp = j;
            while (1) {
               if (temp + 1 == N) //맵 넘어가면 break;
                  break;
               if (map[i][temp + 1] != 0)
                  break;
               map[i][temp + 1] = map[i][temp];
               map[i][temp] = 0;
               temp++;
            }
            if (temp + 1 == N)
               continue;
            if (map[i][temp + 1] == map[i][temp] && check[i][temp + 1] != 1) {
               map[i][temp] = 0;
               map[i][temp + 1] = 2 * map[i][temp + 1];
               check[i][temp + 1] = 1;
            }

         }
      }
   }

   else if (dir == 2) {
      for (i = 0; i < N; i++) {
         for (j = N - 1; j >= 0; j--) {
            temp = j;
            while (1) {
               if (temp + 1 == N) //맵 넘어가면 break;
                  break;
               if (map[temp + 1][i] != 0)
                  break;
               map[temp + 1][i] = map[temp][i];
               map[temp][i] = 0;
               temp++;
            }
            if (temp + 1 == N)
               continue;
            if (map[temp + 1][i] == map[temp][i] && check[temp + 1][i] != 1) {
               map[temp][i] = 0;
               map[temp + 1][i] = 2 * map[temp + 1][i];
               check[temp + 1][i] = 1;
            }

         }
      }
   }

   else if (dir == 3) {
      for (i = 0; i < N; i++) {
         for (j = 0; j < N; j++) {
            temp = j;
            while (1) {
               if (temp - 1 == -1) //맵 넘어가면 break;
                  break;
               if (map[i][temp - 1] != 0)
                  break;
               map[i][temp - 1] = map[i][temp];
               map[i][temp] = 0;
               temp--;

            }
            if (temp - 1 == -1)
               continue;
            if (map[i][temp - 1] == map[i][temp] && check[i][temp - 1] != 1) {
               map[i][temp] = 0;
               map[i][temp - 1] = 2 * map[i][temp - 1];
               check[i][temp - 1] = 1;
            }

         }
      }
   }

}


void print() {
   int i, j, k;
   for (j = 0; j < N; j++) {
      for (k = 0; k < N; k++) {
         printf("%5d", map[j][k]);
      }
      cout << endl;
   }
   cout << endl;
}

void dfs(int cnt) {
   int i, j, k;
   int tMap[21][21];

   if (cnt > 4) {
      for (i = 0; i < N; i++) {
         for (j = 0; j < N; j++) {
            if (max1 < map[i][j])
               max1 = map[i][j];
         }
      }
      return;
   }

   for (i = 0; i < 4; i++) {


      for (j = 0; j < N; j++) {
         for (k = 0; k < N; k++) {
            tMap[j][k] = map[j][k];
         }
      }

      go(i); // 맵복사 및 옮기기
      //print();
      dfs(cnt + 1);


      for (j = 0; j < N; j++) {
         for (k = 0; k < N; k++) {
            map[j][k] = tMap[j][k];
         }
      }
      // 맵돌리기
   }


}



int main() {
   int i, j;

   cin >> N;
   for (i = 0; i < N; i++) {
      for (j = 0; j < N; j++) {
         cin >> map[i][j];
      }
   }
   //dfs1(0);
   dfs(0);

   cout << max1;

   return 0;
}