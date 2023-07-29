# Demo of C++<->Python for Apache Arrow
This is a small example of building a C++ library which reads and returns arrays and schemas linked against `libarrow` (but **DOES NOT REQUIRE** `pyarrow`), and building a python extension that uses this library to pass arrays and schemas back and forth.

## tl;dr
This utilizes Apache Arrow's **ABI-stable C interface**, which would, for example, allow your combined C++/python extension to compile and link against one version of arrow and be utilized with `pyarrow` which would otherwise be ABI-incompatible.
