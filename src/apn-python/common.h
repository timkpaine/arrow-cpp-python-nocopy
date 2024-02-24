#pragma once
#include <string>

#include "Python.h"
#include <arrow/table.h>
#include <apn-common/exports.h>
#include<arrow/util/key_value_metadata.h>

LIB_EXPORT std::shared_ptr<arrow::Array> unpack_array(PyObject*);
LIB_EXPORT std::shared_ptr<arrow::DataType> unpack_dtype(PyObject*);
LIB_EXPORT PyObject* pack_array(std::shared_ptr<arrow::Array>);

LIB_EXPORT std::shared_ptr<arrow::Schema> unpack_schema(PyObject*);
LIB_EXPORT PyObject* pack_schema(std::shared_ptr<arrow::Schema>);

// LIB_EXPORT char* table_info_py(std::shared_ptr<arrow::Table> table);
// LIB_EXPORT std::shared_ptr<arrow::Table> create_table_py();
