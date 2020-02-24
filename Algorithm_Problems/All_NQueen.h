//
//  All_NQueen.h
//  Algorithm_Problems
//
//  Created by Haley Lai on 2/23/20.
//  Copyright © 2020 Haley Lai. All rights reserved.
//

#ifndef All_NQueen_h
#define All_NQueen_h

#include <vector>

using namespace std;

bool conflict(vector<vector<int>> &board, int posX, int posY);
void AllNQueen(vector<vector<int>> &board, int n);

bool conflict(vector<vector<int>> &board, int posX, int posY) {
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

void AllNQueen(vector<vector<int>> &board, int n) {
   if (n == board.size()) {
      for (int i = 0; i < board.size(); i++) {
         for (int j = 0; j < board.size(); j++)
            cout << board[i][j];
         cout << endl;
      }
      cout << endl;
      return;
   }
   
   for (int x = 0; x < board.size(); x++) {
      if (conflict(board, x, n)) continue;
      board[n][x] = 1;
      AllNQueen(board, n + 1);
      board[n][x] = 0;
   }
}

#endif /* All_NQueen_h */
