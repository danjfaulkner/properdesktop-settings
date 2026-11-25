// SPDX-FileCopyrightText: 2026 Reion Wong <reionwong@gmail.com>
// SPDX-License-Identifier: BSD-3-Clause

#pragma once

#include <functional>
#include <memory>
#include <optional>
#include <string>
#include <vector>

#include "base/signal.h"
#include "properdesktop/networkmanager/network_model.h"

namespace properdesktop::networkmanager {
class ConnectionSettings;
class Handler;
}

namespace properdesktop::ui {
class ColumnLayout;
class DialogButton;
class DialogWindow;
}

namespace settings {
class InfoRow;
class ListRow;
class SettingsWindow;
class SwitchRow;
}

namespace settings::network {

class IpSettingsView;
class NetworkList;

// A Wi-Fi network's or a wired profile's details: whether it connects by
// itself, its addresses, and the way to its IP settings, which take the
// details' place with a way back in the title bar. The network is followed
// across the list's changes; the dialog closes once it is gone.
class DetailsDialog
{
public:
    enum class Kind {
        Wireless,
        Wired,
    };

    // A saved network is followed by its connection, others by name.
    DetailsDialog(SettingsWindow& window, NetworkList& list, Kind kind,
                  const properdesktop::networkmanager::NetworkItem& item);
    ~DetailsDialog();

    DetailsDialog(const DetailsDialog&) = delete;
    DetailsDialog& operator=(const DetailsDialog&) = delete;

    void show();
    properdesktop::ui::DialogWindow* dialog() const { return m_dialog.get(); }

    std::function<void()> onClosed;

private:
    class Content;

    std::optional<properdesktop::networkmanager::NetworkItem> find() const;
    void update();
    void showIpSettings(bool shown);
    void setSaved(bool saved);
    void close();

    SettingsWindow& m_window;
    NetworkList& m_list;
    Kind m_kind;
    std::string m_connectionPath;
    std::string m_ssid;
    std::unique_ptr<properdesktop::networkmanager::Handler> m_handler;
    std::unique_ptr<properdesktop::networkmanager::ConnectionSettings> m_settings;
    std::unique_ptr<properdesktop::ui::DialogWindow> m_dialog;
    properdesktop::base::Subscription m_subscription;
    properdesktop::networkmanager::NetworkItem m_row;
    bool m_found = false;
    bool m_saved = false;
    bool m_ipSettingsShown = false;

    Content* m_content = nullptr;
    properdesktop::ui::ColumnLayout* m_details = nullptr;
    properdesktop::ui::ColumnLayout* m_savedCard = nullptr;
    SwitchRow* m_autoConnect = nullptr;
    InfoRow* m_wifiType = nullptr;
    InfoRow* m_security = nullptr;
    InfoRow* m_signal = nullptr;
    properdesktop::ui::ColumnLayout* m_addressCard = nullptr;
    InfoRow* m_ipv4 = nullptr;
    InfoRow* m_ipv6 = nullptr;
    InfoRow* m_mac = nullptr;
    InfoRow* m_gateway = nullptr;
    InfoRow* m_dns = nullptr;
    properdesktop::ui::DialogButton* m_disconnect = nullptr;
    ListRow* m_forget = nullptr;
    IpSettingsView* m_ipSettings = nullptr;
};

} // namespace settings::network
