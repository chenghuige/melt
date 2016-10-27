#pragma once
#include "io_buf.h"
#include "v_array.h"
#include "zlib.h"
#include <stdio.h>
class comp_io_buf : public io_buf
{
public:
v_array<gzFile> gz_files;
comp_io_buf();
virtual int open_file(const char* name, bool stdin_off, int flag=READ);
virtual void reset_file(int f);
virtual ssize_t read_file(int f, void* buf, size_t nbytes);
virtual inline ssize_t write_file(int f, const void* buf, size_t nbytes);
virtual void flush();
virtual bool close_file();
};
