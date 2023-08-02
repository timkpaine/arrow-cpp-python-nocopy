# Find Arrow
# This module defines:
# Arrow_INCLUDE_DIR
# Arrow_LIBRARY
# Arrow_LIB_DIR

find_path(Arrow_INCLUDE_DIR arrow/config.h
  PATHS ${Arrow_ROOT}/include
  HINTS /usr /usr/include /usr/local /usr/local/include /usr/local/Homebrew /usr/local/Homebrew/include  ~/homebrew ~/homebrew/include /opt/homebrew /opt/homebrew/include
  NO_CMAKE_SYSTEM_PATH
  NO_SYSTEM_ENVIRONMENT_PATH)

find_path(Arrow_LIB_DIR
  NAMES libarrow.a arrow.a libarrow.so arrow.so libarrow.dylib arrow.dylib
  PATHS ${Arrow_ROOT}/lib
  HINTS /usr /usr/lib /usr/local /usr/local/lib /usr/local/Homebrew /usr/local/Homebrew/lib ~/homebrew/ ~/homebrew/lib /opt/homebrew/ /opt/homebrew/lib
  NO_CMAKE_SYSTEM_PATH
  NO_SYSTEM_ENVIRONMENT_PATH)

if(BUILD_SHARED_LIBS)
  find_file(Arrow_LIBRARY
    NAMES libarrow.so arrow.so libarrow.dylib arrow.dylib
    PATHS ${Arrow_ROOT}
    HINTS /usr /usr/lib /usr/local /usr/local/lib /usr/local/Homebrew /usr/local/Homebrew/lib ~/homebrew/ ~/homebrew/lib /opt/homebrew/ /opt/homebrew/lib
    NO_CMAKE_SYSTEM_PATH
    NO_SYSTEM_ENVIRONMENT_PATH)
else()
  find_file(Arrow_LIBRARY
    NAMES libarrow.a arrow.a
    PATHS ${Arrow_ROOT}
    HINTS /usr /usr/lib /usr/local /usr/local/lib /usr/local/Homebrew /usr/local/Homebrew/lib ~/homebrew/ ~/homebrew/lib /opt/homebrew/ /opt/homebrew/lib
    NO_CMAKE_SYSTEM_PATH
    NO_SYSTEM_ENVIRONMENT_PATH)
endif()

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(Arrow REQUIRED_VARS Arrow_INCLUDE_DIR Arrow_LIB_DIR Arrow_LIBRARY)
