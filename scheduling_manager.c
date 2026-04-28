#include "mems.h"

void    add_coder_acording_edf(t_coder  *coder){
    
    sort_queue(coder->right_dongle->priority_queue);
    sort_queue(coder->left_dongle->priority_queue);
}

void    add_manage_periority(t_coder    *coder, char    *s_type){
    if (s_type == "edf")
        add_coder_acording_edf(coder);
    else
    {
        enqueue(coder->right_dongle->priority_queue, coder);
        enqueue(coder->left_dongle->priority_queue, coder);
    }
}