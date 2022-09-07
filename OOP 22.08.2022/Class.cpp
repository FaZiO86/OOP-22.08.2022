#include "class.h"
#include <string>
#include <algorithm>
//#include <iostream>
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

	Stock::Stock(std::vector<TradePos> list) {
		for (auto el : ListTrPos) {
			ListTrPos = list;
			//ListTrPos.emplace_back(list);
		}
	}

	Cheque::Cheque(std::vector<TradePos> list) {
		//���������?
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
	//�������� ����������
	void Employees::showEmployees() {
			std::cout << getName() << " ";
			std::cout << getLogin() << " ";
			std::cout << getPasportID() << std::endl;
	}
	//����� ���� �����������
	void Security::print() {
		for (auto& el : Humans) {
			el.showEmployees();
		}
	}
	//������� ����������
	void Security::deleteHuman(std::string login) {
		//������� ������!!!
		auto it = std::find_if(Humans.begin(), Humans.end(),
			[login](Employees& t)->bool{
				return t.getLogin() == login;
			});
		if (it != Humans.end()) {
			std::cout << "������������ �����!" << std::endl;
			Humans.erase(it);
		}else{
			std::cout << "������ ������������ �� ����������!" << std::endl;
		}
		
	}  
	//����� ����������
	void Security::findEmployee(std::string name) {		
		for (auto it : Humans) {
			if (it.getName() == name) {
				std::cout << "����� ������������ ����������!" << std::endl;
				return;
			}
			
		}
		std::cout << "������ ������������ ���!" << std::endl;
		
	}
	//�������� ���� ������� �� ������
	void Stock::showStock() {
		std::cout << "������ ������� �� ������:\n";
		for (auto el : ListTrPos) {
			std::cout << el.getProduct() << ". ���-��: " << el.getAmount() << std::endl;
		}
	}
	//����� ����
	void Cheque::printCheque(std::vector<TradePos> list) {
		//for (auto el : list) {
		//	 
		//}
	}



	