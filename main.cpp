#include <iostream>
# include "board.cpp"

int main(){
    ChessBoard board = ChessBoard();
    board.printBoard();

    std::cout<<"-----\n";

    Move move = Move();
    move.pieceAddresses[0] = 0;
    move.pieceAddresses[1] = -1;
    move.pieceChanges[0] = 0b00000000'00001000'00001000'00000000'00000000'00000000'00000000'00000000;

    board.applyMove(move);
    board.printBoard();

    return 0;
}
