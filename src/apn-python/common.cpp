#include "arrow/c/abi.h"
#include <arrow/c/bridge.h>
#include <apn-python/common.h>
#include <iostream>



void ReleaseArrowArrayPyCapsule(PyObject* array_capsule) {
    // struct ArrowArray* c_array = (struct ArrowArray*)PyCapsule_GetPointer(array_capsule, "arrow_array");
    // if (c_array->release != NULL) {
    //     c_array->release(c_array);
    // }
    // free(c_array);
}

void ReleaseArrowSchemaPyCapsule(PyObject* schema_capsule) {
    // struct ArrowSchema* c_schema = (struct ArrowSchema*)PyCapsule_GetPointer(schema_capsule, "arrow_schema");
    // if (c_schema->release != NULL) {
    //     c_schema->release(c_schema);
    // }
    // free(c_schema);
}

std::shared_ptr<arrow::Array> unpack_array(PyObject* array) {
  // call the method and get the tuple
  PyObject* array_capsule_tuple = PyObject_CallNoArgs(PyObject_GetAttrString(array, "__arrow_c_array__"));
  PyObject* schema_capsule_obj = PyTuple_GetItem(array_capsule_tuple, 0);
  PyObject* array_capsule_obj = PyTuple_GetItem(array_capsule_tuple, 1);

  // extract the capsule
  struct ArrowArray* c_array = (struct ArrowArray*) PyCapsule_GetPointer(array_capsule_obj, "arrow_array");

  // Convert C array to C++ array and extract info
  std::shared_ptr<arrow::Array> arrow_array = arrow::ImportArray(c_array, unpack_dtype(schema_capsule_obj)).ValueOrDie();
  return arrow_array;
}

PyObject* pack_array(std::shared_ptr<arrow::Array> array) {
  // Convert to C api
  struct ArrowArray* c_array = (struct ArrowArray*)malloc(sizeof(struct ArrowArray));
  struct ArrowSchema* c_schema = (struct ArrowSchema*)malloc(sizeof(struct ArrowSchema));
  (void)arrow::ExportArray(*array, c_array, c_schema);

  // Hoist out to pycapsule
  PyObject* array_capsule = PyCapsule_New(c_array, "arrow_array", ReleaseArrowArrayPyCapsule);
  PyObject* schema_capsule = PyCapsule_New(c_schema, "arrow_schema", ReleaseArrowSchemaPyCapsule);

  return PyTuple_Pack(2, schema_capsule, array_capsule);
}

std::shared_ptr<arrow::DataType> unpack_dtype(PyObject* dtype_capsule) {
  // extract the capsule
  struct ArrowSchema* c_dtype = (struct ArrowSchema*) PyCapsule_GetPointer(dtype_capsule, "arrow_schema");
  std::shared_ptr<arrow::DataType> arrow_dtype = arrow::ImportType(c_dtype).ValueOrDie();
  return arrow_dtype;
}

std::shared_ptr<arrow::Schema> unpack_schema(PyObject* schema) {
  // extract the capsule
  PyObject* schema_capsule = PyObject_CallNoArgs(PyObject_GetAttrString(schema, "__arrow_c_schema__"));
  struct ArrowSchema* c_schema = (struct ArrowSchema*) PyCapsule_GetPointer(schema_capsule, "arrow_schema");

  // Convert C schema to C++ schema and extract info
  std::shared_ptr<arrow::Schema> arrow_schema = arrow::ImportSchema(c_schema).ValueOrDie();
  return arrow_schema;
}

PyObject* pack_schema(std::shared_ptr<arrow::Schema> schema) {
  // Convert to C api
  struct ArrowSchema* c_schema = (struct ArrowSchema*)malloc(sizeof(struct ArrowSchema));
  (void)arrow::ExportSchema(*schema, c_schema);

  // Hoist out to pycapsule
  return PyCapsule_New(c_schema, "arrow_schema", ReleaseArrowSchemaPyCapsule);
}
