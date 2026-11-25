// SPDX-FileCopyrightText: 2026 Reion Wong <reionwong@gmail.com>
// SPDX-License-Identifier: BSD-3-Clause

#pragma once

#include <string>
#include <vector>

#include "base/signal.h"
#include "base/timer.h"
#include "widgets/formdialog.h"

namespace properdesktop::ui {
class ColumnLayout;
class DialogButton;
class Label;
class ScrollView;
}

namespace settings {

class Footnote;
class Language;
class SearchField;

// The catalog of languages not yet preferred, searched as it is typed; the
// chosen one is added at the end of the preferred languages.
class AddLanguageDialog : public FormDialog
{
public:
    AddLanguageDialog(SettingsWindow& parent, Language& language);

private:
    void updateRows();
    void updateStates();
    void select(const std::string& code);

    Language& m_language;
    std::vector<properdesktop::base::Subscription> m_subscriptions;
    properdesktop::base::Timer m_searchTimer;
    SearchField* m_search;
    properdesktop::ui::ScrollView* m_scroll;
    properdesktop::ui::ColumnLayout* m_rows;
    properdesktop::ui::Label* m_empty;
    Footnote* m_error;
    properdesktop::ui::DialogButton* m_cancel;
    properdesktop::ui::DialogButton* m_add;
    std::string m_selectedCode;
    bool m_adding = false;
};

} // namespace settings
