#include "define.h"
#include <pthread.h>
#include "terminal.h"
#include "utils.h"
#include "draw.h"
#include "control.h"
#include "game.h"


void init(){


    tc::hide_cursor();
    gm::start_listener();
    gm::init();
}

void loop(){
    int i=1;
    while(gm::running){
        gm::process();
        tc::clean_screen();
        dw::window(1,1,9,6,"Hold");
        dw::window(1,10,12,22,"Tetriz");
        dw::window(7,1,9,16,"Status");
        dw::window(19,22,8,4,"Info");
        dw::window(1,22,8,18,"Next");

        tc::move_to(10,4);
        std::cout<<"FPS:"<<ut::fps();
        
        //tc::move_to(i++%20,10);
        // tc::move_to(gm::row,ut::b2c(gm::col));
        // tc::set_back_color(15);
        // std::cout<<"  ";
        // tc::reset_color();
        // dw::tetromino(gm::cur,gm::row,gm::col);
        // dw::tetromino(gm::cur_set,gm::row,gm::col,gm::cur_index);
        // dw::tetromino(gm::cur_s,gm::row,gm::col,gm::cur_index);

        dw::frame(gm::frame,2,11);

        tc::reset_color();

        std::cout<<std::flush;
        std::this_thread::sleep_for(100ms); //s,ms,ns
    }


}

void exit(){
    tc::show_cursor();
    tc::reset_color();
    tc::clean_screen();
    tc::move_to(1,1);
    tc::set_fore_color(9);
    std::cout<<"Bye!"<<std::endl;

}


int main(){
    // tc::move_to(5,10);
    // tc::set_fore_color(214);
    // std::cout<<"hello world";
    // tc::move_to(10,1);

    init();
    loop();
    exit();


    // tc::hide_cursor();
    // int i=1;
    // while(true){

    //     tc::clean_screen();
    //     tc::move_to(i++,10);
    //     tc::set_back_color(15);
    //     std::cout<<"  ";
    //     tc::reset_color();
    //     std::cout<<std::flush;
    //     std::this_thread::sleep_for(1s); //s,ms,ns
    // }



    return 0;
}