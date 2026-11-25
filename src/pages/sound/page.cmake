find_package(ProperDesktopClients REQUIRED COMPONENTS audio)
target_link_libraries(settings-core PUBLIC ProperDesktop::AudioClient)
