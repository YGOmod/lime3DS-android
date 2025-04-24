// Copyright 2015 Citra Emulator Project
// Licensed under GPLv2 or any later version
// Refer to the license.txt file included..

#pragma once

#include "core/hle/service/service.h"

namespace Service::NIM {

class NIM_S final : public ServiceFramework<NIM_S> {
public:
    NIM_S();
    ~NIM_S();

private:
    /**
     * NIM::CancelDownload service function
     *  Inputs:
     *      1 : None
     *  Outputs:
     *      1 : Result of function, 0 on success, otherwise error code
     */
    void CancelDownload(Kernel::HLERequestContext& ctx);

    SERVICE_SERIALIZATION_SIMPLE
};

} // namespace Service::NIM

BOOST_CLASS_EXPORT_KEY(Service::NIM::NIM_S)
