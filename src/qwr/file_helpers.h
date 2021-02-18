#pragma once

#include <shtypes.h>

#include <filesystem>
#include <optional>
#include <span>
#include <string>

namespace qwr::file
{

/// @throw smp::SmpException
qwr::u8string ReadFile( const std::filesystem::path& path, UINT codepage, bool checkFileExistense = true );

/// @throw smp::SmpException
std::wstring ReadFileW( const std::filesystem::path& path, UINT codepage, bool checkFileExistense = true );

/// @throw smp::SmpException
void WriteFile( const std::filesystem::path& path, qwr::u8string_view content, bool write_bom = true );

UINT DetectFileCharset( const std::filesystem::path& path );

struct FileDialogOptions
{
    std::vector<COMDLG_FILTERSPEC> filterSpec{ { L"All files", L"*.*" } };
    std::wstring defaultExtension = L"";
    std::wstring defaultFilename = L"";
    std::optional<GUID> savePathGuid;
};

std::optional<std::filesystem::path>
FileDialog( const std::wstring& title,
            bool saveFile,
            const FileDialogOptions& options = {} );

} // namespace qwr::file
