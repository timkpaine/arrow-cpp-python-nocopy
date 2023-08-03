# Find Thrift
# This module defines:
# Thrift_INCLUDE_DIR
# Thrift_LIBRARY
# Thrift_LIB_DIR

find_path(Thrift_INCLUDE_DIR thrift/Thrift.h
  PATHS ${Thrift_ROOT}/include
  HINTS /usr /usr/include /usr/local /usr/local/include /usr/local/Homebrew /usr/local/Homebrew/include  ~/homebrew ~/homebrew/include /opt/homebrew /opt/homebrew/include
  NO_CMAKE_SYSTEM_PATH
  NO_SYSTEM_ENVIRONMENT_PATH)

find_path(Thrift_LIB_DIR
  NAMES libthrift.a libthrift.so libthrift.dylib
  PATHS ${Thrift_ROOT}/lib
  HINTS /usr /usr/lib /usr/local /usr/local/lib /usr/local/Homebrew /usr/local/Homebrew/lib ~/homebrew/ ~/homebrew/lib /opt/homebrew/ /opt/homebrew/lib
  NO_CMAKE_SYSTEM_PATH
  NO_SYSTEM_ENVIRONMENT_PATH)

if(BUILD_SHARED_LIBS)
  find_file(Thrift_LIBRARY
    NAMES libthrift.so thrift.so libthrift.dylib thrift.dylib
    PATHS ${Thrift_ROOT}
    HINTS /usr /usr/lib /usr/local /usr/local/lib /usr/local/Homebrew /usr/local/Homebrew/lib ~/homebrew/ ~/homebrew/lib /opt/homebrew/ /opt/homebrew/lib
    NO_CMAKE_SYSTEM_PATH
    NO_SYSTEM_ENVIRONMENT_PATH)
else()
  find_file(Thrift_LIBRARY
    NAMES libthrift.a thrift.a
    PATHS ${Thrift_ROOT}
    HINTS /usr /usr/lib /usr/local /usr/local/lib /usr/local/Homebrew /usr/local/Homebrew/lib ~/homebrew/ ~/homebrew/lib /opt/homebrew/ /opt/homebrew/lib
    NO_CMAKE_SYSTEM_PATH
    NO_SYSTEM_ENVIRONMENT_PATH)
endif()

# For apache arrow
set(ThriftAlt_LIB ${Thrift_LIBRARY})

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(Thrift REQUIRED_VARS Thrift_INCLUDE_DIR Thrift_LIB_DIR Thrift_LIBRARY)
