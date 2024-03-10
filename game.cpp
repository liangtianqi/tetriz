#include "game.h"
#include "tetromino.h"
#include "utils.h"
namespace gm
{
    bool running;
    Piece one_piece;
    Matrix playfield;
    std::chrono::microseconds duration;
    Matrix frame;
    // int row,col;
    // Tetromino_1 cur;
    // Tetromino_2 cur_set;
    // Tetromino cur_s;
    // int cur_index;

    void process()
    {
        render();
        if(ut::timer(duration)){
            one_piece.down();
        }
    }
void render(){
     frame=playfield;
     auto [x,y] = one_piece.get_xy();
     //zhengchangkuai
     //[0,4)
     for(auto i:iota(0,4)){
        auto [dx,dy]=one_piece.get_mino(i);
        frame[x+dx][y+dy]=one_piece.get_Color();
     }

     while (one_piece.test(x,--y))
     {
        /* code */
     };
     y++;
     for(auto i:iota(0,4)){
        auto [dx,dy]=one_piece.get_mino(i);
        if(frame[x+dx][y+dy]==0)
            frame[x+dx][y+dy]=0-one_piece.get_Color();
     }
     


}

    void init()
    {
        running=true;
        one_piece=pick();
        //playfield[x][y],x=0-9,y=0-21
        playfield=Matrix(10,std::vector<int>(22,0));
        duration=500ms;
        frame=playfield;
        one_piece.set_playfield(std::make_shared<Matrix>(playfield));
        // row=2;
        // col=15;
        // cur=S;
         
        // cur_set=I_set;
        // cur_index=0;
        // cur_s=i;
    }
    Piece pick(){

        //
        return Piece(j,4,20,0);
    }
    void quit()
    {
        running=false;
    }
    void rotate()
    {
        // // cur=rotate(cur);
        // cur_index=(cur_index+1)%4;
        one_piece.rotate();
    }

    void left()
    {
        // col--;
        one_piece.left();
    }

    void right()
    {
        // col++;
        one_piece.right();
    }

    void down()
    {
        // row++;
        one_piece.down();
    
    }

} // namespace gm