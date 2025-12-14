#pragma once
namespace httplib { class Server; }

namespace mindseye::ledger::http {
class Server;
void register_routes(httplib::Server& app, Server& srv);
} // namespace mindseye::ledger::http
