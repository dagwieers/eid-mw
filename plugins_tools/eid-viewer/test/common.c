#include <unix.h>
#include <pkcs11.h>
#include <testlib.h>
#include "oslayer.h"
#include <stdlib.h>

enum eid_vwr_source cursrc;

static void newsrc(enum eid_vwr_source src) {
	cursrc = src;
	switch(src) {
		case EID_VWR_SRC_NONE:
			printf("card removed\n");
			break;
		case EID_VWR_SRC_FILE:
			printf("file source\n");
			break;
		case EID_VWR_SRC_CARD:
			printf("card found\n");
			break;
		default:
			printf("unknown source; error?\n");
			exit(TEST_RV_FAIL);
	}
}

static void newstringdata(char* label, char* data) {
	printf("Found string data\nLabel:\t%s\nData:\t%s\n", label, data);
}

static void newbindata(char* label, void* data, int datalen) {
	printf("Found binary data\nLabel:\t%s\nLength:\t%d\n", label, datalen);
}

static void dolog(enum eid_vwr_loglevel lvl, char* line) {
	printf("Log message; level: ");
	switch(lvl) {
		case EID_VWR_LOG_DETAIL:
			printf("detail");
			break;
		case EID_VWR_LOG_NORMAL:
			printf("normal");
			break;
		case EID_VWR_LOG_COARSE:
			printf("coarse");
			break;
	}
	printf("; line: %s", line);
}

struct eid_vwr_ui_callbacks* createcbs() {
	struct eid_vwr_ui_callbacks* cb = eid_vwr_cbstruct();
	if(cb == NULL) {
		return cb;
	}
	cb->newsrc = newsrc;
	cb->newstringdata = newstringdata;
	cb->newbindata = newbindata;
	cb->log = dolog;
	return cb;
}
