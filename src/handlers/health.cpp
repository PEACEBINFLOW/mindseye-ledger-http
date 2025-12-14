#include "mindseye/ledger/http/handlers/health.hpp"

namespace mindseye::ledger::http::handlers {

void health(const httplib::Request&, httplib::Response& res) {
  res.set_content("{\"ok\":true}", "application/json");
}

}
