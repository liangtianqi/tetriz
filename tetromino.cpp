#include "tetromino.h"

namespace gm
{


    //IJLOSTZ
    //1234567
    Tetromino_1 I{{
        {0,0,0,0,0},
        {0,0,0,0,0},
        {0,1,1,1,1},
        {0,0,0,0,0},
        {0,0,0,0,0}
    }};

    Tetromino_1 J{{{2,0,0},{2,2,2},{0,0,0}}};
    Tetromino_1 L{{{0,0,3},{3,3,3},{0,0,0}}};
    Tetromino_1 O{{{0,4,4},{0,4,4},{0,0,0}}};
    Tetromino_1 S{{{0,5,5},{5,5,0},{0,0,0}}};    
    Tetromino_1 T{{{0,6,0},{6,6,6},{0,0,0}}};
    Tetromino_1 Z{{{7,7,0},{0,7,7},{0,0,0}}};


    std::map<int,Color> tetro_color{
        {1,Color::Cyan},
        {2,Color::Blue},
        {3,Color::Orange},
        {4,Color::Yellow},
        {5,Color::Green},
        {6,Color::Purple},
        {7,Color::Red}
    };

    Tetromino_1 rotate(Tetromino_1& t){
        Tetromino_1 result(t.size(),std::vector<int>(t.size(),0));
        //t[i][j]=t'[j][3-i-1]
        for(int i=0;i<t.size();++i){
            for(int j=0;j<t[0].size();++j){
                if(t[i][j]>0)
                    result[j][t.size()-i-1]=t[i][j];
            }
        }

        return std::move(result);
    }



    Tetromino_2 I_set{
        0x0f00 | (int)Color::Cyan << 16 | 'I' << 24,
        0x2222 | (int)Color::Cyan << 16 | 'I' << 24,
        0x00f0 | (int)Color::Cyan << 16 | 'I' << 24,
        0x4444 | (int)Color::Cyan << 16 | 'I' << 24,
    };
    bool get_bit(int t, int i, int j)
    {
        
        return t >> i*4+j&0x1==1;
    }


    Tetromino i{{
        {{{'I',(int)Color::Cyan},{-1,0},{1,0},{2,0}}},  // 0
        {{{'I',(int)Color::Cyan},{0,1},{0,-1},{0,-2}}},  //R
        {{{'I',(int)Color::Cyan},{-2,0},{-1,0},{1,0}}},  //2
        {{{'I',(int)Color::Cyan},{0,2},{0,1},{0,-1}}},   //L
    }};
    Tetromino j{{
        {{{'J',(int)Color::Blue},{-1,1},{-1,0},{1,0}}},  // 0
        {{{'J',(int)Color::Blue},{1,1},{0,1},{0,-1}}},  //R
        {{{'J',(int)Color::Blue},{-1,0},{1,0},{1,-1}}},  //2
        {{{'J',(int)Color::Blue},{0,1},{-1,-1},{0,-1}}},   //L
    }};
    Tetromino l{{
        {{{'L',(int)Color::Orange},{-1,0},{1,0},{1,1}}},  // 0
        {{{'L',(int)Color::Orange},{0,1},{0,-1},{1,-1}}},  //R
        {{{'L',(int)Color::Orange},{-1,-1},{-1,0},{1,0}}},  //2
        {{{'L',(int)Color::Orange},{-1,1},{0,1},{0,-1}}},   //L
    }};
    Tetromino o{{
        {{{'O',(int)Color::Yellow},{0,1},{1,1},{1,0}}},  // 0
        {{{'O',(int)Color::Yellow},{0,-1},{1,0},{1,-1}}},  //R
        {{{'O',(int)Color::Yellow},{-1,-1},{-1,0},{1,0}}},  //2
        {{{'O',(int)Color::Yellow},{-1,1},{-1,0},{0,1}}},   //L
    }};
    Tetromino s{{
        {{{'S',(int)Color::Green},{-1,0},{0,1},{1,1}}},  // 0
        {{{'S',(int)Color::Green},{0,1},{1,0},{1,-1}}},  //R
        {{{'S',(int)Color::Green},{-1,-1},{0,-1},{1,0}}},  //2
        {{{'S',(int)Color::Green},{-1,1},{-1,0},{0,-1}}},   //L
    }};
    Tetromino t{{
        {{{'T',(int)Color::Purple},{-1,0},{0,1},{1,0}}},  // 0
        {{{'T',(int)Color::Purple},{0,1},{1,0},{0,-1}}},  //R
        {{{'T',(int)Color::Purple},{-1,0},{1,0},{0,-1}}},  //2
        {{{'T',(int)Color::Purple},{-1,0},{0,1},{0,-1}}},   //L
    }};
    Tetromino z{{
        {{{'Z',(int)Color::Red},{-1,1},{0,1},{1,0}}},  // 0
        {{{'Z',(int)Color::Red},{1,1},{1,0},{0,-1}}},  //R
        {{{'Z',(int)Color::Red},{-1,0},{0,-1},{1,-1}}},  //2
        {{{'Z',(int)Color::Red},{-1,-1},{-1,0},{0,1}}},   //L
    }};




} // namespace gm
