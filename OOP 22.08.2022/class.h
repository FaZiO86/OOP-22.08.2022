#pragma once
#include <string>
#include <vector>
#include <iostream>

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
		friend std::ostream& operator<<(std::ostream& out, const Product& r) {
			return out << r.Name << " " << r.Color;
		}
		
		bool operator==(const Product& other) {
		
			return this->Name == other.Name &&
				this->Color == other.Color &&
				this->Dimensions == other.Dimensions;
			
		}
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
		void showProduct() {
			std::cout << getName() << " ";
			std::cout << getColor() << " ";
			std::cout << getDimensions() << " ";
		}
		
		

	private:
		std::string Name;
		std::string Color;
		int Dimensions; //размер
	};
	//торговая позиция
	class TradePos {
	public:
		friend std::ostream& operator<<(std::ostream& out, const TradePos& r) {
			return out << r.Product_ << r.Amount;
		}
		bool operator==(const TradePos other) {
			
			return this->Product_ == other.Product_ && 
				/*this->Amount == other.Amount &&*/
				this->DeliveryPrice == other.DeliveryPrice && 
				this->ImpPeriod == other.ImpPeriod;
				
		}
		
		TradePos(){};
		TradePos(Product product, int amount, std::string impPeriod, float deliveryPrice);
		
		void setProduct(Product product) {
			Product_ = product;
		}
		Product getProduct() {
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
		void showTradePos() {
			std::cout << Product_ << " " << getAmount() << " " << getDeliveryPrice();
		}
		///
		
		
		
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
		TradePos operator [](int i) {
			return ListTrPos[i];
		}
		Stock getStock() {
			return ListTrPos;
		}

		//показать список торговых позиций на складе всего!
		void showStock();
		
		//добавление торговой позиции на склад
		void addTP(TradePos &list) {
			ListTrPos.emplace_back(list);
		}
		
		//Удаление торговой позиции
		void deleteTP(TradePos& obj);
		
		//поиск торговой позиции
		auto findPos(TradePos pos) {
			auto place = std::find(ListTrPos.begin(), ListTrPos.end(), pos);
			if (place != ListTrPos.end()) {
				std::cout << "Позиция найдена!" << std::endl;
				return true;
			}
			else {
				std::cout << "Такой позиции нет на складе!" << std::endl;
				return false;
			}
		}
		
	private:
		std::vector<TradePos> ListTrPos;
	};
	
	//чек
	class Cheque {
	public:
		Cheque(){}
		Cheque(std::vector<TradePos> &list, Employees name, int Count);
		void setCount(int count) {
			Count = count;
		}
		const int getCount() {
			return Count;
		}
		void setTime(std::string time) {
			Time = time;
		}
		std::string getTime() {
			return Time;
		}
		void setName(Employees name) {
			Name = name.getName();
		}
		std::string getName() {
			return Name;
		}
		//добавление позиции в чек
		void addPosInCheck(Stock &list, TradePos &other, Employees name, int count) {//склад, что покупаем, сколько штук
			if (list.findPos(other) == true) {
				List.emplace_back(other);
				Count = count;
				//other.setAmount(count);
				list.deleteTP(other);
				Name = name.getName();
			}
			else {
				std::cout << "Такого товара нет!";
			}
			
		}
		

		//Вывод чека
		void printCheque();

	private:
		std::vector<TradePos> List;//позиция в чеке
		std::string Name;//кто продал
		std::string Time;//Время продажи
		int Count;
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