#ifndef DIALOG_H
#define DIALOG_H

    #include "util.h"
    #include "sg.h"
    #include "string.h"

    extern bool DIALOG_SET;
    void show_dialog(u8 item);
    void character_translate(char* string);
    void show_dialog_text(char *text);

#endif