#include <iostream>
#include "string.h"
using namespace std;

#pragma region Backgrounds
// Base Background class
class Background
{
protected:
	char _theme[10];
public:
	Background()
	{
	}
	virtual void getTheme() = 0;
};

// Derived Light Background class
class LightBkgd : public Background
{
public:
	LightBkgd()
	{
		cout << "Making the background white" << endl;
		strcpy(_theme, "light");
	}
	void getTheme()
	{
		cout << "This is a part of the light theme" << endl;
	}
};

// Derived Dark Background class
class DarkBkgd : public Background
{
public:
	DarkBkgd()
	{
		//SetConsoleTextAttribute(hConsole, 15);
		cout << "Making the background black" << endl;
		strcpy(_theme, "dark");
	}
	void getTheme()
	{
		cout << "This is a part of the dark theme" << endl;
	}
};
#pragma endregion Background

#pragma region Text
// Base Text class
class Text
{
protected:
	char _theme[10];
public:
	Text()
	{
	}
	virtual void message() = 0;
};

// Derived Black Text class
class BlackText : public Text
{
public:
	BlackText()
	{
		//SetConsoleTextAttribute(hConsole, 240);
		strcpy(_theme, "light");
		cout << "Making the text black" << endl;
	}
	void message()
	{
		//SetConsoleTextAttribute(hConsole, 240);
		cout << "This is the default font from the light theme" << endl;
	}
};

// Derived White Text class
class WhiteText : public Text
{
public:
	WhiteText()
	{
		//SetConsoleTextAttribute(hConsole, 15);
		strcpy(_theme, "dark");
		cout << "Making the text white" << endl;
	}
	void message()
	{
		//SetConsoleTextAttribute(hConsole, 15);
		cout << "This is the default font for the dark theme" << endl;
	}
};

// Derived Dark Green Text class
class Green1Text : public Text
{
public:
	Green1Text()
	{
		//SetConsoleTextAttribute(hConsole, 240);
		strcpy(_theme, "light");
		cout << "Making the text Green1" << endl;
	}
	void message()
	{
		//SetConsoleTextAttribute(hConsole, 240);
		cout << "This is the default font from the green light theme" << endl;
	}
};

// Derived Light Green Text class
class Green2Text : public Text
{
public:
	Green2Text()
	{
		//SetConsoleTextAttribute(hConsole, 15);
		strcpy(_theme, "dark");
		cout << "Making the text Green2" << endl;
	}
	void message()
	{
		//SetConsoleTextAttribute(hConsole, 15);
		cout << "This is the default font for the green dark theme" << endl;
	}
};

#pragma endregion Text

#pragma region Factories
// Base Factory
class ThemeFactory
{
public:
	virtual Background* setBackground() = 0;
	virtual Text* getDefaultText() = 0;
	virtual Text* getGreenText() = 0;

};

// Derived Light Theme Factory which pairs the white background with darker text
class LightFactory : public ThemeFactory
{
public:
	Background * setBackground()
	{
		return new LightBkgd();
	}
	Text * getDefaultText( )
	{
		return new BlackText();
	}
	Text * getGreenText( )
	{
		return new Green1Text();
	}

};

// Derived Dark Theme Factory which pairs the black background with lighter text
class DarkFactory : public ThemeFactory
{
public:
	Background * setBackground( )
	{
		return new DarkBkgd();
	}
	Text * getDefaultText( )
	{
		return new WhiteText();
	}
	Text * getGreenText( )
	{
		return new Green2Text();
	}

};
#pragma endregion Factories

int main()
{
	ThemeFactory* app;
	int choice;

	cout << "Select a theme: " << endl;
	cout << "1: Light" << endl;
	cout << "2: Dark" << endl;
	cout << "Selection: ";
	cin >> choice;
	cout << endl;

	// Initiate the correct factory based on user input
	switch (choice)
	{
	case 1:
		app = new LightFactory;
		break;
	case 2:
		app = new DarkFactory;
		break;
	default:
		cout << "Invalid Selection" << endl;
		app = NULL;
		break;
	}

	// Get the correct objects based on factory selected
	if (app != NULL)
	{
		Background* appBkgd = app->setBackground();
		Text *appDefaultText = app->getDefaultText();
		Text *appGreenText = app->getGreenText();

		appDefaultText->message();
		appGreenText->message();
	}
	cout << endl;
}
