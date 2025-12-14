#include "mindseye/ledger/http/server.hpp"
#include <cstdlib>

int main() {
  int port = 8081;
  if (const char* p = std::getenv("PORT")) port = std::atoi(p);

  mindseye::ledger::http::ServiceConfig cfg;
  mindseye::ledger::http::Server srv(cfg);
  srv.run(port);
  return 0;
}
