#ifndef EID_VWR_P11_H
#define EID_VWR_P11_H

#ifdef WIN32
#include <win32.h>
#else
#include <unix.h>
#endif
#include <pkcs11t.h>

#define EIDV_RV_OK 0
#define EIDV_RV_FAIL -1

int eid_vwr_p11_init();
int eid_vwr_p11_find_first_slot(CK_SLOT_ID_PTR loc);
int eid_vwr_p11_read_id(void*);
int eid_vwr_p11_read_certs(void*);
int eid_vwr_p11_open_session(void* slot);
int eid_vwr_p11_close_session();
int eid_vwr_p11_finalize_find();
int eid_vwr_p11_do_pinop(void*);
int eid_vwr_p11_leave_pinop();
void eid_vwr_p11_to_ui(const char*, const void*, int);

#endif