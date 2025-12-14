#include "mindseye/ledger/http/server.hpp"
#include "mindseye/ledger/http/routes.hpp"
#include "mindseye/ledger/storage.hpp"

#include "httplib.h"
#include <iostream>

namespace mindseye::ledger::http {

Server::Server(ServiceConfig cfg) : cfg_(std::move(cfg)) {
  storage_ = std::make_shared<mindseye::ledger::FileStorage>(cfg_.storage_path);
  ledger_ = std::make_unique<mindseye::ledger::Ledger>(storage_);
}

SSEBus& Server::bus() { return bus_; }
mindseye::ledger::Ledger& Server::ledger() { return *ledger_; }

void Server::run(int port) {
  httplib::Server app;
  register_routes(app, *this);

  std::cout << "[mindseye-ledger-http] listening on :" << port << "\n";
  app.listen("0.0.0.0", port);
}

} // namespace mindseye::ledger::http
