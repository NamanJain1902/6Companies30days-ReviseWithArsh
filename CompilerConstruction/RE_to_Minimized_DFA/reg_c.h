#ifndef REG_C_H
#define REG_C_H

// using namespace std;

class REG_C {

private:
    static const std::unordered_set<char> ops;
    std::string regexp;
    std::string preprocessed_regexp;


public:

    REG_C() {}
    REG_C(std::string s) : regexp(s) {}

    void preprocess();
    std::string toPostfix(std::string);
    bool isAlpha(char);


    // getters
    std::string get_regexp() {
        return this->regexp;
    }
    std::string get_preprocessed_re() {
        return this->preprocessed_regexp;
    }

    // setters
};

#endif