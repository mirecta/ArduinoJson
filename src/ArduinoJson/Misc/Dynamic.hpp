// ArduinoJson - https://arduinojson.org
// Copyright © 2014-2022, Benoit BLANCHON
// MIT License

#pragma once

#include <functional>
#include <ArduinoJson/Serialization/CountingDecorator.hpp>


namespace ARDUINOJSON_NAMESPACE {


class Dynamic {
  public:
    
    typedef std::function<void (const char* s, size_t n)> WriteFunc;

    virtual size_t writeJson(WriteFunc writer){};
};
};  // namespace ARDUINOJSON_NAMESPACE
