import os
import os.path
import pyarrow as pa
import pandas as pd
from .extension import schema_info, table_info, create_table


__version__ = "0.1.0"


def include_path():
    return os.path.abspath(os.path.join(os.path.dirname(__file__), "include"))


def bin_path():
    return os.path.abspath(os.path.join(os.path.dirname(__file__), "bin"))


def lib_path():
    return os.path.abspath(os.path.join(os.path.dirname(__file__), "lib"))


def create_arrow_table_in_python():
    df = pd.DataFrame({"a": [1, 2, 3], "b": [1.1, 2.2, 3.3], "c": ["abc", "def", "ghi"]})
    arrow_table = pa.Table.from_pandas(df)
    arrow_schema = pa.Schema.from_pandas(df)

    print(schema_info(arrow_schema))
    print(table_info(arrow_table))


def create_arrow_table_in_cpp():
    pa = create_table()
    df = pa.to_df()
    return df
