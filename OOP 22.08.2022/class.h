#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <list>
#include <ctime>

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
		//ћетод вывода сотрудника
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
									//ћетоды
		//показать товар    можно не делать...
		

	private:
		std::string Name;
		std::string Color;
		int Dimensions;
	};
	//—клад
	class Stock {
	public:
		Stock(){}
		Stock(std::list<Product> list);
	private:
		std::list<Product> List;
	};
	//торгова€ позици€
	class TradePos {
	public:
		TradePos(){}
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
	private:
		Product Product_;
		int Amount;
		std::string ImpPeriod;
		float DeliveryPrice;
		
	};
	//чек
	class Cheque {
	public:
		Cheque(){}
		Cheque(std::vector<TradePos> list);
		//¬ывод чека
		void printCheque(std::vector<TradePos> list) {

		}
	private:
		std::vector<TradePos> List;
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