// SPDX-FileCopyrightText: 2026 Reion Wong <reionwong@gmail.com>
// SPDX-License-Identifier: BSD-3-Clause

#pragma once

#include <string>

#include "ui/view.h"

namespace properdesktop::ui {
class Icon;
}

namespace settings {

class Picture;

// The sidebar's tile: a coloured rounded square with a white glyph, for the
// sidebar and a list row's leading slot. The glyph is one of settings'
// sidebar pictures, or a toolkit glyph when the name has no ".svg".
class RowIcon : public properdesktop::ui::View
{
public:
    RowIcon(std::string glyph, properdesktop::ui::Color tint);

    void set(std::string glyph, properdesktop::ui::Color tint);

    properdesktop::ui::SizeF sizeHint() const override { return {24, 24}; }

protected:
    void layout() override;
    void paint(properdesktop::ui::Painter& painter) override;

private:
    properdesktop::ui::Color m_tint;
    Picture* m_picture;
    properdesktop::ui::Icon* m_glyph;
};

} // namespace settings
