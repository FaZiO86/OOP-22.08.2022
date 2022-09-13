#include "class.h"
#include <string>
#include <algorithm>
//#include <iostream>
//#include <vector>
using namespace model;
///Конструкторы///////////////////////////////////////////////////////////////////////
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
	Stock::Stock(std::vector<TradePos> list) {
		for (auto el : ListTrPos) {
			ListTrPos = list;
		}
	}
	Cheque::Cheque(std::vector<TradePos> list, Employees name,std::string time) {
		//правильно?
		
		for (auto el : list) {
			List.push_back(el);
		}
		Name = name.getName();
		Time = time;
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

//////////////////////////////////////////////////////////////////////////////////////////////////////////
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
	//Показать продукт
	void Product::showProduct() {
	std::cout << getName() << " ";
	std::cout << getColor() << " ";
	std::cout << getDimensions() << " ";
	}
	//просмотр всех позиций на складе
	void Stock::showStock() {
		std::cout << "Список товаров на складе:\n";
		for (auto el : ListTrPos) {
			std::cout << el.getProduct() << ". кол-во: " << el.getAmount() << std::endl;
		}
	}
	//удаление торговой позиции
	void Stock::deleteTP(TradePos& obj, int count) {
		auto place = std::find(ListTrPos.begin(), ListTrPos.end(), obj);
		if (place != ListTrPos.end()) { 
			place->setAmount(place->getAmount() - count);
			if (place->getAmount() <= 0) {
				ListTrPos.erase(place);
			}
			std::cout << "Позиция удалена со склада!" << std::endl;
		}
		else {
			std::cout << "Такой позиции нет на складе!" << std::endl;
		}
	}
	//Поиск торговой позиции
	auto Stock::findPos(TradePos pos) {
		auto place = std::find(ListTrPos.begin(), ListTrPos.end(), pos);
		if (place != ListTrPos.end()) {
			std::cout << "Позиция найдена!" << std::endl;
			return true;
		}
		else {
			std::cout << "Такой позиции нет!" << std::endl;
			return false;
		}
	}
	//вывод чека
	void Cheque::printCheque() {
		
		for (auto el : List) {
			std::cout << "\nНаименование товара: " << el.getProduct()
				<< "\nЦена за штуку: " << el.getDeliveryPrice()
				<< "\nОбщая стоимость товара: " << el.getDeliveryPrice() * el.getAmount()
				<< "\nкол-во: " << el.getAmount()
				<< "\nДата продажи: " << el.getImpPeriod() 
				<< "\nПродал: " << getName();
		}
	}
	//добавление позиции в чек
	void Cheque::addPosInCheck(Stock& list, TradePos& other, Employees name, int count) {//склад, что покупаем,имя сотрудника, сколько штук
		if (list.findPos(other) == true) {
			if (other.getAmount() > count) {
				List.emplace_back(other);
				auto place = std::find(List.begin(), List.end(), other);
				if (place != List.end()) {
					place->setAmount(count);
				}
				list.deleteTP(other, count);
				Name = name.getName();
			}
			else{
				std::cout << "не достаточно товара на складе!\n";
			}
		}
		else {
			std::cout << "Такого товара нет!";
		}

	}
	//Удаление позиции из чека
	void Cheque::deletePosInCheck(TradePos list, int count) {
		auto place = std::find(List.begin(), List.end(), list);
		if (place != List.end()) {
			place->setAmount(place->getAmount() - count);
			if (place->getAmount() <= 0) {
				List.erase(place);
			}
			std::cout << "Позиция удалена из чека!" << std::endl;
		}
		else {
			std::cout << "Такой позиции нет в чеке!" << std::endl;
		}
		
//for (auto& el : List) {
		//	if (el == list) {
		//		el.setAmount(el.getAmount() - count);
		//	}
		//}
	}

	