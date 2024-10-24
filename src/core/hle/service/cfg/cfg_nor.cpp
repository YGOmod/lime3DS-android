// Copyright 2016 Citra Emulator Project
// Licensed under GPLv2 or any later version
// Refer to the license.txt file included.

#include "common/archives.h"
#include "core/hle/ipc_helpers.h"
#include "core/hle/service/cfg/cfg_nor.h"

SERIALIZE_EXPORT_IMPL(Service::CFG::CFG_NOR)

namespace Service::CFG {

CFG_NOR::CFG_NOR() : ServiceFramework("cfg:nor", 23) {
    static const FunctionInfo functions[] = {
        // clang-format off
        {0x0001, &CFG_NOR::Initialize, "Initialize"},
        {0x0002, &CFG_NOR::Shutdown, "Shutdown"},
        {0x0005, nullptr, "ReadData"},
        {0x0006, nullptr, "WriteData"},
        {0x0009, nullptr, "ReadIdentification"},
        {0x000E, nullptr, "ReadStatusRegister"},
        {0x000F, nullptr, "ReadDataOther"},
        {0x0010, nullptr, "WriteDataOther"},
        // clang-format on
    };
    RegisterHandlers(functions);
}

void CFG_NOR::Initialize(Kernel::HLERequestContext& ctx) {
    IPC::RequestParser rp(ctx);
    const u8 value = rp.Pop<u8>();

    LOG_WARNING(Service_CFG, "(STUBBED) called, value={}", value);

    IPC::RequestBuilder rb = rp.MakeBuilder(1, 0);
    rb.Push(ResultSuccess);
}

void CFG_NOR::Shutdown(Kernel::HLERequestContext& ctx) {
    IPC::RequestParser rp(ctx);

    IPC::RequestBuilder rb = rp.MakeBuilder(1, 0);
    rb.Push(ResultSuccess);

    LOG_WARNING(Service_CFG, "(STUBBED) called");
}

} // namespace Service::CFG
