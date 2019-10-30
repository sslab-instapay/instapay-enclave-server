package main

/*
#cgo CPPFLAGS: -I/home/xiaofo/sgxsdk/include -I./untrusted -I./include
#cgo LDFLAGS: -L. -ltee

#include "untrusted/app.h"
*/
import "C"

import (
	"fmt"
	// "unsafe"
	// "reflect"
)

func main() {
	C.initialize_enclave()

	/* calling ecall_register_account */
	A := []C.uchar("78902c58006916201F65f52f7834e467877f0500")
	owner := []C.uchar("D03A2CC08755eC7D75887f0997195654b928893e")
	B := []C.uchar("0b4161ad4f49781a821c308d672e6c669139843c")

	PaymentNum := C.ecall_get_request_from_client(&A[0], &B[0], C.uint(8))
	fmt.Printf("payment number: %d\n", PaymentNum)

	C.ecall_add_participant(PaymentNum, &A[0]);
	C.ecall_add_participant(PaymentNum, &owner[0]);
	C.ecall_add_participant(PaymentNum, &B[0]);
	
	C.ecall_add_addrs_sent_agr(PaymentNum, &A[0]);
	C.ecall_add_addrs_sent_agr(PaymentNum, &owner[0]);
	C.ecall_add_addrs_sent_agr(PaymentNum, &B[0]);

    Flag := C.ecall_is_unanimous(PaymentNum, C.int(0));
    fmt.Println(Flag)
}