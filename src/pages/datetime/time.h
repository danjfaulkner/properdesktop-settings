// SPDX-FileCopyrightText: 2026 Reion Wong <reionwong@gmail.com>
// SPDX-License-Identifier: BSD-3-Clause

#pragma once

#include <string>

#include "base/dbus.h"
#include "base/signal.h"

namespace properdesktop::timedate {
class TimeDate;
}

namespace settings {

// Network time, through timedated, and the session's 24-hour clock, which
// properdesktop-services keeps with the region.
class TimeSettings
{
public:
    // `configPath` is properdesktop-services' settings.
    explicit TimeSettings(properdesktop::timedate::TimeDate& timeDate, std::string configPath = defaultConfigPath());

    bool useNtp() const { return m_useNtp; }
    // Shows at once; a refused or cancelled password puts it back.
    void setUseNtp(bool enabled);
    // Whether a network time service is installed.
    bool canNtp() const { return m_canNtp; }

    // The choice made, else the region's clock.
    bool twentyFour() const { return m_twentyFour; }
    void setTwentyFour(bool enabled);

    static std::string defaultConfigPath();

    properdesktop::base::Signal<> useNtpChanged;
    properdesktop::base::Signal<> twentyFourChanged;

private:
    properdesktop::timedate::TimeDate& m_timeDate;
    properdesktop::base::Subscription m_timeDateChanged;
    std::string m_configPath;
    properdesktop::base::dbus::Proxy m_service;
    properdesktop::base::dbus::Match m_changedMatch;
    bool m_canNtp;
    bool m_useNtp;
    bool m_twentyFour;
};

} // namespace settings
