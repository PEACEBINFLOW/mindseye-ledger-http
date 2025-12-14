#pragma once
#include "httplib.h"
#include "mindseye/ledger/ledger.hpp"

namespace mindseye::ledger::http::handlers {
void verify(const httplib::Request& req, httplib::Response& res, mindseye::ledger::Ledger& ledger);
}
