#pragma once
#include "httplib.h"

namespace mindseye::ledger::http::handlers {
void health(const httplib::Request& req, httplib::Response& res);
}
