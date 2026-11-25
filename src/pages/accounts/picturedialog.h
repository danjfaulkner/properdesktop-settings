// SPDX-FileCopyrightText: 2026 Reion Wong <reionwong@gmail.com>
// SPDX-License-Identifier: BSD-3-Clause

#pragma once

#include <functional>
#include <memory>
#include <string>
#include <vector>

#include "properdesktop/accounts/user_account.h"
#include "widgets/formdialog.h"

namespace properdesktop::ui {
class DialogButton;
class FileChooser;
}

namespace settings {

class PicturePreview;
class PictureTile;

// The picture an account will have, large over the presets, and a button that
// picks a file instead. Save gives the account the one shown.
class PictureDialog : public FormDialog
{
public:
    PictureDialog(SettingsWindow& parent, std::shared_ptr<properdesktop::accounts::UserAccount> account);
    ~PictureDialog() override;

    // The picture given to the account, before the service has copied it.
    std::function<void(const std::string& path)> onPicked;

private:
    void select(const std::string& path);
    void chooseFile();
    void save();

    std::shared_ptr<properdesktop::accounts::UserAccount> m_account;
    PicturePreview* m_preview;
    std::vector<PictureTile*> m_tiles;
    std::string m_initial;
    std::string m_selected;
    properdesktop::ui::DialogButton* m_save;
    std::unique_ptr<properdesktop::ui::FileChooser> m_chooser;
};

} // namespace settings
