//
//  main.cpp
//  Algorithm_Problems
//
//  Created by Haley Lai on 2/23/20.
//  Copyright © 2020 Haley Lai. All rights reserved.
//

#include <iostream>
#include "NQueen.h"

int main(int argc, const char * argv[]) {

//   -----------------------------------------
//                   N-Queen
//   -----------------------------------------
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
//   -----------------------------------------
   return 0;
}
