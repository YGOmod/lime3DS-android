// Copyright 2016 Citra Emulator Project
// Licensed under GPLv2 or any later version
// Refer to the license.txt file included.

#include "common/archives.h"
#include "common/common_types.h"
#include "common/logging/log.h"
#include "core/hle/ipc_helpers.h"
#include "core/hle/result.h"
#include "core/hle/service/dlp/dlp_srvr.h"

SERIALIZE_EXPORT_IMPL(Service::DLP::DLP_SRVR)

namespace Service::DLP {

DLP_SRVR::DLP_SRVR() : ServiceFramework("dlp:SRVR", 1) {
    static const FunctionInfo functions[] = {
        // clang-format off
        {0x0001, nullptr, "Initialize"},
        {0x0002, &DLP_SRVR::Finalize, "Finalize"},
        {0x0003, &DLP_SRVR::GetServerState, "GetServerState"},
        {0x0004, nullptr, "GetEventDescription"},
        {0x0005, nullptr, "StartAccepting"},
        {0x0006, nullptr, "EndAccepting"},
        {0x0007, nullptr, "StartDistribution"},
        {0x0008, nullptr, "SendWirelessRebootPassphrase"},
        {0x0009, &DLP_SRVR::AcceptClient, "AcceptClient"},
        {0x000A, &DLP_SRVR::DisconnectClient, "DisconnectClient"},
        {0x000B, nullptr, "GetConnectingClients"},
        {0x000C, nullptr, "GetClientInfo"},
        {0x000D, nullptr, "GetClientState"},
        {0x000E, &DLP_SRVR::IsChild, "IsChild"},
        {0x000F, nullptr, "InitializeWithName"},
        {0x0010, nullptr, "GetDupNoticeNeed"},
        // clang-format on
    };

    RegisterHandlers(functions);
}

void DLP_SRVR::Finalize(Kernel::HLERequestContext& ctx) {
    IPC::RequestParser rp(ctx);
    
    IPC::RequestBuilder rb = rp.MakeBuilder(1, 0);
    rb.Push(ResultSuccess);
    
    LOG_WARNING(Service_DLP, "(STUBBED) called");
}

void DLP_SRVR::GetServerState(Kernel::HLERequestContext& ctx) {
    IPC::RequestParser rp(ctx);
    
    IPC::RequestBuilder rb = rp.MakeBuilder(2, 0);
    rb.Push(ResultSuccess);
    rb.Push<u8>(0);
    LOG_WARNING(Service_DLP, "(STUBBED) called");
}

void DLP_SRVR::AcceptClient(Kernel::HLERequestContext& ctx) {
    IPC::RequestParser rp(ctx);
    const u32 node_id = rp.Pop<u32>();

    IPC::RequestBuilder rb = rp.MakeBuilder(1, 0);
    rb.Push(ResultSuccess);

    LOG_DEBUG(Service_DLP, "(STUBBED) called, node_id={}", node_id);
}

void DLP_SRVR::DisconnectClient(Kernel::HLERequestContext& ctx) {
    IPC::RequestParser rp(ctx);
    const u32 node_id = rp.Pop<u32>();

    IPC::RequestBuilder rb = rp.MakeBuilder(1, 0);
    rb.Push(ResultSuccess);

    LOG_DEBUG(Service_DLP, "(STUBBED) called, node_id={}", node_id);
}

void DLP_SRVR::IsChild(Kernel::HLERequestContext& ctx) {
    IPC::RequestParser rp(ctx);
    rp.Skip(1, false);

    IPC::RequestBuilder rb = rp.MakeBuilder(2, 0);
    rb.Push(ResultSuccess);
    rb.Push(false);

    LOG_WARNING(Service_DLP, "(STUBBED) called");
}

} // namespace Service::DLP
