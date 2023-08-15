#include <stddef.h>
size_t rounddown(size_t foo,size_t val){return(foo/val)*val;}
size_t roundup(size_t foo,size_t val){return((foo/val)*val)+val;}
