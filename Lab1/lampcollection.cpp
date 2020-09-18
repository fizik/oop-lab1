#include <math.h>
#include "lampcollection.h"

const float LampCollection::HEIGHT_MIN = 2;
const float LampCollection::HEIGHT_DEFAULT = 2.6;
const float LampCollection::HEIGHT_MAX = 3;

LampCollection::LampCollection(const int n, const int m) {
    if (n > 0 and m > 0) {
        collection_ = new Lamp *[n];
        for (int i = 0; i < n; i++) {
            collection_[i] = new Lamp [m];
            for (int j = 0; j < m; j++)
            {
                collection_[i][j] = Lamp();
            };
        };
        n_ = n;
        m_ = m;
    }
    else
        throw 1;
};

Lamp LampCollection::getLamp(const int x, const int y) const {
    if ((x >= 0) && (x < n_) && (y >= 0) && (y < m_))
        return collection_[x][y];
    else
        throw 1;
};

void LampCollection::setLamp(const int x, const int y, Lamp &lamp) {
    if ((x >= 0) && (x < n_) && (y >= 0) && (y < m_))
        collection_[x][y] = lamp;
    else
        throw 1;
};

int LampCollection::getLength() const {
    return n_;
};

int LampCollection::getWidth() const {
    return m_;
};

double LampCollection::getIlluminance(const float x, const float y, const float z, const float height) const {
    double illuminance = 0;
    bool is_z_good = (z < height) && (z >= 0);
    bool is_x_good = (x < n_) && (x >= 0);
    bool is_y_good = (y < m_) && (y >= 0);
    bool is_height_good = (height >= HEIGHT_MIN) && (height <= HEIGHT_MAX);
    if (is_x_good && is_y_good && is_z_good && is_height_good)
        for (int i=0; i<n_; i++)
            for (int j=0; j<m_; j++)
            {
                double r = sqrt((x-i)*(x-i) + (y-j)*(y-j) + (height-z)*(height-z));
                double tg_a = (height - z)/sqrt((x-i)*(x-i) + (y-j)*(y-j));
                double cos_a = sqrt(1/(tg_a*tg_a + 1));
                illuminance += collection_[i][j].getIntensity()*cos_a/(r*r);
            }
    return illuminance;
};

LampCollection::~LampCollection() {
    if (collection_) {
        for (int i = 0; i < n_; i++)
            delete [] collection_[i];
        delete [] collection_;
    };
};


