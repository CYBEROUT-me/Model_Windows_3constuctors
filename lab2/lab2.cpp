#include <iostream>
#include "Model_Windows.h"

int main()
{
    /*
    Model_Windows b;
    b.Display();

    Model_Windows c;
    c.Init("Init windows", 0, 0, 200, 200, false, true);
    c.Display();

    Model_Windows a;


    a.Read();
    a.Display();
    a.MoveHorizontal();
    a.MoveVertical();
    a.Resize();
    a.SetVisibility();
    a.SetBorder();
    a.Display();
    */


    Model_Windows a, b;
    a.Init("Window 1", 100, 100, 200, 300, true, true);
    cout << "a: " << endl;
    a.Display();

    b.Init("Window 2", 200, 150, 150, 200, false, false);
    cout << "b: " << endl;
    b.Display();

    Model_Windows c = a + b;
    cout << "After addition (a + b):" << endl;
    c.Display();

    if (a == b) {
        cout << "a and b have the same size." << endl;
    }
    else {
        cout << "a and b have different sizes." << endl;
    }

    Model_Windows d;
    cout << "d before (d=a): " << endl;
    d.Display();

    d = a;
    cout << "After assignment (d = a):" << endl;
    d.Display();

    return 0;
}