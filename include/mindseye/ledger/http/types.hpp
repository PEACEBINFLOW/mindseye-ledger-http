#pragma once
#include <string>

namespace mindseye::ledger::http {

struct ServiceConfig {
  std::string storage_path = "ledger.data";
};

} // namespace mindseye::ledger::http
