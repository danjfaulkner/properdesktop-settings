// SPDX-FileCopyrightText: 2026 Reion Wong <reionwong@gmail.com>
// SPDX-License-Identifier: BSD-3-Clause

#pragma once

#include "ui/view.h"

namespace properdesktop::ui {
class Label;
}

namespace settings {

// Gives every child its whole rect: a list, and an EmptyListOverlay over it.
class StackView : public properdesktop::ui::View
{
protected:
    void layout() override;
};

// A label in the disabled text colour, centred over a list without
// scrolling with it: "Loading…", "Nothing found".
class EmptyListOverlay : public properdesktop::ui::View
{
public:
    EmptyListOverlay();

    properdesktop::ui::Label* label() const { return m_label; }

protected:
    void layout() override;

private:
    properdesktop::ui::Label* m_label;
};

} // namespace settings
