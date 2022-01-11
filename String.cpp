//выполонил все кроме 5ого

#include <iostream>
using namespace std;
class String {
private:
    char* str_;
    int length_;
    static int CINLIMIT;
    static int number_of_strings_;
public:
    String()
    {
        str_ = nullptr;
        length_ = 0;
        number_of_strings_++;
    }
    String(char* str)
    {
        number_of_strings_++;
        length_ = strlen(str);

        str_ = new char[length_ + 1];

        for (int i = 0; i < length_; i++)
        {
            str_[i] = str[i];
        }

        str_[length_] = '\0';

    }
    String(const String& other)
    {
        length_ = strlen(other.str_);
        str_ = new char[length_ + 1];

        for (int i = 0; i < length_; i++)
        {
            str_[i] = other.str_[i];
        }

        str_[length_] = '\0';
    }
    String& operator =(const String& other)
    {
        if (str_ != nullptr)
        {
            delete[] str_;
        }

        length_ = strlen(other.str_);
        str_= new char[length_ + 1];

        for (int i = 0; i < length_; i++)
        {
            str_[i] = other.str_[i];
        }

        str_[length_] = '\0';

        return *this;

    }
    String& operator =(char* str) {

        length_ = strlen(str);

        str_ = new char[length_ + 1];

        for (int i = 0; i < length_; i++)
        {
            str_[i] = str[i];
        }

        str_[length_] = '\0';
    }
    char* GetString() {
        return str_;
    }
    int GetLength() {
        return length_;
    }
    int GetNumberOfStrings() {
        return number_of_strings_;
    }
    char& operator [](int index){
        return str_[index];
    }
    friend ostream& operator << (ostream& out, const String& origin) {
        out << origin.str_;
            return out;
    }
    friend istream& operator >> (istream& in, String& str) {
        in >> str.str_;
        return in;
    }
    bool operator <(const String& other) {
        if (length_ < other.length_) {
            return true;
        }
        return false;
    }
    bool operator >(const String& other) {
        if (length_ > other.length_) {
            return true;
        }
        return false;
    }
    bool operator >=(const String& other) {
        if (length_ >= other.length_) {
            return true;
        }
        return false;
    }
    bool operator <=(const String& other) {
        if (length_ <= other.length_) {
            return true;
        }
        return false;
    }

    bool operator ==(const String& other)
    {
        if (length_!= other.length_)
        {
            return false;
        }

        for (int i = 0; i < length_; i++)
        {
            if (str_[i] != other.str_[i])
            {
                return false;
            }
        }
        return true;
    }
    bool operator !=(const String& other){
        return !(operator==(other));
    }
    String operator+=(char symbol) {
        String newStr;
        int thisLength = strlen(str_);
        newStr.length_ = thisLength + 1;
        newStr.str_ = new char[thisLength + 2];
        int i = 0;
        for (; i < thisLength; i++)
        {
            newStr.str_[i] = str_[i];
        }
        newStr.str_[thisLength] = symbol;

        newStr.str_[thisLength + 1] = '\0';

        return newStr;
    }
    String operator+=(const String& other){
        String newStr;

        int thisLength = strlen(str_);
        int otherLength = strlen(other.str_);

        newStr.length_ = thisLength + otherLength;

        newStr.str_ = new char[thisLength + otherLength + 1];


        int i = 0;
        for (; i < thisLength; i++)
        {
            newStr.str_[i] = this->str_[i];
        }

        for (int j = 0; j < otherLength; j++, i++)
        {
            newStr.str_[i] = other.str_[j];
        }

        newStr.str_[thisLength + otherLength] = '\0';

        return newStr;
    }
    String Reverse() {
        String ReversedString;
        ReversedString.length_ = length_;
        ReversedString.str_ = new char[length_ + 1];
        for (int i = 0; i < length_; i++)
        {
            ReversedString.str_[i] = str_[length_-i];
        }
        return ReversedString;
    }
    String Substr(int start_position, int count) {
        String NewString;
        NewString.length_ = count;
        NewString.str_ = new char[count + 1];
        for (int i = 0; i < count; i++)
        {
            NewString.str_[start_position + i] = str_[i];
        }
        NewString.str_[count] = '\0';
    }
    ~String()
    {
        delete[] str_;
    }
};


int main()
{
    char* s = new char[10];
    String str2(s);
    str2 += 'c';
    
    cout << str2;

    return 0;
}