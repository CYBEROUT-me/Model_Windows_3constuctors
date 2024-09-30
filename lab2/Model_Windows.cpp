#include <iostream>
#include "Model_Windows.h"

using namespace std;


Model_Windows::Model_Windows()
{
    caption = "Recently created";
    l_corner_coordinate_X = 0;
    l_corner_coordinate_Y = 0;
    horizontal_size = 100;
    vertical_size = 100;
    visible = true;
    border = true;
}

void Model_Windows::Read()
{
    cout << endl;
    cout << "\t\t\tREAD" << endl;
    cout << "Input caption: ";
    cin >> caption;

    cout << "Input left corner coordinates(0-1920, 0-1080): \n";

    do {
        cout << "X: ";
        cin >> l_corner_coordinate_X;
        if (l_corner_coordinate_X < 0 || l_corner_coordinate_X > 1920) {
            cout << "Invalid input. Please enter a number between 0 and 1920.\n";
        }
        else {
            break;
        }
    } while (true);


    do {
        cout << "Y: ";
        cin >> l_corner_coordinate_Y;
        if (l_corner_coordinate_Y < 0 || l_corner_coordinate_Y > 1080) {
            cout << "Invalid input. Please enter a number between 0 and 1080.\n";
        }
        else {
            break;
        }
    } while (true);


    do {
        cout << "Input horizontal size: ";
        cin >> horizontal_size;
        if (horizontal_size <= 0) {
            cout << "Invalid input. Please enter a positive number for horizontal size.\n";
        }
        else if (horizontal_size > 1920 - l_corner_coordinate_X)
        {
            horizontal_size = 1920 - l_corner_coordinate_X;
            cout << "Window does not fit in the screen, horizontal size changed to: " << horizontal_size << endl;
            break;
        }
        else {
            break;
        }
    } while (true);


    do {
        cout << "Input vertical size: ";
        cin >> vertical_size;
        if (vertical_size <= 0) {
            cout << "Invalid input. Please enter a positive number for vertical size.\n";
        }
        else if (vertical_size > 1080 - l_corner_coordinate_Y)
        {
            vertical_size = 1080 - l_corner_coordinate_Y;
            cout << "Window does not fit in the screen, vertical size changed to: " << vertical_size << endl;
            break;
        }
        else {
            break;
        }
    } while (true);


    do {
        cout << "If it should be visible - type 1, if not - 0: ";
        cin >> visible;
        if (visible != 0 && visible != 1) {
            std::cout << "Invalid input. Please enter 1 for visible or 0 for not visible.\n";
        }
        else {
            break;
        }
    } while (true);


    do {
        cout << "If it should have borders - type 1, if not - 0: ";
        cin >> border;
        if (border != 0 && border != 1) {
            cout << "Invalid input. Please enter 1 for borders or 0 for no borders.\n";
        }
        else {
            break;
        }
    } while (true);
    cout << endl;
}

void Model_Windows::Display()
{
    cout << endl;
    cout << "\t\t\tDISPLAY" << endl;
    cout << "Caption: " << caption << endl;
    cout << "Left corner coordinates - X: " << l_corner_coordinate_X << " | Y: " << l_corner_coordinate_Y << endl;
    cout << "Horizontal size: " << horizontal_size << endl;
    cout << "Vertical size: " << vertical_size << endl;
    cout << "Visible status: " << visible << endl;
    cout << "Border status: " << border << endl;
    cout << endl;
}

void Model_Windows::Init(string input_caption, int input_l_corner_coordinate_X, int input_l_corner_coordinate_Y, int input_horizontal_size, int input_vertical_size, bool input_visible, bool input_border)
{
    cout << endl;
    cout << "\t\t\tINIT" << endl;

    caption = input_caption;

    int x = input_l_corner_coordinate_X;
    int y = input_l_corner_coordinate_Y;

    if (x < 0 || x > 1920) {
        cout << "Error: X coordinate must be between 0 and 1920. Defaulting to 0.\n";
        l_corner_coordinate_X = 0;
    }
    else {
        l_corner_coordinate_X = x;
    }

    if (y < 0 || y > 1080) {
        cout << "Error: Y coordinate must be between 0 and 1080. Defaulting to 0.\n";
        l_corner_coordinate_Y = 0;
    }
    else {
        l_corner_coordinate_Y = y;
    }


    if (input_horizontal_size <= 0) {
        cout << "Error: Horizontal size must be a positive number. Defaulting to 100.\n";
        horizontal_size = 100;
    }
    else if (input_horizontal_size > 1920 - l_corner_coordinate_X) {
        horizontal_size = 1920 - l_corner_coordinate_X;
        cout << "Window does not fit on the screen, horizontal size changed to: " << horizontal_size << "\n";
    }
    else {
        horizontal_size = input_horizontal_size;
    }

    if (input_vertical_size <= 0) {
        cout << "Error: Vertical size must be a positive number. Defaulting to 100.\n";
        vertical_size = 100;
    }
    else if (input_vertical_size > 1080 - l_corner_coordinate_Y) {
        vertical_size = 1080 - l_corner_coordinate_Y;
        cout << "Window does not fit on the screen, vertical size changed to: " << vertical_size << "\n";
    }
    else {
        vertical_size = input_vertical_size;
    }
    visible = input_visible;

    border = input_border;

    cout << endl;
}

void Model_Windows::MoveHorizontal() {
    cout << endl;
    cout << "\t\t\tMOVE HORIZONTAL" << endl;

    int dx;
    cout << "Enter the horizontal movement (dx): ";
    cin >> dx;

    if (l_corner_coordinate_X + dx >= 0 && l_corner_coordinate_X + dx <= 1920 - horizontal_size) {
        l_corner_coordinate_X += dx;
        cout << "Moved horizontally to X: " << l_corner_coordinate_X << endl;
    }
    else {
        cout << "Movement exceeds screen bounds, operation aborted.\n";
    }
    cout << endl;
}

void Model_Windows::MoveVertical() {
    cout << endl;
    cout << "\t\t\tMOVE VERTICAL" << endl;

    int dy;
    cout << "Enter the vertical movement (dy): ";
    cin >> dy;

    if (l_corner_coordinate_Y + dy >= 0 && l_corner_coordinate_Y + dy <= 1080 - vertical_size) {
        l_corner_coordinate_Y += dy;
        cout << "Moved vertically to Y: " << l_corner_coordinate_Y << endl;
    }
    else {
        cout << "Movement exceeds screen bounds, operation aborted.\n";
    }

    cout << endl;
}

void Model_Windows::Resize() {
    cout << endl;
    cout << "\t\t\tRESIZE" << endl;

    int new_horizontal_size, new_vertical_size;

    cout << "Enter new horizontal size: ";
    cin >> new_horizontal_size;
    cout << "Enter new vertical size: ";
    cin >> new_vertical_size;

    if (new_horizontal_size > 0 && new_horizontal_size <= 1920 - l_corner_coordinate_X) {
        horizontal_size = new_horizontal_size;
        cout << "Horizontal size changed to: " << horizontal_size << endl;
    }
    else {
        cout << "New horizontal size exceeds screen bounds, operation aborted.\n";
    }

    if (new_vertical_size > 0 && new_vertical_size <= 1080 - l_corner_coordinate_Y) {
        vertical_size = new_vertical_size;
        cout << "Vertical size changed to: " << vertical_size << endl;
    }
    else {
        cout << "New vertical size exceeds screen bounds, operation aborted.\n";
    }

    cout << endl;
}

void Model_Windows::SetVisibility() {
    cout << endl;
    cout << "\t\t\tSET VISIBILITY" << endl;

    int input_visible;
    do {
        cout << "Enter 1 if the window should be visible, or 0 if not: ";
        cin >> input_visible;
        if (input_visible != 0 && input_visible != 1) {
            cout << "Invalid input. Please enter 1 or 0.\n";
        }
    } while (input_visible != 0 && input_visible != 1);

    visible = input_visible;
    cout << "Visibility set to: " << (visible ? "Visible" : "Not visible") << endl;

    cout << endl;
}

void Model_Windows::SetBorder() {
    cout << endl;
    cout << "\t\t\tSET BORDERS" << endl;

    int input_border;
    do {
        cout << "Enter 1 if the window should have borders, or 0 if not: ";
        cin >> input_border;
        if (input_border != 0 && input_border != 1) {
            cout << "Invalid input. Please enter 1 or 0.\n";
        }
    } while (input_border != 0 && input_border != 1);

    border = input_border;
    cout << "Border set to: " << (border ? "With border" : "Without border") << endl;

    cout << endl;
}



Model_Windows Model_Windows::operator+(const Model_Windows& other) {
    Model_Windows temp;
    temp.horizontal_size = this->horizontal_size + other.horizontal_size;
    temp.vertical_size = this->vertical_size + other.vertical_size;
    temp.l_corner_coordinate_X = (this->l_corner_coordinate_X + other.l_corner_coordinate_X) / 2;
    temp.l_corner_coordinate_Y = (this->l_corner_coordinate_Y + other.l_corner_coordinate_Y) / 2;
    return temp;
}


bool Model_Windows::operator==(const Model_Windows& other) {
    return (this->horizontal_size == other.horizontal_size && this->vertical_size == other.vertical_size);
}


Model_Windows& Model_Windows::operator=(const Model_Windows& other) {
    if (this != &other) {
        this->caption = other.caption;
        this->l_corner_coordinate_X = other.l_corner_coordinate_X;
        this->l_corner_coordinate_Y = other.l_corner_coordinate_Y;
        this->horizontal_size = other.horizontal_size;
        this->vertical_size = other.vertical_size;
        this->visible = other.visible;
        this->border = other.border;
    }
    return *this;
}
