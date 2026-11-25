find_package(ProperDesktopClients REQUIRED COMPONENTS bluez)
target_link_libraries(settings-core PUBLIC ProperDesktop::BluezClient)

if(BUILD_TESTING)
    # The scenario tests' fake BlueZ answers sd-bus calls for any object path.
    find_package(PkgConfig REQUIRED)
    pkg_check_modules(Systemd REQUIRED IMPORTED_TARGET libsystemd)
    cmake_language(DEFER CALL target_link_libraries settings-scenario-tests PRIVATE PkgConfig::Systemd)
endif()
