#pragma once
#include "httplib.h"
#include "mindseye/ledger/ledger.hpp"
#include "mindseye/ledger/http/sse_bus.hpp"

namespace mindseye::ledger::http::handlers {
void append(const httplib::Request& req, httplib::Response& res, mindseye::ledger::Ledger& ledger, SSEBus& bus);
}
