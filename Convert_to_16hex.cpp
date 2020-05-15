/* Напишите программу, которая конвертирует введенное пользователем десятичное число 
в шестнадцатеричную систему счисления. */

#include <iostream>
#include <string>

// получает натуральное число от пользователя
unsigned get_number()
{
	std::cout << "Введите натуральное число: ";
	int answer;
	std::cin >> answer;
	while (std::cin.fail() || (answer < 0))
	{
		std::cin.clear();
		std::cin.ignore(1000, '\n');
		std::cout << "Нужно ввести натуральное число, повторите ввод: ";
		std::cin >> answer;
	}
	return static_cast<unsigned>(answer);
}

// переводит число в 16-ричную запись (возвращает строку)
std::string convert_to_hex(unsigned number)
{
	std::string hex_number{};                      // строковая переменная для 16-ричной записи
	while (number != 0)
	{
		unsigned short modulo{ number % 16 };      // остаток от деления на 16
		std::string char_to_add;                   // остаток от деления на 16 как один из симоволов 123456789ABCDEF
		if (modulo < 10)
			char_to_add = std::to_string(modulo);  // 1-9
		else 
			char_to_add = (modulo-10) + 65;        // 65 - код символа A, результат будет один из ABCDEF
		hex_number.insert(0, char_to_add);         // добавляем полученный символ в начало 16-ричной записи (индекс 0)
		number /= 16;
	}
	return hex_number;
}

int main()
{
    setlocale(LC_CTYPE, "rus");                          // подключаем кириллицу

    std::cout << "Программа переводит число в 16-ричную запись.\n";
	unsigned given_number{ get_number() };

	std::cout << "Это же число в 16-ричной записи:  ";
	std::cout.setf(std::ios::hex, std::ios::basefield);  // включаем 16-ричную СИ, отключаем все противоречащие флаги группы
	std::cout.setf(std::ios::uppercase);                 // включаем большие буквы
	std::cout << given_number << std::endl;
	
	std::cout << "То же, но с самописным переводом: ";
	std::cout << convert_to_hex(given_number) << std::endl;
	
	return 0;
}