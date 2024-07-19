// Copyright 2016 Citra Emulator Project
// Licensed under GPLv2 or any later version
// Refer to the license.txt file included.

#pragma once

#include "core/hle/service/service.h"

namespace Service::NWM {

class NWM_EXT final : public ServiceFramework<NWM_EXT> {
public:
    NWM_EXT();
    ~NWM_EXT();

private:
    void ControlWirelessEnabled(Kernel::HLERequestContext& ctx);
    
    bool control_wireless_enabled = true;
    
    SERVICE_SERIALIZATION_SIMPLE
};

} // namespace Service::NWM

BOOST_CLASS_EXPORT_KEY(Service::NWM::NWM_EXT)
