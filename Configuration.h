#ifndef Z2WOW_CONFIGURATION_H
#define Z2WOW_CONFIGURATION_H

#include <filesystem>
#include <memory>
#include <string>
#include <utility>

class ConfigError : public std::exception {
    std::string msg;
public:
    explicit ConfigError(std::string imsg) : msg(std::move(imsg)) {}

    [[nodiscard]] const std::string &getMsg() const {
        return msg;
    }
};

class Configuration {
    std::filesystem::path using_file;
    static Configuration* instance;
protected:
    Configuration();
public:
    static Configuration* getInstance() {
        if (!instance) {
            instance = new Configuration();
        }
        return instance;
    }

    std::filesystem::path filesystem_root;
    unsigned short port = 8080;

    Configuration(Configuration const&) = delete;
    Configuration(Configuration&&) = delete;
    Configuration& operator=(Configuration const&) = delete;
    Configuration& operator=(Configuration&&) = delete;
};


#endif //Z2WOW_CONFIGURATION_H
