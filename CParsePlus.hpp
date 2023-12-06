#include <iostream>
#include <typeinfo>
#include <fstream>

namespace CParsePlus 
{
    class Parser {
        /*
        a parser that takes a struct and a file, parsing the file into the 
        proper types in the struct.
        */
        public:
            Parser();
            ~Parser(); //use delete[] (varname) to delete class members

            //reads from file and places types into respective struct member
            template <typename C, typename std::enable_if<std::is_class<C>::value, C>::type* = nullptr> //C for class
            bool parse_to_class(C& object, std::fstream& file);

            //non-class version.
            template <typename C, typename std::enable_if<!std::is_class<C>::value, C>::type* = nullptr> //C for class
            bool parse_to_class(C& object, std::fstream& file);
    };

    //class version.
    template <typename C, typename std::enable_if<std::is_class<C>::value, C>::type* = nullptr> //C for class
    bool Parser::parse_to_class(C& object, std::fstream& file)
    {
        //maybe instead of iterating, allow user to input the members of the class into the function


        return false;
    }

    //non-class version.
    template <typename C, typename std::enable_if<!std::is_class<C>::value, C>::type* = nullptr> //C for class
    bool Parser::parse_to_class(C& object, std::fstream& file)
    {
        throw std::runtime_error("CParsePlus::Parser::parse_to_class-- Input error: not a class or struct.");
        return false;
    }
}