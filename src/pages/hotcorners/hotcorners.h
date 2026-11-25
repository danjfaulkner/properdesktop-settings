// SPDX-FileCopyrightText: 2026 Reion Wong <reionwong@gmail.com>
// SPDX-License-Identifier: BSD-3-Clause

#pragma once

#include <map>
#include <string>

#include "base/dbus.h"
#include "base/signal.h"

namespace settings {

// The compositor's org.properdesktop.HotCorners1: what each screen corner runs.
class HotCorners
{
public:
    HotCorners();

    bool isAvailable() const { return m_available; }

    // corner: top-left, top-right, bottom-left or bottom-right. The action is
    // the compositor's name for it, empty for none.
    std::string action(const std::string& corner) const;
    int modifiers(const std::string& corner) const;
    void setCorner(const std::string& corner, const std::string& action, int modifiers);

    // The modifiers held now, as the compositor sees them.
    int heldModifiers() const;
    // "Option + Shift" and the like, in the session's shortcut convention.
    std::string modifierText(int modifiers) const;

    properdesktop::base::Signal<> changed;

private:
    void reload();

    properdesktop::base::dbus::Proxy m_corners;
    properdesktop::base::dbus::NameWatch m_watch;
    properdesktop::base::dbus::Match m_changedMatch;
    properdesktop::base::dbus::PendingCall m_reload;
    // By corner: a newer change of a corner replaces its older one.
    std::map<std::string, properdesktop::base::dbus::PendingCall> m_calls;
    properdesktop::base::dbus::VariantMap m_properties;
    bool m_available = false;
    bool m_commandKeys = false;
};

} // namespace settings
