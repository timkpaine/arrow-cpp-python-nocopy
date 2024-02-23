#include <apn-python/cpython.hpp>
#include <apn/apn.hpp>
#include <arrow/c/bridge.h>

static PyObject* _raise_error(PyObject* module) {
  PyErr_SetString(PyExc_TypeError, "Bad value provided");
  return NULL;
}

PyObject* array_info_py(PyObject* self, PyObject* args) {
  PyObject* source;

  if(!PyArg_ParseTuple(args, "O", &source))
    return _raise_error(self);

  // Old non-pycapsule way, not ABI stable
  // and relies on pyarrow
  // if(!arrow::py::is_array(source))
  //   return _raise_error(self);
  // arrow::Result<std::shared_ptr<arrow::Array>> result = arrow::py::unwrap_array(source);
  // if(!result.ok())
  //   return _raise_error(self);
  // char* ret_str = array_info_py(std::static_pointer_cast<arrow::Array>(result.ValueOrDie()));

  // New pycapsule way
  if(!PyObject_HasAttrString(source, "__arrow_c_array__"))
    return _raise_error(self);

  // extract the capsule
  PyObject* array_capsule = PyObject_CallNoArgs(PyObject_GetAttrString(source, "__arrow_c_array__"));
  struct ArrowArray* c_array = (struct ArrowArray*) PyCapsule_GetPointer(array_capsule, "arrow_array");

  // Convert C array to C++ array and extract info
  // TODO hardcoding datatype here, you would want to also pass in schema in real world
  std::shared_ptr<arrow::Array> arrow_array = arrow::ImportArray(c_array, arrow::int32()).ValueOrDie();

  // Get info and return
  std::string info = array_info(arrow_array);
  return PyUnicode_FromStringAndSize(info.c_str(), info.length());
}

void ReleaseArrowArrayPyCapsule(PyObject* array_capsule) {
    struct ArrowArray* c_array = (struct ArrowArray*)PyCapsule_GetPointer(array_capsule, "arrow_array");
    // if (c_array->release != NULL) {
    //     c_array->release(c_array);
    // }
    // free(c_array);
}

PyObject* create_array_py(PyObject* self, PyObject* args) {
  // Old non-pycapsule way
  // return arrow::py::wrap_array(create_array_py());

  // Create array with arrow C++
  std::shared_ptr<arrow::Array> array = create_array('a');

  // Convert to C api
  struct ArrowArray *c_array = (struct ArrowArray*)malloc(sizeof(struct ArrowArray));
  (void)arrow::ExportArray(*array, c_array);

  // Hoist out to pycapsule
  return PyCapsule_New(c_array, "arrow_array", ReleaseArrowArrayPyCapsule);
}

PyObject* schema_info_py(PyObject* self, PyObject* args) {
  PyObject* source;

  // parse arguments
  if(!PyArg_ParseTuple(args, "O", &source))
    return _raise_error(self);

  // Old non-pycapsule way, not ABI stable
  // and relies on pyarrow
  // if(!arrow::py::is_schema(source))
  //   return _raise_error(self);
  // if(!result.ok())
  //   return _raise_error(self);
  // arrow::Result<std::shared_ptr<arrow::Schema>> result = arrow::py::unwrap_schema(source);
  // char* ret_str = schema_info_py(std::static_pointer_cast<arrow::Schema>(result.ValueOrDie()));

  // New pycapsule way
  if(!PyObject_HasAttrString(source, "__arrow_c_schema__"))
    return _raise_error(self);

  // extract the capsule
  PyObject* schema_capsule = PyObject_CallNoArgs(PyObject_GetAttrString(source, "__arrow_c_schema__"));
  struct ArrowSchema* c_schema = (struct ArrowSchema*) PyCapsule_GetPointer(schema_capsule, "arrow_schema");

  // Convert C schema to C++ schema and extract info
  std::shared_ptr<arrow::Schema> arrow_schema = arrow::ImportSchema(c_schema).ValueOrDie();
  std::string info = schema_info(arrow_schema);
  return PyUnicode_FromStringAndSize(info.c_str(), info.length());
}

void ReleaseArrowSchemaPyCapsule(PyObject* schema_capsule) {
    struct ArrowSchema* c_schema = (struct ArrowSchema*)PyCapsule_GetPointer(schema_capsule, "arrow_schema");
    if (c_schema->release != NULL) {
        c_schema->release(c_schema);
    }
    // free(c_schema);
}

PyObject* create_schema_py(PyObject* self, PyObject* Py_UNUSED(args)) {
  // Old non-pycapsule way
  // return arrow::py::wrap_schema(create_schema_py());

  // Create array with arrow C++
  std::shared_ptr<arrow::Schema> schema = create_schema();

  // Convert to C api
  struct ArrowSchema* c_schema = (struct ArrowSchema*)malloc(sizeof(struct ArrowSchema));
  (void)arrow::ExportSchema(*schema, c_schema);

  // Hoist out to pycapsule
  return PyCapsule_New(c_schema, "arrow_schema", ReleaseArrowSchemaPyCapsule);
}

// std::string table_info_py_raw(PyObject* source) {
//     // TODO
//     arrow::Result<std::shared_ptr<arrow::Table>> result = arrow::py::unwrap_table(source);
//     return table_info_py(std::static_pointer_cast<arrow::Table>(result.ValueOrDie()));
// }

// PyObject* create_table_py_raw() {
//   return arrow::py::wrap_table(create_table_py());
// }
