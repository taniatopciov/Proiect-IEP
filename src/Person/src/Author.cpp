#include "Author.hpp"

// constructor with member initialization list
Author::Author(char *name, int age, int numberOfWrittenBooks)
    : Person(name, age),
      numberOfWrittenBooks(numberOfWrittenBooks)
{
    cout << "Author constructor" << endl;
}

Author::Author(const char *name, int age, int numberOfWrittenBooks)
    : Author((char *)name, age, numberOfWrittenBooks)
{
}

void Author::printPresentation()
{
    cout << "Hello! My name is " << this->name
         << ". I am " << this->age << " years old and I have written "
         << this->numberOfWrittenBooks << " books." << endl;
}

char *Author::getAuthorName()
{
    return this->name;
}

char *Author::write()
{
    char myText[30];
    strcpy(myText, this->name);
    strcat(myText, " has written this. ");

    char *text = new char[strlen(myText) + 1];
    strcpy(text, myText);

    return text;
}

void Author::writeInCollaboration(Book *b)
{
    char *oldText = b->getText();

    unique_ptr<char> additionalText(write());

    char *newText;

    newText = new char[strlen(b->getText()) + strlen(additionalText.get()) + 1];
    strcpy(newText, oldText);
    strcat(newText, additionalText.get());

    delete[] oldText;

    b->setText(newText);
}