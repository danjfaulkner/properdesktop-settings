find_package(ProperDesktopClients REQUIRED COMPONENTS bluez)
target_link_libraries(settings-core PUBLIC ProperDesktop::BluezClient)
