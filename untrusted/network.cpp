#include "app.h"
#include "enclave_u.h"


unsigned int ecall_accept_request_w(unsigned char *sender, unsigned char *receiver, unsigned int amount)
{
    unsigned int payment_num;

    ecall_accept_request(global_eid, sender, receiver, amount, &payment_num);

    return payment_num;
}


void ecall_add_participant_w(unsigned int payment_num, unsigned char *addr)
{
    ecall_add_participant(global_eid, payment_num, addr);
}


void ecall_update_sentagr_list_w(unsigned int payment_num, unsigned char *addr)
{
    ecall_update_sentagr_list(global_eid, payment_num, addr);
}


void ecall_update_sentupt_list_w(unsigned int payment_num, unsigned char *addr)
{
    ecall_update_sentupt_list(global_eid, payment_num, addr);
}


int ecall_check_unanimity_w(unsigned int payment_num, int which_list)
{
    int is_unanimous;

    ecall_check_unanimity(global_eid, payment_num, which_list, &is_unanimous);

    return is_unanimous;
}