#include <cstdint>
#include <iostream>

class ChessBoard {
public:
    uint64_t whitePawns, whiteKnights, whiteBishops, whiteRooks, whiteQueens, whiteKings;
    uint64_t blackPawns, blackKnights, blackBishops, blackRooks, blackQueens, blackKings;

    bool whiteToMove;
    int enPassantSquare;
    uint8_t castlingRights;

    ChessBoard() {
        whitePawns   = 0b00000000'11111111'00000000'00000000'00000000'00000000'00000000'00000000;
        whiteKnights = 0b01000010'00000000'00000000'00000000'00000000'00000000'00000000'00000000;
        whiteBishops = 0b00100100'00000000'00000000'00000000'00000000'00000000'00000000'00000000;
        whiteRooks   = 0b10000001'00000000'00000000'00000000'00000000'00000000'00000000'00000000;
        whiteQueens  = 0b00010000'00000000'00000000'00000000'00000000'00000000'00000000'00000000;
        whiteKings   = 0b00001000'00000000'00000000'00000000'00000000'00000000'00000000'00000000;

        blackPawns   = 0b00000000'00000000'00000000'00000000'00000000'00000000'11111111'00000000;
        blackKnights = 0b00000000'00000000'00000000'00000000'00000000'00000000'00000000'01000010;
        blackBishops = 0b00000000'00000000'00000000'00000000'00000000'00000000'00000000'00100100;
        blackRooks   = 0b00000000'00000000'00000000'00000000'00000000'00000000'00000000'10000001;
        blackQueens  = 0b00000000'00000000'00000000'00000000'00000000'00000000'00000000'00010000;
        blackKings   = 0b00000000'00000000'00000000'00000000'00000000'00000000'00000000'00001000;

        whiteToMove = true;
        enPassantSquare = -1;
        castlingRights = 0b1111;
    }

    void printBoard() const {
        for (int rank = 7; rank >= 0; --rank) {
            for (int file = 7; file >= 0; --file) {
                int square = rank * 8 + file;
                char piece = '.';

                if (whitePawns & (1ULL << square)) piece = 'P';
                else if (whiteKnights & (1ULL << square)) piece = 'N';
                else if (whiteBishops & (1ULL << square)) piece = 'B';
                else if (whiteRooks & (1ULL << square)) piece = 'R';
                else if (whiteQueens & (1ULL << square)) piece = 'Q';
                else if (whiteKings & (1ULL << square)) piece = 'K';
                else if (blackPawns & (1ULL << square)) piece = 'p';
                else if (blackKnights & (1ULL << square)) piece = 'n';
                else if (blackBishops & (1ULL << square)) piece = 'b';
                else if (blackRooks & (1ULL << square)) piece = 'r';
                else if (blackQueens & (1ULL << square)) piece = 'q';
                else if (blackKings & (1ULL << square)) piece = 'k';

                std::cout << piece << ' ';
            }
            std::cout << std::endl;
        }
    }
};
