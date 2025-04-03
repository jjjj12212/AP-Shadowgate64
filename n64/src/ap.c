#include "ap.h"

void ap_check()
{
    for(u16 item = 1; item < AP_ITEM_MAX; item++)
    {
        if(ap_memory.pc.items[item] == 1)
        {
            obtain_item(item);
        }
    }
    for(u16 book = 75; book < AP_BOOK_MAX; book++)
    {
        if(ap_memory.pc.items[book] == 1)
        {
            obtain_item(book);
        }
    }
    for(u16 note = 104; note < AP_NOTE_MAX; note++)
    {
        if(ap_memory.pc.items[note] == 1)
        {
            obtain_item(note);
        }
    }
}
    