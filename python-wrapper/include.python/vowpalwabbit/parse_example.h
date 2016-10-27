#pragma once
#include <stdint.h>
#include "parse_regressor.h"
#include "parse_primitives.h"
#include "parser.h"
#include "example.h"
int read_features(void* a, example* ex);
void read_line(vw& all, example* ex, char* line);
size_t hashstring (substring s, uint32_t h);
hash_func_t getHasher(const std::string& s);
