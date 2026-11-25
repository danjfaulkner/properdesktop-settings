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

class Region;
class SearchField;

// Every region, searched as it is typed, the current one checked; Choose
// makes the checked one the session's region.
class ChooseRegionDialog : public FormDialog
{
public:
    ChooseRegionDialog(SettingsWindow& parent, Region& region);

private:
    void updateRows();
    void updateStates();
    void select(const std::string& code);

    Region& m_region;
    std::vector<properdesktop::base::Subscription> m_subscriptions;
    properdesktop::base::Timer m_searchTimer;
    SearchField* m_search;
    properdesktop::ui::ScrollView* m_scroll;
    properdesktop::ui::ColumnLayout* m_rows;
    properdesktop::ui::Label* m_empty;
    properdesktop::ui::DialogButton* m_choose;
    std::string m_selectedCode;
    bool m_revealSelection = true;
};

} // namespace settings
