#pragma once
#include <string>

using namespace std;

class Model_Windows 
{
private:
	string caption;
	int l_corner_coordinate_X;
	int l_corner_coordinate_Y;
	int horizontal_size;
	int vertical_size;
	bool visible;
	bool border;
	

public:
	Model_Windows();

	void Init(string caption, int l_corner_coordinate_X, int l_corner_coordinate_Y, int horizontal_size, int vertical_size, bool visible, bool border);
	
	void Read();

	void Display();

	void MoveHorizontal();
	void MoveVertical();

	void Resize();

	void SetVisibility();

	void SetBorder();
};