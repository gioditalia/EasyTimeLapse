#include "timelapse.h"

int timelapse(char* source,char* out,char* fps,char* compression){
    char command[500] = {0};

    //Command : ffmpeg -r 'fps' -pattern_type glob -i 'source/*.jpg' -c:v 'compression' 'out'

    strcat(command,"ffmpeg -y -r ");
    strcat(command,fps);
    strcat(command," -pattern_type glob -i '");
    strcat(command,source);
    strcat(command,"' -c:v mjpeg -q:v ");
    strcat(command,compression);
    strcat(command," '");
    strcat(command,out);
    strcat(command,".avi'");
    //system(command) return -1 when fail to launch a new process
    if(system(command) != -1)return 0;
    else return 1;
}

