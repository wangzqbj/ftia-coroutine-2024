#include <stdio.h>
#include <unistd.h>
#include "ae.h"

static void do_with_fd(int fd)
{
        char buf[1024] = {0};
        int r = read(fd,buf,sizeof(buf));
        if(fd == fd1){
                do_something1(fd);
        }else if (fd == fd2){
                do_something2(fd);
        }

}

int main(int argc,char **argv)
{
        ae_init(do_with_fd);
        ae_add_event(fd1,READ_EVENT);
        ae_add_event(fd2,READ_EVENT);

        ae_loop();

        return 0;
}
