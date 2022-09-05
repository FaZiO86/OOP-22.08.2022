#include "class.h"
#include <string>
#include <algorithm>
//#include <ostream>
//#include <vector>
using namespace model;

	Employees::Employees(int pasportID, std::string name, std::string login) {
		PasportID = pasportID;
		Name = name;
		Login = login;
	}

	Product::Product(std::string name, std::string color, int dimensions) {
		Name = name;
		Color = color;
		Dimensions = dimensions;
	}

	Stock::Stock(std::list<Product> list) {
		for (auto& el : list) {
			List = list;
		}
	}

	Cheque::Cheque(std::vector<TradePos> list) {
		for (auto& el : list) {
			List = list;
		}
	}

	Security::Security(std::vector<Employees> humans) {
		for (auto& el : humans) {
			Humans = humans;
		}
	}

	TradePos::TradePos(Product product, int amount, std::string impPeriod, float deliveryPrice) {
		Product_ = product;
		Amount = amount;
		ImpPeriod = impPeriod;
		DeliveryPrice = deliveryPrice;
	}
	//показать сотрудникА
	void Employees::showEmployees() {
			std::cout << getName() << " ";
			std::cout << getLogin() << " ";
			std::cout << getPasportID() << std::endl;
	}
	//вывод всех сотрудников
	void Security::print() {
		for (auto& el : Humans) {
			el.showEmployees();
		}
	}
	//удалить сотрудника
	void Security::deleteHuman(std::string login) {
		//Изучить лямбду!!!
		auto it = std::find_if(Humans.begin(), Humans.end(),
			[login](Employees& t)->bool{
				return t.getLogin() == login;
			});
		if (it != Humans.end()) {
			std::cout << "Пользователь удалён!" << std::endl;
			Humans.erase(it);
		}else{
			std::cout << "Такого пользователя не существует!" << std::endl;
		}
		
	}  
	//найти сотрудника
	void Security::findEmployee(std::string name) {		
		for (auto it : Humans) {
			if (it.getName() == name) {
				std::cout << "Такой пользователь существует!" << std::endl;
				return;
			}
			
		}
		std::cout << "Такого пользователя нет!" << std::endl;
		
	}

	