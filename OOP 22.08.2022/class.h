#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <ctime>
//#include <list>

namespace model {

	



	//сотрпудники
	class Employees {
	public:
		Employees() {}
		Employees(int pasportID, std::string name, std::string login);
		void setPasportID(int id) {
			PasportID = id;
		}
		const int getPasportID() {
			return PasportID;
		}
		void setName(std::string name) {
			Name = name;
		}
		const std::string getName() {
			return Name;
		}
		void setLogin(std::string login) {
			Login = login;
		}
		const std::string getLogin() {
			return Login;
		}
		//Метод вывода сотрудника
		void showEmployees();
	private:
		int PasportID = 0;
		std::string Name = "";
		std::string Login;
	};
	//товары
	class Product {
	public:
		Product(){}
		Product(std::string name, std::string color, int dimensions);
		void setName(std::string name) {
			Name = name;
		}
		const std::string getName() {
			return Name;
		}
		void setColor(std::string color) {
			Color = color;
		}
		const std::string getColor() {
			return Color;
		}
		void setDimensions(int dimensions) {
			Dimensions = dimensions;
		}
		const int getDimensions() {
			return Dimensions;
		}
									//Методы
		//показать товар    можно не делать...
		

	private:
		std::string Name;
		std::string Color;
		int Dimensions;
	};
	//торговая позиция
	class TradePos {
	public:
		TradePos() {}
		TradePos(Product product, int amount, std::string impPeriod, float deliveryPrice);
		void setProduct(Product product) {
			Product_ = product;
		}
		const Product getProduct() {
			return Product_;
		}
		void setAmount(int amount) {
			Amount = amount;
		}
		const int getAmount() {
			return Amount;
		}
		void setImpPeriod(std::string impPeriod) {
			ImpPeriod = impPeriod;
		}
		const std::string getImpPeriod() {
			return ImpPeriod;
		}
		void setDeliveryPrice(float deliveryPrice) {
			DeliveryPrice = deliveryPrice;
		}
		const float getDeliveryPrice() {
			return DeliveryPrice;
		}
		//методы
		

	private:
		Product Product_; //товар
		int Amount;//количество
		std::string ImpPeriod;//дата продажи
		float DeliveryPrice;//цена поставки

	};
	
	//Склад
	
	class Stock {
	public:
		Stock(){}
		Stock(std::vector<TradePos> list);
		Stock getListTrPos() {
			return ListTrPos;
		}
		//добавление торговой позиции на склад
		void addProduct(TradePos list) {
			ListTrPos.push_back(list);
		}
		//изменение торговой позиции
		//void changeInTrPos(TradePos list, std::string name) {
		//	for (auto it : ListTrPos) {
		//		if ( == name) {
		//			std::cout << "Такой пользователь существует!" << std::endl;
		//			return;
		//		}
		//
		//	}
		//}
		//поиск торговой позиции
		//void SearchTP(std::string name) {
		//	for (auto it : ListTrPos) {
		//			if (it.getProduct() == name) {
		//				std::cout << "Такой товар есть!" << std::endl;
		//				return;
		//			}
		//		
		//	}
		//}
		//

		
	private:
		std::vector<TradePos> ListTrPos;
	};
	
	//чек
	class Cheque {
	public:
		Cheque(){}
		Cheque(std::vector<TradePos> list);
		
		
		//Вывод чека
		void printCheque(std::vector<TradePos> list);

	private:
		std::vector<TradePos> List;//торговая позиция
		Employees Name;//кто продал
		std::string time;//Время продажи
		
	};
	//система безопасности
	class Security {
	public:
		Security(){}
		Security(std::vector<Employees> humans);
		//добавить сотрудника
		void addHuman(Employees human) {
			Humans.push_back(human);
		}
		//удалить сотрудника								
		void deleteHuman(std::string login);
		//найти сотрудника
		void findEmployee(std::string name);

		//вывод всех сотрудников
		void print();
	private:
		std::vector<Employees> Humans;
	};


}