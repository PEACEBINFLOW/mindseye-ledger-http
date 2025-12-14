#include "mindseye/ledger/http/handlers/verify.hpp"

namespace mindseye::ledger::http::handlers {

void verify(const httplib::Request&, httplib::Response& res, mindseye::ledger::Ledger& ledger) {
  std::string err;
  bool ok = ledger.verify_chain(&err);
  if (ok) {
    res.set_content("{\"ok\":true}", "application/json");
  } else {
    res.status = 409;
    res.set_content("{\"ok\":false,\"error\":\"" + err + "\"}", "application/json");
  }
}

}
