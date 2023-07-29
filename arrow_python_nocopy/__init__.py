import os
import os.path
import pyarrow as pa
import pandas as pd
from .pybind11extension import array_info, create_array
from .pybind11extension import schema_info, create_schema
# from .pybind11extension import table_info, create_table


__version__ = "0.1.0"


def include_path():
    return os.path.abspath(os.path.join(os.path.dirname(__file__), "include"))


def bin_path():
    return os.path.abspath(os.path.join(os.path.dirname(__file__), "bin"))


def lib_path():
    return os.path.abspath(os.path.join(os.path.dirname(__file__), "lib"))

def _df():
    return pd.DataFrame({"a": [1, 2, 3], "b": [1.1, 2.2, 3.3], "c": ["abc", "def", "ghi"]})

def _table():
    return pa.Table.from_pandas(_df())

def create_arrow_array_in_python():
    table = _table()
    array = table.columns['a']
    print(array_info(array))

def create_arrow_array_in_cpp():
    return create_array()


def create_arrow_schema_in_python():
    table = _table()
    schema = table.schema
    print(schema_info(schema))

def create_arrow_schema_in_cpp():
    return create_schema()


# def create_arrow_table_in_python():
#     table = _table()
#     print(table_info(table))


# def create_arrow_table_in_cpp():
#     return create_table()
