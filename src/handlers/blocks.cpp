#include "mindseye/ledger/http/handlers/blocks.hpp"
#include <string>

namespace mindseye::ledger::http::handlers {

void blocks(const httplib::Request&, httplib::Response& res, mindseye::ledger::Ledger& ledger) {
  auto all = ledger.read_all();
  std::string json = "{\"blocks\":[";
  for (size_t i = 0; i < all.size(); ++i) {
    const auto& b = all[i];
    json += "{\"block_id\":\"" + b.block_id + "\",\"hash\":\"" + b.block_hash_hex +
            "\",\"prev\":\"" + b.prev_hash + "\",\"ts_ms\":" + std::to_string(b.ts_ms) + "}";
    if (i + 1 < all.size()) json += ",";
  }
  json += "]}";
  res.set_content(json, "application/json");
}

}
