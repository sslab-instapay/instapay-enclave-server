#include "app.h"
#include "enclave_u.h"


unsigned int ecall_get_request_from_client(unsigned char *sender, unsigned char *receiver, unsigned int amount)
{
    unsigned int payment_num;

    ecall_accept_request(global_eid, sender, receiver, amount, &payment_num);

    return payment_num;
}


void ecall_add_participant(unsigned int payment_num, unsigned char *addr)
{
    ecall_register_participant(global_eid, payment_num, addr);
}


void ecall_add_addrs_sent_agr(unsigned int payment_num, unsigned char *addr)
{
    ecall_update_addrs_sent_agr(global_eid, payment_num, addr);
}


void ecall_add_addrs_sent_upt(unsigned int payment_num, unsigned char *addr)
{
    ecall_update_addrs_sent_upt(global_eid, payment_num, addr);
}


int ecall_is_unanimous(unsigned int payment_num, int s)
{
    int is_unanimous;

    ecall_check_unanimity(global_eid, payment_num, s, &is_unanimous);
    return is_unanimous;
}