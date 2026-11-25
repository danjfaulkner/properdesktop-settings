// SPDX-FileCopyrightText: 2026 Reion Wong <reionwong@gmail.com>
// SPDX-License-Identifier: BSD-3-Clause

#pragma once

#include <string>
#include <vector>

#include "base/dbus.h"
#include "base/signal.h"

namespace settings {

// The compositor's org.properdesktop.ComputerControl1: the apps whose agents may
// control the computer without asking.
class ComputerControl
{
public:
    struct App
    {
        std::string path;
        // The agent's name for itself, and its application's desktop entry.
        std::string name;
        std::string appId;
    };

    ComputerControl();

    bool isAvailable() const { return m_available; }
    const std::vector<App>& allowedApps() const { return m_apps; }
    void forget(const std::string& path);

    properdesktop::base::Signal<> changed;

private:
    void reload();

    properdesktop::base::dbus::Proxy m_control;
    properdesktop::base::dbus::NameWatch m_watch;
    properdesktop::base::dbus::Match m_changedMatch;
    properdesktop::base::dbus::PendingCall m_reload;
    properdesktop::base::dbus::PendingCall m_forget;
    std::vector<App> m_apps;
    bool m_available = false;
};

} // namespace settings
