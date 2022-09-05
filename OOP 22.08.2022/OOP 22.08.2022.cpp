#include <iostream>
#include <string>
#include "class.h"
#include <ctime>
#include <vector>
#include <list>


using namespace model;
using namespace std;

int main(){
    setlocale(LC_ALL, "ru");
    
    Employees people1 = {123456,"Александр", "Al"};
    Employees people2 = { 4321, "Валера", "Val" };
    Employees people3 = { 12312,"Буратино", "Bool" };
    Security list;
   ////////////////////////////////////////////////////////////////////
    //list.addHuman(people1);
    //list.addHuman(people2);
    //list.addHuman(people3);                           //безопасность
    //list.deleteHuman("Bool");
    //list.print();
   // list.findEmployee("dfgdf");
   // list.print();
   ///////////////////////////////////////////////////////////////////// 

    
   Product rose1 = { "Роза", "Крассная", 10 };
   Product rose2 = { "Роза", "Синяя", 30 };
   Product rose3 = { "Роза", "Жёлтая", 15 };
  
   TradePos  tr1 = { rose1, 10, "21.08.2022" ,120.10};
   TradePos tr2 = { rose2, 5, "21.07.2022", 90.50 };
   TradePos tr3 = { rose3, 30, "14.05.2022", 200 };

   
    
    
    
    
    ///////////////////////////////////////////////////////////////////
}


