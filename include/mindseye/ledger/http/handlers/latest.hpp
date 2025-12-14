#pragma once
#include "httplib.h"
#include "mindseye/ledger/ledger.hpp"

namespace mindseye::ledger::http::handlers {
void latest(const httplib::Request& req, httplib::Response& res, mindseye::ledger::Ledger& ledger);
}
