#include "b3.h"

void SoNguyenLon::Pow10(const int& n)
{
    if (n <= 0 || (lCS.size() == 1 && lCS[0] == 0))
    {
        return;
    }
    for (int i = 0; i < n; ++i)
    {
        lCS.insert(lCS.begin(), 0);
    }
}

SoNguyenLon::SoNguyenLon(void)
{
    lCS.push_back(0);
}

SoNguyenLon::SoNguyenLon(const int& cs, const int& scs)
{
    int csR = cs;
    if (csR < 1)
    {
        csR = 1;
    }
    if (csR > 9)
    {
        csR = 9;
    }
    int soCS = std::abs(scs);
    if (soCS < 1)
    {
        soCS = 1;
    }
    for (int i = 0; i < soCS; ++i)
    {
        lCS.push_back(csR);
    }
}

SoNguyenLon::SoNguyenLon(const unsigned long& n)
{
    unsigned long temp = n;
    do
    {
        lCS.push_back(temp % 10);
        temp /= 10;
    } while (temp > 0);
}

SoNguyenLon::SoNguyenLon(const SoNguyenLon& snl)
{
    lCS = snl.lCS;
}

SoNguyenLon::SoNguyenLon(const char* s)
{
    if (s == nullptr)
    {
        lCS.push_back(0);
        return;
    }
    int len = std::strlen(s);
    int start = 0;
    while (start < len && (s[start] < '0' || s[start] > '9'))
    {
        start++;
    }
    while (start < len - 1 && s[start] == '0')
    {
        start++;
    }
    for (int i = len - 1; i >= start; --i)
    {
        if (s[i] >= '0' && s[i] <= '9')
        {
            lCS.push_back(s[i] - '0');
        }
    }
    if (lCS.size() == 0)
    {
        lCS.push_back(0);
    }
}

SoNguyenLon::~SoNguyenLon(void)
{
}

int SoNguyenLon::SoCS() const
{
    return lCS.size();
}

bool SoNguyenLon::operator>(const SoNguyenLon& snl) const
{
    if (lCS.size() > snl.lCS.size())
    {
        return true;
    }
    if (lCS.size() < snl.lCS.size())
    {
        return false;
    }
    for (int i = lCS.size() - 1; i >= 0; --i)
    {
        if (lCS[i] == snl.lCS[i])
        {
            continue;
        }
        if (lCS[i] > snl.lCS[i])
        {
            return true;
        }
        return false;
    }
    return false;
}

SoNguyenLon& SoNguyenLon::operator=(const SoNguyenLon& snl)
{
    if (this == &snl)
    {
        return *this;
    }
    lCS = snl.lCS;
    return *this;
}

SoNguyenLon& SoNguyenLon::operator+=(SoNguyenLon snl)
{
    *this = *this + snl;
    return *this;
}

SoNguyenLon SoNguyenLon::operator+(SoNguyenLon snl)
{
    SoNguyenLon snlKQ;
    snlKQ.lCS.clear();
    SoNguyenLon* snlSCSMax = (SoCS() > snl.SoCS()) ? this : &snl;
    SoNguyenLon* snlSCSMin = (snlSCSMax == this) ? &snl : this;
    int nho = 0, temp;
    for (int i = 0; i < snlSCSMin->SoCS(); ++i)
    {
        temp = lCS[i] + snl.lCS[i] + nho;
        snlKQ.lCS.push_back(temp % 10);
        nho = temp / 10;
    }
    for (int i = snlSCSMin->SoCS(); i < snlSCSMax->SoCS(); ++i)
    {
        temp = snlSCSMax->lCS[i] + nho;
        snlKQ.lCS.push_back(temp % 10);
        nho = temp / 10;
    }
    if (nho > 0)
    {
        snlKQ.lCS.push_back(1);
    }
    return snlKQ;
}

SoNguyenLon SoNguyenLon::operator-(SoNguyenLon snl)
{
    if (!(*this > snl))
    {
        return SoNguyenLon();
    }
    SoNguyenLon snlKQ;
    snlKQ.lCS.clear();
    int muon = 0, temp;
    for (int i = 0; i < snl.SoCS(); ++i)
    {
        temp = lCS[i] - snl.lCS[i] - muon;
        if (temp < 0)
        {
            temp += 10;
            muon = 1;
        }
        else
        {
            muon = 0;
        }
        snlKQ.lCS.push_back(temp);
    }
    for (int i = snl.SoCS(); i < SoCS(); ++i)
    {
        temp = lCS[i] - muon;
        if (temp < 0)
        {
            temp += 10;
            muon = 1;
        }
        else
        {
            muon = 0;
        }
        snlKQ.lCS.push_back(temp);
    }
    while (snlKQ.SoCS() > 1 && snlKQ.lCS[snlKQ.SoCS() - 1] == 0)
    {
        snlKQ.lCS.RemoveTail();
    }
    return snlKQ;
}

SoNguyenLon SoNguyenLon::operator*(SoNguyenLon snl)
{
    SoNguyenLon snlKQ, * psnlTemp;
    SoNguyenLon* snlSCSMax = (SoCS() > snl.SoCS()) ? this : &snl;
    SoNguyenLon* snlSCSMin = (snlSCSMax == this) ? &snl : this;
    int nho = 0, temp;
    for (int i = 0; i < snlSCSMin->SoCS(); ++i)
    {
        psnlTemp = new SoNguyenLon;
        psnlTemp->lCS.clear();
        nho = 0;
        for (int j = 0; j < snlSCSMax->SoCS(); ++j)
        {
            temp = snlSCSMin->lCS[i] * snlSCSMax->lCS[j] + nho;
            psnlTemp->lCS.push_back(temp % 10);
            nho = temp / 10;
        }
        if (nho > 0)
        {
            psnlTemp->lCS.push_back(nho);
        }
        psnlTemp->Pow10(i);
        snlKQ += *psnlTemp;
        delete psnlTemp;
    }
    while (snlKQ.SoCS() > 1 && snlKQ.lCS[snlKQ.SoCS() - 1] == 0)
    {
        snlKQ.lCS.RemoveTail();
    }
    return snlKQ;
}

SoNguyenLon operator+(const unsigned int& n, const SoNguyenLon& snl)
{
    return SoNguyenLon((unsigned long)n) + snl;
}

SoNguyenLon operator-(const unsigned int& n, const SoNguyenLon& snl)
{
    return SoNguyenLon((unsigned long)n) - snl;
}

std::ostream& operator<<(std::ostream& os, const SoNguyenLon& snl)
{
    for (int i = snl.lCS.size() - 1; i >= 0; --i)
        os << (int)snl.lCS[i];
    return os;
}