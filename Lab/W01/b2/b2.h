#pragma once 

class Ngay
{
private:
    int _ng, _th, _n;
    void ChuanHoa();

public:
    Ngay();
    Ngay(const int&);
    Ngay(const int&, const int&, const int&);
    Ngay(const char* s);
    ~Ngay();

    void Xuat();
};

