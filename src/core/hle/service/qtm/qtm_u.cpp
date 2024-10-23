// Copyright 2016 Citra Emulator Project
// Licensed under GPLv2 or any later version
// Refer to the license.txt file included.

#include "common/archives.h"
#include "core/hle/ipc_helpers.h"
#include "core/hle/service/qtm/qtm_u.h"

SERIALIZE_EXPORT_IMPL(Service::QTM::QTM_U)

namespace Service::QTM {

QTM_U::QTM_U() : ServiceFramework("qtm:u", 2) {
    static const FunctionInfo functions[] = {
        // qtm common commands
        // clang-format off
        {0x0001, nullptr, "GetRawTrackingDataEx"},
        {0x0002, nullptr, "GetTrackingDataEx"},
        {0x0003, nullptr, "EnableManualIrLedControl"},
        {0x0004, nullptr, "DisableManualIrLedControl"},
        {0x0005, nullptr, "SetIrLedStatus"},
        {0x0006, nullptr, "IsCurrentAppBlacklisted"},
        // clang-format on
    };

    RegisterHandlers(functions);
}

} // namespace Service::QTM
