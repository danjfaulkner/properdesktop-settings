// SPDX-FileCopyrightText: 2026 Reion Wong <reionwong@gmail.com>
// SPDX-License-Identifier: BSD-3-Clause

#pragma once

#include <functional>
#include <memory>
#include <string>
#include <vector>

#include "base/signal.h"
#include "properdesktop/networkmanager/ip_utils.h"
#include "ui/cell_layout.h"

namespace properdesktop::networkmanager {
class Handler;
}

namespace properdesktop::ui {
class DialogButton;
class TextField;
}

namespace settings {
class Card;
class Footnote;
class RowComboBox;
class SwitchRow;
class TextFieldRow;
}

namespace settings::network {

// How a saved network gets its addresses and name servers, shown in place of
// its details. Save writes the profile and applies it to the connection at
// once; onFinished follows a save.
class IpSettingsView : public properdesktop::ui::ColumnLayout
{
public:
    explicit IpSettingsView(std::string connectionPath);
    ~IpSettingsView() override;

    std::function<void()> onFinished;

private:
    RowComboBox* addMethod(Card* card, const std::string& text);
    TextFieldRow* addField(Card* card, const std::string& text, const std::string& placeholder);
    void load();
    properdesktop::networkmanager::ip::Form collect() const;
    void fillFromCurrent(bool v4);
    void save();
    void update();

    std::string m_connectionPath;
    std::unique_ptr<properdesktop::networkmanager::Handler> m_handler;
    std::vector<properdesktop::base::Subscription> m_subscriptions;
    properdesktop::networkmanager::ip::Form m_form;
    bool m_saving = false;
    std::string m_error;

    RowComboBox* m_ipv4Method;
    TextFieldRow* m_ipv4AddressRow;
    properdesktop::ui::TextField* m_ipv4Address;
    TextFieldRow* m_ipv4NetmaskRow;
    properdesktop::ui::TextField* m_ipv4Netmask;
    TextFieldRow* m_ipv4GatewayRow;
    properdesktop::ui::TextField* m_ipv4Gateway;
    RowComboBox* m_ipv6Method;
    TextFieldRow* m_ipv6AddressRow;
    properdesktop::ui::TextField* m_ipv6Address;
    TextFieldRow* m_ipv6PrefixRow;
    properdesktop::ui::TextField* m_ipv6Prefix;
    TextFieldRow* m_ipv6GatewayRow;
    properdesktop::ui::TextField* m_ipv6Gateway;
    SwitchRow* m_automaticDns;
    properdesktop::ui::TextField* m_dns;
    Footnote* m_message;
    properdesktop::ui::DialogButton* m_cancelButton;
    properdesktop::ui::DialogButton* m_saveButton;
};

} // namespace settings::network
