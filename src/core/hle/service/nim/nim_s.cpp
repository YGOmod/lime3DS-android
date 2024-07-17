// Copyright 2015 Citra Emulator Project
// Licensed under GPLv2 or any later version
// Refer to the license.txt file included.

#include "common/archives.h"
#include "core/hle/ipc_helpers.h"
#include "core/hle/service/nim/nim_s.h"

SERIALIZE_EXPORT_IMPL(Service::NIM::NIM_S)

namespace Service::NIM {

NIM_S::NIM_S() : ServiceFramework("nim:s", 1) {
    const FunctionInfo functions[] = {
        // clang-format off
        {0x0001, nullptr, "StartDownloadSimple"},
        {0x0002, &NIM_S::CancelDownload, "CancelDownload"},
        {0x0003, nullptr, "GetProgress"},
        {0x0005, nullptr, "UnregisterTask"},
        {0x0006, nullptr, "IsTaskRegistered"},
        {0x0007, nullptr, "GetTaskInfoFromTitleId"},
        {0x0008, nullptr, "GetTaskList"},
        {0x000A, nullptr, "CheckSysupdateAvailableSOAP"},
        {0x000B, nullptr, "SetAttribute"},
        {0x000C, nullptr, "SetAttributeInt32"},
        {0x000D, nullptr, "Connect"},
        {0x000E, nullptr, "UnregisterSOAP"},
        {0x000F, nullptr, "SetCountrySOAP"},
        {0x0012, nullptr, "SetExternalAccountSOAP"},
        {0x0013, nullptr, "DeleteExternalAccountSOAP"},
        {0x0014, nullptr, "DeleteSavedCardSOAP"},
        {0x0015, nullptr, "ListCashReplenishAmountsSOAP"},
        {0x0016, nullptr, "ListTitles"},
        {0x0017, nullptr, "ListContentSetsExSOAP"},
		{0x0018, nullptr, "ListItemsSOAP"},
		{0x0019, nullptr, "ListContentSetGroupsSOAP"},
		{0x001E, nullptr, "GetTaxesSOAP"},
		{0x001F, nullptr, "GetTaxLocationSOAP"},
		{0x0022, nullptr, "AccountDeleteTitleETicketsSOAP"},
        {0x0029, nullptr, "AccountCheckBalanceSOAP"},
        {0x002D, nullptr, "DownloadTickets"},
        {0x003C, nullptr, "RegisterSelf"},
        {0x003F, nullptr, "GetInitializeResult"},
        {0x0042, nullptr, "StartDownload"},
        {0x0055, nullptr, "RegisterTask"},
        {0x0057, nullptr, "ConnectNoTicketDownload"},
        {0x005B, nullptr, "DeleteInitAccSavedData"},
        {0x005C, nullptr, "DeleteAccountSavedData"},
        {0x005F, nullptr, "DownloadTitleSeed"},
        // clang-format on
    };
    RegisterHandlers(functions);
}

NIM_S::~NIM_S() = default;

void NIM_S::CancelDownload(Kernel::HLERequestContext& ctx) {
    IPC::RequestParser rp(ctx);

    IPC::RequestBuilder rb = rp.MakeBuilder(1, 0);
    rb.Push(ResultSuccess);

    LOG_WARNING(Service_NIM, "(STUBBED) called");
}

} // namespace Service::NIM
