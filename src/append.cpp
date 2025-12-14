#include "mindseye/ledger/http/handlers/append.hpp"

#include <chrono>

static int64_t now_ms() {
  using namespace std::chrono;
  return duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
}

namespace mindseye::ledger::http::handlers {

void append(const httplib::Request& req, httplib::Response& res, mindseye::ledger::Ledger& ledger, SSEBus& bus) {
  // For now: treat body as a single opaque entry (bytes).
  // Next upgrade repo can accept JSON with base64 entries.
  std::vector<std::vector<uint8_t>> entries;
  entries.emplace_back(req.body.begin(), req.body.end());

  auto block = ledger.append_block(std::move(entries), now_ms());
  bus.publish("ledger.block", "{\"block_id\":\"" + block.block_id + "\",\"hash\":\"" + block.block_hash_hex + "\"}");

  res.set_content(
    "{\"ok\":true,\"block_id\":\"" + block.block_id + "\",\"hash\":\"" + block.block_hash_hex + "\"}",
    "application/json"
  );
}

}
