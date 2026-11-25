find_package(ProperDesktopClients REQUIRED COMPONENTS accounts)
find_library(SETTINGS_CRYPT_LIBRARY crypt REQUIRED)
target_link_libraries(settings-core PUBLIC ProperDesktop::AccountsClient ${SETTINGS_CRYPT_LIBRARY})
