#include <cstdint>
#include <iostream>

union Pieces{
    struct{
        uint64_t whitePawns, whiteKnights, whiteBishops, whiteRooks, whiteQueens, whiteKings;
        uint64_t blackPawns, blackKnights, blackBishops, blackRooks, blackQueens, blackKings;
    };

    uint64_t arr[12];
};

struct Move{
    uint64_t pieceChanges[3];
    int8_t pieceAddresses[3];

    uint8_t castlingRightsChanges;
    int8_t enPassantSquare;
};

class ChessBoard {
public:
    Pieces pieces;

    bool whiteToMove;
    int8_t enPassantSquare;
    uint8_t castlingRights;

    ChessBoard() {
        pieces.whitePawns   = 0b00000000'11111111'00000000'00000000'00000000'00000000'00000000'00000000;
        pieces.whiteKnights = 0b01000010'00000000'00000000'00000000'00000000'00000000'00000000'00000000;
        pieces.whiteBishops = 0b00100100'00000000'00000000'00000000'00000000'00000000'00000000'00000000;
        pieces.whiteRooks   = 0b10000001'00000000'00000000'00000000'00000000'00000000'00000000'00000000;
        pieces.whiteQueens  = 0b00010000'00000000'00000000'00000000'00000000'00000000'00000000'00000000;
        pieces.whiteKings   = 0b00001000'00000000'00000000'00000000'00000000'00000000'00000000'00000000;

        pieces.blackPawns   = 0b00000000'00000000'00000000'00000000'00000000'00000000'11111111'00000000;
        pieces.blackKnights = 0b00000000'00000000'00000000'00000000'00000000'00000000'00000000'01000010;
        pieces.blackBishops = 0b00000000'00000000'00000000'00000000'00000000'00000000'00000000'00100100;
        pieces.blackRooks   = 0b00000000'00000000'00000000'00000000'00000000'00000000'00000000'10000001;
        pieces.blackQueens  = 0b00000000'00000000'00000000'00000000'00000000'00000000'00000000'00010000;
        pieces.blackKings   = 0b00000000'00000000'00000000'00000000'00000000'00000000'00000000'00001000;

        whiteToMove = true;
        enPassantSquare = -1;
        castlingRights = 0b1111;
    }

    void applyMove(Move& move){
        for (int i = 0; i < 3; i++){
            int8_t addr = move.pieceAddresses[i];
            if (addr == -1)break;

            uint64_t changes = move.pieceChanges[i];
            pieces.arr[addr] ^= changes;
        }
        castlingRights ^= move.castlingRightsChanges;
        enPassantSquare = move.enPassantSquare;
        whiteToMove = !whiteToMove;
    }

    void printBoard() const {
        for (int rank = 7; rank >= 0; --rank) {
            for (int file = 7; file >= 0; --file) {
                int square = rank * 8 + file;
                char piece = '.';

                if (pieces.whitePawns & (1ULL << square)) piece = 'P';
                else if (pieces.whiteKnights & (1ULL << square)) piece = 'N';
                else if (pieces.whiteBishops & (1ULL << square)) piece = 'B';
                else if (pieces.whiteRooks & (1ULL << square)) piece = 'R';
                else if (pieces.whiteQueens & (1ULL << square)) piece = 'Q';
                else if (pieces.whiteKings & (1ULL << square)) piece = 'K';
                else if (pieces.blackPawns & (1ULL << square)) piece = 'p';
                else if (pieces.blackKnights & (1ULL << square)) piece = 'n';
                else if (pieces.blackBishops & (1ULL << square)) piece = 'b';
                else if (pieces.blackRooks & (1ULL << square)) piece = 'r';
                else if (pieces.blackQueens & (1ULL << square)) piece = 'q';
                else if (pieces.blackKings & (1ULL << square)) piece = 'k';

                std::cout << piece << ' ';
            }
            std::cout << std::endl;
        }
    }
};
