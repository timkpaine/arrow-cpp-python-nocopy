import os
import os.path
import multiprocessing
import sys
import sysconfig
from skbuild import setup

python_version = f"{sys.version_info.major}.{sys.version_info.minor}"
cmake_args = [f"-DPYTHON_VERSION={python_version}"]
vcpkg_config_file = os.path.abspath(os.path.join("vcpkg/scripts/buildsystems/vcpkg.cmake"))
cmake_args.extend(
    [
        "-DPython_ADDITIONAL_VERSIONS={}".format(python_version),
        "-DPython_FIND_VERSION={}".format(python_version),
        "-DPython_EXECUTABLE={}".format(sys.executable).replace("\\", "/"),
        "-DPYTHON_LIBRARY={}".format(sysconfig.get_config_var("LIBDIR")).replace("\\", "/"),
        "-DPYTHON_INCLUDE_DIR={}".format(sysconfig.get_config_var("INCLUDEPY")).replace("\\", "/"),
        "-DPython_ROOT_DIR={}".format(sys.prefix).replace("\\", "/"),
    ]
)

# if os.path.exists(vcpkg_config_file) and os.name != "posix":
#     cmake_args.append(f"-DCMAKE_TOOLCHAIN_FILE={vcpkg_config_file}")

if "DEBUG" in os.environ:
    cmake_args.append("-DCMAKE_BUILD_TYPE=Debug")

if "STATIC_PYTHON" in os.environ:
    cmake_args.append("-DSTATIC_PYTHON=On")

if "CMAKE_BUILD_PARALLEL_LEVEL" not in os.environ:
    os.environ["CMAKE_BUILD_PARALLEL_LEVEL"] = str(multiprocessing.cpu_count())

setup(
    name="arrow_python_nocopy",
    version="0.1.0",
    packages=["arrow_python_nocopy"],
    cmake_install_dir="arrow_python_nocopy",
    cmake_args=cmake_args,
)
