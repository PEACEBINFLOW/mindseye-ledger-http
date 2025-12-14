#include "mindseye/ledger/http/handlers/proof.hpp"

namespace mindseye::ledger::http::handlers {

void proof(const httplib::Request& req, httplib::Response& res, mindseye::ledger::Ledger& ledger) {
  auto block_id = req.get_param_value("block_id");
  if (block_id.empty()) {
    res.status = 400;
    res.set_content("{\"error\":\"block_id_required\"}", "application/json");
    return;
  }

  auto all = ledger.read_all();
  for (const auto& b : all) {
    if (b.block_id == block_id) {
      // Stub: returns merkle root but not path proof yet.
      // Next repo upgrades: merkle path, index, and verification helper.
      res.set_content(
        "{\"block_id\":\"" + b.block_id + "\",\"merkle_root\":\"" + b.merkle_root_hex + "\",\"proof\":null}",
        "application/json"
      );
      return;
    }
  }

  res.status = 404;
  res.set_content("{\"error\":\"not_found\"}", "application/json");
}

}
