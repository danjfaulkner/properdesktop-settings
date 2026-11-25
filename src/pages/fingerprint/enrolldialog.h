// SPDX-FileCopyrightText: 2026 Reion Wong <reionwong@gmail.com>
// SPDX-License-Identifier: BSD-3-Clause

#pragma once

#include <memory>
#include <string>

#include "base/signal.h"
#include "properdesktop/fprint/fingerprint_reader.h"
#include "widgets/formdialog.h"

namespace properdesktop::ui {
class Animation;
class DialogButton;
class Label;
class RowLayout;
}

namespace settings {

class FingerprintView;

// Records one fingerprint: a print that fills in as the finger is placed on
// the sensor again and again, and what to do next under it. It opens on an
// enrollment that has started, and closes at once when polkit was refused.
// Cancel (or Escape) closes it and stops the enrollment.
class EnrollDialog : public FormDialog
{
public:
    EnrollDialog(SettingsWindow& parent, properdesktop::fprint::Reader& reader,
                 std::unique_ptr<properdesktop::fprint::Enrollment> enrollment);
    ~EnrollDialog() override;

private:
    void watch();
    void update();
    void tryAgain();
    void showAction(bool show);

    properdesktop::fprint::Reader& m_reader;
    std::unique_ptr<properdesktop::fprint::Enrollment> m_enrollment;
    properdesktop::base::Subscription m_changed;
    FingerprintView* m_print;
    properdesktop::ui::Label* m_title;
    properdesktop::ui::Label* m_detail;
    properdesktop::ui::RowLayout* m_buttons;
    std::unique_ptr<properdesktop::ui::Animation> m_fade;
    properdesktop::ui::DialogButton* m_cancel;
    properdesktop::ui::DialogButton* m_action;
};

} // namespace settings
