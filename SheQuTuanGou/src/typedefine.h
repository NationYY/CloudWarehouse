#pragma once
#include <string>
#include <map>
#include <set>
#include "BasicExcel.hpp"
using namespace YCompoundFiles;
using namespace YExcel;
using namespace std;

#define DOUBLE_PRECISION 0.00000001
typedef std::map<std::wstring, int> map_key_wstring_val_int;
typedef std::vector<std::wstring> vec_wvals;
typedef std::vector<std::wstring> split_wstr_vec;