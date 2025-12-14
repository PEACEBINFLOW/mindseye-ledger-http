# MindsEye Ledger HTTP

`mindseye-ledger-http` exposes the MindsEye ledger over REST + SSE.

This repository is **transport**, not integrity.

Integrity and verification are implemented in `mindseye-ledger-core`.

---

## Purpose

MindsEye systems need to:
- append ledger entries (from gateways/executors)
- query blocks for replay
- verify integrity on demand
- stream new blocks to UI/renderers

This service provides those surfaces.

---

## Submodules (Mandatory)

```text
external/
├─ mindseye-ledger-core
└─ mindseye-protocol
Add them:

https://github.com/PEACEBINFLOW/mindseye-protocol/tree/main
https://github.com/PEACEBINFLOW/mindscript-runtime-c/tree/main
https://github.com/PEACEBINFLOW/mindscript-google-executor/tree/main
https://github.com/PEACEBINFLOW/mindseye-google-gateway/tree/main
https://github.com/PEACEBINFLOW/mindseye-google-auth/tree/main
https://github.com/PEACEBINFLOW/mindseye-ledger-core/tree/main

