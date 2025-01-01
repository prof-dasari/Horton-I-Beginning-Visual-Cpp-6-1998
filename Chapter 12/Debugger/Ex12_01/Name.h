// Name.h - Definition of the Name class

#ifndef NAME_H
#define NAME_H

// Class defining a person's name
class Name
{
  public:
    Name();                                             // Default constructor
    Name(const char* pFirst, const char* pSecond);      // Constructor

    char* getName(char* pName) const;                   // Get the complete name
    int getNameLength() const;                          // Get the complete name length

  // Comparison operators for names    
    bool operator<(const Name& name) const;
    bool operator==(const Name& name) const;
    bool operator>(const Name& name) const;

  private:
    char* pFirstname;
    char* pSurname;
};

#endif //NAME_H
