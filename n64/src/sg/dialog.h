#ifndef SG_DIALOG
#define SG_DIALOG
    
    #define sg_dialog_question (*(u16*)0x800E7A28) //1 = normal, 2 = yes / no dialog
    #define sg_dialog_text (*(u16*)0x800E7A26)
    #define sg_dialog_show_icon (*(u16*)0x800E7A32) //0x01 = display icon
    #define sg_dialog_icon (*(u16*)0x800E7A34)

typedef void (*sg_fnt_dialog_init)();
    #define sg_fn_dialog_init ((sg_fnt_dialog_init)0x8007CF94)
    typedef void (*sg_fnt_dialog_text)(u32*);
    #define sg_fn_dialog_text ((sg_fnt_dialog_text)0x8007C40C)

#endif