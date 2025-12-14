#include "mindseye/ledger/http/routes.hpp"
#include "mindseye/ledger/http/server.hpp"
#include "mindseye/ledger/http/handlers/health.hpp"
#include "mindseye/ledger/http/handlers/append.hpp"
#include "mindseye/ledger/http/handlers/latest.hpp"
#include "mindseye/ledger/http/handlers/blocks.hpp"
#include "mindseye/ledger/http/handlers/verify.hpp"
#include "mindseye/ledger/http/handlers/proof.hpp"

#include "httplib.h"

namespace mindseye::ledger::http {

void register_routes(httplib::Server& app, Server& srv) {
  app.Get("/healthz", [&](const httplib::Request& req, httplib::Response& res) {
    handlers::health(req, res);
  });

  app.Post("/v1/append", [&](const httplib::Request& req, httplib::Response& res) {
    handlers::append(req, res, srv.ledger(), srv.bus());
  });

  app.Get("/v1/latest", [&](const httplib::Request& req, httplib::Response& res) {
    handlers::latest(req, res, srv.ledger());
  });

  app.Get("/v1/blocks", [&](const httplib::Request& req, httplib::Response& res) {
    handlers::blocks(req, res, srv.ledger());
  });

  app.Get("/v1/verify", [&](const httplib::Request& req, httplib::Response& res) {
    handlers::verify(req, res, srv.ledger());
  });

  app.Get("/v1/proof", [&](const httplib::Request& req, httplib::Response& res) {
    handlers::proof(req, res, srv.ledger());
  });

  app.Get("/v1/stream", [&](const httplib::Request&, httplib::Response& res) {
    res.set_header("Content-Type", "text/event-stream");
    res.set_header("Cache-Control", "no-cache");
    res.set_header("Connection", "keep-alive");

    auto snap = srv.bus().snapshot();
    std::string out;
    for (const auto& msg : snap) out += msg;
    res.set_content(out, "text/event-stream");
  });
}

} // namespace mindseye::ledger::http
