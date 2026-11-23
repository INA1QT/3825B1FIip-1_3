#include "tset.h"
TSet::TSet(int mp) : MaxPower(mp), BitField(mp) {
}
TSet::TSet(const TSet& s) : MaxPower(s.MaxPower), BitField(s.BitField) {
}

TSet::TSet(const TBitField& bf) : MaxPower(bf.GetLength()), BitField(bf) {
}
TSet::operator TBitField() {
    return BitField;
}
int TSet::GetMaxPower(void) const {
    return MaxPower;
}
void TSet::InsElem(const int Elem) {
    BitField.SetBit(Elem);
}
void TSet::DelElem(const int Elem) {
    BitField.ClrBit(Elem);
}
int TSet::IsMember(const int Elem) const {
    return BitField.GetBit(Elem);
}

int TSet::operator==(const TSet& s) const {
    return (BitField == s.BitField) && (MaxPower == s.MaxPower);
}
int TSet::operator!=(const TSet& s) const {
    return !(*this == s);
}
TSet& TSet::operator=(const TSet& s) {
    if (this == &s) {
        return *this;
    }
    MaxPower = s.MaxPower;
    BitField = s.BitField;

    return *this;
}
TSet TSet::operator+(const int Elem) {
    TSet res(*this);
    res.InsElem(Elem);
    return res;
}
TSet TSet::operator-(const int Elem) {
    TSet res(*this);
    res.DelElem(Elem);
    return res;
}
TSet TSet::operator+(const TSet& s) {
    int maxPower = MaxPower > s.MaxPower ? MaxPower : s.MaxPower;
    TSet res(maxPower);
    res.BitField = BitField | s.BitField;
    return res;
}
TSet TSet::operator*(const TSet& s) {
    int maxPower = MaxPower > s.MaxPower ? MaxPower : s.MaxPower;
    TSet res(maxPower);
    res.BitField = BitField & s.BitField;
    return res;
}
TSet TSet::operator~(void) {
    TSet res(~BitField);
    return res;
}
std::istream& operator>>(std::istream& is, TSet& s) {
    int elem;
    char ch;
    do {
        is >> ch;
    } while (ch != '{');

    do {
        is >> elem;

        s.InsElem(elem);

        is >> ch;

    } while (ch == ',');

    return is;
}
std::ostream& operator<<(std::ostream& os, const TSet& s) {
    os << "{";
    int first = 1;
    for (int i = 0; i < s.MaxPower; i++) {
        if (s.IsMember(i)) {
            if (!first) {
                os << ", ";
            }

            os << i;

            first = 0;
        }
    }
    os << "}";
    return os;
}