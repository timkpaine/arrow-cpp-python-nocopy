#pragma once

#include <string>

#include <arrow/table.h>

#include <apn/exports.h>

extern "C" {
#include "apn/apn.h"
}

LIB_EXPORT std::shared_ptr<arrow::Array> create_array(char);
LIB_EXPORT std::string array_info(std::shared_ptr<arrow::Array> arr);

LIB_EXPORT std::shared_ptr<arrow::Schema> create_schema();
LIB_EXPORT std::string schema_info(std::shared_ptr<arrow::Schema>);

// LIB_EXPORT std::string table_info(std::shared_ptr<arrow::Table>);
// LIB_EXPORT std::shared_ptr<arrow::Table> create_table();
