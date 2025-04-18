// Licensed under GPLv2 or any later version
// Refer to the license.txt file included.

#pragma once

#include "core/hle/service/frd/frd.h"

namespace Service::FRD {

class FRD_N final : public Module::Interface {
public:
    explicit FRD_N(std::shared_ptr<Module> frd);

private:
    SERVICE_SERIALIZATION(FRD_N, frd, Module)
};

} // namespace Service::FRD

BOOST_CLASS_EXPORT_KEY(Service::FRD::FRD_N)
BOOST_SERIALIZATION_CONSTRUCT(Service::FRD::FRD_N)
