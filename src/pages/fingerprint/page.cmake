find_package(ProperDesktopClients REQUIRED COMPONENTS fprint)
target_link_libraries(settings-core PUBLIC ProperDesktop::FprintClient)
