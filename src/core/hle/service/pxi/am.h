// Licensed under GPLv2 or any later version
// Refer to the license.txt file included.

#pragma once

#include "core/hle/service/service.h"

namespace Service::PXI {

/// Interface to "pxi:am" service
class AM final : public ServiceFramework<AM> {
public:
    AM();
    ~AM();

private:
    SERVICE_SERIALIZATION_SIMPLE
};

} // namespace Service::PXI

BOOST_CLASS_EXPORT_KEY(Service::PXI::AM)
