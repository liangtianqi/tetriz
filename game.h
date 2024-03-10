#pragma once

#include "tetromino.h"
#include "piece.h"
namespace gm
{


    //变量

    extern bool running;
    extern Piece one_piece;

    extern Matrix playfield;
    extern std::chrono::microseconds duration;
    extern Matrix frame;
    //方法

    // void quit();

    void process();
    void init();
    void render();
    Piece pick();
    void quit();
    void rotate();
    void left();
    void right();
    void down();

    // extern int row,col;

    // // extern Tetromino_1 cur;
    // // extern Tetromino_2 cur_set;
    // extern Tetromino cur_s;
    // extern int cur_index;


} // namespace gm
