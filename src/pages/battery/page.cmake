find_package(ProperDesktopClients REQUIRED COMPONENTS upower)
target_link_libraries(settings-core PUBLIC ProperDesktop::UPowerClient)
