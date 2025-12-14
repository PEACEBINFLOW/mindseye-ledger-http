#include "mindseye/ledger/http/handlers/latest.hpp"

namespace mindseye::ledger::http::handlers {

void latest(const httplib::Request&, httplib::Response& res, mindseye::ledger::Ledger& ledger) {
  auto blocks = ledger.read_all();
  if (blocks.empty()) {
    res.set_content("{\"latest\":null}", "application/json");
    return;
  }
  const auto& b = blocks.back();
  res.set_content(
    "{\"block_id\":\"" + b.block_id + "\",\"hash\":\"" + b.block_hash_hex + "\",\"prev\":\"" + b.prev_hash +
    "\",\"merkle\":\"" + b.merkle_root_hex + "\",\"ts_ms\":" + std::to_string(b.ts_ms) + "}",
    "application/json"
  );
}

}
