// Copyright 2024 Citra Emulator Project
// Licensed under GPLv2 or any later version
// Refer to the license.txt file included.

#include "common/archives.h"
#include "core/hle/service/nim/nim_ndm.h"

SERIALIZE_EXPORT_IMPL(Service::NIM::NIM_NDM)

namespace Service::NIM {

NIM_NDM::NIM_NDM() : ServiceFramework("nim:ndm", 1) {
    const FunctionInfo functions[] = {
        // clang-format off
        {0x0001, nullptr, "GetDaemonEventHandle"},
        {0x0002, nullptr, "Unknown02"}, // always returns 0
        {0x0003, nullptr, "SetDaemonToWorkingState"},
        {0x0004, nullptr, "SetDaemonToSuspendedState"},
        {0x0005, nullptr, "GetDaemonState"},
        // clang-format on
    };
    RegisterHandlers(functions);
}

NIM_NDM::~NIM_NDM() = default;

} // namespace Service::NIM
