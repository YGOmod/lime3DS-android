// Licensed under GPLv2 or any later version
// Refer to the license.txt file included.

#include "common/archives.h"
#include "core/hle/service/pxi/am.h"

SERIALIZE_EXPORT_IMPL(Service::PXI::AM)

namespace Service::PXI {

AM::AM() : ServiceFramework("pxi:am", 1) {
    // clang-format off
    static const FunctionInfo functions[] = {
        // clang-format off
        {0x0001, nullptr, "GetTitleCount"},
        {0x0002, nullptr, "GetTitleList"},
        {0x0003, nullptr, "GetTitleInfo"},
        {0x0004, nullptr, "DeleteTitle"},
        {0x0005, nullptr, "GetTitleProductCode"},
        {0x0006, nullptr, "GetTitleExtDataId"},
        {0x0007, nullptr, "DeletePendingTitles"},
        {0x0008, nullptr, "InstallFIRM"},
        {0x0009, nullptr, "InstallTikBegin"},
        {0x000A, nullptr, "InstallTikWrite"},
        {0x000B, nullptr, "InstallTikAbort"},
        {0x000C, nullptr, "InstallTikFinish"},
        {0x000D, nullptr, "DeleteTicket"},
        {0x000E, nullptr, "GetTicketCount"},
        {0x000F, nullptr, "GetTicketList"},
        {0x0010, nullptr, "InstallTitleBegin"},
        {0x0011, nullptr, "InstallTitleStop"},
        {0x0012, nullptr, "InstallTitleResume"},
        {0x0013, nullptr, "InstallTmdBegin"},
        {0x0014, nullptr, "InstallTmdWrite"},
        {0x0015, nullptr, "InstallTmdAbort"},
        {0x0016, nullptr, "InstallTmdFinish"},
        {0x0017, nullptr, "InstallContentBegin"},
        {0x0018, nullptr, "InstallContentWrite"},
        {0x0019, nullptr, "InstallContentStop"},
        {0x001A, nullptr, "InstallContentAbort"},
        {0x001B, nullptr, "InstallContentResume"},
        {0x001C, nullptr, "InstallContentFinish"},
        {0x001D, nullptr, "GetPendingTitleCount"},
        {0x001E, nullptr, "GetPendingTitleList"},
        {0x001F, nullptr, "GetPendingTitleInfo"},
        {0x0020, nullptr, "DeletePendingTitle"},
        {0x0021, nullptr, "GetNumImportContentContexts"},
        {0x0022, nullptr, "GetImportContentContextList"},
        {0x0023, nullptr, "GetImportContentContexts"},
        {0x0024, nullptr, "DeleteImportContentContexts"},
        {0x0025, nullptr, "GetNumCurrentImportContentContexts"},
        {0x0026, nullptr, "GetCurrentImportContentContextList"},
        {0x0027, nullptr, "GetCurrentImportContentContexts"},
        {0x0028, nullptr, "InstallTitleAbort"},
        {0x0029, nullptr, "InstallTitleFinish"},
        {0x002A, nullptr, "CommitImportPrograms"},
        {0x0039, nullptr, "Sign"},
        {0x003B, nullptr, "GetCTCert"},
        {0x003C, nullptr, "GetDeviceID"},
        {0x003D, nullptr, "SetCertificates"},
        {0x003E, nullptr, "SetCertificate"},
        {0x003F, nullptr, "IsImportDatabaseInitialized"},
        {0x0040, nullptr, "DoCleanup"},
        {0x0041, nullptr, "DeleteAllTemporaryPrograms"},
        {0x0042, nullptr, "InstallTitlesFinishFIRM"},
        {0x0043, nullptr, "VerifyDSiWareFooter"},
        {0x0044, nullptr, "Unknown_45"}, //This does basically nothing: after checking the two buffers' mem-ranges successfully(on failure it executes svcBreak like all other Process9 code for that), this just returns 0x0.
        {0x0045, nullptr, "DecryptDSiWareData"},
        {0x0046, nullptr, "WriteTWLSavedata"},
        {0x0047, nullptr, "InitializeTitleDatabase"},
        {0x0048, nullptr, "ReloadDBS"},
        {0x0049, nullptr, "GetNumTicketIds"},
        {0x004A, nullptr, "GetTicketIdList"},
        {0x004B, nullptr, "DeleteTicketId"},
        {0x004C, nullptr, "GetPersonalizedTicketInfoList"},
        {0x004D, nullptr, "ExportDSiWare"},
        {0x004E, nullptr, "BeginInstallDSiWareExport"},
        {0x004F, nullptr, "GetDSiWareExportSize"},
        {0x0050, nullptr, "GetTwlProgramListForReboot"},
        {0x0051, nullptr, "DeleteAllTwlUserPrograms"},
        {0x0052, nullptr, "DeleteAllExpiredUserPrograms"},
        {0x0053, nullptr, "ValidateDSiWareMovableSedHash"},
        {0x0054, nullptr, "GetTWLPartitionInfo"},
        {0x0055, nullptr, "ValidateDSiWareSectionMAC"},
        {0x0056, nullptr, "CheckContentRights"},
        {0x0057, nullptr, "CreateImportContentContexts"},
        {0x0058, nullptr, "GetNumContentInfos"},
        {0x0059, nullptr, "FindContentInfos"},
        {0x005A, nullptr, "ListContentInfos"},
        {0x005B, nullptr, "GetNumCurrentContentInfos"},
        {0x005C, nullptr, "FindCurrentContentInfos"},
        {0x005D, nullptr, "ListCurrentContentInfos"},
        {0x005E, nullptr, "DeleteContents"},
        {0x005F, nullptr, "GetNumTicketsOfProgram"},
        {0x0060, nullptr, "ListDataTitleTicketInfos"},
        {0x0061, nullptr, "ExportLicenseTicket"},
        {0x0062, nullptr, "GetTicketLimitInfos"},
        {0x0063, nullptr, "UpdateImportContentContexts"},
        {0x0064, nullptr, "GetInternalTitleLocationInfo"},
        {0x0065, nullptr, "MigrateAGBtoSAV"},
        {0x0067, nullptr, "DeleteProgramsAtomically"},
        {0x0068, nullptr, "GetItemRights"},
        {0x0069, nullptr, "IsDataTitleInUse"},
        {0x006A, nullptr, "GetNumExistingContentInfos"},
        {0x006B, nullptr, "ListExistingContentInfos"},
        {0x006C, nullptr, "InstallTitleBeginForOverwrite"},
        {0x006D, nullptr, "ExportTicketWrapped"},
        // clang-format on
    };
    // clang-format on
    RegisterHandlers(functions);
}

AM::~AM() = default;

} // namespace Service::PXI
