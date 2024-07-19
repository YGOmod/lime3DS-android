// Copyright 2014 Citra Emulator Project
// Licensed under GPLv2 or any later version
// Refer to the license.txt file included.

#include "common/archives.h"
#include "core/hle/ipc_helpers.h"
#include "core/hle/service/nim/nim_aoc.h"

SERIALIZE_EXPORT_IMPL(Service::NIM::NIM_AOC)

namespace Service::NIM {

NIM_AOC::NIM_AOC() : ServiceFramework("nim:aoc", 2) {
    const FunctionInfo functions[] = {
        // clang-format off
        {0x0003, nullptr, "SetApplicationId"},
        {0x0004, nullptr, "SetTin"},
        {0x0009, nullptr, "ListContentSetsEx"},
        {0x0018, nullptr, "GetBalance"},
        {0x001D, nullptr, "GetCustomerSupportCode"},
        {0x0021, &NIM_AOC::Initialize, "Initialize"},
        {0x0024, nullptr, "CalculateContentsRequiredSize"},
        {0x0025, nullptr, "RefreshServerTime"},
        // clang-format on
    };
    RegisterHandlers(functions);
}

NIM_AOC::~NIM_AOC() = default;

void NIM_AOC::Initialize(Kernel::HLERequestContext& ctx) {
    IPC::RequestParser rp(ctx);

    IPC::RequestBuilder rb = rp.MakeBuilder(1, 0);
    rb.Push(ResultSuccess);

    LOG_WARNING(Service_NIM, "(STUBBED) called");
}

} // namespace Service::NIM