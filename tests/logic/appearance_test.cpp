// SPDX-FileCopyrightText: 2026 Reion Wong <reionwong@gmail.com>
// SPDX-License-Identifier: BSD-3-Clause

#include <gtest/gtest.h>

#include "properdesktop/appearance/appearance.h"

// The tests run on a private bus, where no appearance service answers: a
// change goes out, and the value stays until the service reports one, as
// the Qt version's did.
TEST(AppearanceClient, WaitsForTheServiceToReportAChange)
{
    properdesktop::appearance::Appearance appearance;
    int changes = 0;
    properdesktop::base::Subscription subscription = appearance.changed.connect([&changes] { ++changes; });
    const int accent = appearance.accentColor();
    appearance.setAccentColor(accent + 1);
    appearance.setDarkModeSchedule(properdesktop::appearance::Appearance::SunsetToSunrise);
    EXPECT_EQ(appearance.accentColor(), accent);
    EXPECT_EQ(appearance.darkModeSchedule(), int(properdesktop::appearance::Appearance::Never));
    EXPECT_EQ(changes, 0);
}
