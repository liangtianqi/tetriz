#include "control.h"
#include "define.h"
#include "game.h"
namespace gm
{

    char command;
    std::map<char,std::function<void()>> comm_func{
        {KEY_Q,commamd_quit},
        {KEY_W,command_rotate},
        {KEY_A,command_left},
        {KEY_D,command_right},
        {KEY_S,command_down}
    };
    char getch()
    {
    char c;
    struct termios old,cur;
    tcgetattr(0,&cur);
    old=cur;
    cfmakeraw(&cur);
    tcsetattr(0,0,&cur);
    c=getchar();
    tcsetattr(0,0,&old);

    return c;
    }

    void key_event()
    {
     while(running){
        command=getch();
        if(comm_func.find(command)!=comm_func.end())
            comm_func[command]();
        }
    }

void start_listener()
{
    std::thread t(key_event);
    t.detach();
}

void commamd_quit()
{
    quit();
}

void command_rotate()
{
    rotate();
}

void command_left()
{
    left();
}

void command_right()
{
    right();
}

void command_down()
{
    down();
}

} // namespace gm
