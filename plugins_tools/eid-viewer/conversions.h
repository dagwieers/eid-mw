#ifndef EID_VWR_CONVERSIONS_H
#define EID_VWR_CONVERSIONS_H

#ifdef __cplusplus
extern "C" {
#endif

#include "utftranslate.h"
#include <eid-viewer/oslayer.h>

#ifdef WIN32
#define SLEEP(x) Sleep(x*1000)
#else
#define SLEEP(x) sleep(x)
#endif

EID_CHAR* converted_string(const EID_CHAR* label, const EID_CHAR* normal);
EID_CHAR* convert_to_xml(const EID_CHAR* label, const EID_CHAR* item);
void* convert_from_xml(const EID_CHAR* name, const EID_CHAR* value, int* len_return);
int can_convert(const EID_CHAR* label);
enum eid_vwr_langs convert_get_lang();

#ifdef __cplusplus
}
#endif

#endif
