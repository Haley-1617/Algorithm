//
//  main.cpp
//  Algorithm_Problems
//
//  Created by Haley Lai on 2/23/20.
//  Copyright © 2020 Haley Lai. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

bool attack(vector<vector<int>> &board, int posX, int posY);
bool NQueen(vector<vector<int>> &board, int n, int y);

bool attack(vector<vector<int>> &board, int posX, int posY) {
//   vertical detectation
   for (int y = 0; y < board.size(); y++)
      if (y != posY && board[y][posX] == 1) return true;

//   horizontal detectation
   for (int x = 0; x < board.size(); x++)
      if (x != posX && board[posY][x] == 1) return true;

//   diagonal detectation (top left to bottom right)
   int x = 0, y = 0;
   if (posX >= posY) x = posX - posY;
   else y = posY - posX;
   for (; y < board.size(); y++, x++)
      if (!(y == posY && x == posX) && board[y][x] == 1) return true;

//   diagonal detectation (bottom left to top right)
   x = posX; y = posY;
   while (x != 0 && y != board.size() - 1) {
      x--;
      y++;
   }
   for (; y >= 0; x++, y--)
      if (!(y == posY && x == posX) && board[y][x] == 1) return true;

   return false;
}

bool NQueen(vector<vector<int>> &board, int n, int y) {
   if (n == 0) return true;
   for (; y < board.size(); y++) {
      for (int x = 0; x < board.size(); x++) {
         if (attack(board, x, y)) continue;
         board[y][x] = 1;
         if (NQueen(board, n - 1, y + 1)) return true;
         board[y][x] = 0;
      }
   }
   return false;
}

int main(int argc, const char * argv[]) {
   int n = 0;
   cout << "Size of the board: ";
   cin >> n;
   vector<vector<int>> board(n, vector<int>(n, 0));
   NQueen(board, n, 0);
   for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++)
         cout << board[i][j];
      cout << endl;
   }
   return 0;
}
