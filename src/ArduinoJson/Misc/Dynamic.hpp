// ArduinoJson - https://arduinojson.org
// Copyright © 2014-2022, Benoit BLANCHON
// MIT License

#pragma once

#include <ArduinoJson/Serialization/CountingDecorator.hpp>

namespace ARDUINOJSON_NAMESPACE {


class Dynamic {
  public:
    typedef void (*writeFunc)(const char* s, size_t n);

    virtual size_t writeJson(writeFunc writer) = 0;
};
};  // namespace ARDUINOJSON_NAMESPACE
