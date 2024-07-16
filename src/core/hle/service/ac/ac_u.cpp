// Copyright 2014 Citra Emulator Project
// Licensed under GPLv2 or any later version
// Refer to the license.txt file included.

#include "common/archives.h"
#include "core/hle/service/ac/ac_u.h"

namespace Service::AC {

AC_U::AC_U(std::shared_ptr<Module> ac) : Module::Interface(std::move(ac), "ac:u", 10) {
    static const FunctionInfo functions[] = {
        // clang-format off
        {0x0001, &AC_U::CreateDefaultConfig, "CreateDefaultConfig"},
        {0x0002, nullptr, "DebugSetApType"},
        {0x0003, nullptr, "DebugSetNetworkArea"},
        {0x0004, &AC_U::ConnectAsync, "ConnectAsync"},
        {0x0005, &AC_U::GetConnectResult, "GetConnectResult"},
        {0x0006, nullptr, "DebugSetNetworkSetting1"},
        {0x0007, &AC_U::CancelConnectAsync, "CancelConnectAsync"},
        {0x0008, &AC_U::CloseAsync, "CloseAsync"},
        {0x0009, &AC_U::GetCloseResult, "GetCloseResult"},
        {0x000A, &AC_U::GetLastErrorCode, "GetLastErrorCode"},
        {0x000B, nullptr, "GetLastDetailErrorCode"},
        {0x000C, &AC_U::GetStatus, "GetStatus"},
        {0x000D, &AC_U::GetWifiStatus, "GetWifiStatus"},
        {0x000E, &AC_U::GetCurrentAPInfo, "GetCurrentAPInfo"},
        {0x000F, &AC_U::GetConnectingInfraPriority, "GetConnectingInfraPriority"},
        {0x0010, nullptr, "GetCurrentNZoneInfo"},
        {0x0011, nullptr, "GetNZoneApNumService"},
        {0x0012, nullptr, "GetConnectingHotspot"},
        {0x0013, nullptr, "GetConnectingHotspotSubset"},
        {0x0014, nullptr, "GetConnectingLocation"},
        {0x0016, nullptr, "GetExclusiveResult"},
        {0x0017, nullptr, "UnExclusiveAsync"},
        {0x0018, nullptr, "GetUnExcusiveResult"},
        {0x0019, nullptr, "CloseAllASync"},
        {0x001A, nullptr, "GetCloseAllResult"},
        {0x001B, nullptr, "LogoutHotspotAsync"},
        {0x001C, nullptr, "GetLogoutHotspotResult"},
        {0x001D, nullptr, "ScanAPs"},
        {0x001E, nullptr, "ScanNintendoZone"},
        {0x001F, nullptr, "ScanNintendoZoneSubset"},
        {0x0020, nullptr, "BeginScanUsbAccessPoint"},
        {0x0021, nullptr, "EndScanUsbAccessPoint"},
        {0x0022, nullptr, "SetAllowApType"},
        {0x0023, nullptr, "AddAllowApType"},
        {0x0024, nullptr, "AddDenyApType"},
        {0x0025, nullptr, "SetNetworkArea"},
        {0x0026, nullptr, "SetInfraPriority"},
        {0x0027, &AC_U::GetInfraPriority, "GetInfraPriority"},
        {0x0028, nullptr, "SetPowerSaveMode"},
        {0x0029, nullptr, "GetPowerSaveMode"},
        {0x002A, nullptr, "SetBssidFilter"},
        {0x002B, nullptr, "SetApNumFilter"},
        {0x002C, &AC_U::SetFromApplication, "SetFromApplication"},
        {0x002D, &AC_U::SetRequestEulaVersion, "SetRequestEulaVersion"},
        {0x002E, nullptr, "ConvertPassphraseToPsk"},
        {0x002F, &AC_U::GetNZoneBeaconNotFoundEvent, "GetNZoneBeaconNotFoundEvent"},
        {0x0030, &AC_U::RegisterDisconnectEvent, "RegisterDisconnectEvent"},
        {0x0031, nullptr, "GetStatusChangeEvent"},
        {0x0032, nullptr, "SetAuthServerType"},
        {0x0033, nullptr, "GetConnectingSecurityMode"},
        {0x0034, nullptr, "GetConnectingSsid"},
        {0x0035, nullptr, "GetConnectingSsidLength"},
        {0x0036, &AC_U::GetConnectingProxyEnable, "GetConnectingProxyEnable"},
        {0x0037, nullptr, "GetConnectingProxyAuthType"},
        {0x0038, nullptr, "GetConnectingProxyPort"},
        {0x0039, nullptr, "GetConnectingProxyHost"},
        {0x003A, nullptr, "GetConnectingProxyUserName"},
        {0x003B, nullptr, "GetConnectingProxyPassword"},
        {0x003C, nullptr, "GetAPSSIDList"},
        {0x003D, nullptr, "SetZoneMacFilter}"},
        {0x003E, &AC_U::IsConnected, "IsConnected"},
        {0x003F, nullptr, "GetNotAwakeMacFilter"},
        {0x0040, &AC_U::SetClientVersion, "SetClientVersion"},
        {0x0041, nullptr, "SetTemporaryNetworkSettings"},
        // clang-format on
    };
    RegisterHandlers(functions);
}

} // namespace Service::AC

SERIALIZE_EXPORT_IMPL(Service::AC::AC_U)
