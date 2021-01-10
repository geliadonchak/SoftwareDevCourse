#include <fstream>

#include "config.h"
#include "../external/json.h"

config_t Config::characters_;

void Config::init(const std::string& filename) {
    std::ifstream ifs(filename);
    nlohmann::json j = nlohmann::json::parse(ifs);

    auto characters = j["characters"];
    for (auto it = characters.begin(); it != characters.end(); ++it) {
        config_parameters_t parameters;
        auto character_params = it.value();
        for (auto it_param = character_params.begin(); it_param != character_params.end(); ++it_param) {
            parameters[static_cast<std::string>(it_param.key())] = static_cast<int>(it_param.value());
        }

        Config::characters_[static_cast<std::string>(it.key())] = parameters;
    }
}

config_parameters_t Config::get_character_parameters(const std::string &character) {
    return characters_.at(character);
}
