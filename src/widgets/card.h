// SPDX-FileCopyrightText: 2026 Reion Wong <reionwong@gmail.com>
// SPDX-License-Identifier: BSD-3-Clause

#pragma once

#include "ui/painter.h"
#include "ui/cell_layout.h"

namespace settings {

// A rounded panel on a page in FishUI's second background colour: the
// RoundedItem's ColumnLayout, its rows its children. A list card holds
// ListRows edge to edge, without padding, so a row's press background
// reaches the card's edge and its corners follow the card's.
class Card : public properdesktop::ui::ColumnLayout
{
public:
    enum class Style {
        Padded,
        List,
    };

    explicit Card(Style style = Style::Padded);

protected:
    void paint(properdesktop::ui::Painter& painter) override;
};


// Kept for pages written before the toolkit had it; new code calls
// properdesktop::ui::themeCorners().
inline properdesktop::ui::Corners panelCorners()
{
    return properdesktop::ui::themeCorners();
}

} // namespace settings
