#include "mems.h"

void    add_coder_acording_edf(t_coder  *coder){
    t_queue *q;
    t_node *tmp;

    q = coder->right_dongle->priority_queue;
    while (q && q->front->next)
    {
        if (q->front->value.last_compiletime > coder->last_compiletime)
            break;
        q = q->front->next;
    }
    tmp->value = q->front->value;
    q->front->value = coder;
    tmp->next = q->front->next;
    q->front->next = tmp;
    
}
void    manage_periority(t_coder    *coder, char    *s_type, int    num_of_coders){
    if (s_type == "edf"){
        add_coder_acording_edf(coder->right_dongle, coder->last_compiletime);
        add_acording_edf(coder->left_dongle, coder->last_compiletime);
    }
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