// Copyright 2016 Citra Emulator Project
// Licensed under GPLv2 or any later version
// Refer to the license.txt file included.

#pragma once

#include "core/hle/service/service.h"

namespace Service::DLP {

class DLP_SRVR final : public ServiceFramework<DLP_SRVR> {
public:
    DLP_SRVR();
    ~DLP_SRVR() = default;

private:
    void Finalize(Kernel::HLERequestContext& ctx);
    void GetServerState(Kernel::HLERequestContext& ctx);
    void AcceptClient(Kernel::HLERequestContext& ctx);
    void DisconnectClient(Kernel::HLERequestContext& ctx);
    void IsChild(Kernel::HLERequestContext& ctx);

    SERVICE_SERIALIZATION_SIMPLE
};

} // namespace Service::DLP

BOOST_CLASS_EXPORT_KEY(Service::DLP::DLP_SRVR)
