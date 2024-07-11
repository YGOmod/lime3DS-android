// Copyright 2015 Citra Emulator Project
// Licensed under GPLv2 or any later version
// Refer to the license.txt file included.

#include "common/archives.h"
#include "core/hle/ipc_helpers.h"
#include "core/hle/service/gsp/gsp_lcd.h"

SERIALIZE_EXPORT_IMPL(Service::GSP::GSP_LCD)

namespace Service::GSP {

GSP_LCD::GSP_LCD() : ServiceFramework("gsp::Lcd") {
    static const FunctionInfo functions[] = {
        // clang-format off
        {0x0001, nullptr, "EnableABL"},
        {0x0002, nullptr, "DisableABL"},
        {0x0003, nullptr, "SetRSLut"},
        {0x0004, nullptr, "SetRSParams"},
        {0x0005, nullptr, "SetABLArea"},
        {0x0007, nullptr, "SetInertia"},
        {0x0008, nullptr, "SetDitherMode"},
        {0x0009, nullptr, "SetDitherParams"},
        {0x000A, nullptr, "SetBrightnessRaw"},
        {0x000B, nullptr, "SetBrightness"},
        {0x000F, nullptr, "PowerOnAllBacklights"},
        {0x0010, nullptr, "PowerOffAllBacklights"},
        {0x0011, nullptr, "PowerOnBacklight"},
        {0x0012, nullptr, "PowerOffBacklight"},
        {0x0013, nullptr, "SetLedForceOff"},
        {0x0014, nullptr, "GetVendor"},
        {0x0015, nullptr, "GetBrightness"},
        // clang-format on
    };
    RegisterHandlers(functions);
};

} // namespace Service::GSP
