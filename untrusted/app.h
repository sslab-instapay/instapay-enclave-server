#ifndef _APP_H_
#define _APP_H_

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

#include "sgx_error.h"       /* sgx_status_t */
#include "sgx_eid.h"     /* sgx_enclave_id_t */

#ifndef TRUE
# define TRUE 1
#endif

#ifndef FALSE
# define FALSE 0
#endif

# define TOKEN_FILENAME   "enclave.token"
# define ENCLAVE_FILENAME "enclave.signed.so"

extern sgx_enclave_id_t global_eid;    /* global enclave id */

#if defined(__cplusplus)
extern "C" {
#endif

int initialize_enclave(void);

unsigned int ecall_get_request_from_client(unsigned char *sender, unsigned char *receiver, unsigned int amount);
void ecall_add_participant(unsigned int payment_num, unsigned char *addr);
void ecall_add_addrs_sent_agr(unsigned int payment_num, unsigned char *addr);
void ecall_add_addrs_sent_upt(unsigned int payment_num, unsigned char *addr);
int ecall_is_unanimous(unsigned int payment_num, int s);

#if defined(__cplusplus)
}
#endif

#endif /* !_APP_H_ */
