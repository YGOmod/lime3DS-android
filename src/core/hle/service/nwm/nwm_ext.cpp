// Copyright 2016 Citra Emulator Project
// Licensed under GPLv2 or any later version
// Refer to the license.txt file included.

#include "common/archives.h"
#include "core/hle/ipc_helpers.h"
#include "core/hle/service/nwm/nwm_ext.h"

SERIALIZE_EXPORT_IMPL(Service::NWM::NWM_EXT)

namespace Service::NWM {

NWM_EXT::NWM_EXT() : ServiceFramework("nwm::EXT") {
    static const FunctionInfo functions[] = {
        // clang-format off
        {0x0008, &NWM_EXT::ControlWirelessEnabled, "ControlWirelessEnabled"},
        // clang-format on
    };
    RegisterHandlers(functions);
}

void NWM_EXT::ControlWirelessEnabled(Kernel::HLERequestContext& ctx) {
    IPC::RequestParser rp(ctx);

    control_wireless_enabled = rp.Pop<bool>();

    IPC::RequestBuilder rb = rp.MakeBuilder(2, 0);
    rb.Push(ResultSuccess);
    rb.Push(control_wireless_enabled ? 0 : 1);

    LOG_DEBUG(Service_NWM, "(STUBBED) called. control_wireless_enabled = {}", control_wireless_enabled);
}

} // namespace Service::NWM
