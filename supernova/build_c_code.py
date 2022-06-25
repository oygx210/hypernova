from cffi import FFI

ffibuilder = FFI()

ffibuilder.cdef("""
    double dot(double u[3], double v[3]);
""")


ffibuilder.set_source('supernova.supernova_c',  # name of the output C extension
                      '#include "vector_operations.h"',
                      include_dirs=["supernova/src/vector_math"],
                      sources=['supernova/src/vector_math/vector_operations.c'])
# TODO: link math library on unix based systems

if __name__ == "__main__":
    ffibuilder.compile(verbose=True)
