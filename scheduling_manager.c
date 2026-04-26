#include "mems.h"

void    manage_periority(t_queue    *r, t_queue *l, char    s_type, int   id){
    
}
void    add_coder_toschedual(t_coder    *coder, t_configs   cofigs){
    char    *schedual;
    t_queue *r_priority;
    t_queue *l_priority;

    schedual = cofigs.scheduler_type;
    r_priority = coder->right_dongle->priority_queue;
    l_priority = coder->left_dongle->priority_queue;
    manage_periority()
}