find_package(ProperDesktopClients REQUIRED COMPONENTS display)
target_link_libraries(settings-core PUBLIC ProperDesktop::DisplayClient)
