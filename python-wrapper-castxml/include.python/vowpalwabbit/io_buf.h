#pragma once
#ifndef _WIN32
#include <sys/types.h>
#include <unistd.h>
#endif
#include <stdio.h>
#include <fcntl.h>
#include "v_array.h"
#include<iostream>
#include <errno.h>
using namespace std;
#ifndef O_LARGEFILE
#define O_LARGEFILE 0
#endif
#ifdef _WIN32
#define ssize_t size_t
#include <io.h>
#include <sys/stat.h>
#endif
class io_buf
{
public:
v_array<char> space;
v_array<int> files;
size_t count;
size_t current;
char* endloaded;
v_array<char> currentname;
v_array<char> finalname;
static const int READ = 1;
static const int WRITE = 2;
void init();
virtual int open_file(const char* name, bool stdin_off, int flag=READ);
virtual void reset_file(int f);
io_buf();
virtual ~io_buf();
void set(char *p);
virtual ssize_t read_file(int f, void* buf, size_t nbytes);
static ssize_t read_file_or_socket(int f, void* buf, size_t nbytes);
size_t fill(int f);
virtual ssize_t write_file(int f, const void* buf, size_t nbytes);
static ssize_t write_file_or_socket(int f, const void* buf, size_t nbytes);
virtual void flush();
virtual bool close_file();
static void close_file_or_socket(int f);
void close_files();
static bool is_socket(int f);
};
void buf_write(io_buf &o, char* &pointer, size_t n);
size_t buf_read(io_buf &i, char* &pointer, size_t n);
bool isbinary(io_buf &i);
size_t readto(io_buf &i, char* &pointer, char terminal);
inline size_t bin_read_fixed(io_buf& i, char* data, size_t len, const char* read_message);
inline size_t bin_read(io_buf& i, char* data, size_t len, const char* read_message);
inline size_t bin_write_fixed(io_buf& o, const char* data, uint32_t len);
inline size_t bin_write(io_buf& o, const char* data, uint32_t len);
inline size_t bin_text_write(io_buf& io, char* data, uint32_t len,
const char* text_data, uint32_t text_len, bool text);
inline size_t bin_text_read_write(io_buf& io, char* data, uint32_t len,
const char* read_message, bool read,
const char* text_data, uint32_t text_len, bool text);
inline size_t bin_text_write_fixed(io_buf& io, char* data, uint32_t len,
const char* text_data, uint32_t text_len, bool text);
inline size_t bin_text_read_write_fixed(io_buf& io, char* data, uint32_t len,
const char* read_message, bool read,
const char* text_data, uint32_t text_len, bool text);
