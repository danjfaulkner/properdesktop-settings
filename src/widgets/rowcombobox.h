// SPDX-FileCopyrightText: 2026 Reion Wong <reionwong@gmail.com>
// SPDX-License-Identifier: BSD-3-Clause

#pragma once

#include "ui/row_combo_box.h"
#include "widgets/listrow.h"

namespace settings {

// The toolkit's list-row choice, which a list row lets reach past its content edge.
class RowComboBox : public properdesktop::ui::RowComboBox, public TrailingOverhang
{
public:
    using properdesktop::ui::RowComboBox::RowComboBox;

    double trailingOverhang() const override { return properdesktop::ui::RowComboBox::trailingOverhang(); }
};

} // namespace settings
