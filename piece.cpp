#include "piece.h"


namespace gm
{
    Piece::Piece(Tetromino &t, int x0, int y0, int i):tetro_set(t),x(x0),y(y0),index(i),sp_playfield(nullptr)
    {

    }

    void Piece::down()
    {
        if(test(x,y-1)){
            y--;
        }
    }

    void Piece::set_playfield(std::shared_ptr<Matrix> p)
    {
        sp_playfield=p;
    }

    bool Piece::test(int ox, int oy)
    {
        for(int i=0;i<3;++i){
            auto [dx,dy]=get_mino(i);
            //yuejie
            if(ox+dx<0||ox+dx>(*sp_playfield).size()-1||oy+dy<0||oy+dy>(*sp_playfield)[0].size()-1){
                return false;
            }
            if((*sp_playfield)[ox+dx][ox+dy]>0) return false;

        }
        return true;
    }

    std::pair<int, int> Piece::get_mino(int i)
    {
        assert(i>=0 && i<=3);

        if(i==0)return {0,0};
        return tetro_set[index][i];
    }

} // namespace gm
