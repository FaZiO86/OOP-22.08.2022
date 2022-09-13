#include "class.h"
#include <string>
#include <algorithm>
//#include <iostream>
//#include <vector>
using namespace model;
///������������///////////////////////////////////////////////////////////////////////
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
		//���������?
		
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
	//�������� �������
	void Product::showProduct() {
	std::cout << getName() << " ";
	std::cout << getColor() << " ";
	std::cout << getDimensions() << " ";
	}
	//�������� ���� ������� �� ������
	void Stock::showStock() {
		std::cout << "������ ������� �� ������:\n";
		for (auto el : ListTrPos) {
			std::cout << el.getProduct() << ". ���-��: " << el.getAmount() << std::endl;
		}
	}
	//�������� �������� �������
	void Stock::deleteTP(TradePos& obj, int count) {
		auto place = std::find(ListTrPos.begin(), ListTrPos.end(), obj);
		if (place != ListTrPos.end()) { 
			place->setAmount(place->getAmount() - count);
			if (place->getAmount() <= 0) {
				ListTrPos.erase(place);
			}
			std::cout << "������� ������� �� ������!" << std::endl;
		}
		else {
			std::cout << "����� ������� ��� �� ������!" << std::endl;
		}
	}
	//����� �������� �������
	auto Stock::findPos(TradePos pos) {
		auto place = std::find(ListTrPos.begin(), ListTrPos.end(), pos);
		if (place != ListTrPos.end()) {
			std::cout << "������� �������!" << std::endl;
			return true;
		}
		else {
			std::cout << "����� ������� ���!" << std::endl;
			return false;
		}
	}
	//����� ����
	void Cheque::printCheque() {
		
		for (auto el : List) {
			std::cout << "\n������������ ������: " << el.getProduct()
				<< "\n���� �� �����: " << el.getDeliveryPrice()
				<< "\n����� ��������� ������: " << el.getDeliveryPrice() * el.getAmount()
				<< "\n���-��: " << el.getAmount()
				<< "\n���� �������: " << el.getImpPeriod() 
				<< "\n������: " << getName();
		}
	}
	//���������� ������� � ���
	void Cheque::addPosInCheck(Stock& list, TradePos& other, Employees name, int count) {//�����, ��� ��������,��� ����������, ������� ����
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
				std::cout << "�� ���������� ������ �� ������!\n";
			}
		}
		else {
			std::cout << "������ ������ ���!";
		}

	}
	//�������� ������� �� ����
	void Cheque::deletePosInCheck(TradePos list, int count) {
		auto place = std::find(List.begin(), List.end(), list);
		if (place != List.end()) {
			place->setAmount(place->getAmount() - count);
			if (place->getAmount() <= 0) {
				List.erase(place);
			}
			std::cout << "������� ������� �� ����!" << std::endl;
		}
		else {
			std::cout << "����� ������� ��� � ����!" << std::endl;
		}
		
//for (auto& el : List) {
		//	if (el == list) {
		//		el.setAmount(el.getAmount() - count);
		//	}
		//}
	}

	