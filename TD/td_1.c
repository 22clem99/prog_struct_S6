typedef element_t



lifo_t lifo_push (  element_t e, lifo_t l)
{
return ((list_t) list_add_first( e, (list_t)stack));
}

element_t lifo_pop (lifo_t *l)
{
    element_t e = (*l)->val;

    *l = (lifo_t) list_del_first ((list_t)(*l));

    return e; 
}


element_t fifo_dequeue (fifo_t * p_queue)
{
    if (!list_t_empty((list_t)*p_queue))
    {
        element_t e = ((*p_queue)->next)->val;
        
    }
    

}