#include <stdafx.h>

#include "acfu_integration.h"

#include <qwr/semantic_version.h>
#include <qwr/string_helpers.h>

namespace qwr::acfu
{

void QwrSource::get_info( file_info& info )
{
    if ( !isVersionFetched_ )
    {
        installedVersion_ = FetchVersion();
        isVersionFetched_ = true;
    }

    info.meta_set( "version", installedVersion_.c_str() );
    info.meta_set( "name", GetComponentName().c_str() );
    info.meta_set( "module", GetComponentFilename().c_str() );
}

bool QwrSource::is_newer( const file_info& info )
{
    if ( !info.meta_get( "version", 0 ) || installedVersion_.empty() )
    {
        return false;
    }

    const std::u8string availableVersion = [&info]() {
        std::u8string version = info.meta_get( "version", 0 );
        version = qwr::string::Trim<char8_t>( version );
        if ( version[0] == 'v' )
        {
            version = version.substr( 1 );
        }
        return version;
    }();

    try
    {
        return ( qwr::SemVer{ availableVersion } > qwr::SemVer{ installedVersion_ } );
    }
    catch ( const std::runtime_error& )
    {
        assert( false );
        return false;
    }
}

std::string QwrSource::FetchVersion()
{
    const auto componentFilename = GetComponentFilename();
    auto cvRet = [&componentFilename]() -> componentversion::ptr {
        for ( service_enum_t<componentversion> e; !e.finished(); ++e )
        {
            auto cv = e.get();

            pfc::string8 file_name;
            cv->get_file_name( file_name );
            if ( file_name.equals( componentFilename.c_str() ) )
            {
                return cv;
            }
        }

        return componentversion::ptr{};
    }();

    if ( cvRet.is_empty() )
    {
        return "0.0.0";
    }
    else
    {
        pfc::string8 version;
        cvRet->get_component_version( version );
        return std::string( version.c_str(), version.length() );
    }
}

} // namespace qwr::acfu
