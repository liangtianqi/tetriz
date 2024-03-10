#include "draw.h"
#include "terminal.h"
#include <iostream>
#include "utils.h"
/*
0 	    1 	2 	 3 	 4 	  5    6    7 	8 	9 	A 	  B 	C 	D 	E 	F
U+250x 	─ 	━ 	│ 	┃ 	┄ 	┅ 	┆ 	┇ 	┈ 	┉ 	┊ 	┋ 	┌ 	┍ 	┎ 	┏
U+251x 	┐ 	┑ 	┒ 	┓ 	└ 	┕ 	┖ 	┗ 	┘ 	┙ 	┚ 	┛ 	├ 	┝ 	┞ 	┟
U+252x 	┠ 	┡ 	┢ 	┣ 	┤ 	┥ 	┦ 	┧ 	┨ 	┩ 	┪ 	┫ 	┬ 	┭ 	┮ 	┯
U+253x 	┰ 	┱ 	┲ 	┳ 	┴ 	┵ 	┶ 	┷ 	┸ 	┹ 	┺ 	┻ 	┼ 	┽ 	┾ 	┿
U+254x 	╀ 	╁ 	╂ 	╃ 	╄ 	╅ 	╆ 	╇ 	╈ 	╉ 	╊ 	╋ 	╌ 	╍ 	╎ 	╏
U+255x 	═ 	║ 	╒ 	╓ 	╔ 	╕ 	╖ 	╗ 	╘ 	╙ 	╚ 	 ╛ 	  ╜ 	╝ 	╞ 	╟
U+256x 	╠ 	╡ 	╢ 	╣ 	╤ 	╥ 	╦ 	╧ 	╨ 	╩ 	╪ 	 ╫ 	  ╬ 	╭ 	╮ 	╯
U+257x 	╰ 	╱ 	╲ 	╳ 	╴ 	╵ 	╶ 	╷ 	╸ 	╹ 	 ╺ 	╻ 	╼ 	╽ 	╾ 	╿
*/
namespace dw
{
    const std::u32string style1=U" ┌┐└┘│─";
    const std::u32string style2=U" ╔╗╚╝║═";
    const std::u32string style3=U" ┏┓┗┛┃━";
    const std::u32string style4=U" ╭╮╰╯│─";
    const std::u32string cur_style=style4;




    void window(int top, int left, int width, int height, std::string title)
    {
    for(int r=0;r<height;r++){
        tc::move_to(top+r,ut::b2c(left));
        for(int c=0;c<width;c++){
            if(r==0){
                if(c==0){
                    std::cout<<ut::utf32_to_utf8({cur_style[0],cur_style[1]});
                }
                else if(c==width-1){
                    std::cout<<ut::utf32_to_utf8({cur_style[2]});
                }
                else{std::cout<<ut::utf32_to_utf8({cur_style[6],cur_style[6]});}
            }
            else if(r==height-1){
                if(c==0){
                    std::cout<<ut::utf32_to_utf8({cur_style[0],cur_style[3]});
                }
                else if(c==width-1){
                    std::cout<<ut::utf32_to_utf8({cur_style[4]});
                }
                else{std::cout<<ut::utf32_to_utf8({cur_style[6],cur_style[6]});}
            }
            else{
                if(c==0){
                    std::cout<<ut::utf32_to_utf8({cur_style[0],cur_style[5]});
                }
                else if(c==width-1){
                    std::cout<<ut::utf32_to_utf8({cur_style[5]});
                }
                else{std::cout<<"  ";}
            }


        }

    }

    //title
    tc::move_to(top,ut::b2c(left)+(width*2-title.length())/2);
    std::cout<<title;
    }
    void tetromino(gm::Tetromino_1 &t, int top, int left)
    {
        for(int i=0;i<t.size();++i){
            tc::move_to(top+i,ut::b2c(left));
            for(int j=0;j<t[0].size();++j){
                if(t[i][j]>0){
                    tc::set_back_color((int)gm::tetro_color[t[i][j]]);
                    std::cout<<"  ";
                }
                else{
                    tc::reset_color();
                    std::cout<<"  ";
                }
            }
        }
    }
    void tetromino(gm::Tetromino_2 &t, int top, int left, int index)
    {
        for(int i=0;i<4;++i){
            tc::move_to(top+i,ut::b2c(left));
            for(int j=0;j<4;++j)
            {
                if(gm::get_bit(t[index],i,j))
                {
                    tc::set_back_color(t[index]>>16 &0xff);
                    std::cout<<"  ";
                }
                else
                {
                    tc::reset_color();
                    std::cout<<"  ";
                }
                
            }
        }

    }
    void tetromino(gm::Tetromino &t, int top, int left, int index)
    {
        tc::move_to(top,ut::b2c(left));
        tc::set_back_color(t[index][0].second);
        std::cout << "  ";
        for(auto p:t[index]){
            if(p.first>'A') continue;
            tc::move_to(top-p.second, ut::b2c(left+p.first));
            std::cout << "  ";
            
        }
    }
    void frame(Matrix &frame, int top, int left)
    {
        int row,col;
        //frame xy col ===> row/col
        for (int x=0;x<10;++x){
            for(int y=0;y<20;y++){
                row=top+20-y-1;
                col=left+x;
                tc::move_to(row,ut::b2c(col));
                if(frame[x][y]>0){
                    tc::reset_color();
                    tc::set_back_color(frame[x][y]);
                    std::cout<<"  ";
                }else if(frame[x][y]<0){
                    tc::reset_color();
                    tc::set_fore_color(0-frame[x][y]);
                    std::cout<<"\u25e3\u25e5";
                }else{
                    tc::reset_color();
                    std::cout<<"\u30FB";
                }
            }
        }
    }
} // namespace dw
