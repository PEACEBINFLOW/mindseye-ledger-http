#pragma once
#include <mutex>
#include <string>
#include <vector>

namespace mindseye::ledger::http {

class SSEBus {
public:
  void publish(const std::string& event, const std::string& data);
  std::vector<std::string> snapshot() const;

private:
  mutable std::mutex mu_;
  std::vector<std::string> buffer_;
};

} // namespace mindseye::ledger::http
