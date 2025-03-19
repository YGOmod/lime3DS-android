// Copyright 2016 Citra Emulator Project
// Licensed under GPLv2 or any later version
// Refer to the license.txt file included.

#include "common/archives.h"
#include "core/hle/ipc_helpers.h"
#include "core/hle/service/qtm/qtm_sp.h"

SERIALIZE_EXPORT_IMPL(Service::QTM::QTM_SP)

namespace Service::QTM {

QTM_SP::QTM_SP() : ServiceFramework("qtm:sp", 2) {
    static const FunctionInfo functions[] = {
        // qtm common commands
        // clang-format off
        {0x0001, nullptr, "GetHeadtrackingInfoRaw"},
        {0x0002, &QTM_SP::GetHeadtrackingInfo, "GetHeadtrackingInfo"},
        {0x0003, nullptr, "EnableManualIrLedControl"},
        {0x0004, nullptr, "DisableManualIrLedControl"},
        {0x0005, nullptr, "SetIrLedStatus"},
        {0x0006, nullptr, "IsCurrentAppBlacklisted"},
        // qtm:s
        {0x0401, nullptr, "SetCentralBarrierPosition"},
        {0x0402, nullptr, "GetCameraLuminance"},
        {0x0403, nullptr, "EnableAutoBarrierControl"},
        {0x0404, nullptr, "DisableAutoBarrierControl"},
        {0x0405, nullptr, "SetBarrierPosition"},
        {0x0406, nullptr, "GetCurrentBarrierPosition"},
        {0x0407, nullptr, "SetIrLedStatusOverride"},
        {0x0408, nullptr, "SetCalibrationData"},
        {0x0409, nullptr, "GetQtmStatus"},
        {0x040A, nullptr, "SetQtmStatus"},
        // qtm:sp
        {0x0801, nullptr, "NotifyTopLcdModeChange"},
        {0x0802, nullptr, "NotifyTopLcdPowerOn"},
        {0x0803, nullptr, "IsExpanderInUse"},
        {0x0804, nullptr, "NotifyTopLcdPowerOff"},
        // clang-format on
    };

    RegisterHandlers(functions);
}

void QTM_SP::GetHeadtrackingInfo(Kernel::HLERequestContext& ctx) {
    IPC::RequestParser rp(ctx);
    [[maybe_unused]] const u64 unknown = rp.Pop<u64>();

    std::array<u8, 0x40> data{};
    IPC::RequestBuilder rb = rp.MakeBuilder(17, 0);
    rb.Push(ResultSuccess);
    rb.PushRaw<std::array<u8, 0x40>>(data);

    LOG_DEBUG(Service, "(STUBBED) called");
}

} // namespace Service::QTM
