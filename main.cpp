#include <iostream>
#include <thread>
#include "terminal.h"
#include "utils.h"
using namespace std::chrono_literals;




void init(){
     tc::hide_cursor();
}

void loop(){
    int i=1;
    while(true){
        
        tc::clean_screen();

        tc::move_to(1,1);
        std::cout<<"FPS:"<<ut::fps();
        
        tc::move_to(i++%20,10);
        tc::set_back_color(15);
        std::cout<<"  ";
        tc::reset_color();
        std::cout<<std::flush;
        std::this_thread::sleep_for(100ms); //s,ms,ns
    }


}

void exit(){


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