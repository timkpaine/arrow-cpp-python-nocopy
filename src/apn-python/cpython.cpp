#include <apn-python/cpython.hpp>

static PyObject* _raise_error(PyObject* module) {
  PyErr_SetString(PyExc_TypeError, "Bad value provided");
  return NULL;
}

PyObject* array_info_py_raw(PyObject* self, PyObject* args) {
  PyObject* source;

  if(!PyArg_ParseTuple(args, "O", &source))
    return _raise_error(self);

  if(!arrow::py::is_array(source))
    return _raise_error(self);

  arrow::Result<std::shared_ptr<arrow::Array>> result = arrow::py::unwrap_array(source);

  if(!result.ok())
    return _raise_error(self);

  char* ret_str = array_info_py(std::static_pointer_cast<arrow::Array>(result.ValueOrDie()));
  return PyUnicode_FromStringAndSize(ret_str, strlen(ret_str));
}

PyObject* create_array_py_raw(PyObject* self, PyObject* args) {
  return arrow::py::wrap_array(create_array_py());
}

PyObject* schema_info_py_raw(PyObject* self, PyObject* args) {
  PyObject* source;

  // parse arguments
  if(!PyArg_ParseTuple(args, "O", &source))
    return _raise_error(self);

  if(!arrow::py::is_schema(source))
    return _raise_error(self);

  arrow::Result<std::shared_ptr<arrow::Schema>> result = arrow::py::unwrap_schema(source);

  if(!result.ok())
    return _raise_error(self);

  char* ret_str = schema_info_py(std::static_pointer_cast<arrow::Schema>(result.ValueOrDie()));
  return PyUnicode_FromStringAndSize(ret_str, strlen(ret_str));
}

PyObject* create_schema_py_raw(PyObject* self, PyObject* Py_UNUSED(args)) {
  return arrow::py::wrap_schema(create_schema_py());
}

// std::string table_info_py_raw(PyObject* source) {
//     // TODO
//     arrow::Result<std::shared_ptr<arrow::Table>> result = arrow::py::unwrap_table(source);
//     return table_info_py(std::static_pointer_cast<arrow::Table>(result.ValueOrDie()));
// }

// PyObject* create_table_py_raw() {
//   return arrow::py::wrap_table(create_table_py());
// }
