//------------------------------
//  DO NOT MODIFY NEXT LINE
//------------------------------
#include "catch.hpp"
//------------------------------

// Implement the class methods
class Rot13 {
    const int rotation{13};
    std::string text;

public:
    Rot13(std::string msg = "");
    bool operator!();
    void operator>>(std::string&);
    friend void operator<<(std::string&, Rot13&);
};

//Rot13::operator!(){

//  if(text==0)
//  return 0;
//  else 
// return 1;
//}
public:
        Rot13(string text);
        bool operator !();
        void operator >>(string *s);
        void operator <<(string *s);
};

Rot13::Rot13(string text) {
        for(char c : text) {
                        if((c<'a'||c>'z') && c!=32 && c!='\0')
                                return ;
                }
                this->text = text;
}

bool Rot13::operator ! () {
        if(this->text.size()==0)
                        return true;
                else
                        return false;
}

void Rot13::operator >>(string *s) {
                for(char c : this->text) {
                        if(c==' '){
                                s->push_back(' ');
                                continue;
                        }
                        int index = static_cast<int >(c) - 97;
                        int new_index = (index+13)%26;
                        int ASCII = new_index + 97;

                        char new_char = static_cast<char >(ASCII);
                        
                }
}

void Rot13::operator <<(string *s) {
                for(char &c : *s) {
                        if(c==' '){
                                s->push_back(' ');
                                continue;
                        }
                        int index = static_cast<int >(c) - 97;
                        int new_index = (26+index-13)%26;
                        int ASCII = new_index + 97;

                        char new_char = static_cast<char >(ASCII);
                        c = new_char;
                }
}
//------------------------------
//   DO NOT MODIFY TEST CASES
//------------------------------
TEST_CASE( "Assignment" ) {
    SECTION( "v1" ) {
        Rot13 cipher;
        REQUIRE( !cipher );
    }
    SECTION( "v2" ) {
        Rot13 cipher{"ABCDEFGHIJKLMNOPQRSTUVWXYZ"};
        REQUIRE( !cipher );
    }
    SECTION( "v3" ) {
        Rot13 cipher{"slkgjskjg  akjf Adkfjd fsdfj"};
        REQUIRE( !cipher );
    }
    SECTION( "v4" ) {
        Rot13 cipher{"abcdefghijkl mnopqrst uvwxyz"};
        REQUIRE( !!cipher );
    }
    SECTION( "e1" ) {
        Rot13 cipher{"abcdefghijkl mnopqrst uvwxyz"};
        REQUIRE( !!cipher );
        std::string secret;
        cipher >> secret;
        REQUIRE( secret == "nopqrstuvwxy zabcdefg hijklm" );
    }
    SECTION( "e2" ) {
        Rot13 cipher{"nopqrstuvwxy zabcdefg hijklm"};
        REQUIRE( !!cipher );
        std::string msg;
        msg << cipher;
        REQUIRE( msg == "abcdefghijkl mnopqrst uvwxyz" );
    }
}
//------------------------------
