#pragma once
#include "tetromino.h"
#include "define.h"
namespace gm
{
    class Piece
    {
        public:
            Piece(Tetromino &t,int x0,int y0,int i);
            Piece()=default;
            void down();
            void left();
            void right();
            void rotate();
            void set_playfield(std::shared_ptr<Matrix> p);
            std::pair<int,int> get_mino(int i);
            std::pair<int,int> get_xy();
            int get_Color();
            bool test(int x,int y);
        private:
            Tetromino tetro_set;
            int index;// 0 R L 2
            int x,y; //政教指教坐标系
            
            std::shared_ptr<Matrix> sp_playfield;

            void move(int dx,int dy);
            
    };
} // namespace gm
