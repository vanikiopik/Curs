#pragma once
#include <iostream>
#include <string>

std::string StringInput(std::string_view message);
std::string StringInput(std::string_view message, std::string_view invalidChars);
