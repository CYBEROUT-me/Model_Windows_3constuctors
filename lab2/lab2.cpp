#include <iostream>
#include "Model_Windows.h"

int main()
{
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
}