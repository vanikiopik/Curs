#pragma once
#include <iostream>
#include <string>

std::string StringInput(std::string_view message);
std::string StringInput(std::string_view message, std::string_view invalidChars);

int IntInput(std::string message);
int IntPositiveInput(std::string message);
int IntProductIDInput(std::string message);

float FloatMoneyInput(std::string message);