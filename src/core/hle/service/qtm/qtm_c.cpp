// Copyright 2016 Citra Emulator Project
// Licensed under GPLv2 or any later version
// Refer to the license.txt file included.

#include "common/archives.h"
#include "core/hle/ipc_helpers.h"
#include "core/hle/service/qtm/qtm_c.h"

SERIALIZE_EXPORT_IMPL(Service::QTM::QTM_C)

namespace Service::QTM {

QTM_C::QTM_C() : ServiceFramework("qtm:c", 2) {
    static const FunctionInfo functions[] = {
        // qtm calibration commands
        // clang-format off
        {0x0001, nullptr, "StartHardwareCheck"},
        {0x0002, nullptr, "StopHardwareCheck"},
        {0x0003, nullptr, "SetBarrierPattern"},
        {0x0004, nullptr, "WaitAndCheckExpanderWorking"},
        {0x0005, nullptr, "SetIrLedStatusOverride"},
        // clang-format on
    };

    RegisterHandlers(functions);
};

} // namespace Service::QTM
