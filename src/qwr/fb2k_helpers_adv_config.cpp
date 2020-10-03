#include <stdafx.h>

#include "fb2k_helpers_config.h"

namespace qwr::fb2k::config
{

std::string GetValue( advconfig_string_factory_MT& config )
{
    pfc::string8 value;
    config.get( value );
    return value.c_str();
}

} // namespace qwr::fb2k::config
