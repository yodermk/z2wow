#include <vector>
#include <yaml-cpp/yaml.h>
#include "Configuration.h"

Configuration::Configuration() {
    std::vector<std::filesystem::path> check_files {"./z2wow.conf", "~/z2wow.conf", "/etc/z2wow.conf"};

    // tried using find_if but path::exists doesn't seem to work as a predicate :/
    for (auto &p : check_files) {
        if (std::filesystem::exists(p)) {
            using_file = p;
            break;
        } else {
            throw ConfigError("Configuration file not found.");
        }
    }

    YAML::Node config = YAML::LoadFile(using_file);
    if (!config.IsMap())
        throw ConfigError("Top level YAML must be a dictionary.");



}
