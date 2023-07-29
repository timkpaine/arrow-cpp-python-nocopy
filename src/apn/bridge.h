#pragma once
#include <stddef.h>
#include "apn-common/exports.h"
#include "arrow/c/abi.h"

#ifdef __cplusplus
extern "C" {
#endif
    LIB_EXPORT int array_info_cabi(struct ArrowArray*, char*, size_t);
    LIB_EXPORT int create_array_cabi(struct ArrowArray*);

    LIB_EXPORT int schema_info_cabi(struct ArrowSchema*, char*, size_t);
    LIB_EXPORT int create_schema_cabi(struct ArrowSchema*);
#ifdef __cplusplus
}
#endif
