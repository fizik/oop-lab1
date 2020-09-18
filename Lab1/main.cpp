#include <iostream>
#include "tests.h"
#include "lamp.h"
#include "lampcollection.h"

using namespace std;

int main()
{
    //Тестирование класса и пример использования
    testLamps();
    Lamp lamp(60, 90);
    lamp.printParams();
    lamp.setPower(80);
    lamp.setIntensity(120);
    lamp.printParams();
    LampCollection room(5, 7);
    room.getLamp(0, 0).printParams();
    cout << "Illuminance: " << room.getIlluminance(1.2, 2.3, 1.9, 2) << endl;
    return 0;
}
