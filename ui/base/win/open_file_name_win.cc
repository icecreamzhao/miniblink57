// Copyright (c) 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "ui/base/win/open_file_name_win.h"

#include "base/files/file_path.h"
#include "base/macros.h"
#include "base/strings/string_util.h"
#include "base/win/windows_version.h"

namespace ui {
namespace win {

    namespace {

        // Ensures that the Save As dialog is on-screen.
        UINT_PTR CALLBACK SaveAsDialogHook(HWND dialog, UINT message,
            WPARAM wparam, LPARAM lparam)
        {
            static const UINT kPrivateMessage = 0x2F3F;
            switch (message) {
            case WM_INITDIALOG: {
                // Do nothing here. Just post a message to defer actual processing.
                ::PostMessage(dialog, kPrivateMessage, 0, 0);
                return TRUE;
            }
            case kPrivateMessage: {
                // The dialog box is the parent of the current handle.
                HWND real_dialog = ::GetParent(dialog);

                // Retrieve the final size.
                RECT dialog_rect;
                ::GetWindowRect(real_dialog, &dialog_rect);

                // Verify that the upper left corner is visible.
                POINT point = { dialog_rect.left, dialog_rect.top };
                HMONITOR monitor1 = ::MonitorFromPoint(point, MONITOR_DEFAULTTONULL);
                point.x = dialog_rect.right;
                point.y = dialog_rect.bottom;

                // Verify that the lower right corner is visible.
                HMONITOR monitor2 = ::MonitorFromPoint(point, MONITOR_DEFAULTTONULL);
                if (monitor1 && monitor2)
                    return 0;

                // Some part of the dialog box is not visible, fix it by moving is to the
                // client rect position of the browser window.
                HWND parent_window = ::GetParent(real_dialog);
                if (!parent_window)
                    return 0;
                WINDOWINFO parent_info;
                parent_info.cbSize = sizeof(WINDOWINFO);
                ::GetWindowInfo(parent_window, &parent_info);
                ::SetWindowPos(
                    real_dialog,
                    NULL,
                    parent_info.rcClient.left,
                    parent_info.rcClient.top,
                    0,
                    0, // Size.
                    SWP_NOACTIVATE | SWP_NOOWNERZORDER | SWP_NOSIZE | SWP_NOZORDER);

                return 0;
            }
            }
            return 0;
        }

    } // namespace

    OpenFileName::OpenFileName(HWND parent_window, DWORD flags)
    {
        ::ZeroMemory(&openfilename_, sizeof(openfilename_));
        openfilename_.lStructSize = sizeof(openfilename_);

        // According to http://support.microsoft.com/?scid=kb;en-us;222003&x=8&y=12,
        // The lpstrFile Buffer MUST be NULL Terminated.
        filename_buffer_[0] = 0;
        openfilename_.lpstrFile = filename_buffer_;
        openfilename_.nMaxFile = arraysize(filename_buffer_);

        openfilename_.Flags = flags;
        openfilename_.hwndOwner = parent_window;
    }

    OpenFileName::~OpenFileName()
    {
    }

    void OpenFileName::SetFilters(
        const std::vector<base::Tuple<base::string16, base::string16>>& filters)
    {
        openfilename_.lpstrFilter = NULL;
        filter_buffer_.clear();
        if (filters.empty())
            return;
        for (const auto& filter : filters) {
            filter_buffer_.append(base::get<0>(filter));
            filter_buffer_.push_back(0);
            filter_buffer_.append(base::get<1>(filter));
            filter_buffer_.push_back(0);
        }
        filter_buffer_.push_back(0);
        openfilename_.lpstrFilter = filter_buffer_.c_str();
    }

    void OpenFileName::SetInitialSelection(const base::FilePath& initial_directory,
        const base::FilePath& initial_filename)
    {
        // First reset to the default case.
        // According to http://support.microsoft.com/?scid=kb;en-us;222003&x=8&y=12,
        // The lpstrFile Buffer MUST be NULL Terminated.
        filename_buffer_[0] = 0;
        openfilename_.lpstrFile = filename_buffer_;
        openfilename_.nMaxFile = arraysize(filename_buffer_);
        openfilename_.lpstrInitialDir = NULL;
        initial_directory_buffer_.clear();

        if (initial_directory.empty())
            return;

        initial_directory_buffer_ = initial_directory.value();
        openfilename_.lpstrInitialDir = initial_directory_buffer_.c_str();

        if (initial_filename.empty())
            return;

        // The filename is ignored if no initial directory is supplied.
        base::wcslcpy(filename_buffer_,
            initial_filename.value().c_str(),
            arraysize(filename_buffer_));
    }

    void OpenFileName::MaybeInstallWindowPositionHookForSaveAsOnXP()
    {
        if (base::win::GetVersion() >= base::win::VERSION_VISTA)
            return;

        openfilename_.Flags |= OFN_ENABLEHOOK;
        DCHECK(!openfilename_.lpfnHook);
        openfilename_.lpfnHook = &SaveAsDialogHook;
    }

    base::FilePath OpenFileName::GetSingleResult()
    {
        base::FilePath directory;
        std::vector<base::FilePath> filenames;
        GetResult(&directory, &filenames);
        if (filenames.size() != 1)
            return base::FilePath();
        return directory.Append(filenames[0]);
    }

    void OpenFileName::GetResult(base::FilePath* directory,
        std::vector<base::FilePath>* filenames)
    {
        DCHECK(filenames->empty());
        const wchar_t* selection = openfilename_.lpstrFile;
        // The return value of |openfilename_.lpstrFile| is dependent on the
        // value of the Multi-Select flag within |openfilename_|. If the flag is
        // not set the return value will be a single null-terminated wide string.
        // If it is set it will be more than one null-terminated wide string, itself
        // terminated by an empty null-terminated wide string.
        if (openfilename_.Flags & OFN_ALLOWMULTISELECT) {
            while (*selection) { // Empty string indicates end of list.
                filenames->push_back(base::FilePath(selection));
                // Skip over filename and null-terminator.
                selection += filenames->back().value().length() + 1;
            }
        } else {
            filenames->push_back(base::FilePath(selection));
        }
        if (filenames->size() == 1) {
            // When there is one file, it contains the path and filename.
            *directory = (*filenames)[0].DirName();
            (*filenames)[0] = (*filenames)[0].BaseName();
        } else if (filenames->size() > 1) {
            // Otherwise, the first string is the path, and the remainder are
            // filenames.
            *directory = (*filenames)[0];
            filenames->erase(filenames->begin());
        }
    }

    // static
    void OpenFileName::SetResult(const base::FilePath& directory,
        const std::vector<base::FilePath>& filenames,
        OPENFILENAME* openfilename)
    {
        base::string16 filename_value;
        if (filenames.size() == 1) {
            filename_value = directory.Append(filenames[0]).value();
        } else {
            filename_value = directory.value();
            filename_value.push_back(0);
            for (std::vector<base::FilePath>::const_iterator it = filenames.begin();
                 it != filenames.end();
                 ++it) {
                filename_value.append(it->value());
                filename_value.push_back(0);
            }
        }
        if (filename_value.size() + 1 < openfilename->nMaxFile) {
            // Because the result has embedded nulls, we must memcpy.
            memcpy(openfilename->lpstrFile,
                filename_value.c_str(),
                (filename_value.size() + 1) * sizeof(filename_value[0]));
        } else if (openfilename->nMaxFile) {
            openfilename->lpstrFile[0] = 0;
        }
    }

    // static
    std::vector<base::Tuple<base::string16, base::string16>>
    OpenFileName::GetFilters(const OPENFILENAME* openfilename)
    {
        std::vector<base::Tuple<base::string16, base::string16>> filters;

        const base::char16* display_string = openfilename->lpstrFilter;
        if (!display_string)
            return filters;

        while (*display_string) {
            const base::char16* display_string_end = display_string;
            while (*display_string_end)
                ++display_string_end;
            const base::char16* pattern = display_string_end + 1;
            const base::char16* pattern_end = pattern;
            while (*pattern_end)
                ++pattern_end;
            filters.push_back(
                base::MakeTuple(base::string16(display_string, display_string_end),
                    base::string16(pattern, pattern_end)));
            display_string = pattern_end + 1;
        }

        return filters;
    }

} // namespace win
} // namespace ui
