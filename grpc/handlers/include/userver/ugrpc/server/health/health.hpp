#pragma once

#include <healthchecking/healthchecking.pb.h>
#include <healthchecking/healthchecking_service.usrv.pb.hpp>

#include <userver/components/state.hpp>

USERVER_NAMESPACE_BEGIN

namespace ugrpc::server {

class HealthHandler final : public grpc::health::v1::HealthBase {
public:
    explicit HealthHandler(const components::ComponentContext& context);

    CheckResult Check(CallContext& context, ::grpc::health::v1::HealthCheckRequest&& request) override;

private:
    const components::State components_;
};

}  // namespace ugrpc::server

USERVER_NAMESPACE_END
