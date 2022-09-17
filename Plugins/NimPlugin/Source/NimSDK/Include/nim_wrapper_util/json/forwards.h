// Copyright 2007-2010 Baptiste Lepilleur and The JsonCpp Authors
// Distributed under MIT license, or public domain if desired and
// recognized in your jurisdiction.
// See file LICENSE for detail or copy at http://jsoncpp.sourceforge.net/LICENSE

#ifndef NIM_CPP_WRAPPER_UTIL_JSON_FORWARDS_H_INCLUDED
#define NIM_CPP_WRAPPER_UTIL_JSON_FORWARDS_H_INCLUDED

#if !defined(JSON_IS_AMALGAMATION)
#include "config.h"
#endif  // if !defined(JSON_IS_AMALGAMATION)

namespace nim_cpp_wrapper_util {
namespace Json {

// writer.h
class StreamWriter;
class StreamWriterBuilder;
class Writer;
class FastWriter;
class StyledWriter;
class StyledStreamWriter;

// reader.h
class Reader;
class CharReader;
class CharReaderBuilder;

// json_features.h
class Features;

// value.h
using ArrayIndex = unsigned int;
class StaticString;
class Path;
class PathArgument;
class Value;
class ValueIteratorBase;
class ValueIterator;
class ValueConstIterator;

}  // namespace Json
}  // namespace nim_cpp_wrapper_util

#endif  // JSON_FORWARDS_H_INCLUDED
