#pragma once

#include <iostream>
#include <algorithm>

class Array {
protected:
    int* data;
    int size;

public:
    Array(int s = 0);
    Array(const Array& other);
    virtual ~Array();

    Array& operator=(const Array& other);

    int get(int index) const;
    virtual void set(int index, int val);
    int getSize() const;

    virtual void display() const;
};

class HistogramArray : public Array {
private:
    int* histogram;
    int histSize;

public:
    HistogramArray(int s, int hSize);
    HistogramArray(const HistogramArray& other);
    ~HistogramArray() override;

    HistogramArray& operator=(const HistogramArray& other);

    void compute_histogram();
    void set(int index, int val) override;
    void display_histogram() const;
};