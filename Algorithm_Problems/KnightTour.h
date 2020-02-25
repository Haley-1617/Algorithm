//
//  KnightTour.h
//  Algorithm_Problems
//
//  Created by Haley Lai on 2/24/20.
//  Copyright © 2020 Haley Lai. All rights reserved.
//

#ifndef KnightTour_h
#define KnightTour_h

#include <vector>

bool outOfRange(int posX, int posY, int size);
void knight(vector<vector<int>> &board, vector<pair<int, int>> move,
            int n, int posX, int posY);

bool outOfRange(int posX, int posY, int size) {
   if (posX < 0 || posX >= size || posY < 0 || posY >= size )
      return true;
   return false;
}

void knight(vector<vector<int>> &board, vector<pair<int, int>> move,
            int n, int posX, int posY) {

   if (n >= board.size() * board.size()) {
      for (int i = 0; i < board.size(); i++) {
         for (int j = 0; j < board.size(); j++)
            cout << board[i][j] << ", ";
         cout << endl;
      }
      cout << endl;
   }

   for (int i = 0; i < move.size(); i++) {
      int x = posX + move[i].second;
      int y = posY + move[i].first;
      if (outOfRange(x, y, board.size()) || board[y][x] != 0) continue;
      board[y][x] = n + 1;
      knight(board, move, n + 1, x, y);
      board[y][x] = 0;
   }

}

#endif /* KnightTour_h */
