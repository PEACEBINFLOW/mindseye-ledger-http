FROM ubuntu:24.04

RUN apt-get update && apt-get install -y \
  build-essential cmake git ca-certificates \
  && rm -rf /var/lib/apt/lists/*

WORKDIR /app
COPY . /app

RUN mkdir -p build && cd build && cmake .. && cmake --build . -j

ENV PORT=8081
EXPOSE 8081
CMD ["./build/mindseye_ledger_http"]
