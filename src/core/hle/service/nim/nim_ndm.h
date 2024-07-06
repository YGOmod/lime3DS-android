// Copyright 2024 Citra Emulator Project
// Licensed under GPLv2 or any later version
// Refer to the license.txt file included..

#pragma once

#include "core/hle/service/service.h"

namespace Service::NIM {

class NIM_NDM final : public ServiceFramework<NIM_NDM> {
public:
    NIM_NDM();
    ~NIM_NDM();

private:
    SERVICE_SERIALIZATION_SIMPLE
};

} // namespace Service::NIM

BOOST_CLASS_EXPORT_KEY(Service::NIM::NIM_NDM)
