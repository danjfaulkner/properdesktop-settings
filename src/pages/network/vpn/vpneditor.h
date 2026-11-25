// SPDX-FileCopyrightText: 2026 Reion Wong <reionwong@gmail.com>
// SPDX-License-Identifier: BSD-3-Clause

#pragma once

#include <functional>
#include <map>
#include <memory>
#include <string>
#include <vector>

#include "properdesktop/networkmanager/handler.h"
#include "pages/network/vpn/vpnformmodel.h"
#include "ui/cell_layout.h"

namespace properdesktop::ui {
class TextField;
}

namespace settings {
class Card;
class Footnote;
class SwitchRow;
}

namespace settings::network {

class PluginForm;
class WireGuardEditor;

// What a VPN profile is made of, for the Add VPN and details dialogs: its
// name, the fields of its kind, and who may use it, filled from and typed
// into its VpnFormModel.
class VpnEditor : public properdesktop::ui::ColumnLayout
{
public:
    VpnEditor();
    ~VpnEditor() override;

    void load(const properdesktop::networkmanager::VpnForm& form);
    void setSecrets(const properdesktop::networkmanager::VpnSecrets& secrets);
    properdesktop::networkmanager::VpnValues collect() const;
    void focusFirst();

    const VpnFormModel& model() const { return m_model; }
    const properdesktop::networkmanager::VpnForm& form() const { return m_model.form(); }
    bool installed() const { return m_model.installed(); }
    bool complete() const;

    // Return in a field.
    std::function<void()> onAccepted;
    // Anything that changes complete() or the size.
    std::function<void()> onChanged;

private:
    void changed();

    VpnFormModel m_model;
    Footnote* m_notInstalled;
    // The name, then the first rows of the profile's kind.
    Card* m_basic;
    properdesktop::ui::TextField* m_name;
    PluginForm* m_plugin = nullptr;
    WireGuardEditor* m_wireGuard = nullptr;
    Card* m_switches;
    SwitchRow* m_shared;
    SwitchRow* m_ownNetworkOnly;
};

} // namespace settings::network
