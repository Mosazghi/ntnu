#include <iostream>
using namespace std;

const int N = 10;
int gBrett[N + 2][N + 2] = {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0}, //  Setter opp brikker
                            {0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 1, 0}, //  likt med det i
                            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, //  oppgaveteksten:
                            {0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0},
                            {0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0},
                            {0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0},
                            {0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0},
                            {0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0},
                            {0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0},
                            {0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0},
                            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};

void visitGroup(int x, int y)
{
  if (gBrett[x][y] == 1)
  {
    gBrett[x][y] = 2;
    cout << "(" << x << "," << y << ") ";
    visitGroup(x, y + 1);
    visitGroup(x + 1, y);
    visitGroup(x, y - 1);
    visitGroup(x - 1, y);
  }
}

int main()
{
  for (int i = 1; i <= N; i++)
  {
    for (int j = 1; j <= N; j++)
    {
      if (gBrett[i][j] == 1)
      {
        visitGroup(i, j);
      }
    }
    cout << endl;
  }

  return 0;
}