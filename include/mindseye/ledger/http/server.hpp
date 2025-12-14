#pragma once
#include "mindseye/ledger/http/types.hpp"
#include "mindseye/ledger/http/sse_bus.hpp"
#include "mindseye/ledger/ledger.hpp"
#include <memory>

namespace mindseye::ledger::http {

class Server {
public:
  explicit Server(ServiceConfig cfg);
  void run(int port);

  SSEBus& bus();
  mindseye::ledger::Ledger& ledger();

private:
  ServiceConfig cfg_;
  SSEBus bus_;
  std::shared_ptr<mindseye::ledger::IStorage> storage_;
  std::unique_ptr<mindseye::ledger::Ledger> ledger_;
};

} // namespace mindseye::ledger::http
