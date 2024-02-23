#include <apn-python/cpython.h>
#include <apn-python/common.h>
#include <apn/apn.h>
#include <arrow/c/bridge.h>

static PyObject* _raise_error(PyObject* module, const std::string& msg = "Bad value provided") {
  PyErr_SetString(PyExc_TypeError, msg.c_str());
  return NULL;
}

PyObject* array_info_py(PyObject* self, PyObject* args) {
  PyObject* array;

  if(!PyArg_ParseTuple(args, "O", &array))
    return _raise_error(self, "Bad arguments to array_info");

  if(!PyObject_HasAttrString(array, "__arrow_c_array__"))
    return _raise_error(self, "Argument to array_info not an array");

  // unpack
  std::shared_ptr<arrow::Array> arrow_array = unpack_array(array);

  // Get info and return
  std::string info = array_info(arrow_array);
  return PyUnicode_FromStringAndSize(info.c_str(), info.length());
}


PyObject* create_array_py(PyObject* self, PyObject* args) {
  // Create array with arrow C++
  std::shared_ptr<arrow::Array> array = create_array('a');
  return pack_array(array);
}

PyObject* schema_info_py(PyObject* self, PyObject* args) {
  PyObject* schema;

  // parse arguments
  if(!PyArg_ParseTuple(args, "O", &schema))
    return _raise_error(self, "Bad arguments to schema_info");

  if(!PyObject_HasAttrString(schema, "__arrow_c_schema__"))
    return _raise_error(self, "First argument to schema_info not a schema");

  // unpack
  std::shared_ptr<arrow::Schema> arrow_schema = unpack_schema(schema);

  // Get info and return
  std::string info = schema_info(arrow_schema);
  return PyUnicode_FromStringAndSize(info.c_str(), info.length());
}


PyObject* create_schema_py(PyObject* self, PyObject* Py_UNUSED(args)) {
  // Create array with arrow C++
  std::shared_ptr<arrow::Schema> schema = create_schema();
  return pack_schema(schema);
}

// std::string table_info_py_raw(PyObject* source) {
//     // TODO
//     arrow::Result<std::shared_ptr<arrow::Table>> result = arrow::py::unwrap_table(source);
//     return table_info_py(std::static_pointer_cast<arrow::Table>(result.ValueOrDie()));
// }

// PyObject* create_table_py_raw() {
//   return arrow::py::wrap_table(create_table_py());
// }
