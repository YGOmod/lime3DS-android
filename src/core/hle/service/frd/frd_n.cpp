// Licensed under GPLv2 or any later version
// Refer to the license.txt file included.

#include "common/archives.h"
#include "core/hle/service/frd/frd_n.h"

SERIALIZE_EXPORT_IMPL(Service::FRD::FRD_N)

namespace Service::FRD {

FRD_N::FRD_N(std::shared_ptr<Module> frd) : Module::Interface(std::move(frd), "frd:n", 8) {
    static const FunctionInfo functions[] = {
        {0x0001, nullptr, "GetHandleOfNdmStatusChangedEvent"},
        {0x0002, nullptr, "Resume"},
        {0x0003, nullptr, "SuspendAsync"},
        {0x0004, nullptr, "QueryStatus"},
    };
    RegisterHandlers(functions);
}

} // namespace Service::FRD
