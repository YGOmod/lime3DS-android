// Copyright 2014 Citra Emulator Project
// Licensed under GPLv2 or any later version
// Refer to the license.txt file included.

#include "common/archives.h"
#include "core/hle/service/am/am_app.h"

namespace Service::AM {

AM_APP::AM_APP(std::shared_ptr<Module> am) : Module::Interface(std::move(am), "am:app", 5) {
    static const FunctionInfo functions[] = {
        // clang-format off
        {0x1001, &AM_APP::GetDLCContentInfoCount, "GetDLCContentInfoCount"},
        {0x1002, &AM_APP::FindDLCContentInfos, "FindDLCContentInfos"},
        {0x1003, &AM_APP::ListDLCContentInfos, "ListDLCContentInfos"},
        {0x1004, &AM_APP::DeleteDLCContents, "DeleteDLCContents"},
        {0x1005, &AM_APP::GetDLCTitleInfos, "GetDLCTitleInfos"},
        {0x1006, nullptr, "GetDLCOrLicenseNumTickets"},
        {0x1007, &AM_APP::ListDLCOrLicenseTicketInfos, "ListDLCOrLicenseTicketInfos"},
        {0x1008, nullptr, "GetDLCOrLicenseItemRights"},
        {0x1009, nullptr, "IsDLCTitleInUse"},
        {0x100A, nullptr, "ReloadSDTitleDatabase"},
        {0x100B, nullptr, "GetNumDLCExistingContentInfos"},
        {0x100C, nullptr, "ListDLCExistingContentInfos"},
        {0x100D, &AM_APP::GetPatchTitleInfos, "GetPatchTitleInfos"},
        // clang-format on
    };
    RegisterHandlers(functions);
}

} // namespace Service::AM

SERIALIZE_EXPORT_IMPL(Service::AM::AM_APP)
