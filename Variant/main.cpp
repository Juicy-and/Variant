#include <iostream>
#include <vector>
#include <string>
#include <variant>

std::variant<int, std::string, std::vector<int>> get_variant() {
	std::srand(std::time(nullptr));
	int random_variable = std::rand() % 3;
	std::variant<int, std::string, std::vector<int>> result;
	switch (random_variable)
	{
	case 0:
		result = 5;
		break;
	case 1:
		result = "string";
		break;
	case 2:
		result = std::vector<int>{ 1, 2, 3, 4, 5 };
		break;
	default:
		break;
	}
	return result;
}

int main() {
		std::variant<int, std::string, std::vector<int>> var_o = get_variant();
		auto var_int = std::get_if<int>(&var_o);
		auto var_string = std::get_if<std::string>(&var_o);
		auto var_vector = std::get_if<std::vector<int>>(&var_o);
		if (var_int != nullptr)
			std::cout << *var_int * 2;
		if (var_string != nullptr)
			std::cout << *var_string;
		if(var_vector != nullptr)
			for (auto& i : *var_vector)
				std::cout << i << " ";
};