#include "ex6.1.h"

Array::Array(int s) : size(s) {
    if (size > 0) {
        data = new int[size]();
    } else {
        data = nullptr;
    }
}

Array::Array(const Array& other) : size(other.size) {
    if (size > 0) {
        data = new int[size];
        for (int i = 0; i < size; ++i) {
            data[i] = other.data[i];
        }
    } else {
        data = nullptr;
    }
}

Array::~Array() {
    delete[] data;
}

Array& Array::operator=(const Array& other) {
    if (this != &other) {
        delete[] data;
        size = other.size;
        if (size > 0) {
            data = new int[size];
            for (int i = 0; i < size; ++i) {
                data[i] = other.data[i];
            }
        } else {
            data = nullptr;
        }
    }
    return *this;
}

int Array::get(int index) const {
    if (index >= 0 && index < size) {
        return data[index];
    }
    return -1;
}

void Array::set(int index, int val) {
    if (index >= 0 && index < size) {
        data[index] = val;
    }
}

int Array::getSize() const {
    return size;
}

void Array::display() const {
    std::cout << "Array: [ ";
    for (int i = 0; i < size; ++i) {
        std::cout << data[i] << " ";
    }
    std::cout << "]\n";
}

// --- LỚP HISTOGRAMARRAY ---
HistogramArray::HistogramArray(int s, int hSize) : Array(s), histSize(hSize) {
    if (histSize > 0) {
        histogram = new int[histSize]();
    } else {
        histogram = nullptr;
    }
    compute_histogram();
}

HistogramArray::HistogramArray(const HistogramArray& other) : Array(other), histSize(other.histSize) {
    if (histSize > 0) {
        histogram = new int[histSize];
        for (int i = 0; i < histSize; ++i) {
            histogram[i] = other.histogram[i];
        }
    } else {
        histogram = nullptr;
    }
}

HistogramArray::~HistogramArray() {
    delete[] histogram;
}

HistogramArray& HistogramArray::operator=(const HistogramArray& other) {
    if (this != &other) {
        Array::operator=(other);
        delete[] histogram;
        histSize = other.histSize;
        if (histSize > 0) {
            histogram = new int[histSize];
            for (int i = 0; i < histSize; ++i) {
                histogram[i] = other.histogram[i];
            }
        } else {
            histogram = nullptr;
        }
    }
    return *this;
}

void HistogramArray::compute_histogram() {
    if (!histogram) return;
    
    std::fill(histogram, histogram + histSize, 0);

    for (int i = 0; i < size; ++i) {
        if (data[i] >= 0 && data[i] < histSize) {
            histogram[data[i]]++;
        }
    }
}

void HistogramArray::set(int index, int val) {
    if (index >= 0 && index < size) {
        Array::set(index, val);
        compute_histogram();
    }
}

void HistogramArray::display_histogram() const {
    std::cout << "--- Histogram (Tan suat xuat hien) ---\n";
    for (int i = 0; i < histSize; ++i) {
        std::cout << "Gia tri " << i << ": " << histogram[i] << " lan\n";
    }
}
