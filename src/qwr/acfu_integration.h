#pragma once

#include <qwr/acfu_github.h>

#include <acfu-sdk/utils/common.h>

namespace qwr::acfu
{

class QwrSource
    : public ::acfu::source
    , public qwr::acfu::github_conf
{
public:
    void get_info( file_info& info ) override;
    bool is_newer( const file_info& info ) override;

private:
    std::string FetchVersion();

    virtual std::string GetComponentName() const = 0;
    virtual std::string GetComponentFilename() const = 0;

private:
    bool isVersionFetched_ = false;
    std::string installedVersion_;
};

} // namespace qwr
