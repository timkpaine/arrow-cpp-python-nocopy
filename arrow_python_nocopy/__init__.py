import os
import os.path
import pyarrow as pa
import pandas as pd
from .lib.pybind11extension import array_info, create_array
from .lib.pybind11extension import schema_info, create_schema
from .lib.cpythonextension import array_info as array_info_cp, create_array as create_array_cp
from .lib.cpythonextension import schema_info as schema_info_cp, create_schema as create_schema_cp


__version__ = "0.1.0"


def _df():
    return pd.DataFrame({"a": pd.Series([1, 2, 3], dtype='Int32'), "b": pd.Series([1.1, 2.2, 3.3], dtype='Float32'), "c": pd.Series(["abc", "def", "ghi"], dtype=str)})


def _table():
    return pa.Table.from_pandas(_df())


def create_arrow_array_in_python():
    table = _table()
    array = table['a'].combine_chunks()
    return array_info(array)


def create_arrow_array_in_cpp():
    return pa.Array._import_from_c_capsule(*create_array())


def create_arrow_schema_in_python():
    table = _table()
    schema = table.schema
    return schema_info(schema)


def create_arrow_schema_in_cpp():
    return pa.Schema._import_from_c_capsule(create_schema())

# def create_arrow_table_in_python():
#     table = _table()
#     print(table_info(table))


# def create_arrow_table_in_cpp():
#     return create_table()
